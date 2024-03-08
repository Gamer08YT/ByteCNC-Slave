//
// Created by Jan Heil on 08.03.2024.
//

#include "WriteDigital.h"
#include "Arduino.h"

namespace commands {
    /**
     * @brief Executes the write digital command.
     *
     * This function is responsible for executing the write digital command. It sends the settings and calls the execute function of the Command class.
     *
     * @param argsIO A vector of character pointers representing the arguments.
     * @return A boolean value indicating the success or failure of the execution.
     */
    bool WriteDigital::execute(std::vector<char *> argsIO) {
        const auto valueIO = (argsIO[1] == "true" || argsIO[1] == "1" ? HIGH : LOW);

        // Write State to Pin.
        digitalWrite(*argsIO[0], valueIO);

        return true;
    }

    const char *WriteDigital::description() {
        return "Retrieve Settings";
    }
} // commands