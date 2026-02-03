

#ifndef WHEELS_H
#define WHEELS_H

namespace car::component {

    class Wheels {
    public:
        virtual ~Wheels() = default;
        virtual float getGripFactor() const = 0;
    };

    class RacingSlicks : public Wheels {
    public:
        float getGripFactor() const override { return 1.4f; }
    };

    class AllTerrainWheels : public Wheels {
    public:
        float getGripFactor() const override { return 0.9f; }
    };

}

#endif


