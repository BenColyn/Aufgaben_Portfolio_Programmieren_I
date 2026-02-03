#ifndef SUSPENSION_H
#define SUSPENSION_H

#include <string>

namespace car::component {

    class Suspension {
    public:
        virtual ~Suspension() = default;
        virtual std::string describe() const = 0;
    };

    class SportSuspension : public Suspension {
    public:
        std::string describe() const override { return "hart und direkt"; }
    };

    class AirSuspension : public Suspension {
    public:
        std::string describe() const override { return "sanft gleitend"; }
    };

}

#endif