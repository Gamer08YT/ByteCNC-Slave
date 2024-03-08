//
// Created by Jan Heil on 08.03.2024.
//

#include "WriteAnalog.h"
#include "Arduino.h"
#include "handler/SlaveHandler.h"

namespace commands {
    /**
     * @file
     * @brief Define the WriteAnalog class and its member functions.
     */
    char * WriteAnalog::execute(std::vector<char *> argsIO) {
        int valueIO = reinterpret_cast<int>(argsIO[1]);

        // Don't do anything on Emergency.
        if(!handler::SlaveHandler::isEmergency()) {
            // Write State to Pin if not over max Value.
            if (valueIO <= 255) {
                analogWrite(*argsIO[0], valueIO);
            }

            return nullptr;
        }

        return "EMERGENCY";
    }

    const char *WriteAnalog::description() {
        return "WA <IO> <0-255>"
    }
} // commands