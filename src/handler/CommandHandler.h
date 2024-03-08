//
// Created by Jan Heil on 08.03.2024.
//

#ifndef BYTECNC_SLAVE_COMMANDHANDLER_H
#define BYTECNC_SLAVE_COMMANDHANDLER_H

#include <unordered_map>
#include <commands/Command.h>

namespace handler {

    class CommandHandler {
        // Store registered Commands in Map.
        static std::unordered_map<char*, commands::Command*> commands;

        public:
            // Execute given Command.
            static bool execute(char *dataIO);

            // Add Command to Map.
            static void addCommand(char *invokeIO, commands::Command *commandIO);
    };

} // handler

#endif //BYTECNC_SLAVE_COMMANDHANDLER_H
