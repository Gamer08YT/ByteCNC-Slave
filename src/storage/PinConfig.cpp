//
// Created by Jan Heil on 08.03.2024.
//

#include "PinConfig.h"

namespace storage {

    bool PinConfig::isAnalog() const {
        return isAnalogMode;
    }

    void PinConfig::setIsAnalog(bool analogMode) {
        PinConfig::isAnalogMode = analogMode;
    }

    int PinConfig::getAnalogFallback() const {
        return analogFallback;
    }

    void PinConfig::setAnalogFallback(int analogFallbackValue) {
        PinConfig::analogFallback = analogFallbackValue;
    }

    int PinConfig::getDigitalFallback() const {
        return digitalFallback;
    }

    void PinConfig::setDigitalFallback(int digitalFallbackValue) {
        PinConfig::digitalFallback = digitalFallbackValue;
    }
}