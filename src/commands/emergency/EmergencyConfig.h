//
// Created by Jan Heil on 08.03.2024.
//

#ifndef BYTECNC_SLAVE_EMERGENCYCONFIG_H
#define BYTECNC_SLAVE_EMERGENCYCONFIG_H

#include <vector>
#include "commands/Command.h"

    class EmergencyConfig : public Command {
        public:
        String execute(std::vector<String> argsIO);

            const char *description() {
                return "CONFIG <IO> <0-1, 0-255>";
            };
    };

#endif //BYTECNC_SLAVE_EMERGENCYCONFIG_H
