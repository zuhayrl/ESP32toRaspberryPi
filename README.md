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

3. **Using as an Access Point:**
   - If you want to use the ESP32 as an access point, uncomment the following lines in the sketch:
     ```cpp
     /*
     WiFi.softAP(ssid, password);
     IPAddress IP = WiFi.softAPIP();
     Serial.print("AP IP address: ");
     Serial.println(IP);
     */
     ```
   - Comment out or remove the lines related to connecting to a WiFi network.
   - This will enable the ESP32 to create its own WiFi network with the specified SSID and password, and you can connect to it directly.

### Functionality

- The web server responds to HTTP GET requests to the `/files` endpoint.
- It retrieves the list of files stored in the SPIFFS and sends it as a response to the client.
- If there's an error mounting the SPIFFS, an error message is displayed.
- The loop function continuously runs, allowing for additional functionality to be added if needed.

## ESP32 File Downloader (Python Script)

This Python script is designed to download files stored on an ESP32 microcontroller's SPIFFS (SPI Flash File System) to a Raspberry Pi (or any other computer).

### Requirements

- Python 3.x
- `requests` library

### Usage

1. **Update ESP32 IP Address:**
   - Replace `"insert_ip_address_for_esp32"` with the actual IP address of your ESP32.

2. **Run the Script:**
   - Open a terminal or command prompt.
   - Navigate to the directory where the script is saved.
   - Run the script by executing:
     ```
     python esp32_file_downloader.py
     ```

3. **Download Files:**
   - The script will retrieve the list of files stored on the ESP32's SPIFFS.
   - It will then download each file to the same directory where the script is located.

### Functionality

- The script sends an HTTP GET request to the ESP32 to retrieve the list of files stored on its SPIFFS.
- It then iterates through the list of files and downloads each file one by one.
- The downloaded files are saved in the same directory where the script is located.

### Note

- Before running the script, ensure that the ESP32 is connected to the same network as the computer running the script, and replace `"insert_ip_address_for_esp32"` with the actual IP address of the ESP32.

### License

This script is provided under the [MIT License](LICENSE).
