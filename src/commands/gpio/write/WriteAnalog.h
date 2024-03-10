//
// Created by Jan Heil on 08.03.2024.
//

#ifndef BYTECNC_SLAVE_WRITEANALOG_H
#define BYTECNC_SLAVE_WRITEANALOG_H

#include <vector>
#include "commands/Command.h"


    /**
     * @class WriteAnalog
     * @brief A class for writing analog values.
     *
     * This class inherits from the Command class and provides the functionality to write analog values.
     */
    class WriteAnalog : public Command{
        public:
        String execute(std::vector<String> argsIO);

            const char *description() override {
                return "WA <IO> <0-255>";
            };
    };

#endif //BYTECNC_SLAVE_WRITEANALOG_H
