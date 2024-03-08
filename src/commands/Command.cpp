//
// Created by Jan Heil on 08.03.2024.
//

#include <vector>
#include "Command.h"

namespace commands {
    /**
     * @brief Executes the command.
     *
     * This function is responsible for executing the command. It takes a pointer to an array of arguments as input and returns a boolean value indicating the success or failure of the execution
    *.
     *
     * @param argsIO A pointer to an array of arguments.
     * @return A boolean value indicating the success or failure of the execution.
     */
    bool Command::execute(std::vector<char *> argsIO) {
        return false;
    }
} // commands