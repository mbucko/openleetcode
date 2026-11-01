const path = require('path')
const file = require('fs');
const amdLoader = require('monaco-editor/min/vs/loader.js');
const Split = require('split.js')
const { exec } = require('child_process');
const DirectoryManager = require('./directory-manager.js');
const { Validator } = require('jsonschema');

const amdRequire = amdLoader.require;
const amdDefine = amdLoader.require.define;
var editor;

const directory_manager = require('./directory-manager.js');
const directoryManager = new directory_manager.DirectoryManager();

amdRequire.config({
    baseUrl: path.join(__dirname, './node_modules/monaco-editor/min')
});

var activeProblem = null;
var activeLanguage = null;

const LANGUAGE_LABELS = {
    cpp: 'C++',
    python: 'Python',
};
const LANGUAGE_STORAGE_KEY = 'language';

// workaround monaco-css not understanding the environment
self.module = undefined;

// Writes the editor content to the solution file of the problem and language
// the editor is currently showing.
function saveSolution(content) {
    if (!previousProblem) {
        return;
    }

    const userSolutionFilename =
        directoryManager.getUserSolutionFilename(previousProblem,
                                                 previousLanguage);

    if (file.existsSync(userSolutionFilename) &&
        file.readFileSync(userSolutionFilename, 'utf8') === content) {
            console.log("No changes to save");
        return;
    }
    console.log("Saving problem " + previousProblem + " to " +
        userSolutionFilename);
    file.writeFileSync(userSolutionFilename, content);
}

function parseResultsFileFromStdout(stdout) {
    // stdout:
    // LongestSubstringWithoutRepeatingCharacters for testcase All in language cpp
    // Results written to /path\to/openleetcode/src/ui/testcase_output/<testname><datetime>.results
    // Status: <status>
    // Duration: <duration>ms
    match = stdout.match(/Results written to (.*\.results)/);
    if (!match || match.length === 0) {
        return null;
    }
    return match[1];
}

function parseBuildError(stdout) {
    // Running command: cmake --build ...
    // <MATCHED BUILD ERROR>
    // Error running the command: cmake --build
    const regex = /cmake --build[\s\S]*?cmake --build/;
    const match = stdout.match(regex);
    if (!match || match.length === 0) {
        return stdout;
    }
    const buildError = match[0].split('\n').slice(1, -1).join('\n');

    return buildError;
}

// Returns whether the results match the schema. If they don't, the reason is
// shown in the Compilation tab so a broken run is never silently ignored.
function validateResults(results) {
    let error;
    try {
        const schema = directoryManager.getResultsSchemaJson();
        const v = new Validator();
        const validation = v.validate(results, schema);
        if (validation.valid) {
            return true;
        }
        error = validation.errors.map(e => e.stack).join('\n');
    } catch (e) {
        error = String(e);
    }

    console.error("Invalid test results:", error);
    document.getElementById('compilation-content').textContent =
        "The test run produced invalid results:\n" + error +
        "\n\nResults:\n" + JSON.stringify(results, null, 4);
    document.getElementById('tab-compilation-button').click();
    return false;
}

// Picks the one-line description of a crash out of sanitizer output, e.g.
// "solution.cpp:12:9: runtime error: signed integer overflow: ..." or
// "heap-buffer-overflow solution.cpp:5 in Solution::twoSum(...)".
function parseRuntimeError(stderr) {
    const lines = (stderr || '').split('\n');
    for (const line of lines) {
        // UndefinedBehaviorSanitizer: "<path>:<line>:<col>: runtime error: ..."
        const match = line.match(/^(.*):(\d+):(\d+): runtime error: (.*)$/);
        if (match) {
            const [, file, lineNumber, column, message] = match;
            return `${path.basename(file)}:${lineNumber}:${column}: ${message}`;
        }
    }
    // AddressSanitizer already reports the file name without its directory.
    const summary = lines.find(line => line.startsWith('SUMMARY: '));
    if (summary) {
        return summary.replace(/^SUMMARY: \w+Sanitizer: /, '');
    }
    return null;
}

function escapeHtml(text) {
    const div = document.createElement('div');
    div.textContent = text ?? '';
    return div.innerHTML;
}

