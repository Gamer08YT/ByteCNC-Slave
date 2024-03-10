//
// Created by Jan Heil on 08.03.2024.
//

#include "CommandHandler.h"
#include "commands/gpio/read/ReadAnalog.h"
#include "commands/gpio/read/ReadDigital.h"
#include "commands/gpio/write/WriteAnalog.h"
#include "commands/gpio/write/WriteDigital.h"
#include "commands/gpio/mode/PinMode.h"
#include "commands/emergency/EmergencyStop.h"
#include "commands/emergency/Unlock.h"
#include "commands/emergency/EmergencyConfig.h"
#include "commands/help/HelpCommand.h"
#include <iterator>
#include <map>
#include <vector>


namespace handler {
    std::map<String, Command*> CommandHandler::commands;

    /**
     * @brief CommandHandler class responsible for managing commands.
     *
     * The CommandHandler class is used to add and manage commands in a map.
     * It stores registered commands in an unordered map, with the command's invokeIO as the key and the commandIO pointer as the value.
     */
    void CommandHandler::addCommand(String invokeIO, Command *commandIO) {
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
    String CommandHandler::execute(String dataIO) {
        // Split via Spaces.
        std::vector<String> results = split(dataIO, " ");

        String invokeIO = results[0];

        // Check if Command exits.
        if(!results.empty() && commands[invokeIO] != nullptr) {
            // Remove first Item.
            results.erase(results.begin());

            // Execute Command.
            return commands[invokeIO]->execute(results);
        }

        // rest of your code
        return "";
    }

    /**
     * @brief CommandHandler class responsible for managing commands.
     *
     * The CommandHandler class is used to add default commands in a map.
     * It stores registered commands in an unordered map, with the command's invokeIO as the key and the commandIO pointer as the value.
     */
    void CommandHandler::addDefaults() {
        // Clear old Commands.
        commands.clear();

        // Add Emergency Features.
        addCommand("STOP", new EmergencyStop());
        addCommand("UNLOCK", new Unlock());
        addCommand("CONFIG", new EmergencyConfig());

        // Add Help Features.
        addCommand("HELP", new HelpCommand());

        // Add Arduino Vanilla Features.
        addCommand("MODE", new PinMode());

        // Add Default Read Handler.
        addCommand("RA", new ReadAnalog());
        addCommand("RD", new ReadDigital());

        // Add Default Write Handler.
        addCommand("WA", new WriteAnalog());
        addCommand("WD", new WriteDigital());
    }


    /**
     * @brief Splits a given string into a vector of substrings based on a delimiter.
     *
     * The split method takes a reference to a string and a delimiter as input.
     * It splits the string into multiple substrings using the specified delimiter and stores them in a vector.
     * The resulting vector is returned.
     *
     * @param valueIO The string to be split.
     * @param delimiterIO The delimiter to use for splitting the string.
     * @return A vector of substrings obtained after splitting the string.
     */
    std::vector<String> CommandHandler::split(String &valueIO, const char *delimiterIO) {
        std::vector<String> returnIO;
        int indexIO = 0;
        while (true) {
            int positionIO = valueIO.indexOf(delimiterIO, indexIO);
            if (positionIO == -1) {
                returnIO.push_back(valueIO.substring(indexIO));
                break;
            } else {
                returnIO.push_back(valueIO.substring(indexIO, positionIO));
                indexIO = positionIO + strlen(delimiterIO);
            }
        }

        return returnIO;
    }
} // handler