//
// Created by Jan Heil on 08.03.2024.
//

#ifndef BYTECNC_SLAVE_EMERGENCYSTOP_H
#define BYTECNC_SLAVE_EMERGENCYSTOP_H

#include <vector>
#include "commands/Command.h"

    class EmergencyStop : public Command{
        public:
        String execute(std::vector<String> argsIO);

            const char *description() override {
                return "STOP";
            };
    };


#endif //BYTECNC_SLAVE_EMERGENCYSTOP_H