// Arguments of a testcase file: every line except the expected output.
function readTestcaseInput(test) {
    // When the whole run fails, testcase_file is the testcases folder.
    if (test.testcase_file === undefined ||
        !file.existsSync(test.testcase_file) ||
        !file.statSync(test.testcase_file).isFile()) {
        return null;
    }
    const lines = file.readFileSync(test.testcase_file, 'utf8').split('\n');
    return lines.slice(0, -1).join('\n');
}

function getVerdict(results) {
    if (results.status === 'Ok') {
        return 'Accepted';
    }
    const failed = results.tests.filter(test => test.status === 'Failed');
    if (failed.some(test => (test.reason || '').startsWith('Runtime error'))) {
        return 'Runtime error';
    }
    if (failed.some(test => test.reason ===
            'Mismatch between expected and actual output.')) {
        return 'Wrong answer';
    }
    return 'Failed';
}

function renderTestcaseDetail(test) {
    const rows = [];
    const input = readTestcaseInput(test);
    if (input !== null) {
        rows.push(['Input', input, '']);
    }
    if (test.status === 'Failed' && test.expected !== '') {
        rows.push(['Output', JSON.stringify(test.actual), 'bad']);
        rows.push(['Expected', JSON.stringify(test.expected), 'good']);
    }
    if (test.reason && !test.reason.startsWith('Mismatch')) {
        rows.push(['Reason', test.reason, 'bad']);
    }
    return rows.map(([label, value, kind]) => `
        <span class="label">${label}</span>
        <pre class="value ${kind}">${escapeHtml(value)}</pre>`).join('');
}

function setTestResults(results) {
    if (!validateResults(results)) {
        return;
    }
    console.log("Setting test results: " + JSON.stringify(results));
    const div = document.getElementById('test-results-content');
    const tests = results.tests;
    const passed = tests.filter(test => test.status === 'Success').length;
    const failedCount = tests.filter(test => test.status === 'Failed').length;
    const accepted = results.status === 'Ok';

    div.innerHTML = `
        <div class="verdict ${accepted ? 'verdict-pass' : 'verdict-fail'}">
            <h2>${getVerdict(results)}</h2>
            <span class="verdict-details">${passed} of ${tests.length}
                testcases passed in ${results.duration_ms} ms</span>
        </div>
        ${results.stderr ?
            `<pre class="run-error">${escapeHtml(results.stderr)}</pre>` : ''}
        <div class="testcase-strip"></div>
        <div class="testcase-detail"></div>`;

    const strip = div.querySelector('.testcase-strip');
    const detail = div.querySelector('.testcase-detail');
    const chips = tests.map(test => {
        const chip = document.createElement('button');
        const kind = test.status === 'Success' ? 'pass' :
            test.status === 'Failed' ? 'fail' : 'other';
        chip.className = `testcase-chip ${kind}`;
        chip.textContent = test.testcase_name.replace(/^TestCase/, '');
        chip.title = `${test.testcase_name}: ${test.status}`;
        chip.addEventListener('click', () => {
            chips.forEach(other => other.classList.remove('selected'));
            chip.classList.add('selected');
            detail.innerHTML = renderTestcaseDetail(test);
        });
        strip.appendChild(chip);
        return chip;
    });

    // Open the first failing testcase, as it's the one to look at.
    const firstFailed = tests.findIndex(test => test.status === 'Failed');
    if (firstFailed !== -1) {
        chips[firstFailed].click();
    }

    document.getElementById('failed-count').textContent =
        failedCount > 0 ? `${failedCount} failed` : '';
    document.getElementById('tab-test-results-button').click();
}

