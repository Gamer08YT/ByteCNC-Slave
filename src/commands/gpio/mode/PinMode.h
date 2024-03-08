//
// Created by Jan Heil on 08.03.2024.
//

#ifndef BYTECNC_SLAVE_PINMODE_H
#define BYTECNC_SLAVE_PINMODE_H

#include <vector>
#include "commands/Command.h"

namespace commands {

    class PinMode : public Command {
    public:
        char *execute(std::vector<char *> argsIO) override;

    private:
        const char *description() override;
    };

} // commands

#endif //BYTECNC_SLAVE_PINMODE_H
