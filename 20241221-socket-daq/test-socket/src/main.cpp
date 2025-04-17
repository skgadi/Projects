
#include <Arduino.h>

#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>

// Create an Async WebSocket server
AsyncWebServer server(443);
AsyncWebSocket ws("/ws");

void onWebSocketEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, 
                      AwsEventType type, void *arg, uint8_t *data, size_t len) {
    if (type == WS_EVT_CONNECT) {
        Serial.printf("Client connected: %u\n", client->id());
        client->text("Welcome to the secure WebSocket server!");
    } else if (type == WS_EVT_DISCONNECT) {
        Serial.printf("Client disconnected: %u\n", client->id());
    } else if (type == WS_EVT_DATA) {
        Serial.printf("Data received from client %u: %s\n", client->id(), data);
        client->text("Message received!");
    }
}

const char* ssid = "Uyamak";          // Enter SSID
const char* password = "y5?*tFrdQU";  // Enter Password

// HTTPS credentials (self-signed or CA signed)
const char* serverCert = R"EOF("
-----BEGIN CERTIFICATE-----
MIIEMzCCAxugAwIBAgIUNzH3KyWsHd18ZcXyy7ptFTVOrAgwDQYJKoZIhvcNAQEL
BQAwgagxCzAJBgNVBAYTAk1YMREwDwYDVQQIDAhDb2FodWlsYTEQMA4GA1UEBwwH
VG9ycmVvbjEPMA0GA1UECgwGU0tHYWRpMQwwCgYDVQQLDANDSVQxKzApBgNVBAMM
IkNvbnRyb2wgYW5kIElkZW50aWZpY2F0aW9uIFRvb2xib3gxKDAmBgkqhkiG9w0B
CQEWGWdhZGlzdXJlc2hrdW1hckBnbWFpbC5jb20wHhcNMjQxMjI2MTUwNTI0WhcN
MjUxMjI2MTUwNTI0WjCBqDELMAkGA1UEBhMCTVgxETAPBgNVBAgMCENvYWh1aWxh
MRAwDgYDVQQHDAdUb3JyZW9uMQ8wDQYDVQQKDAZTS0dhZGkxDDAKBgNVBAsMA0NJ
VDErMCkGA1UEAwwiQ29udHJvbCBhbmQgSWRlbnRpZmljYXRpb24gVG9vbGJveDEo
MCYGCSqGSIb3DQEJARYZZ2FkaXN1cmVzaGt1bWFyQGdtYWlsLmNvbTCCASIwDQYJ
KoZIhvcNAQEBBQADggEPADCCAQoCggEBAM6C6yMN03TOBeDlxos5daUlTeSkEOJs
VQR160QxXgugppBucQ5ogcbO8+h+ZhyoMuVnsxQQwoNawkB2HDaO9eR1Aj2eF+qf
KbyPWu+YmlgeUYmyk2qPUuiZ6khPbGIS+2/RNXLTKGxDmXOBuvQ9lHrozm394zXs
Rcd06GqOl7wJmPi3FnvdQeb7Kj+in6InmFagX9fZSH7v+piwU62hEoekHyoL+i8B
3fquhCjQ91iYfhUpgr57fFqWTY4cZd0Tm+MDJQrnbASkUmzIr6AivDaU9NUTBkQP
uGNCxlszbr5WrIychz9cLBnTjOsTmt2t+uJNcpPx0h2sf5mxpxDZ820CAwEAAaNT
MFEwHQYDVR0OBBYEFBhwlds+yuqDTfCovhV+6TWoNeuKMB8GA1UdIwQYMBaAFBhw
lds+yuqDTfCovhV+6TWoNeuKMA8GA1UdEwEB/wQFMAMBAf8wDQYJKoZIhvcNAQEL
BQADggEBAHicR/3eYYaZzDLne6LnAH1uIblJxGyTrzCF7Z+MHIwL9rLmDdInFLfJ
S+exx1l/8CG5jLWmlbLqBIiYUKOeGxdF8svVGOjahAv/Exd742y+MKSn8gVSxs9z
vRM1Aps5kHsYSZkvumywM31e8+C1dCAk8VD0rKkCUTrMH0SzDBpqgjIwmoE0fOyT
lnIHORMjTDG08dBhWGFbl5Yt46IJD7qg63dCn8veukrFDlZHQBeXmwUTIN0zzToS
IAb37xzoG/rrOpFEAO0uwNW6nK6ebiXZlvCN/iaDKiBIX+iVPeFwi+CjfCApiM/r
AZFz40jFqaH7/Icn9mXCV/Mzek1l5gY=
-----END CERTIFICATE-----
)EOF"; // Replace with your certificate

