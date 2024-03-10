//
// Created by Jan Heil on 08.03.2024.
//

#ifndef BYTECNC_SLAVE_COMMANDHANDLER_H
#define BYTECNC_SLAVE_COMMANDHANDLER_H

#include <map>
#include <unordered_map>
#include <commands/Command.h>

namespace handler {

    class CommandHandler {
        public:
            // Execute given Command.
            static String execute(String dataIO);

            static std::map<String, Command*> commands;

            // Add Command to Map.
            static void addCommand(String invokeIO, Command *commandIO);

            static void addDefaults();

            static std::vector<String> split(String&valueIO, const char* delimiterIO);
    };

} // handler

#endif //BYTECNC_SLAVE_COMMANDHANDLER_H
