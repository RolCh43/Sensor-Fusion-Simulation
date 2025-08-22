#pragma once
#include <memory>
#include <vector>
#include <thread>
#include <mutex>
#include <atomic>
#include "sensor.hpp"
#include "fusion_engine.hpp"

class SensorManager {
    public:
        ~SensorManager() { stop();}
            
        void addSensor(std::unique_ptr<Sensor> sensor, double weight);
        void start();
        void stop();

        //Secure access to readings and weights
        std::vector<double> getReadings() const;
        std::vector<double> getWeights() const;

        double fusedWeightedAverage() const;
        
    private:
        void sensorLoop(size_t idx);

        std::vector<std::unique_ptr<Sensor>> sensors;
        std::vector<double> readings;
        std::vector<double> weights;

        mutable std::mutex mtx;
        std::vector<std::thread> threads;
        std::atomic<bool> running{false};
};