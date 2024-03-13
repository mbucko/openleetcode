const { app, BrowserWindow, globalShortcut } = require('electron');
const path = require('path');
const DirectoryManager = require('./directory-manager.js');

saveFilePaths();

let win;

function saveFilePaths() {
    var problemBuildsDir = "./problem_builds";
    var problemBuildsArg = process.argv.find(arg => arg.startsWith('--problem_builds_dir='));
    
    if (problemBuildsArg && problemBuildsArg.length > 0) {
        problemBuildsDir = problemBuildsArg.split('=')[1];
        console.log("Setting problemBuildsDir to " + problemBuildsDir);
    } else {
        console.log("problemBuildsDir was not set. Using default " + problemBuildsDir);
        console.log("process.argv: " + process.argv);
    }
    problemBuildsDir = path.resolve(problemBuildsDir);
    
    const fs = require('fs');
    fs.writeFileSync(DirectoryManager.getPathsFile(), 
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

    // win.webContents.openDevTools();

    win.on('closed', () => {
        win = null
    })
}

function registerSaveCommand() {
    const ret = globalShortcut.register('CommandOrControl+S', () => {
        console.log('CommandOrControl+S is pressed')
        win.webContents.send('save-command')
    })

    if (!ret) {
        console.log('Registration failed!')
    }

    console.log("CommandOrControl+S registered: " +
        globalShortcut.isRegistered('CommandOrControl+S'))

}

function registerRunCommand() {
    const ret = globalShortcut.register('CommandOrControl+R', () => {
        console.log('CommandOrControl+R is pressed')
        win.webContents.send('run-command')
    })

    if (!ret) {
        console.log('Registration failed!')
    }

    console.log("CommandOrControl+R registered: " +
        globalShortcut.isRegistered('CommandOrControl+R'))
}

function registerCustomTestcaseCommand() {
    const ret = globalShortcut.register('CommandOrControl+T', () => {
        console.log('CommandOrControl+T is pressed')
        win.webContents.send('custom-testcase-command')
    })

    if (!ret) {
        console.log('Registration failed!')
    }

    console.log("CommandOrControl+T registered: " +
        globalShortcut.isRegistered('CommandOrControl+T'))
}

function registerCommands() {
    registerSaveCommand();
    registerRunCommand();
    registerCustomTestcaseCommand();
}

app.whenReady().then(() => {
    const argv = process.argv;

    createWindow()
    app.on('activate', () => {
        if (BrowserWindow.getAllWindows().length === 0) {
            createWindow()
        }
    })
    registerCommands();
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

app.on('will-quit', () => {
    globalShortcut.unregisterAll()
})