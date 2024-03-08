//
// Created by Jan Heil on 08.03.2024.
//

#include "SlaveHandler.h"

namespace handler {
    bool SlaveHandler::isEmergency() {
        return SlaveHandler::emergency;
    }

    void SlaveHandler::setEmergency(bool valueIO) {
        SlaveHandler::emergency = valueIO;
    }
}
