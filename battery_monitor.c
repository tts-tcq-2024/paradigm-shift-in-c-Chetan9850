#include "battery_monitor.h"
#include <stdio.h>

int isTemperatureOutOfRange(float temperature) {
    if (temperature < 0 || temperature > 45) {
        printf("Temperature out of range!\n");
        return 1;
    }
    return 0;
}

int isSocOutOfRange(float soc) {
    if (soc < 20 || soc > 80) {
        printf("State of Charge out of range!\n");
        return 1;
    }
    return 0;
}

int isChargeRateOutOfRange(float chargeRate) {
    if (chargeRate > 0.8) {
        printf("Charge Rate out of range!\n");
        return 1;
    }
    return 0;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    int temperatureOutOfRange = isTemperatureOutOfRange(temperature);
    int socOutOfRange = isSocOutOfRange(soc);
    int chargeRateOutOfRange = isChargeRateOutOfRange(chargeRate);

    return !(temperatureOutOfRange || socOutOfRange || chargeRateOutOfRange);
}
