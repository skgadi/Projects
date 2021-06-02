const {
  ipcRenderer
} = require('electron')

ipcRenderer.on('asynchronous-reply', (event, arg) => {
  //console.log(arg) // prints "pong"
  try{
    document.getElementById("executingText").innerText = "[Idle]";
    appendLog(arg);
  } catch (e) {
    console.log(e);
  }
  readyToExec = true;
});

setInterval(() => {
  if (readyToExec) {
    if (commandQueue.length>0) {
      try{
        let command = commandQueue.shift();
        document.getElementById("executingText").innerText = "[Executing]: " + command.name + " >> " + command.instruction;
        appendLog("[Executing]: " + command.name + " >> " + command.instruction + "\n");
        ipcRenderer.send('exec', command.instruction);
        readyToExec = false;
      } catch(e){
        console.log(e);
      }
    }
  }
}, 200);

function appendLog(text) {
  document.getElementById("log").innerText = document.getElementById("log").innerText + text;
  document.getElementById("log").scrollTop = document.getElementById("log").scrollHeight;

}
// We are using electron and i am using electronService to check if we are inside electron
