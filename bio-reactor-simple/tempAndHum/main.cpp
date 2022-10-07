
# include "main.h"


//part of code taken from
// https://github.com/milesburton/Arduino-Temperature-Control-Library/blob/master/examples/Multibus_simple/Multibus_simple.ino

OneWire oneWire(TEMP_SENSOR_PIN);


int total_devices=2;
DeviceAddress sensor_address; 


DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);


  sensors.begin();
  //total_devices = sensors.getDeviceCount();
  
  Serial.print("Locating devices...");
  Serial.print("Found ");
  Serial.print(total_devices, DEC);
  Serial.println(" devices.");

  for(int i=0;i<total_devices; i++){
    if(sensors.getAddress(sensor_address, i)){
      Serial.print("Found device ");
      Serial.print(i, DEC);
      Serial.print(" with address: ");
      printAddress(sensor_address);
      Serial.println();
    } else {
      Serial.print("Found device at ");
      Serial.print(i, DEC);
      Serial.print(" but could not detect address. Check circuit connection!");
    }
  }
}
void loop () {
  Serial.print(",");
  Serial.print(analogRead(HUMIDITY_SENSOR_1));
  Serial.print(",");
  Serial.print(analogRead(HUMIDITY_SENSOR_2));





  
  for(int i=0;i<total_devices; i++){

    sensors.requestTemperatures();
    if(sensors.getAddress(sensor_address, i)){
           
      float temperature_degreeCelsius = sensors.getTempC(sensor_address);
      Serial.print(",");
      Serial.print(temperature_degreeCelsius);
    }
  }

  Serial.println("");






  for (int i=0; i<SHOW_READING_EVERY_x_SECONDS; i++) {
    delay(1000);
  }
}


void printAddress(DeviceAddress deviceAddress) {
  for (uint8_t i = 0; i < 8; i++){
    if (deviceAddress[i] < 16) Serial.print("0");
      Serial.print(deviceAddress[i], HEX);
  }
}
