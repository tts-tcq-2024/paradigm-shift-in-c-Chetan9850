#include <stdio.h>
#include <assert.h>

// Function to check if a parameter is out of range
int isOutOfRange(float value, float lower_limit, float upper_limit, const char *parameter_name) {
    if (value < lower_limit || value > upper_limit) {
        printf("%s out of range!\n", parameter_name);
        return 1;
    }
    return 0;
}

// Function to check if temperature is out of range
int isTemperatureOutOfRange(float temperature) {
    return isOutOfRange(temperature, 0, 45, "Temperature");
}

// Function to check if state of charge is out of range
int isSocOutOfRange(float soc) {
    return isOutOfRange(soc, 20, 80, "State of Charge");
}

// Function to check if charge rate is out of range
int isChargeRateOutOfRange(float chargeRate) {
    return isOutOfRange(chargeRate, 0, 0.8, "Charge Rate");
}

// Function to check if battery parameters are within acceptable ranges
int batteryIsOk(float temperature, float soc, float chargeRate) {
    if (isTemperatureOutOfRange(temperature) ||
        isSocOutOfRange(soc) ||
        isChargeRateOutOfRange(chargeRate)) {
        return 0;
    }
    return 1;
}

// Tests covering all conditions
void runTests() {
    // Normal cases
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));

    // Edge cases for temperature
    assert(!batteryIsOk(-1, 70, 0.7));  // Below lower limit
    assert(!batteryIsOk(46, 70, 0.7));  // Above upper limit

    // Edge cases for state of charge
    assert(!batteryIsOk(25, 19, 0.7));  // Below lower limit
    assert(!batteryIsOk(25, 81, 0.7));  // Above upper limit

    // Edge cases for charge rate
    assert(!batteryIsOk(25, 70, -0.1)); // Below lower limit
    assert(!batteryIsOk(25, 70, 0.81)); // Above upper limit

    printf("All tests passed!\n");
}

int main() {
    runTests();
    return 0;
}
