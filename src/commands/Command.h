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
 * This function is responsible for executing the command. It takes a pointer to an array of arguments as input and returns a boolean value indicating the success or failure of the execution
*.
 *
 * @param argsIO A pointer to an array of arguments.
 * @return A boolean value indicating the success or failure of the execution.
 */
virtual bool execute(std::vector<char *> argsIO);
    };

} // commands

#endif //BYTECNC_SLAVE_COMMAND_H