function run(callback, testcase = 'All', expected = false) {
    saveSolution(editor.getValue());
    const pathsFile = DirectoryManager.getPathsFile();
    if (!file.existsSync(pathsFile)) {
        throw new Error(`Paths file does not exist: ${pathsFile}`);
    }

    problemBuildsDir = file.readFileSync(pathsFile, 'utf8');
    problemBuildsDir = path.resolve(problemBuildsDir);
    const extension = process.platform === 'win32' ? '.bat' : '.sh';

    const command = `${problemBuildsDir}/openleetcode${extension} ` +
    `--problem_builds_dir ${problemBuildsDir} ` +
    `--language ${activeLanguage} ` +
    `--problem ${activeProblem} ` +
    `--testcase ${testcase} ` +
    `${expected ? '--run-expected-tests ' : ''}` +
    `--verbose`;

    console.log("Running command: " + command);

    var resultsFilename;
    exec(command, (error, stdout, stderr) => {
        var element = document.getElementById("compilation-content");
        
        element.textContent = "";
        resultsFilename = parseResultsFileFromStdout(stdout);
        if (!resultsFilename || !file.existsSync(resultsFilename)) {
            console.log("Setting error");
            console.log("Error running the command, error: " + error +
                        ", stderr: " + stderr + ", stdout: " + stdout);
            element.textContent = parseBuildError(stdout);
            document.getElementById('tab-compilation-button').click();
            return;
        }

        const results = file.readFileSync(resultsFilename, 'utf8');
        console.log(results);
        const resultsJson = JSON.parse(results);
        errorcode = resultsJson["errorcode"];
        console.log("errorcode: " + errorcode);
        if (errorcode != undefined && errorcode !== 0) {
            const runtimeError = parseRuntimeError(resultsJson.stderr);
            html = runtimeError ?
                `<p>Runtime error: ${escapeHtml(runtimeError)}</p>` : '';
            html += "<p>Errorcode: " + resultsJson.errorcode + "</p>";
            html += "<p>Stdout:</p><pre>" + escapeHtml(resultsJson.stdout) +
                "</pre>";
            html += "<p>Stderr:</p><pre>" + escapeHtml(resultsJson.stderr) +
                "</pre>";

            element.innerHTML = html;
            document.getElementById('tab-compilation-button').click();
            return;
        } else {
            console.log("Setting results");
            callback(resultsJson);
        }
    });
}

function setCustomTestcaseResults(results) {
    if (!validateResults(results)) {
        return;
    }
    
    document.getElementById('testcase-stderr').textContent = results.stderr;

    if (results.tests.length !== 1) {
        console.error("Expected 1 custom test results, got " +
            results.tests.length);
        return;
    }

    if (results.tests[0].status !== "Skipped") {
        console.error("Expected custom test status to be 'skipped', got " +
            results.tests[0].status);
        return;
    }

    console.log("Setting custom testcase results: " + JSON.stringify(results));

    document.getElementById('testcase-stdout').textContent = results.stdout;
    document.getElementById('testcase-output').textContent =
    JSON.stringify(results.tests[0].actual);

    run(setExpectedTestcaseResults, directoryManager.getCustomTestcaseName(),
    true);

    document.getElementById('tab-testcases').click();
}

function setExpectedTestcaseResults(expected) {
    if (!validateResults(expected)) {
        return;
    }

    if (expected.tests.length !== 1) {
        console.error("Expected 1 test results, got " +
            expected.tests.length);
            return;
    }

    if (expected.tests[0].status !== "Skipped") {
        console.error("Expected test status to be 'skipped', got " +
        expected.tests[0].status);
    }

    document.getElementById('expected-output').textContent =
        JSON.stringify(expected.tests[0].actual);
}

function runCustomTestcase() {
    console.log("Running custom testcase for " + activeProblem);

    document.getElementById('testcase-stdout').textContent = "";
    document.getElementById('testcase-stderr').textContent = "";
    document.getElementById('testcase-output').textContent = "";
    document.getElementById('compilation-content').textContent = "";
    document.getElementById('test-results-content').innerHTML = "";

    const inputValue = document.getElementById('input-container').value;
    if (inputValue.trim() === "") {
        document.getElementById('testcase-output').textContent =
            "Enter the input above, one argument per line.";
        document.getElementById('tab-testcases').click();
        return;
    }
    const input = inputValue + "\n*";
    const customTestcaseFilename =
        directoryManager.getCustomTestcaseFilename(activeProblem);
    if (!file.existsSync(path.dirname(customTestcaseFilename))) {
        console.log('The directory does not exist. Directory: ' + path.dirname(customTestcaseFilename));
        return;
    }
    
    file.writeFileSync(customTestcaseFilename, input);
    if (!file.existsSync(customTestcaseFilename)) {
        throw new Error(`Failed to write custom testcase to ` +
            `${customTestcaseFilename}`);
    }

    console.log('Custom testcase written to ' + customTestcaseFilename);

    run(setCustomTestcaseResults, directoryManager.getCustomTestcaseName());
}

