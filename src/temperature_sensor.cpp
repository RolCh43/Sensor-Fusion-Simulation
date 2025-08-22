#include "../include/temperature_sensor.hpp"
#include <chrono>

TemperatureSensor::TemperatureSensor(const std::string& name, int updateRateMs)
    : Sensor(name, updateRateMs), distribution(20.0, 25.0) {
    
    generator.seed(std::chrono::system_clock::now().time_since_epoch().count());
}

double TemperatureSensor::readValue() {
    return distribution(generator);
}