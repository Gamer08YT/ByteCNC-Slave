//
// Created by Jan Heil on 08.03.2024.
//

#ifndef BYTECNC_SLAVE_PINMODE_H
#define BYTECNC_SLAVE_PINMODE_H

#include <vector>
#include "commands/Command.h"

    class PinMode : public Command {
        public:
            String execute(std::vector<String> argsIO);


            const char *description() override {
                return "MODE <IO> <ANALOG/DIGITAL>";
            };

        }; // commands

#endif //BYTECNC_SLAVE_PINMODE_H
