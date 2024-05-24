#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>

const char* ssid = "Your_WiFi_SSID";
const char* password = "Your_WiFi_Password";

AsyncWebServer server(80);

void handleFileList(AsyncWebServerRequest *request) {
  if (!SPIFFS.begin(true)) {
    Serial.println("An Error has occurred while mounting SPIFFS");
    request->send(500, "text/plain", "Error mounting SPIFFS");
    return;
  }

  String fileList = "";
  File root = SPIFFS.open("/");
  File file = root.openNextFile();
  while (file) {
    if (!file.isDirectory()) {
      fileList += file.name();
      fileList += "\n";
    }
    file = root.openNextFile();
  }

  request->send(200, "text/plain", fileList);
}

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi======================================================
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.println(WiFi.localIP());
  

  // Access Point =========================================================
  /*
  WiFi.softAP(ssid, password);
  // Print ESP32 Local IP Address
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
  */

  // Start the web server==================================================
  server.on("/files", HTTP_GET, handleFileList);
  server.begin();
  Serial.println("HTTP server started");
  
}

void loop() {
//loop code
  
}

