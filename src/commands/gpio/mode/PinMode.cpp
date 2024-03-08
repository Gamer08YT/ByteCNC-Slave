//
// Created by Jan Heil on 08.03.2024.
//

#include "PinMode.h"

namespace commands {
    char *PinMode::execute(std::vector<char *> argsIO) {
        return Command::execute(argsIO);
    }

    const char *PinMode::description() {
        return "MODE <IO> <ANALOG/DIGITAL>";
    }
} // commands