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

// Function to calculate abnormal measure based on inputs
float calculateAbnormalMeasure(float temperature, float soc, float chargeRate) {
    // Example calculation (you may adjust based on specific requirements)
    float abnormal_measure = 0.0;
    if (temperature < 0 || temperature > 45) {
        abnormal_measure += 1.0; // Example weight for temperature out of range
    }
    if (soc < 20 || soc > 80) {
        abnormal_measure += 0.5; // Example weight for soc out of range
    }
    if (chargeRate > 0.8) {
        abnormal_measure += 0.8; // Example weight for charge rate out of range
    }
    return abnormal_measure;
}

// Function to detect breach based on abnormal measure and thresholds
int detectBreach(float abnormal_measure, float high_threshold, float low_threshold) {
    if (abnormal_measure > high_threshold) {
        printf("High breach detected!\n");
        return 1;
    } else if (abnormal_measure < -low_threshold) {
        printf("Low breach detected!\n");
        return -1;
    }
    return 0;
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
    
    // Calculate abnormal measure
    float abnormal_measure = calculateAbnormalMeasure(temperature, soc, chargeRate);
    
    // Detect breaches
    int breach_status = detectBreach(abnormal_measure, 1.5, 0.5); // Example thresholds
    
    if (breach_status == 1 || breach_status == -1) {
        // Take effective action based on breach status
        // Example: send alert, log data, etc.
        printf("Action taken for breach.\n");
    }
    
    return 1;
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