function setDescription(problemName) {
    var element =
        document.querySelector('.markdown-content#description-content');
    element.innerHTML = directoryManager.getDescription(problemName);
}

function setSolution(problemName, language) {
    var element = document.querySelector('.markdown-content#solution-content');
    element.innerHTML = directoryManager.getSolution(problemName, language);
}

function setUserSolution(problemName, language) {
    const userSolutionFilename =
        directoryManager.getUserSolutionFilename(problemName, language);
    editor.setValue(file.readFileSync(userSolutionFilename, 'utf8'));
    monaco.editor.setModelLanguage(editor.getModel(), language);
}

// Saves the code being edited, then loads the given problem and language.
var previousProblem;
var previousLanguage;
function loadSolution(problemName, language) {
    saveSolution(editor.getValue());
    previousProblem = problemName;
    previousLanguage = language;

    setSolution(problemName, language);
    setUserSolution(problemName, language);
}

function onProblemSelected(problemName) {
    document.getElementById('testcase-stdout').textContent = "";
    document.getElementById('testcase-stderr').textContent = "";
    document.getElementById('testcase-output').textContent = "";

    console.log(`Problem selected: ${problemName}`);
    setDescription(problemName);
    loadSolution(problemName, activeLanguage);
    activeProblem = problemName;
    updateProblemControls();
}

function onLanguageSelected(language) {
    console.log(`Language selected: ${language}`);
    activeLanguage = language;
    localStorage.setItem(LANGUAGE_STORAGE_KEY, language);
    loadSolution(activeProblem, language);
}

function initializeLanguageSelect(languages) {
    const savedLanguage = localStorage.getItem(LANGUAGE_STORAGE_KEY);
    activeLanguage =
        languages.includes(savedLanguage) ? savedLanguage : languages[0];

    const select = document.getElementById('language-select');
    languages.forEach(language => {
        const option = document.createElement('option');
        option.value = language;
        option.textContent = LANGUAGE_LABELS[language];
        select.appendChild(option);
    });
    select.value = activeLanguage;
    select.addEventListener('change', event => {
        onLanguageSelected(event.target.value);
    });
}

// Themes: the CSS in styles.css defines each one's colors; the code editor
// gets a matching Monaco theme.
const THEMES = {
    cabin: { label: 'Dark blue', editorTheme: 'openleetcode-cabin' },
    graphite: { label: 'Dark grey', editorTheme: 'vs-dark' },
    sheet: { label: 'Light', editorTheme: 'vs' },
};
const DEFAULT_THEME = 'cabin';
const THEME_STORAGE_KEY = 'theme';
var activeTheme = DEFAULT_THEME;

function defineEditorThemes() {
    monaco.editor.defineTheme('openleetcode-cabin', {
        base: 'vs-dark',
        inherit: true,
        rules: [],
        colors: {
            'editor.background': '#0f1923',
            'editor.lineHighlightBackground': '#15222e',
            'editorLineNumber.foreground': '#4f6578',
            'editorLineNumber.activeForeground': '#d8e3ec',
            'editor.selectionBackground': '#264f78',
        },
    });
}

function applyTheme(theme) {
    activeTheme = theme;
    document.documentElement.dataset.theme = theme;
    if (typeof monaco !== 'undefined') {
        monaco.editor.setTheme(THEMES[theme].editorTheme);
    }
}

function initializeSettings() {
    const savedTheme = localStorage.getItem(THEME_STORAGE_KEY);
    applyTheme(savedTheme in THEMES ? savedTheme : DEFAULT_THEME);

    const select = document.getElementById('theme-select');
    Object.entries(THEMES).forEach(([theme, { label }]) => {
        const option = document.createElement('option');
        option.value = theme;
        option.textContent = label;
        select.appendChild(option);
    });
    select.value = activeTheme;
    select.addEventListener('change', event => {
        localStorage.setItem(THEME_STORAGE_KEY, event.target.value);
        applyTheme(event.target.value);
    });

    const panel = document.getElementById('settings-panel');
    document.getElementById('settings-button').addEventListener('click', () => {
        panel.classList.toggle('open');
    });
    document.addEventListener('mousedown', event => {
        if (!event.target.closest('#settings-panel') &&
            !event.target.closest('#settings-button')) {
            panel.classList.remove('open');
        }
    });
}

