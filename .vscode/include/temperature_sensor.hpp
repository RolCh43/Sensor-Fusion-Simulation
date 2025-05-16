#pragma once
#include "sensor.hpp"
#include <random>

class TemperatureSensor : public Sensor {
    public:
        TemperatureSensor(const std::string& name, int updateRateMs);
        double readValue() override;

    private:
        std::default_random_engine generator;
        std::uniform_real_distribution<double> distribution;
        
};