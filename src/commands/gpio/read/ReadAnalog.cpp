//
// Created by Jan Heil on 08.03.2024.
//

#include <Arduino.h>
#include "ReadAnalog.h"

namespace commands {

    /**
     * @brief Executes the ReadAnalog command.
     *
     * This function stops all relays and stepper motors.
     *
     * @param argsIO A vector of character pointers representing the command arguments.
     * @return Returns false.
     */
    char * ReadAnalog::execute(std::vector<char *> argsIO) {
        return reinterpret_cast<char *>(analogRead(*argsIO[0]));
    }

    const char *ReadAnalog::description() {
        return "RA <IO>";
    }
}