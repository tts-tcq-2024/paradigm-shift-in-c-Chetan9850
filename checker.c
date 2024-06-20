
#include <stdio.h>
#include <assert.h>

// Function to check if temperature is within acceptable range
int isTemperatureValid(float temperature) {
    return (temperature >= 0 && temperature <= 45);
}

// Function to check if state of charge (soc) is within acceptable range
int isSocValid(float soc) {
    return (soc >= 20 && soc <= 80);
}

// Function to check if charge rate is within acceptable range
int isChargeRateValid(float chargeRate) {
    return (chargeRate <= 0.8);
}

// Function to check if battery parameters are within acceptable ranges
int batteryIsOk(float temperature, float soc, float chargeRate) {
    if (!isTemperatureValid(temperature)) {
        printf("Temperature out of range!\n");
        return 0;
    }
    if (!isSocValid(soc)) {
        printf("State of Charge out of range!\n");
        return 0;
    }
    if (!isChargeRateValid(chargeRate)) {
        printf("Charge Rate out of range!\n");
        return 0;
    }
    // return 1;
}

// Main function for testing
int main() {
    // Test cases with assertions
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    
    // Additional test cases for edge conditions
    assert(!batteryIsOk(-1, 70, 0.7));  // Temperature too low
    assert(!batteryIsOk(46, 70, 0.7));  // Temperature too high
    assert(!batteryIsOk(25, 15, 0.7));  // Soc too low
    assert(!batteryIsOk(25, 85, 0.7));  // Soc too high
    assert(!batteryIsOk(25, 70, 0.85)); // Charge rate too high
    assert(batteryIsOk(25, 70, 0));     // Charge rate zero is acceptable
    
    printf("All tests passed!\n");
    return 0;
}
