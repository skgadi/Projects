const commandQueue = ["ver"];
let readyToExec = true;
const availHardware = {
  "1617064809234": {
    "name": "8 channel - VMLS",
    "desc": "8 channel - Vending machine for liquid detergents",
    "firmware": {
      "folder": "ver001-final/automatic_soap_dispenser/automatic_soap_dispenser.ino",
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
        "value": 120
      }, {
        "id": "REMOVE_CREDIT_AFTER_x_SECONDS",
        "name": "Credit is removed after (seconds)",
        "desc": "After above selected time the credit is set to zero when no activity is registered.",
        "type": "number",
        "min": 60,
        "max": 3600,
        "value": 600
      }],
      "directives": [{
        "id": "PROGRAM_SUMMARY",
        "name": "Program the summary",
        "desc": "Include the firmware that programs the sales summary",
        "value": false
      }]
    }
  },
  "1617070729488": {
    "name": "32 channel - VMLS",
    "desc": "32 channel - Vending machine for liquid detergents",
    "firmware": {
      "folder": "ver001-final/automatic_soap_dispenser/automatic_soap_dispenser.ino",
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
        "value": 120
      }, {
        "id": "REMOVE_CREDIT_AFTER_x_SECONDS",
        "name": "Credit is removed after (seconds)",
        "desc": "After above selected time the credit is set to zero when no activity is registered.",
        "type": "number",
        "min": 60,
        "max": 3600,
        "value": 600
      }],
      "directives": [{
        "id": "PROGRAM_SUMMARY",
        "name": "Program the summary",
        "desc": "Include the firmware that programs the sales summary",
        "value": false
      }]
    }
  }
};