//
// Created by Jan Heil on 08.03.2024.
//

#ifndef BYTECNC_SLAVE_PINHANDLER_H
#define BYTECNC_SLAVE_PINHANDLER_H

#include <unordered_map>
#include "storage/PinConfig.h"

namespace handler {

    class PinHandler {
        public:
            static const std::unordered_map<uint8_t, storage::PinConfig *> &getPins();

            static void addPin(uint8_t pinIO, storage::PinConfig* commandIO);

            static void emergency();
    };

} // handler

#endif //BYTECNC_SLAVE_PINHANDLER_H
