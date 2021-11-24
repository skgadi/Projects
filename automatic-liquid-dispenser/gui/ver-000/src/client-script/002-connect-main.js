const {
  ipcRenderer
} = require('electron')

ipcRenderer.on('asynchronous-reply', (event, arg) => {
  //console.log(arg) // prints "pong"
  try{
    document.getElementById("executingText").innerText = "[Idle]";
    appendLog(arg);
    appendLog("-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-\n");
    appendLog("『🙏』『🙏』『🙏』『🙏』『🙏』『🙏』『🙏』『🙏』『🙏』『🙏』『🙏』『🙏』『🙏』『🙏』『🙏』『🙏』『🙏』『🙏』\n");
    appendLog("[Done]\n");
    appendLog("『🙏』『🙏』『🙏』『🙏』『🙏』『🙏』『🙏』『🙏』『🙏』『🙏』『🙏』『🙏』『🙏』『🙏』『🙏』『🙏』『🙏』『🙏』\n");
    appendLog("-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-\n");
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
        console.log(command);
        document.getElementById("executingText").innerHTML = "[Last command]: <tt class='w3-small'>" + command.name + "</tt>";
        //appendLog("-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-\n");
        //appendLog("『🐨』『🐨』『🐨』『🐨』『🐨』『🐨』『🐨』『🐨』『🐨』『🐨』『🐨』『🐨』『🐨』『🐨』『🐨』『🐨』『🐨』『🐨』\n");
        //appendLog("[Executing]: " + command.name + " >> " + command.instruction + "\n");
        //appendLog("『🐨』『🐨』『🐨』『🐨』『🐨』『🐨』『🐨』『🐨』『🐨』『🐨』『🐨』『🐨』『🐨』『🐨』『🐨』『🐨』『🐨』『🐨』\n");
        //appendLog("-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-҉-\n");
        //ipcRenderer.send('exec', command.instruction);
        ipcRenderer.send('terminal-into', command.instruction+"\r");
        //readyToExec = false;
      } catch(e){
        console.log(e);
      }
    }
  }
}, 200);

function appendLog(text) {
  //document.getElementById("log").innerText = document.getElementById("log").innerText + text;
  //document.getElementById("log").scrollTop = document.getElementById("log").scrollHeight;

}
// We are using electron and i am using electronService to check if we are inside electron
