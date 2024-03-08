//
// Created by Jan Heil on 08.03.2024.
//

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
    bool ReadAnalog::execute(std::vector<char *> argsIO) {

        // @todo: Return Analog Value.

        return false;
    }

    const char *ReadAnalog::description() {
        return "Quickstop";
    }
}