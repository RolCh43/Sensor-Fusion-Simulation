#include <iostream>
#include "fusion_engine.hpp"

int main() {
    std::vector<double> temps = {24.2, 25.0, 24.5};
    std::vector<double> weights = {0.5, 0.3, 0.2};
    
    FusionEngine fusionEngine(temps, weights);
    std::cout << "Fused Temperature: " 
    << fusionEngine.fuseWeightedAverage() 
    << "°C\n ";
    return 0;
}