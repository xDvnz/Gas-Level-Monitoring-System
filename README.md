# Gas-Level-Monitoring-System
An IoT-based Gas Level Monitoring System using NodeMCU ESP8266 and MQ-2 sensor to detect gas leaks and monitor LPG levels in real-time via the Blynk app.

## Required Libraries

Before uploading the code to your microcontroller, ensure you have installed the following libraries in your Arduino IDE:
* **ESP8266WiFi.h**: Handles Wi-Fi connectivity and network protocols for the NodeMCU ESP8266 chip.
* **BlynkSimpleEsp8266.h**: Connects the microcontroller directly to the Blynk IoT cloud platform.
* **LiquidCrystal_I2C.h**: Controls the text display on the LCD screen via the I2C interface.

## Installation & Setup

Follow these steps to set up your development environment and upload the code to your hardware:

### 1. Software & Board Preparation
* Download and install the **Arduino IDE** on your computer.
* Open Arduino IDE, then navigate to **File** > **Preferences**.
* Add the ESP8266 board manager URL to the **Additional Boards Manager URLs** field.
* Go to **Tools** > **Board** > **Boards Manager**, search for `esp8266`, and click install to enable NodeMCU board support.

### 2. Installing Libraries
* Navigate to **Sketch** > **Include Library** > **Manage Libraries...** in the Arduino IDE.
* Search for **Blynk** and click install.
* Search for **LiquidCrystal I2C** and click install.

### 3. Blynk IoT Configuration
* Log in to your Blynk IoT web console.
* Copy your unique project configuration credentials: `BLYNK_TEMPLATE_ID`, `BLYNK_TEMPLATE_NAME`, and `BLYNK_AUTH_TOKEN`.
* Paste these tokens along with your local Wi-Fi SSID and password into the designated lines at the top of your code.

### 4. Uploading the Code
* Connect your physical NodeMCU ESP8266 module to your computer using a Micro USB data cable.
* Select the correct board configuration via **Tools** > **Board** > **ESP8266 Boards** > **NodeMCU 1.0 (ESP-12E Module)**.
* Choose the active connection port under **Tools** > **Port**.
* Click the **Verify** icon to check the script for errors, then click **Upload** to flash the program onto your microcontroller.
