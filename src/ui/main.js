const { app, BrowserWindow } = require('electron');
const path = require('path');
const DirectoryManager = require('./directory-manager.js');

saveProblemBuildsDirToFile();

let win;

function saveProblemBuildsDirToFile() {
    var problemBuildsDir = "./problem_builds";
    var problemBuildsArg = process.argv.find(arg => arg.startsWith('--problem_builds_dir='));
    
    if (problemBuildsArg) {
        problemBuildsDir = problemBuildsArg.split('=')[1];
        console.log("Setting problemBuildsDir to " + problemBuildsDir);
    } else {
        console.log("problemBuildsDir was not set. Using default " + problemBuildsDir);
    }
    problemBuildsDir = path.resolve(problemBuildsDir);
    
    const fs = require('fs');
    fs.writeFileSync(DirectoryManager.getProblemBuildsDirTmpFile(),
                     problemBuildsDir, 'utf8');
}

function createWindow() {
    win = new BrowserWindow({
            width: 1400,
            height: 1000,
            webPreferences: {
                preload: path.join(__dirname, 'preload.js'),
                nodeIntegration: true,
                contextIsolation: false,
        }
    });

    win.setMenuBarVisibility(false);
    win.loadFile('index.html');

    win.webContents.openDevTools();

    win.on('closed', () => {
        win = null
    })
}

app.whenReady().then(() => {
    const argv = process.argv;

    createWindow()
    app.on('activate', () => {
        if (BrowserWindow.getAllWindows().length === 0) {
            createWindow()
        }
    })
});

app.on('window-all-closed', () => {
    if (process.platform !== 'darwin') {
        app.quit()
    }
})

app.on('activate', () => {
    if (win === null) {
        createWindow()
    }
})