const commandQueue = ["ver"];
let readyToExec = true;
const availHardware = {
  "1617064809234": {
    "name": "8 channel - VMLS",
    "desc": "8 channel - Vending machine for liquid detergents",
    "firmware": {
      "folder": "verUse/automatic_soap_dispenser/automatic_soap_dispenser.ino",
      "board": "arduino:avr:uno",
      "burnItems": ["bootloader", "burn"],
      "programmer": "arduinoasisp",
      "globalConfigs": [{
        "id": "NUMBER_OF_CHEMICALS",
        "name": "Number of products",
        "desc": "The number of maximum products allowed with this card",
        "type": "number",
        "min": 5,
        "max": 8,
        "value": 5
      }, {
        "id": "MAX_MONEY_PER_LITER",
        "name": "Maximum money per liter",
        "desc": "The money that user can set for a product.",
        "type": "number",
        "min": 100,
        "max": 1000,
        "value": 100
      }, {
        "id": "HIDE_PRICE_AFTER_x_SECONDS",
        "name": "Hides price after (seconds)",
        "desc": "The price shown will be hiden after the above selected time.",
        "type": "number",
        "min": 10,
        "max": 900,
        "value": 10
      }, {
        "id": "REMOVE_CREDIT_AFTER_x_SECONDS",
        "name": "Credit is removed after (seconds)",
        "desc": "After above selected time the credit is set to zero when no activity is registered.",
        "type": "number",
        "min": 60,
        "max": 3600,
        "value": 600
      }, {
        "id": "RESET_LCD_AFTER_x_MINUTES",
        "name": "Resets LCD screen (minutes)",
        "desc": "It helps rectify problems caused due to serial communication.",
        "type": "number",
        "min": 60,
        "max": (24 * 60),
        "value": 60
      }, {
        "id": "RESET_SYSTEM_AFTER_x_MINUTES",
        "name": "Resets entire system (minutes)",
        "desc": "A reset is required to keep the timer work properly.",
        "type": "number",
        "min": (24 * 60),
        "max": (10 * 24 * 60),
        "value": (24 * 60)
      }],
      "directives": [{
        "id": "PROGRAM_SUMMARY",
        "name": "Program the summary",
        "desc": "Include the firmware that programs the sales summary",
        "value": false
      }, {
        "id": "PROGRAM_FROM_APP",
        "value": "true",
        "hide": true
        /*}, {
          "id": "IS_SMD_MICRO",
          "value": "true",
          "hide": true*/
      }, {
        "id": "PROGRAM_FROM_APP",
        "value": "true",
        "hide": true
      }]
    }
  },
  "1617070729488": {
    "name": "32 channel - VMLS",
    "desc": "32 channel - Vending machine for liquid detergents",
    "firmware": {
      "folder": "verUse/automatic_soap_dispenser/automatic_soap_dispenser.ino",
      "board": "arduino:avr:uno",
      "burnItems": ["bootloader", "burn"],
      "programmer": "arduinoasisp",
      "globalConfigs": [{
        "id": "NUMBER_OF_CHEMICALS",
        "name": "Number of products",
        "desc": "The number of maximum products allowed with this card",
        "type": "number",
        "min": 5,
        "max": 32,
        "value": 5
      }, {
        "id": "MAX_MONEY_PER_LITER",
        "name": "Maximum money per liter",
        "desc": "The money that user can set for a product.",
        "type": "number",
        "min": 100,
        "max": 1000,
        "value": 100
      }, {
        "id": "HIDE_PRICE_AFTER_x_SECONDS",
        "name": "Hides price after (seconds)",
        "desc": "The price shown will be hiden after the above selected time.",
        "type": "number",
        "min": 10,
        "max": 900,
        "value": 10
      }, {
        "id": "REMOVE_CREDIT_AFTER_x_SECONDS",
        "name": "Credit is removed after (seconds)",
        "desc": "After above selected time the credit is set to zero when no activity is registered.",
        "type": "number",
        "min": 60,
        "max": 3600,
        "value": 600
      }, {
        "id": "RESET_LCD_AFTER_x_MINUTES",
        "name": "Resets LCD screen (minutes)",
        "desc": "It helps rectify problems caused due to serial communication.",
        "type": "number",
        "min": 60,
        "max": (24 * 60),
        "value": 60
      }, {
        "id": "RESET_SYSTEM_AFTER_x_MINUTES",
        "name": "Resets entire system (minutes)",
        "desc": "A reset is required to keep the timer work properly.",
        "type": "number",
        "min": (24 * 60),
        "max": (10 * 24 * 60),
        "value": (24 * 60)
      }],
      "directives": [{
        "id": "PROGRAM_SUMMARY",
        "name": "Program the summary",
        "desc": "Include the firmware that programs the sales summary",
        "value": false
      }, {
        "id": "PROGRAM_FROM_APP",
        "value": "true",
        "hide": true
        /*}, {
          "id": "IS_SMD_MICRO",
          "value": "true",
          "hide": true*/
      }, {
        "id": "PROGRAM_FROM_APP",
        "value": "true",
        "hide": true
      }]
    }
  },
  "1619070266072": {
    "name": "32 channel - VMLS - SMD",
    "desc": "32 channel - Vending machine for liquid detergents with SMD",
    "firmware": {
      "folder": "verUse/automatic_soap_dispenser/automatic_soap_dispenser.ino",
      "board": "arduino:avr:uno",
      "burnItems": ["bootloader", "burn"],
      "programmer": "arduinoasisp",
      "globalConfigs": [{
        "id": "NUMBER_OF_CHEMICALS",
        "name": "Number of products",
        "desc": "The number of maximum products allowed with this card",
        "type": "number",
        "min": 5,
        "max": 32,
        "value": 5
      }, {
        "id": "MAX_MONEY_PER_LITER",
        "name": "Maximum money per liter",
        "desc": "The money that user can set for a product.",
        "type": "number",
        "min": 100,
        "max": 1000,
        "value": 100
      }, {
        "id": "HIDE_PRICE_AFTER_x_SECONDS",
        "name": "Hides price after (seconds)",
        "desc": "The price shown will be hiden after the above selected time.",
        "type": "number",
        "min": 10,
        "max": 900,
        "value": 10
      }, {
        "id": "REMOVE_CREDIT_AFTER_x_SECONDS",
        "name": "Credit is removed after (seconds)",
        "desc": "After above selected time the credit is set to zero when no activity is registered.",
        "type": "number",
        "min": 60,
        "max": 3600,
        "value": 600
      }, {
        "id": "RESET_LCD_AFTER_x_MINUTES",
        "name": "Resets LCD screen (minutes)",
        "desc": "It helps rectify problems caused due to serial communication.",
        "type": "number",
        "min": 60,
        "max": (24 * 60),
        "value": 60
      }, {
        "id": "RESET_SYSTEM_AFTER_x_MINUTES",
        "name": "Resets entire system (minutes)",
        "desc": "A reset is required to keep the timer work properly.",
        "type": "number",
        "min": (24 * 60),
        "max": (10 * 24 * 60),
        "value": (24 * 60)
      }],
      "directives": [{
        "id": "PROGRAM_SUMMARY",
        "name": "Program the summary",
        "desc": "Include the firmware that programs the sales summary",
        "value": false
      }, {
        "id": "PROGRAM_SD",
        "name": "Program the SD Card",
        "desc": "Include the firmware that programs the sales summary",
        "value": false
      }, {
        "id": "PROGRAM_FROM_APP",
        "value": "true",
        "hide": true
      }, {
        "id": "IS_SMD_MICRO",
        "value": "true",
        "hide": true
      }, {
        "id": "PROGRAM_FROM_APP",
        "value": "true",
        "hide": true
      }]
    }
  },
  "1620570420374": {
    "name": "32 channel - VMLS - With Power Supply",
    "desc": "32 channel - Vending machine for liquid detergents with power supply",
    "firmware": {
      "folder": "verUse/automatic_soap_dispenser/automatic_soap_dispenser.ino",
      "board": "arduino:avr:uno",
      "burnItems": ["bootloader", "burn"],
      "programmer": "arduinoasisp",
      "globalConfigs": [{
        "id": "NUMBER_OF_CHEMICALS",
        "name": "Number of products",
        "desc": "The number of maximum products allowed with this card",
        "type": "number",
        "min": 5,
        "max": 32,
        "value": 5
      }, {
        "id": "MAX_MONEY_PER_LITER",
        "name": "Maximum money per liter",
        "desc": "The money that user can set for a product.",
        "type": "number",
        "min": 100,
        "max": 1000,
        "value": 100
      }, {
        "id": "HIDE_PRICE_AFTER_x_SECONDS",
        "name": "Hides price after (seconds)",
        "desc": "The price shown will be hiden after the above selected time.",
        "type": "number",
        "min": 10,
        "max": 900,
        "value": 10
      }, {
        "id": "REMOVE_CREDIT_AFTER_x_SECONDS",
        "name": "Credit is removed after (seconds)",
        "desc": "After above selected time the credit is set to zero when no activity is registered.",
        "type": "number",
        "min": 60,
        "max": 3600,
        "value": 600
      }, {
        "id": "RESET_LCD_AFTER_x_MINUTES",
        "name": "Resets LCD screen (minutes)",
        "desc": "It helps rectify problems caused due to serial communication.",
        "type": "number",
        "min": 60,
        "max": (24 * 60),
        "value": 60
      }, {
        "id": "RESET_SYSTEM_AFTER_x_MINUTES",
        "name": "Resets entire system (minutes)",
        "desc": "A reset is required to keep the timer work properly.",
        "type": "number",
        "min": (24 * 60),
        "max": (10 * 24 * 60),
        "value": (24 * 60)
      }],
      "directives": [{
        "id": "PROGRAM_SUMMARY",
        "name": "Program the summary",
        "desc": "Include the firmware that programs the sales summary",
        "value": false
      }, {
        "id": "PROGRAM_SD",
        "name": "Program the SD card",
        "desc": "Include the firmware that programs the sales summary",
        "value": false
      }, {
        "id": "PROGRAM_FROM_APP",
        "value": "true",
        "hide": true
      }, {
        "id": "IS_SMD_MICRO",
        "value": "true",
        "hide": true
      }, {
        "id": "PROGRAM_FROM_APP",
        "value": "true",
        "hide": true
      }]
    }
  }
};