#include "sensor.hpp"

Sensor::Sensor(const std::string name, int updateRateMs)
    : name(name), updateRateMs(updateRateMs) {}

std::string Sensor::getName() const {
    return name;
}
int Sensor::getUpdateRate() const {
    return updateRateMs;
}