// Registers a Cmd/Ctrl+<key> shortcut that only fires while this window has
// focus. The capture phase lets it work while the code editor has focus.
function addShortcut(key, handler) {
    window.addEventListener('keydown', event => {
        if ((event.metaKey || event.ctrlKey) &&
            event.key.toLowerCase() === key) {
            event.preventDefault();
            event.stopPropagation();
            handler();
        }
    }, true);
}

// Problem picker: a drawer with search and a difficulty filter, plus
// previous/next/random buttons in the control panel.
// Top-level vars share the global scope with directory-manager.js, so these
// names must not collide with its globals (e.g. global.problems).
var pickerProblems = [];
var difficultyFilter = 'All';
var highlightedIndex = 0;

function problemLabel(problem) {
    return `${problem.number}. ${problem.title}`;
}

function getFilteredProblems() {
    const query =
        document.getElementById('problem-search').value.trim().toLowerCase();
    return pickerProblems.filter(problem =>
        (difficultyFilter === 'All' ||
            problem.difficulty === difficultyFilter) &&
        problemLabel(problem).toLowerCase().includes(query));
}

function renderProblemList() {
    const filtered = getFilteredProblems();
    highlightedIndex =
        Math.max(0, Math.min(highlightedIndex, filtered.length - 1));

    const list = document.getElementById('problem-list');
    list.innerHTML = '';
    filtered.forEach((problem, index) => {
        const item = document.createElement('li');
        item.classList.toggle('active', problem.name === activeProblem);
        item.classList.toggle('highlighted', index === highlightedIndex);

        const label = document.createElement('span');
        label.className = 'problem-label';
        label.textContent = problemLabel(problem);

        const difficulty = document.createElement('span');
        difficulty.className =
            'difficulty difficulty-' + problem.difficulty.toLowerCase();
        difficulty.textContent = problem.difficulty;

        item.append(label, difficulty);
        item.addEventListener('click', () => selectProblem(problem.name));
        list.appendChild(item);
    });

    document.getElementById('problem-count').textContent =
        `${filtered.length} of ${pickerProblems.length} problems`;

    const highlighted = list.querySelector('.highlighted');
    if (highlighted) {
        highlighted.scrollIntoView({ block: 'nearest' });
    }
}

function isProblemDrawerOpen() {
    return document.getElementById('problem-drawer')
        .classList.contains('open');
}

function openProblemDrawer() {
    const search = document.getElementById('problem-search');
    search.value = '';
    highlightedIndex = Math.max(0, getFilteredProblems()
        .findIndex(problem => problem.name === activeProblem));
    document.getElementById('problem-drawer').classList.add('open');
    renderProblemList();
    search.focus();
}

function closeProblemDrawer() {
    document.getElementById('problem-drawer').classList.remove('open');
}

function selectProblem(problemName) {
    closeProblemDrawer();
    if (problemName !== activeProblem) {
        onProblemSelected(problemName);
    }
}

function selectProblemByOffset(offset) {
    const index =
        pickerProblems.findIndex(problem => problem.name === activeProblem);
    const next = pickerProblems[index + offset];
    if (next) {
        selectProblem(next.name);
    }
}

function selectRandomProblem() {
    const candidates = getFilteredProblems()
        .filter(problem => problem.name !== activeProblem);
    if (candidates.length > 0) {
        const index = Math.floor(Math.random() * candidates.length);
        selectProblem(candidates[index].name);
    }
}

function updateProblemControls() {
    const index =
        pickerProblems.findIndex(problem => problem.name === activeProblem);
    const problem = pickerProblems[index];
    document.getElementById('active-problem-title').textContent =
        problemLabel(problem);
    const difficulty = document.getElementById('active-problem-difficulty');
    difficulty.textContent = problem.difficulty;
    difficulty.className = 'difficulty-badge difficulty-' +
        problem.difficulty.toLowerCase();
    document.getElementById('previous-problem-button').disabled = index <= 0;
    document.getElementById('next-problem-button').disabled =
        index >= pickerProblems.length - 1;
}

function onProblemSearchKeyDown(event) {
    const filtered = getFilteredProblems();
    if (event.key === 'ArrowDown' || event.key === 'ArrowUp') {
        event.preventDefault();
        highlightedIndex += event.key === 'ArrowDown' ? 1 : -1;
        renderProblemList();
    } else if (event.key === 'Enter' && filtered[highlightedIndex]) {
        selectProblem(filtered[highlightedIndex].name);
    } else if (event.key === 'Escape') {
        closeProblemDrawer();
    }
}

