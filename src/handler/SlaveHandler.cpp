//
// Created by Jan Heil on 08.03.2024.
//

#include "SlaveHandler.h"
#include "PinHandler.h"

namespace handler {
    static bool emergency;

    /**
     * @brief Check if there is an emergency.
     *
     * This function returns the value of the static member variable `emergency`.
     *
     * @return true if there is an emergency, false otherwise.
     */
    bool SlaveHandler::isEmergency() {
        return emergency;
    }

    /**
     * @brief Set the emergency state.
     *
     * This method sets the value of the static member variable `emergency` in the `SlaveHandler` class. If the `valueIO` parameter is `true`, it also calls the `emergency()` method in the `handler::PinHandler` class to set all pins to emergency fallback state.
     *
     * @param valueIO The value to be set for the emergency state. `true` to activate emergency state, `false` to deactivate emergency state.
     */
    void SlaveHandler::setEmergency(bool valueIO) {
        emergency = valueIO;

        // Set all Pins to Emergency Fallback if true.
        if(valueIO) {
            PinHandler::emergency();
        }
    }
}
