#include <stdio.h>
#include <assert.h>

int isOutOfRange(float value, float lower_limit, float upper_limit, const char *parameter_name) {
    if (value < lower_limit || value > upper_limit) {
        printf("%s out of range!\n", parameter_name);
        return 1;
    }
    return 0;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    int temperatureOutOfRange = isOutOfRange(temperature, 0, 45, "Temperature");
    int socOutOfRange = isOutOfRange(soc, 20, 80, "State of Charge");
    int chargeRateOutOfRange = isOutOfRange(chargeRate, 0, 0.8, "Charge Rate");

    return !(temperatureOutOfRange || socOutOfRange || chargeRateOutOfRange);
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
}
