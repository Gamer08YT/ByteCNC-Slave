//
// Created by Jan Heil on 08.03.2024.
//

#ifndef BYTECNC_SLAVE_READDIGITAL_H
#define BYTECNC_SLAVE_READDIGITAL_H


#include <vector>
#include "commands/Command.h"

    /**
     * @class ReadDigital
     *
     * @brief The ReadDigital class is a derived class of Command and represents a command to read digital data.
     *
     * The ReadDigital class is responsible for executing the command to read digital data. It overrides the execute function from the base class Command and provides its own implementation
    *.
     */
    class ReadDigital : public Command{
        public:
            String execute(std::vector<String> argsIO);

            const char *description() override {
                return "RD <IO>";
            };
    };

#endif //BYTECNC_SLAVE_READDIGITAL_H
