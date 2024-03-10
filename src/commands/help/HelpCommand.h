//
// Created by Jan Heil on 10.03.2024.
//

#ifndef HELPCOMMAND_H
#define HELPCOMMAND_H


#include "commands/Command.h"

class HelpCommand : public Command{
public:
    String execute(std::vector<String> argsIO);

    const char *description() override {
        return "HELP";
    };
};



#endif //HELPCOMMAND_H
