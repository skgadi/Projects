const app = {
  data() {
    return {
      avHw: availHardware,
      selHardware: "",
      hardware: {},
      autoUpdate: 0,
      port: ""
    }
  },
  watch: {
    selHardware(newHardware, old) {
      this.hardware = JSON.parse(JSON.stringify(this.avHw[newHardware]));
      this.autoUpdate++;
    },
    hardware(newVal, old) {
      for (let i = 0; i < newVal.firmware.globalConfigs.length; i++) {
        if (newVal.firmware.globalConfigs.value > newVal.firmware.globalConfigs.max) {
          newVal.firmware.globalConfigs.value = max;
        }
        if (newVal.firmware.globalConfigs.value < newVal.firmware.globalConfigs.min) {
          newVal.firmware.globalConfigs.value = min;
        }
      }
      console.log(newVal);
    }
  },
  methods: {
    prepareFlags: function() {
      let buildFlags = "";
      for (let i=0; i<this.hardware.firmware.globalConfigs.length; i++) {
        buildFlags += " -D"+this.hardware.firmware.globalConfigs[i].id+"="+this.hardware.firmware.globalConfigs[i].value;
      }
      for (let i=0; i<this.hardware.firmware.directives.length; i++) {
        if (this.hardware.firmware.directives[i].value) {
          buildFlags += " -D"+this.hardware.firmware.directives[i].id;
        }
      }
      return " --build-property build.extra_flags=\""+ buildFlags + "\"";
    },
    compile: function () {
      commandQueue.push({
        name: "Compile",
        instruction: "arduino-cli compile --fqbn arduino:avr:uno ../../firmware/"+this.hardware.firmware.folder+" --programmer arduinoasisp -v --clean "+ this.prepareFlags()
      });
    },
    burn: function () {
      if (this.port === "") {
        appendLog("Port cannot be empty.\nShowing the list of available ports\n");
        this.getPorts();
      } else {
        commandQueue.push({
          name: "Burning bootloader",
          instruction: "arduino-cli burn-bootloader --fqbn arduino:avr:uno  --programmer arduinoasisp -v --port  "+ this.port
        });
        commandQueue.push({
          name: "Burning bootloader",
          instruction: "arduino-cli compile --fqbn arduino:avr:uno ../../firmware/"+this.hardware.firmware.folder+" --programmer arduinoasisp -u -t -v --clean -p "+ this.port + this.prepareFlags()
        });
        //arduino-cli compile --fqbn arduino:avr:uno .\automatic_soap_dispenser.ino --programmer arduinoasisp -t -v --clean --build-property build.extra_flags="-DNUMBER_OF_CHEMICALS=10 -DMAX_MONEY_PER_LITER=100"
      }
    },
    getPorts: function () {
      commandQueue.push({
        name: "Get ports list",
        instruction: "arduino-cli board list"
      });
    },
    clearLog: function () {
      document.getElementById("log").innerText = "";
    }
  }
}


Vue.createApp(app).mount('#app')