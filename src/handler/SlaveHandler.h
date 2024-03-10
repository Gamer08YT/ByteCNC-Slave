//
// Created by Jan Heil on 08.03.2024.
//

#ifndef BYTECNC_SLAVE_SLAVEHANDLER_H
#define BYTECNC_SLAVE_SLAVEHANDLER_H

namespace handler {
    class SlaveHandler {

    public:
        static bool isEmergency();
        static void setEmergency(bool emergency);
    };
}


#endif //BYTECNC_SLAVE_SLAVEHANDLER_H
