#include <iostream>
#include <thread>
#include "../include/sensor_manager.hpp"
#include "../include/temperature_sensor.hpp"

int main() {
    SensorManager sensor_manager;
    sensor_manager.addSensor(std::make_unique<TemperatureSensor>("T1", 1000), 0.5);
    sensor_manager.addSensor(std::make_unique<TemperatureSensor>("T2", 1000), 0.3);
    sensor_manager.addSensor(std::make_unique<TemperatureSensor>("T3", 1000), 0.2);

    sensor_manager.start();

    for (int i = 0; i < 100; ++i) {
        std::cout << "Fused: " << sensor_manager.fusedWeightedAverage() << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    sensor_manager.stop();
}