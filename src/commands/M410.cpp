//
// Created by Jan Heil on 08.03.2024.
//

#include "M410.h"

namespace commands {

    /**
     * @brief Executes the M410 command
     *
     * This function is responsible for stopping all relays and stepper motors.
     *
     * @param argsIO The arguments passed to the command (none required)
     * @return Returns false
     */
    bool M410::execute(std::vector<char *> argsIO) {

        // @todo: Stop all Relais / Stepper.

        return false;
    }

    const char *M410::description() {
        return "Quickstop";
    }
}