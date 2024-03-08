//
// Created by Jan Heil on 08.03.2024.
//

#ifndef BYTECNC_SLAVE_PINCONFIG_H
#define BYTECNC_SLAVE_PINCONFIG_H


#include <cstdint>

namespace storage {
    class PinConfig {
        private:
            // Pin Mode (Analog/Digital).
            bool isAnalogMode = false;

            // Analog Value on Emergency Stop.
            uint8_t analogFallback = 0;

            // Digital Value on Emergency Stop.
            uint8_t digitalFallback = 0;
    public:
        bool isAnalog() const;

        void setIsAnalog(bool isAnalog);

        int getAnalogFallback() const;

        void setAnalogFallback(int analogFallback);

        int getDigitalFallback() const;

        void setDigitalFallback(int digitalFallback);
    };
};


#endif //BYTECNC_SLAVE_PINCONFIG_H
