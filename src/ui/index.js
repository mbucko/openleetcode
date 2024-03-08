const path = require('path')
const file = require('fs');
const amdLoader = require('monaco-editor/min/vs/loader.js');
const Split = require('split.js')
const { ipcRenderer } = require('electron');
const { exec } = require('child_process');
const DirectoryManager = require('./directory-manager.js');

const amdRequire = amdLoader.require;
const amdDefine = amdLoader.require.define;
var editor;

const directory_manager = require('./directory-manager.js');
const directoryManager = new directory_manager.DirectoryManager();

amdRequire.config({
    baseUrl: path.join(__dirname, './node_modules/monaco-editor/min')
});

var activeProblem = null;

// workaround monaco-css not understanding the environment
self.module = undefined;

function saveSolution(language, content) {
    if (!previousProblem) {
        return;
    }

    const userSolutionFilename =
        directoryManager.getUserSolutionFilename(previousProblem);
    console.log("Saving problem " + previousProblem + " to " +
        userSolutionFilename);
    file.writeFileSync(userSolutionFilename, content);
}

function parseStdout(stdout) {
    // stdout:
    // LongestSubstringWithoutRepeatingCharacters for testcase All in language cpp
    // Results written to /path\to/openleetcode/src/ui/testcase_output/<testname><datetime>.results
    // Status: <status>
    // Duration: <duration>ms
    return stdout.match(/Results written to (.*\.results)/)[1];
}

function parseBuildError(stdout) {
    // Running command: cmake --build ...
    // <MATCHED BUILD ERROR>
    // Error running the command: cmake --build
    const regex = /cmake --build[\s\S]*?cmake --build/;
    const match = stdout.match(regex);
    const buildError = match[0].split('\n').slice(1, -1).join('\n');

    return buildError;
}

function run() {
    saveSolution('cpp', editor.getValue());
    const pathsFile = DirectoryManager.getPathsFile();
    if (!file.existsSync(pathsFile)) {
        throw new Error(`Paths file does not exist: ${pathsFile}`);
    }

    problemBuildsDir = file.readFileSync(pathsFile, 'utf8');
    problemBuildsDir = path.resolve(problemBuildsDir);
    const extension = process.platform === 'win32' ? '.bat' : '.sh';

    const command = `${problemBuildsDir}/openleetcode${extension} ` +
    `--problem_builds_dir ${problemBuildsDir} ` +
    `--language cpp ` +
    `--problem ${activeProblem} ` +
    `--verbose`;

    var resultsFilename;
    exec(command, (error, stdout, stderr) => {
        if (error) {
            var element = document.getElementById("compilation-content");
            element.textContent = parseBuildError(stdout);
            document.getElementById('tab-compilation').click();
            return;
        }
        var element = document.getElementById("compilation-content");
        element.textContent = "";
        
        resultsFilename = parseStdout(stdout);
        if (!resultsFilename) {
            throw new Error("Could not parse results filename from stdout: " +
                            "${stdout}");
        }

        if (!file.existsSync(resultsFilename)) {
            throw new Error(`Results file does not exist: ${resultsFilename}`);
        }
    
        const results = file.readFileSync(resultsFilename, 'utf8');
        console.log(results);
        const resultsJson = JSON.parse(results);
    });
}

function setDescription(problemName) {
    var element =
        document.querySelector('.markdown-content#description-content');
    element.innerHTML = directoryManager.getDescription(problemName);
}

function setSolution(problemName) {
    var element = document.querySelector('.markdown-content#solution-content');
    element.innerHTML = directoryManager.getSolution(problemName);
}

function setUserSolution(problemName) {
    var element = document.querySelector('#user-solution-content');
    const userSolutionFilename =
        directoryManager.getUserSolutionFilename(problemName);
    editor.setValue(file.readFileSync(userSolutionFilename, 'utf8'));
}

var previousProblem;
function onProblemSelected(problemName) {
    saveSolution('cpp', editor.getValue());
    previousProblem = problemName;
    
    console.log(`Problem selected: ${problemName}`);
    setDescription(problemName);
    setSolution(problemName);
    setUserSolution(problemName);
    activeProblem = problemName;
}

function initializeProblemsCombo(problemNames) {
    var select = document.getElementById('problem-select');
    problemNames.forEach(problemName => {
        var option = document.createElement('option');
        option.value = problemName;
        option.textContent = problemName;
        select.appendChild(option);
    });

    select.addEventListener('change', function(event) {
        onProblemSelected(event.target.value);
    });
}

function initializeSaveCommand() {
    ipcRenderer.on('save-command', () => {
        console.log('Received save command');
        saveSolution('cpp', editor.getValue());
    });
    
    document.getElementById('save-button')
        .addEventListener('click', function() {
            console.log('Save button clicked');
            saveSolution('cpp', editor.getValue());
    });
}

function initializeRunCommand() {
    ipcRenderer.on('run-command', () => {
        console.log('Received run command');
        run();
    });
    
    document.getElementById('run-button')
        .addEventListener('click', function() {
            console.log('Run button clicked');
            run();
    });
}

document.addEventListener('DOMContentLoaded', (event) => {
    var tabs = document.querySelectorAll('.tab');

    // For now...
    const problemNames = directoryManager.getProblemNames();
    initializeProblemsCombo(problemNames);
    initializeSaveCommand();
    initializeRunCommand();

    amdRequire(['vs/editor/editor.main'], function() {
        monaco.editor.setTheme('vs-dark');
        editor = monaco.editor.create(
            document.getElementById('user-solution-content'), {
                language: 'cpp',
                minimap: { enabled: false },
                scrollbar: {
                    vertical: 'auto',
                    horizontal: 'auto'
                },
                automaticLayout: true
        });
    
        onProblemSelected(problemNames[0]);
    });

    tabs.forEach(tab => {
        tab.addEventListener('click', function(event) {
            var tabContents = event.target.parentNode.parentNode.querySelectorAll('.tab-content');
            tabContents.forEach(content => {
                content.classList.remove('active');
            });
    
            var paneId = this.textContent.toLowerCase();
            var selectedPane = document.getElementById('tab-' + paneId);
            if (selectedPane) {
                selectedPane.classList.add('active');
            }
        });
    });
});

document.addEventListener('DOMContentLoaded', (event) => {
    Split(['#left-panel', '#right-panel'], {
        minSize: 100,
        expandToMin: true,
        gutterSize: 5,
    })
    
    Split(['#top-right-panel', '#bottom-right-panel'], {
        minSize: 100,
        expandToMin: true,
        gutterSize: 5,
        direction: 'vertical',
        cursor: 'row-resize',
    })
});