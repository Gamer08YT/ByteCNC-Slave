//
// Created by Jan Heil on 10.03.2024.
//

#include "TelnetHandler.h"
#include "CommandHandler.h"

namespace handler {
    ESPTelnet TelnetHandler::telnetIO;

    void TelnetHandler::setup() {
        // Add Connection Listener.
        telnetIO.onConnect([](String str) {
            // Print Connection Message.
            Serial.println("Client connected to Telnet Server.");

            // Print Welcome Message to let Client know for successful Connection.
            telnetIO.println("WELCOME");
        });

        // Add Disconnection Listener.
        telnetIO.onDisconnect([](String str) {
            // Print Disconnection Message.
            Serial.println("Client disconnected from Telnet Server.");
        });

        // Add Connection Attempt Listener.
        telnetIO.onConnectionAttempt([](String str) {
            // Print Failed Message.
            Serial.println("Client failed connecting to Telnet Server.");
        });

        // Add Input Listener.
        telnetIO.onInputReceived([](String str) {
            // Print to Serial.
            Serial.println(str);

            // Handle Command.
            String responseIO = handler::CommandHandler::execute(str.c_str());

            // Print Response to Telnet Client.
            if (responseIO.c_str() != "") {
                Serial.println(responseIO);
                telnetIO.println(responseIO);
            }

        });
    }


} // handler