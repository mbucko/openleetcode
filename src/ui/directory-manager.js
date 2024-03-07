const path = require('path');
const fs = require('fs');

global.dirDict = null;
global.languages = null;
global.problemNames = null;

global.problemBuildsDir = null;

LANGUAGES_DIR_NAME = "languages";
PROBLEMS_DIR_NAME = "problems";

function getPathsFile() {
    return path.resolve("filePaths.tmp")
}

function readMdFile(filePath) {
    const marked = require('marked');
    marked.setOptions({
        breaks: false,
    });
    const data = fs.readFileSync(filePath, 'utf8');
    if (!data) {
        throw new Error(`File does not exist: ${filePath}`);
    }
    return marked.marked(data);
}

function populateLanguages(languagesDir) {
    var languages = [];
    fs.readdirSync(languagesDir).forEach(language => {
        languages.push(language);
    });
    return languages;
}

function populateProblems(problemsDir) {
    var problems = [];
    fs.readdirSync(problemsDir).forEach(problemName => {
        problems.push(problemName);
    });
    return problems;
}

function calculateDirectories() {
    if (global.dirDict) {
        return;
    }

    const pathsFile = getPathsFile();
    if (!fs.existsSync(pathsFile)) {
        throw new Error(`Paths file does not exist: ${pathsFile}`);
    }

    global.problemBuildsDir = fs.readFileSync(pathsFile, 'utf8');

    localDirDict = {};

    const problemsDir = path.join(problemBuildsDir, PROBLEMS_DIR_NAME);
    if (!fs.existsSync(problemsDir)) {
        throw new Error(`Problems directory does not exist: ${problemsDir}`);
    }

    const languagesDir = path.join(problemBuildsDir, LANGUAGES_DIR_NAME);
    if (!fs.existsSync(languagesDir)) {
        throw new Error(`Languages directory does not exist: ${languagesDir}`);
    }

    const languages = populateLanguages(languagesDir);
    const problemNames = populateProblems(problemsDir);

    fs.readdirSync(problemsDir).forEach(problemName => {
        // For now assume cpp, later expand to all languages
        const language = "cpp";
        const problemDir = path.join(problemsDir, problemName);
        const descriptionFile = path.join(problemDir, 'description.md');
        const solutionFile = path.join(problemDir, language, 'solution.md');
        const userSolutionFilename = path.join(problemDir, language, 'solution.cpp');

        if (!fs.existsSync(userSolutionFilename)) {
            throw new Error(`User solution file does not exist: ${userSolutionFilename}`);
        }

        global.localDirDict[problemName] =
            global.localDirDict[problemName] || {};
        global.localDirDict[problemName]["description"] =
            readMdFile(descriptionFile);
        global.localDirDict[problemName][language] =
            global.localDirDict[problemName][language] || {};
            global.localDirDict[problemName][language]["solution"] =
                readMdFile(solutionFile);
            global.localDirDict[problemName][language]
                ["user-solution-filename"] = userSolutionFilename;
    });

    global.dirDict = localDirDict;
    global.languages = languages;
    global.problemNames = problemNames;
}

class DirectoryManager {
    constructor() {
        console.log("Initializing DirectoryManager");
        calculateDirectories();
    }

    getDescription(problemName) {
        return global.dirDict[problemName]["description"];
    }

    getSolution(problemName) {
        return global.dirDict[problemName]["cpp"]["solution"];
    }

    getUserSolutionFilename(problemName) {
        return global.dirDict[problemName]["cpp"]["user-solution-filename"];
    }

    getLanguages() {
        return [...global.languages];
    }

    getProblemNames() {
        return [...global.problemNames];
    }
}

module.exports = {
    DirectoryManager,
    getPathsFile
};