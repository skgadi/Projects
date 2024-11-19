#include <Arduino.h>
#include <IRrecv.h>
#include <IRremoteESP8266.h>
#include <IRutils.h>

#include <map>
#include <string>
std::map<int, std::string> mapping = {

    {0xFFA25D, "1"},    {0xFF629D, "2"},     {0xFFE21D, "3"},
    {0xFF22DD, "4"},    {0xFF02FD, "5"},     {0xFFC23D, "6"},
    {0xFFE01F, "7"},    {0xFFA857, "8"},     {0xFF906F, "9"},
    {0xFF9867, "0"},    {0xFF6897, "*"},     {0xFFB04F, "#"},
    {0xFF18E7, "up"},   {0xFF5AA5, "right"}, {0xFF4AB5, "down"},
    {0xFF10EF, "left"}, {0xFF38C7, "ok"},

};

IRrecv irRec(13);
decode_results results;

void setup() {
    Serial.begin(115200);
    irRec.enableIRIn();  // Start the receiver
}

void loop() {
    if (irRec.decode(&results)) {
        if (results.value != 0xFFFFFFFFFFFFFFFF) {
            std::map<int, std::string>::const_iterator iter =
                mapping.find(results.value);
            if (iter != mapping.end()) {
              Serial.println(iter->second.c_str());
            } else {
              Serial.println("Unknown code");
            }
        }

        // dump(&results);
        // Serial.println("DEPRECATED: Please use IRrecvDumpV2.ino instead!");
        irRec.resume();  // Receive the next value
    }
}