//
// Created by Jan Heil on 08.03.2024.
//

#include "CommandHandler.h"
#include "commands/read/ReadAnalog.h"
#include "commands/read/ReadDigital.h"
#include "commands/write/WriteAnalog.h"
#include "commands/write/WriteDigital.h"
#include <sstream>
#include <iterator>
#include <vector>


namespace handler {
    /**
     * @brief CommandHandler class responsible for managing commands.
     *
     * The CommandHandler class is used to add and manage commands in a map.
     * It stores registered commands in an unordered map, with the command's invokeIO as the key and the commandIO pointer as the value.
     */
    void CommandHandler::addCommand(char *invokeIO, commands::Command *commandIO) {
        commands[invokeIO] = commandIO;
    }

    /**
     * @brief Executes a command by parsing the input data and executing the corresponding command.
     *
     * This function takes a null-terminated string of input data and parses it into individual tokens.
     * It checks if the first token is a valid command, and if so, removes it from the list of tokens.
     * Finally, it executes the command associated with the first token (if any) passing the remaining tokens.
     *
     * @param dataIO A null-terminated string containing the input data.
     * @return `true` if the command was executed successfully, `false` otherwise.
     */
    bool CommandHandler::execute(char *dataIO) {
        std::istringstream iss(dataIO);
        std::vector<char*> results((std::istream_iterator<char*>(iss)),
                                         std::istream_iterator<char*>());

        // Check if Command exits.
        if(!results.empty() && commands[results[0]] != nullptr) {
            // Remove first Item.
            results.erase(results.begin());

            // Execute Command.
            return commands[results[0]]->execute(results);
        }

        // rest of your code
        return false;
    }

    /**
     * @brief CommandHandler class responsible for managing commands.
     *
     * The CommandHandler class is used to add default commands in a map.
     * It stores registered commands in an unordered map, with the command's invokeIO as the key and the commandIO pointer as the value.
     */
    void CommandHandler::addDefaults() {
        // Add Default Read Handler.
        addCommand("RA", new commands::ReadAnalog);
        addCommand("RD", new commands::ReadDigital);

        // Add Default Write Handler.
        addCommand("WA", new commands::WriteAnalog);
        addCommand("WD", new commands::WriteDigital);
    }

} // handler