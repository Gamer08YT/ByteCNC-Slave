//
// Created by Jan Heil on 08.03.2024.
//

#include <string>
#include "EmergencyConfig.h"
#include "EEPROM.h" // EEPROM library to write values

    /**
     * @brief Executes the EmergencyConfig command.
     *
     * This function is responsible for executing the EmergencyConfig command with the given arguments.
     * The command takes two arguments: a PIN (argsIO[0]) and a value (argsIO[1]).
     *
     * @param argsIO A vector of char pointers representing the arguments for the command.
     * @return char* A pointer to the result of the execution (null in this case).
     *
     * @note The PIN argument is expected to be a string. It is stored as a const char*.
     * @note The value argument is expected to be a pointer. It is stored as an int.

     * @see EmergencyConfig
     */
    String EmergencyConfig::execute(std::vector<String> argsIO) {
        const String pinIO = argsIO[0];
        int valueIO = argsIO[1].toInt();

        // Convert pinIO to int as EEPROM expects int value for address.
        int eepromAddress = pinIO.toInt();

        // @todo Serialize...

        // Write value to EEPROM.
        EEPROM.write(eepromAddress, valueIO);

        return "";
    }
