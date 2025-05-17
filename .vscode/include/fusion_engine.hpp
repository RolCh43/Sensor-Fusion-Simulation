#pragma once
#include "sensor.hpp" 
#include <vector>
#include <stdexcept>

class FusionEngine {

    public:
       FusionEngine(const std::vector<double>& sensorValues,
                     const std::vector<double>& weights)
                    : sensorValues(sensorValues),
                    weights(weights) {
                        if (sensorValues.size() != weights.size()) {
                            throw std::invalid_argument("Sensor values and weights must have the same size");
                                        }
                                     }
       

        double fuseWeightedAverage() const;
    
        double getSensorValue(size_t index) const;

        double getWeight(size_t index) const;


    private:
        std::vector<double> sensorValues;
        std::vector<double> weights;
};
 