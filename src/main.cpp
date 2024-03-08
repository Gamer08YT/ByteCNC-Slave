#include <Arduino.h>
#include <Ethernet.h>
#include <handler/CommandHandler.h>

// Set Default MAC-Address should be ESP32 MAC.
byte macIO[] = {0x00, 0x04, 0x03, 0x41, 0x8C, 0xEE};

// Set Default Static Address.
IPAddress ipIO(10, 0, 0, 10);

// Initialize the Ethernet TCP Server.
EthernetServer serverIO(52003);

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
  // Start the Ethernet connection and the server
  Ethernet.begin(macIO, ipIO);

  // Begin TCP Server.
  serverIO.begin();
}

/**
 * @brief Handle incoming client requests
 *
 * This function is called repeatedly in the main loop to check if a client has connected and process their requests accordingly.
 *
 * @note This function assumes that an EthernetServer instance named 'server' has already been defined and initialized with a port number.
 */
void loop() {
  // Check if a client has connected
  EthernetClient clientIO = serverIO.available();

  // Check if Client is available.
  if (clientIO) {
    // Read the first line of the Client request.
    String requestIO = clientIO.readStringUntil('\r');

    // Flush Socket Stream.
    clientIO.flush();

    // Match the request if not empty.
    if (requestIO) {
        // Execute Command.
        handler::CommandHandler::execute(const_cast<char *>(requestIO.c_str()));
    }
  }
}