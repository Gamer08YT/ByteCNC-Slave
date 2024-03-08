//
// Created by Jan Heil on 08.03.2024.
//

#ifndef BYTECNC_SLAVE_M410_H
#define BYTECNC_SLAVE_M410_H

#include <vector>
#include "Command.h"

namespace commands {
    class M410 : public Command{
    public:
        bool execute(std::vector<char *> argsIO) override;

    private:
        const char *description() override;
    };
};


#endif //BYTECNC_SLAVE_M410_H
