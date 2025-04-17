#include "gsk_main.h"
extern GSK_MAIN gskMain;

WebsocketsServer GSK_SERVER;

GSK_COMM::GSK_COMM() {
    inCommand = new json;
    outCommand = new json;
}

json GSK_COMM::encodeOutCommand() {
    *outCommand = {{"command", "test"}};
    return json::to_cbor(*outCommand);
}

void GSK_COMM::setup() {
    Serial.println("Websocket server starting up ...");
    GSK_SERVER.listen(80);
    while (!GSK_SERVER.available()) {
        Serial.println("Waiting for server to be available");
        delay(1000);
    }
    Serial.println("Websocket server started");
}

void GSK_COMM::loop() {
    Serial.println("Websocket server loop");
    WebsocketsClient client = GSK_SERVER.accept();
    Serial.println("waiting for client");

    delay(1000);
}