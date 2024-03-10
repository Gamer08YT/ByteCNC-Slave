//
// Created by Jan Heil on 08.03.2024.
//

#include "WriteDigital.h"
#include "Arduino.h"
#include "handler/SlaveHandler.h"

    /**
     * @brief Executes the write digital command.
     *
     * This function is responsible for executing the write digital command. It sends the settings and calls the execute function of the Command class.
     *
     * @param argsIO A vector of character pointers representing the arguments.
     * @return A boolean value indicating the success or failure of the execution.
     */
    String WriteDigital::execute(std::vector<String> argsIO) {
        const auto valueIO = (argsIO[1] == "true" || argsIO[1] == "1" ? HIGH : LOW);

        // Don't do anything on Emergency.
        if(!handler::SlaveHandler::isEmergency()) {
            // Write State to Pin.
            digitalWrite(argsIO[0].toInt(), valueIO);

            return "";
        }

        return "EMERGENCY";
    }
