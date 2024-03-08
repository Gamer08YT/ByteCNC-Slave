//
// Created by Jan Heil on 08.03.2024.
//

#ifndef BYTECNC_SLAVE_WRITEANALOG_H
#define BYTECNC_SLAVE_WRITEANALOG_H

#include <vector>
#include "commands/Command.h"

namespace commands {

    /**
     * @class WriteAnalog
     * @brief A class for writing analog values.
     *
     * This class inherits from the Command class and provides the functionality to write analog values.
     */
    class WriteAnalog : public Command{
        public:
            char * execute(std::vector<char *> argsIO) override;

        private:
            const char *description() override;
    };

} // commands

#endif //BYTECNC_SLAVE_WRITEANALOG_H
