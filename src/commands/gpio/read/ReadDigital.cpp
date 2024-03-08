//
// Created by Jan Heil on 08.03.2024.
//

#include <Arduino.h>
#include "ReadDigital.h"

namespace commands {

    /**
     * @brief Executes the ReadDigital command.
     *
     * This function is responsible for executing the ReadDigital command. It overrides the execute function from the base class Command and saves the data to EEPROM before calling the base
    * class implementation.
     *
     * @param argsIO A vector of char pointers representing the arguments for the command.
     * @return A boolean value indicating the success or failure of the execution.
     */
    char * ReadDigital::execute(std::vector<char *> argsIO) {
        return reinterpret_cast<char *>(analogRead(*argsIO[0]));
    }

    const char *ReadDigital::description() {
        return "RD <IO>";
    }
}
