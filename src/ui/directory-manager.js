const path = require('path');
const fs = require('fs');

global.dirDict = null;
global.languages = null;
global.problems = null;
global.resultsSchemaJson = null;

global.problemBuildsDir = null;

LANGUAGES_DIR_NAME = "languages";
PROBLEMS_DIR_NAME = "problems";
TESTCASES_DIR_NAME = "testcases";
RESULTS_VALIDATION_SCHEMA_FILENAME = "results_validation_schema.json";
DIFFICULTIES = ["Easy", "Medium", "Hard"];
// The file the user edits for each language the UI supports.
SOLUTION_FILENAMES = {
    cpp: "solution.cpp",
    python: "solution.py",
};

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
        if (language in SOLUTION_FILENAMES) {
            languages.push(language);
        }
    });
    return languages;
}

function readTitle(descriptionFile) {
    const data = fs.readFileSync(descriptionFile, 'utf8');
    const match = data.match(/^#\s+(.+)$/m);
    if (!match) {
        throw new Error(`No title heading in ${descriptionFile}`);
    }
    return match[1].trim();
}

function readMetadata(metadataFile) {
    if (!fs.existsSync(metadataFile)) {
        throw new Error(`Metadata file does not exist: ${metadataFile}`);
    }
    const metadata = JSON.parse(fs.readFileSync(metadataFile, 'utf8'));
    if (!Number.isInteger(metadata.number) ||
        !DIFFICULTIES.includes(metadata.difficulty)) {
        throw new Error(`Invalid metadata in ${metadataFile}`);
    }
    return metadata;
}

// Returns the problems sorted by number, each as
// { name, number, title, difficulty }.
function populateProblems(problemsDir) {
    var problems = [];
    fs.readdirSync(problemsDir).forEach(problemName => {
        const problemDir = path.join(problemsDir, problemName);
        const metadata = readMetadata(path.join(problemDir, 'metadata.json'));
        problems.push({
            name: problemName,
            number: metadata.number,
            title: readTitle(path.join(problemDir, 'description.md')),
            difficulty: metadata.difficulty,
        });
    });
    return problems.sort((a, b) => a.number - b.number);
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
    const problems = populateProblems(problemsDir);

    fs.readdirSync(problemsDir).forEach(problemName => {
        const problemDir = path.join(problemsDir, problemName);
        const descriptionFile = path.join(problemDir, 'description.md');

        global.localDirDict[problemName] =
            global.localDirDict[problemName] || {};
        global.localDirDict[problemName]["description"] =
            readMdFile(descriptionFile);

        languages.forEach(language => {
            const solutionFile =
                path.join(problemDir, language, 'solution.md');
            const userSolutionFilename = path.join(
                problemDir, language, SOLUTION_FILENAMES[language]);

            if (!fs.existsSync(userSolutionFilename)) {
                throw new Error(`User solution file does not exist: ${userSolutionFilename}`);
            }

            global.localDirDict[problemName][language] = {
                "solution": readMdFile(solutionFile),
                "user-solution-filename": userSolutionFilename,
            };
        });
    });

    const resultsSchemaFilename =
        path.join(problemBuildsDir, RESULTS_VALIDATION_SCHEMA_FILENAME);

    if (!fs.existsSync(resultsSchemaFilename)) {
        throw new Error(`Results validation schema file 
                            does not exist: 
                            ${resultsSchemaFilename}`);
    }

    resultsSchema = fs.readFileSync(resultsSchemaFilename, 'utf8');

    
    const resultsSchemaJson = JSON.parse(resultsSchema);

    if (!resultsSchemaJson) {
        throw new Error(`Could not parse results validation schema from 
                        ${resultsSchema}`);
    }
    
    global.dirDict = localDirDict;
    global.languages = languages;
    global.problems = problems;
    global.resultsSchemaJson = resultsSchemaJson;
}

class DirectoryManager {
    constructor() {
        console.log("Initializing DirectoryManager");
        calculateDirectories();
    }

    getDescription(problemName) {
        return global.dirDict[problemName]["description"];
    }

    getSolution(problemName, language) {
        return global.dirDict[problemName][language]["solution"];
    }

    getUserSolutionFilename(problemName, language) {
        return global.dirDict[problemName][language]["user-solution-filename"];
    }

    getLanguages() {
        return [...global.languages];
    }

    getProblems() {
        return global.problems.map(problem => ({ ...problem }));
    }
    
    getResultsSchemaJson() {
        return global.resultsSchemaJson;
    }

    getCustomTestcaseName() {
        return "_custom_testcase";
    }

    getCustomTestcaseFilename(problemName) {
        return path.join(problemBuildsDir,
                         PROBLEMS_DIR_NAME,
                         problemName,
                         TESTCASES_DIR_NAME,
                         this.getCustomTestcaseName() + '.test');
    }
}

module.exports = {
    DirectoryManager,
    getPathsFile,
};