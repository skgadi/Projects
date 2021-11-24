const Terminal  =  require('xterm').Terminal;
const FitAddon = require('xterm-addon-fit').FitAddon;

const term = new Terminal();
const fitAddon = new FitAddon();
term.loadAddon(fitAddon);

// Open the terminal in #terminal-container
term.open(document.getElementById('log-view'));
term.onData(e => {
    ipcRenderer.send("terminal-into", e);
} );
ipcRenderer.on('terminal-incData', (event, data) => {
    term.write(data);
})

// Make the terminal's size and geometry fit the size of #terminal-container
fitAddon.fit();