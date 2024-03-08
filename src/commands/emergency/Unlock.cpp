//
// Created by Jan Heil on 08.03.2024.
//

#include "Unlock.h"
#include "handler/SlaveHandler.h"

namespace commands {
    /**
     * @brief Executes the unlock operation.
     *
     * This function removes the Emergency State Lock by calling `handler::SlaveHandler::setEmergency`
     * and setting the emergency state to false.
     *
     * @param argsIO A vector of char pointers representing the input arguments. Unused in this function.
     * @return Always returns nullptr.
     */
    char *Unlock::execute(std::vector<char *> argsIO) {
        // Remove Emergency State Lock.
        handler::SlaveHandler::setEmergency(false);

        return nullptr;
    }

    const char *Unlock::description() {
        return "UNLOCK";
    }
} // commands