const char* serverKey = R"EOF("
-----BEGIN PRIVATE KEY-----
MIIEvQIBADANBgkqhkiG9w0BAQEFAASCBKcwggSjAgEAAoIBAQDOgusjDdN0zgXg
5caLOXWlJU3kpBDibFUEdetEMV4LoKaQbnEOaIHGzvPofmYcqDLlZ7MUEMKDWsJA
dhw2jvXkdQI9nhfqnym8j1rvmJpYHlGJspNqj1LomepIT2xiEvtv0TVy0yhsQ5lz
gbr0PZR66M5t/eM17EXHdOhqjpe8CZj4txZ73UHm+yo/op+iJ5hWoF/X2Uh+7/qY
sFOtoRKHpB8qC/ovAd36roQo0PdYmH4VKYK+e3xalk2OHGXdE5vjAyUK52wEpFJs
yK+gIrw2lPTVEwZED7hjQsZbM26+VqyMnIc/XCwZ04zrE5rdrfriTXKT8dIdrH+Z
sacQ2fNtAgMBAAECggEARuNQ1M0br4ZDJVKqp0L3m9Nk3B3nf9nhCzFxK4zotAQW
+RA4NdJw7e4/cqjk42RnaDEDG1mvc4iVkqwYfi/vv1bdCIq6ufqdyJDLDeDr5mCt
658FlHgTZS3kaqL82OOcNONzPfG2+AbyZ2B6bPmwfMpqhf43Xty2jUOXvnApLM3e
m1BMugDypYX+xGS3EaZ4SbAxPoF3fMICG7o3Vr/t50eXVSsd4DiBeRZ2UabkOiq+
epqZR/NkzNMijqJCMxOgVL4uPr8In4uwm7W/kyX8AH9KODK87cTNc1NlHcZuYDVg
bMRj9JE/l964GheDbJHimQzGM0kuuFF1yyBf/UC87wKBgQDvu2U3+D4irk0m3YVO
nHVooj8kr7BkTXqmyYYPOiurkjdvtTwQXa8Hs9olJo0KGR9pDEJLNLO5JavJV5Hx
HFa0QBWzoxoa15Qu1rx01vdYADZUnRDVLResGg9o4q7qQ2sFq1feWRjBxnuT7OHm
xC3diJY/P9gpy4h26rMwEWZDEwKBgQDchmraP8H1b5/QXURcMtDFA4wsLdvFsvr5
218lu3iUve6n1bFI6DKkXuATeFk4IWFNjZOSqMyKAUJld9gvm2AJkl1MY33fTMwK
w0WP7zjXIngbnmWC0UuGnsyjDJCleTvEn9xUXH0kVwnXSfPCPlI2nSEoh1UQelTO
LioKn48/fwKBgE90Y5rGSwnBjU6ZUup4Dq3MQHNPS34i88i9uBHp7Lljr731al/e
PPmnkWCIw2waYX+2kW5NnFd79dC4lmU8SDxblRXBtBA7bSCNCU8MRFRFVbx7hi2x
UUw4Iu1XXDPGfn0VifzmuL7YovKnK0QJt03aTDnQVjub+rG3HgaLbcJDAoGAA0K1
h76TlpZs7X7DiP1zWsZfpzOSYUzxKwqUUJGCCej5A2BEe8h7HzUL6R3Ja+wKbUQf
n3aBd7TnD2sDNkj81Ydle8Co1sli5vHWMHegBoZK8lWYOKPxku78JZkE9n1hZdnb
PyAS9ZuX2KgOQ5v6STZvjBLcLh8w68+A7aFIU+8CgYEAkXDxW+gnn5F7PKqXe5U+
4IfwXUwNQEVcrfAqPUlmCeMfg3DAFQr6CAhIYnDOoGDY3PuTUzj/1KUSRWgZUMPS
DxKeD55qnERCJ7yqITgfd9hwuJx9tHFXgphrqPKHOg26ku1LSonkqPnB87MkqGKT
hq40ESRu3U/qoljqq9jRXUw=
-----END PRIVATE KEY-----
)EOF";



void setupWiFi() {
    Serial.print("Connecting to Wi-Fi");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWi-Fi connected!");
}

void setup() {
Serial.begin(115200);
    setupWiFi();

    // Attach WebSocket event handler
    ws.onEvent(onWebSocketEvent);
    server.addHandler(&ws);

    // Enable SSL/TLS
    if (!server.beginSecure(CERTIFICATE, PRIVATE_KEY)) {
        Serial.println("Failed to start secure server!");
        while (true);
    }

    Serial.println("Secure WebSocket server started!");

}

void loop() {
}