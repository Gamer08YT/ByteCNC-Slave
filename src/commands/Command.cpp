//
// Created by Jan Heil on 08.03.2024.
//

#include <vector>
#include "Command.h"

namespace commands {
    /**
     * @brief Executes the command.
     *
     * This function is responsible for executing the command. It takes a vector of char pointers as input, which represents the arguments, and returns a pointer to a char array. The result
    * of the execution is stored in the returned char array.
     *
     * @param argsIO A vector of char pointers representing the arguments.
     * @return A pointer to a char array representing the result of the execution. Returns nullptr if execution fails.
     */
    char * Command::execute(std::vector<char *> argsIO) {
        return nullptr;
    }
} // commands