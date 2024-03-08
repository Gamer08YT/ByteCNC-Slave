//
// Created by Jan Heil on 08.03.2024.
//

#include "SlaveHandler.h"
#include "PinHandler.h"

namespace handler {
    /**
     * @brief Check if there is an emergency.
     *
     * This function returns the value of the static member variable `emergency`.
     *
     * @return true if there is an emergency, false otherwise.
     */
    bool SlaveHandler::isEmergency() {
        return SlaveHandler::emergency;
    }

    /**
     * @brief Set the emergency flag value for the SlaveHandler.
     *
     * This function sets the value of the emergency flag in the SlaveHandler class.
     *
     * @param valueIO The new value for the emergency flag.
     *
     * @details
     * The emergency flag is a static member variable of the SlaveHandler class.
     * It indicates whether the system is in an emergency state or not.
     *
     * If the valueIO is true, the emergency flag will be set to true.
     * In addition, the emergency state will be propagated to all pins.
     *
     * @note
     * This function should be called whenever an emergency condition is detected or resolved.
     *
     * @see SlaveHandler::emergency
     * @see handler::PinHandler::emergency()
     * @see SlaveHandler::isEmergency()
     */
    void SlaveHandler::setEmergency(bool valueIO) {
        SlaveHandler::emergency = valueIO;

        // Set all Pins to Emergency Fallback if true.
        if(valueIO) {
            handler::PinHandler::emergency();
        }
    }
}
