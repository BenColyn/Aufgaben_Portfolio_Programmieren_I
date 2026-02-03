
#ifndef BRAKES_H
#define BRAKES_H

namespace car::component {

    class Brakes {
    public:
        virtual ~Brakes() = default;
        virtual float getBrakeEfficiency() const = 0;
    };

    class CeramicBrakes : public Brakes {
    public:
        float getBrakeEfficiency() const override { return 1.5f; }
    };

    class SteelBrakes : public Brakes {
    public:
        float getBrakeEfficiency() const override { return 0.8f; }
    };

}

#endif


