//
// Created by Jan Heil on 08.03.2024.
//

#ifndef BYTECNC_SLAVE_COMMAND_H
#define BYTECNC_SLAVE_COMMAND_H

namespace commands {

    class Command {
        /**
         * Basic Command Description (Docs Ref. no full Sentence)
         * @return
         */
        virtual const char *description() {
            return "See X.X.X";
        }

    public:
/**
 * @brief Executes the command.
 *
 * This function is responsible for executing the command. It takes a vector of char pointers as input, which represents the arguments, and returns a pointer to a char array. The result
* of the execution is stored in the returned char array.
 *
 * @param argsIO A vector of char pointers representing the arguments.
 * @return A pointer to a char array representing the result of the execution. Returns nullptr if execution fails.
 *
 * @see Command::description()
 */
virtual char * execute(std::vector<char *> argsIO);
    };

} // commands

#endif //BYTECNC_SLAVE_COMMAND_H
