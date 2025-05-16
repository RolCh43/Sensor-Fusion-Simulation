#pragma once
#include <string>


class Sensor {
    public:
        Sensor( const std::string name, int updateRateMs);
        virtual ~Sensor() = default;

        virtual double readValue() = 0;
        std::string getName() const;
        int getUpdateRate() const;

    protected:
        std::string name;
        int updateRateMs;

};