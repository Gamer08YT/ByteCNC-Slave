//
// Created by Jan Heil on 08.03.2024.
//

#include "EmergencyStop.h"
#include "handler/SlaveHandler.h"

    /**
     * @brief Executes the emergency stop command.
     *
     * This function sets all the input/output (IO) values to their emergency values.
     * It calls the `setEmergency` function of the `SlaveHandler` class to set the emergency status to true.
     *
     * @param argsIO A vector of char pointers representing the input/output arguments (not used in this function).
     * @return A pointer to a char (nullptr in this case).
     *
     * @see SlaveHandler::setEmergency()
     */
    String EmergencyStop::execute(std::vector<String> argsIO) {
        // Set All IOs to emergency Values (Default Values).
        handler::SlaveHandler::setEmergency(true);

        return "OK";
    }
