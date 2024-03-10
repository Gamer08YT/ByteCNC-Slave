//
// Created by Jan Heil on 08.03.2024.
//

#include <Arduino.h>
#include "PinHandler.h"

namespace handler {
    // Store registered Pins in Map.
    static std::unordered_map<uint8_t, storage::PinConfig*> pins;

    /**
     * @brief PinHandler class for managing pins.
     *
     * This class provides functions for managing pins, including getting the registered pins.
     */
    const std::unordered_map<uint8_t, storage::PinConfig *> &PinHandler::getPins() {
        return pins;
    }

    /**
     * @brief Add a pin and its corresponding configuration to the PinHandler.
     *
     * This function adds a pin and its corresponding configuration to the PinHandler's internal storage.
     *
     * @param pinIO A pointer to the pin number (GPIO) to be added.
     * @param commandIO A pointer to the PinConfig object containing the configuration of the pin.
     */
    void PinHandler::addPin(uint8_t pinIO, storage::PinConfig *commandIO) {
        pins[pinIO] = commandIO;
    }


    /**
     * @brief Sets the states of registered pins to their default values in case of an emergency.
     *
     * This function loops through the registered pins and sets their states accordingly. If a pin is configured to be in digital mode,
     * the function sets its state to the digital fallback value. If a pin is configured to be in analog mode, the function sets its state to
     * either HIGH or LOW based on the analog fallback value.
     */
    void PinHandler::emergency() {
        // Loop trough Pins and set States.
        for(std::pair<uint8_t const, storage::PinConfig *> pinIO : pins) {
            uint8_t keyIO = pinIO.first;
            storage::PinConfig* configIO = pinIO.second;

            // Set Default Analog or Digital Value.
            if(!configIO->isAnalog()) {
                digitalWrite(keyIO, configIO->getDigitalFallback());
            } else {
                analogWrite(keyIO, (configIO->getAnalogFallback() == 1 ? HIGH : LOW));
            }
        }
    }

} // handler