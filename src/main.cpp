#include <Arduino.h>
#include <handler/CommandHandler.h>
#include <handler/TelnetHandler.h>
#include <ESP8266WiFi.h>
#include <Secret.h>

// Set Default MAC-Address should be ESP32 MAC.
byte macIO[] = {0x00, 0x04, 0x03, 0x41, 0x8C, 0xEE};

// // Set Default Static Address.
// IPAddress ipIO(10, 0, 0, 10);

// Default WiFi Fallback.
/*const char* ssid = "ByteSlave";
const char* password = "Hostinger2024";*/
const char* ssid = Secret::ssid;
const char* password = Secret::password;

/**
 * @brief Initializes the Ethernet connection and starts the server.
 *
 * This function should be called in the `setup()` function to initialize
 * the Ethernet connection and start the server.
 *
 * @note The `mac` and `ip` variables should be defined with appropriate values before calling this function.
 *
 * @see mac
 * @see ip
 * @see server
 *
 * @return void
 */
void setup() {
    // Begin Serial Output.
    Serial.begin(115200);

    // Setting up WiFi AP.
    Serial.print("Connecting to WiFi Network.");

    #if defined(ARDUINO_ARCH_ESP8266)
        WiFi.forceSleepWake();
        delay(200);
    #endif

    // Start WiFi AP.
    WiFi.begin(ssid, password);

    // Wait for connection to complete.
    while (WiFi.status()  != WL_CONNECTED) {
        Serial.print(".");
        delay(100);
    }

    // Set Auto Reconnect and Persistent.
    WiFi.setAutoReconnect(true);
    WiFi.persistent(true);

    // Print Debug Message.
    Serial.print("Local IP address: ");
    Serial.println(WiFi.localIP());

    //  // Start the Ethernet connection.
    //  Ethernet.begin(macIO, ipIO);

    //  // Get Status of Ethernet Shield.
    //  EthernetLinkStatus linkStatus = Ethernet.linkStatus();
    //
    //  // Open WiFi AP if Ethernet Status is not Connected.
    //  if(linkStatus == Unknown || linkStatus == LinkOFF) {
    //      // Ethernet not connected.
    //      Serial.println("Ethernet not connected. Starting WiFi AP.");
    //
    //      // Start WiFi AP.
    //      WiFi.softAP(ssid, password);
    //  }

    // Setup Telnet Listeners.
    handler::TelnetHandler::setup();

    // Begin TCP Server.
    handler::TelnetHandler::telnetIO.begin(23);

    // Add Default Commands.
    handler::CommandHandler::addDefaults();
}

/**
 * @brief Handle incoming client requests
 *
 * This function is called repeatedly in the main loop to check if a client has connected and process their requests accordingly.
 *
 * @note This function assumes that an EthernetServer instance named 'server' has already been defined and initialized with a port number.
 */
void loop() {
    // Loop Telnet Server Function.
    handler::TelnetHandler::telnetIO.loop();
}