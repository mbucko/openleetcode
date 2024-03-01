const path = require('path')
const file = require('fs');
const amdLoader = require('monaco-editor/min/vs/loader.js');
const Split = require('split.js')

const amdRequire = amdLoader.require;
const amdDefine = amdLoader.require.define;
var editor;

const directory_manager = require('./directory-manager.js');
const directoryManager = new directory_manager.DirectoryManager();

amdRequire.config({
    baseUrl: path.join(__dirname, './node_modules/monaco-editor/min')
});

// workaround monaco-css not understanding the environment
self.module = undefined;

function saveSolution(problemName, language, content) {
    if (!problemName) {
        return;
    }

    const userSolutionFilename =
        directoryManager.getUserSolutionFilename(problemName);
    console.log("Saving problem " + problemName + " to " +
        userSolutionFilename);
    file.writeFileSync(userSolutionFilename, content);
}

function setDescription(problemName) {
    var element = document.querySelector('.markdown-content#description-content');
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
    saveSolution(previousProblem, 'cpp', editor.getValue());
    previousProblem = problemName;
    
    console.log(`Problem selected: ${problemName}`);
    setDescription(problemName);
    setSolution(problemName);
    setUserSolution(problemName);
    console.log(`previousProblem: ${previousProblem}`);
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

document.addEventListener('DOMContentLoaded', (event) => {
    var tabs = document.querySelectorAll('.tab');

    // For now...
    const problemNames = directoryManager.getProblemNames();
    initializeProblemsCombo(problemNames);

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