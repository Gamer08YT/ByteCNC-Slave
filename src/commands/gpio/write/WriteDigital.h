//
// Created by Jan Heil on 08.03.2024.
//

#ifndef BYTECNC_SLAVE_WRITEDIGITAL_H
#define BYTECNC_SLAVE_WRITEDIGITAL_H

#include <vector>
#include "commands/Command.h"


    /**
     * @class WriteDigital
     * @brief A class that represents a write digital command.
     *
     * This class is a subclass of the Command class and is responsible for executing a write digital command.
     */
    class WriteDigital : public Command{
        public:
        String execute(std::vector<String> argsIO);

            const char *description() override {
                return "WD <IO> <0-1>";
            };
    };

#endif //BYTECNC_SLAVE_WRITEDIGITAL_H
