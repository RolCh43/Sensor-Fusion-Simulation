#include "../include/sensor_manager.hpp"
#include <chrono>
#include <stdexcept>

void SensorManager::addSensor(std::unique_ptr<Sensor> sensor, double weight){
    if(running.load()) {
        throw std::runtime_error("Cannot add sensor while manager is running");
    }
    sensors.push_back(std::move(sensor));
    readings.push_back(0.0); // Initialize reading
    weights.push_back(weight);
}
void SensorManager::start() {
    if (running.exchange(true)) return; // Already running
    threads.reserve(sensors.size());
    for (size_t i =0; i < sensors.size(); ++i) {
        threads.emplace_back(&SensorManager::sensorLoop, this, i);
    }
}

void SensorManager::stop(){
    if (!running.exchange(false)) return; // Not running
    for (auto& thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
    threads.clear();
}

void SensorManager::sensorLoop(size_t idx) {
    using namespace std::chrono;
    auto* s = sensors[idx].get();
    const auto period = milliseconds(s->getUpdateRate());
    auto next = steady_clock::now();

    while (running.load()) {
        double v = s->readValue();
        {
            std::lock_guard<std::mutex> lock(mtx);
            readings[idx] = v;
        }
        next += period;
        std::this_thread::sleep_until(next); 
    }
}

std::vector<double> SensorManager::getReadings() const {
    std::lock_guard<std::mutex> lock(mtx);
    return readings; 
}

std::vector<double> SensorManager::getWeights() const {
    std::lock_guard<std::mutex> lock(mtx);
    return weights;
}

double SensorManager::fusedWeightedAverage() const {
    auto vals = getReadings();
    auto w    = getWeights();
    FusionEngine engine(vals, w);
    return engine.fuseWeightedAverage();
}

