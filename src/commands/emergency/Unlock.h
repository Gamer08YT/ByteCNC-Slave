//
// Created by Jan Heil on 08.03.2024.
//

#ifndef BYTECNC_SLAVE_UNLOCK_H
#define BYTECNC_SLAVE_UNLOCK_H

#include <vector>
#include "commands/Command.h"


    class Unlock : public Command {
        public:
        String execute(std::vector<String> argsIO);

            const char *description() override {
                return "UNLOCK";
            };
    };


#endif //BYTECNC_SLAVE_UNLOCK_H
