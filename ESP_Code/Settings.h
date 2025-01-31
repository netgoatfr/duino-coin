// Settings.h
#ifndef SETTINGS_H
#define SETTINGS_H

// ---------------------- General settings ---------------------- //
// Change the part in brackets to your Duino-Coin username
extern const char DUCO_USER[] = "my_cool_username";
// Change the part in brackets to your mining key (if you have set it in the wallet)
extern const char MINER_KEY[] = "mySecretPass";
// Change the part in brackets if you want to set a custom miner name
// Use Auto to autogenerate, None for no custom identifier
extern const char RIG_IDENTIFIER[] = "None";
// Change the part in brackets to your WiFi name
extern const char SSID[] = "SSID";
// Change the part in brackets to your WiFi password
extern const char PASSWORD[] = "PASSW0RD";

// Uncomment if you want to host the dashboard page (available on ESPs IP address)
// #define WEB_DASHBOARD

// Uncomment if you want to use LAN8720. WLAN-credentials will be ignored using LAN
// Select correct Board in ArduinoIDE!!! Really!
// #define USE_LAN

// Comment out the line below if you wish to disable LED blinking
#define LED_BLINKING

// Comment out the line below if you wish to disable Serial printing
#define SERIAL_PRINTING

// Edit the line below if you wish to change the serial speed (low values may reduce performance but are less prone to interference)
#define SERIAL_BAUDRATE 500000

// ESP8266 WDT loop watchdog. Do not edit this value, but if you must - do not set it too low or it will falsely trigger during mining!
#define LWD_TIMEOUT 30000

// Uncomment to enable a SSD1306 OLED screen on the I2C bus to display mining info in real time
// Default connections (can be overriden with Wire.begin(SDA, SCL)):
// GND - GND
// VCC - 5V or 3.3V depending on display
// SCL - GPIO21 (ESP32) or GPIO5 (ESP8266) or GPIO35 (ESP32-S2)
// SDA - GPIO22 (ESP32) or GPIO4 (ESP8266) or GPIO33 (ESP32-S2)
// #define DISPLAY_SSD1306

// -------------------------------------------------------------- //

// ---------------------- IoT examples -------------------------- //
// https://github.com/revoxhere/duino-coin/wiki/Duino's-take-on-the-Internet-of-Things

// Uncomment the line below if you wish to use the internal temperature sensor (Duino IoT example)
// Only ESP32-S2, -S3, -H2, -C2, -C3, -C6 and some old models have one!
// More info: https://www.espboards.dev/blog/esp32-inbuilt-temperature-sensor/
// NOTE: Mining performance will decrease by about 20 kH/s!
// #define USE_INTERNAL_SENSOR

// Uncomment the line below if you wish to use a DS18B20 temperature sensor (Duino IoT example)
// NOTE: Mining performance should stay the same
// #define USE_DS18B20

// Uncomment the line below if you wish to use a DHT11/22 temperature and humidity sensor (Duino IoT example)
// NOTE: Untested as of right now
// #define USE_DHT
// -------------------------------------------------------------- //

#if defined(ESP8266)
    // ESP8266
    #define LED_BUILTIN 2
#elif defined(CONFIG_FREERTOS_UNICORE) 
    // ESP32-S2
    #define LED_BUILTIN 15
#else
    // ESP32
    #define LED_BUILTIN 2
#endif

#define BLINK_SETUP_COMPLETE 2
#define BLINK_CLIENT_CONNECT 5

#define SOFTWARE_VERSION "4.2"
extern unsigned int hashrate = 0;
extern unsigned int difficulty = 0;
extern unsigned long share_count = 0;
extern unsigned long accepted_share_count = 0;
extern String node_id = "";
extern String WALLET_ID = "";
extern unsigned int ping = 0;

#if defined(USE_INTERNAL_SENSOR)
  #include "driver/temp_sensor.h"
#endif

#if defined(USE_DS18B20)
  // Install OneWire and DallasTemperature libraries if you get an error
  #include <OneWire.h>
  #include <DallasTemperature.h>
  // Change 12 to the pin you've connected your sensor to
  #define DSPIN 12
  
  OneWire oneWire(DSPIN);
  DallasTemperature extern sensors(&oneWire);
#endif

#if defined(USE_DHT)
  // Install "DHT sensor library" if you get an error
  #include <DHT.h>
  // Change 12 to the pin you've connected your sensor to
  #define DHTPIN 12
  // Set DHT11 or DHT22 type accordingly
  #define DHTTYPE DHT11
  
  DHT extern dht(DHTPIN, DHTTYPE);
#endif

#if defined(DISPLAY_SSD1306)
    #include <U8g2lib.h>
    #include <Wire.h>
    // Display definition from the U8G2 library. Edit if you use a different display
    U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);
#endif

#endif  // End of SETTINGS_H
