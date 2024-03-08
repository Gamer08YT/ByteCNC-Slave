//
// Created by Jan Heil on 08.03.2024.
//

#include "EmergencyConfig.h"

namespace commands {
    /**
     * @file
     * @brief Contains the definition of the EmergencyConfig class and its member functions.
     */
    char *EmergencyConfig::execute(std::vector<char *> argsIO) {
        const char* pinIO = argsIO[0];
        int valueIO = reinterpret_cast<int>(argsIO[1]);

        return nullptr;
    }

    const char *EmergencyConfig::description() {
        return "CONFIG <IO> <0-1, 0-255>";
    }
} // commands