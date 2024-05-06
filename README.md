# ESP32 to Raspberry Pi


## ESP32 SPIFFS Web Server

This project is an Arduino sketch for ESP32 microcontrollers. It creates a web server that allows clients to access a list of files stored on the ESP32's SPIFFS (SPI Flash File System) through a web browser.

### What You'll Need

- Arduino IDE
- ESP32 board (e.g., ESP32 DevKit)
- USB cable for programming
- Access to a WiFi network

### Installation Steps

1. **Install Libraries:**
   - Open Arduino IDE.
   - Go to `Sketch` > `Include Library` > `Manage Libraries...`
   - Search for and install:
     - `ESPAsyncWebServer` library by `me-no-dev`
     - `SPIFFS` library (comes with ESP32 board support)

2. **Set Up WiFi:**
   - Open the sketch file (`ESP32_SPIFFS_Web_Server.ino`).
   - Find the lines:
     ```cpp
     const char* ssid = "Your_WiFi_SSID";
     const char* password = "Your_WiFi_Password";
     ```
   - Replace `"Your_WiFi_SSID"` with your WiFi network name and `"Your_WiFi_Password"` with your WiFi password.

3. **Upload Sketch:**
   - Connect your ESP32 board to your computer via USB.
   - Select the appropriate board and port from the `Tools` menu in Arduino IDE.
   - Click the "Upload" button to upload the sketch to your ESP32 board.

### Usage

1. **Find ESP32 IP Address:**
   - After uploading the sketch, open the Serial Monitor in Arduino IDE.
   - The ESP32 will print its IP address once it connects to the WiFi network.

2. **Access Files:**
   - Open a web browser on any device connected to the same WiFi network.
   - In the address bar, enter the IP address printed by the ESP32 followed by `/files` (e.g., `http://192.168.1.100/files`).
   - Press Enter to view the list of files stored on the ESP32's SPIFFS.

### Functionality

- The web server responds to HTTP GET requests to the `/files` endpoint.
- It retrieves the list of files stored in the SPIFFS and sends it as a response to the client.
- If there's an error mounting the SPIFFS, an error message is displayed.
- The loop function continuously runs, allowing for additional functionality to be added if needed.

### License

This project is licensed under the [MIT License](LICENSE).
