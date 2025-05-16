#include <iostream>
#include "temperature_sensor.hpp"

int main() {
    TemperatureSensor tempSensor("TempSensor1", 1000);

    for (int i = 0; i < 5; ++i) {
        std::cout << tempSensor.getName() << ": "
                  << tempSensor.readValue() << " °C" << std::endl;
    }

    return 0;
}