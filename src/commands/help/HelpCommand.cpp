//
// Created by Jan Heil on 10.03.2024.
//

#include "HelpCommand.h"
#include "handler/CommandHandler.h"

String HelpCommand::execute(std::vector<String> argsIO) {
    String bufferIO = "";

    // Loop trough Command Map.
    for (const auto &pair: handler::CommandHandler::commands) {

        // Check if Command is not this Command.
        if(pair.first != "HELP") {
            bufferIO += (pair.first + " -> (" + pair.second->description() + ")");
        }
    }

    return bufferIO;
}
