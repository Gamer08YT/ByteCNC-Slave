//
// Created by Jan Heil on 10.03.2024.
//

#include <ESPTelnet.h>

#ifndef TELNETHANDLER_H
#define TELNETHANDLER_H

namespace handler {

class TelnetHandler {
    public:
        static ESPTelnet telnetIO;

        static void setup();
};

} // handler

#endif //TELNETHANDLER_H
