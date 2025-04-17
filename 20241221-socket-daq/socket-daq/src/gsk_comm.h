#ifndef GSK_COMM_H
#define GSK_COMM_H

#include "nlohmann/json.hpp"
using json = nlohmann::json;
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

#include <ArduinoWebsockets.h>
#include <WiFi.h>
using namespace websockets;

extern WebsocketsServer GSK_SERVER;
class GSK_COMM {
    json *inCommand;
    json *outCommand;
    

   public:
    GSK_COMM();
    void setup();
    void loop();
    json encodeOutCommand();
};

#endif  // GSK_COMM_H