function initializeProblemPicker(allProblems) {
    pickerProblems = allProblems;

    document.getElementById('problem-list-button')
        .addEventListener('click', () => {
            isProblemDrawerOpen() ? closeProblemDrawer() : openProblemDrawer();
        });
    document.getElementById('previous-problem-button')
        .addEventListener('click', () => selectProblemByOffset(-1));
    document.getElementById('next-problem-button')
        .addEventListener('click', () => selectProblemByOffset(1));
    document.getElementById('random-problem-button')
        .addEventListener('click', selectRandomProblem);

    const search = document.getElementById('problem-search');
    search.addEventListener('input', () => {
        highlightedIndex = 0;
        renderProblemList();
    });
    search.addEventListener('keydown', onProblemSearchKeyDown);

    document.querySelectorAll('.difficulty-filter').forEach(button => {
        button.addEventListener('click', () => {
            document.querySelectorAll('.difficulty-filter')
                .forEach(other => other.classList.remove('active'));
            button.classList.add('active');
            difficultyFilter = button.dataset.difficulty;
            highlightedIndex = 0;
            renderProblemList();
            search.focus();
        });
    });

    addShortcut('p', () => {
        isProblemDrawerOpen() ? closeProblemDrawer() : openProblemDrawer();
    });

    document.addEventListener('mousedown', event => {
        if (isProblemDrawerOpen() &&
            !event.target.closest('#problem-drawer') &&
            !event.target.closest('#problem-list-button')) {
            closeProblemDrawer();
        }
    });
}

function initializeSaveCommand() {
    const save = () => saveSolution(editor.getValue());
    addShortcut('s', save);
    document.getElementById('save-button').addEventListener('click', save);
}

function initializeRunCommand() {
    const runTests = () => {
        document.getElementById('compilation-content').textContent = "";
        document.getElementById('test-results-content').innerHTML = "";
        document.getElementById('failed-count').textContent = "";
        run(setTestResults);
    };
    addShortcut('r', runTests);
    document.getElementById('run-button').addEventListener('click', runTests);
}

function initializeCustomTestcaseCommand() {
    addShortcut('t', runCustomTestcase);
    document.getElementById('custom-testcase-button')
        .addEventListener('click', runCustomTestcase);
}

document.addEventListener('DOMContentLoaded', (event) => {
    var tabs = document.querySelectorAll('.tab');

    const allProblems = directoryManager.getProblems();
    initializeProblemPicker(allProblems);
    initializeLanguageSelect(directoryManager.getLanguages());
    initializeSaveCommand();
    initializeRunCommand();
    initializeCustomTestcaseCommand();
    initializeSettings();

    amdRequire(['vs/editor/editor.main'], function() {
        defineEditorThemes();
        editor = monaco.editor.create(
            document.getElementById('user-solution-content'), {
                language: activeLanguage,
                minimap: { enabled: false },
                scrollbar: {
                    vertical: 'auto',
                    horizontal: 'auto'
                },
                automaticLayout: true,
                scrollBeyondLastLine: false,
                theme: THEMES[activeTheme].editorTheme,
                fontFamily: '"SF Mono", Menlo, Consolas, monospace',
                fontSize: 13,
        });

        onProblemSelected(allProblems[0].name);
    });

    // Each tab names the pane it shows in data-pane.
    tabs.forEach(tab => {
        if (!tab.dataset.pane) {
            return;
        }
        tab.addEventListener('click', function() {
            const card = this.closest('.card');
            card.querySelectorAll('.tab').forEach(other =>
                other.classList.toggle('active', other === this));
            card.querySelectorAll('.tab-content').forEach(content =>
                content.classList.toggle('active',
                                         content.id === this.dataset.pane));
        });
    });
});

document.addEventListener('DOMContentLoaded', (event) => {
    Split(['#left-panel', '#right-panel'], {
        minSize: 100,
        sizes: [50, 50],
        gutterSize: 6,
    })
    
    Split(['#top-right-panel', '#bottom-right-panel'], {
        minSize: 100,
        sizes: [60, 40],
        gutterSize: 6,
        direction: 'vertical',
        cursor: 'row-resize',
    })
});