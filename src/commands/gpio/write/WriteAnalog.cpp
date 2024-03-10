//
// Created by Jan Heil on 08.03.2024.
//

#include "WriteAnalog.h"
#include "Arduino.h"
#include "handler/SlaveHandler.h"

    /**
     * @file
     * @brief Define the WriteAnalog class and its member functions.
     */
    String WriteAnalog::execute(std::vector<String> argsIO) {
        int valueIO = argsIO[1].toInt();

        // Don't do anything on Emergency.
        if(!handler::SlaveHandler::isEmergency()) {
            // Write State to Pin if not over max Value.
            if (valueIO <= 255) {
                analogWrite(argsIO[0].toInt(), valueIO);
            }

            return "";
        }

        return "EMERGENCY";
    }
