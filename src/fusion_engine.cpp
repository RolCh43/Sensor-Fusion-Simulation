#include "fusion_engine.hpp"


double FusionEngine::fuseWeightedAverage() const {
    double sumProducts = 0.0;
    double sumWeights = 0.0;

    for (size_t i = 0; i< sensorValues.size(); ++i) {
        sumProducts += sensorValues[i] * weights[i];
        sumWeights += weights[i];
    }
    if (sumWeights == 0.0) {
        throw std::runtime_error("Sum of weights is zero.");
        }
    return sumProducts / sumWeights;
}


double FusionEngine::getSensorValue(size_t index) const {
    if (index>= sensorValues.size()) {
        throw std::out_of_range("Sensor index out of range");

    }
    return sensorValues[index];
}

double FusionEngine::getWeight(size_t index) const{
    if (index >= weights.size()) {
        throw std::out_of_range("Weight index out of range");
    }
    return weights[index];
    
}
