//
// Created by Jan Heil on 08.03.2024.
//

#include <Arduino.h>
#include "ReadAnalog.h"

    /**
     * @brief Executes the ReadAnalog command.
     *
     * This function stops all relays and stepper motors.
     *
     * @param argsIO A vector of character pointers representing the command arguments.
     * @return Returns false.
     */
    String ReadAnalog::execute(std::vector<String> argsIO) {
        return String(analogRead(argsIO[0].toInt()));
    }
