//
// Created by Jan Heil on 08.03.2024.
//

#ifndef BYTECNC_SLAVE_READANALOG_H
#define BYTECNC_SLAVE_READANALOG_H

#include <vector>
#include "commands/Command.h"

namespace commands {
    /**
     * @class ReadAnalog
     * @brief The ReadAnalog class is a subclass of the Command class.
     *
     * The ReadAnalog class is responsible for executing the ReadAnalog command, which stops all relays and stepper motors.
     */
    class ReadAnalog : public Command {
        public:
            char * execute(std::vector<char *> argsIO) override;

        private:
            const char *description() override;
    };
};


#endif //BYTECNC_SLAVE_READANALOG_H
