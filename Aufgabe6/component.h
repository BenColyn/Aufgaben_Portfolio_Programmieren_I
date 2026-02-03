#ifndef COMPONENT_H
#define COMPONENT_H
#include <string>

namespace car::component {
    // Engine
    class Engine {
    public:
        virtual ~Engine() = default;
        virtual int getHP() const = 0;
        virtual std::string getName() const = 0;
        void start() { running = true; }
        void stop() { running = false; }
        bool isRunning() const { return running; }
    protected:
        bool running = false;
    };
    class V8Engine : public Engine {
    public:
        int getHP() const override { return 580; }
        std::string getName() const override { return "V8-Aggregat"; }
    };
    class DieselEngine : public Engine {
    public:
        int getHP() const override { return 320; }
        std::string getName() const override { return "Reihen-6-Zylinder Diesel"; }
    };

    // Brakes, Wheels, Gears, Frame, Suspension
    class Brakes { public: virtual float getBrakeEfficiency() const = 0; virtual ~Brakes() = default; };
    class CeramicBrakes : public Brakes { float getBrakeEfficiency() const override { return 1.5f; } };
    class SteelBrakes : public Brakes { float getBrakeEfficiency() const override { return 0.8f; } };

    class Wheels { public: virtual float getGripFactor() const = 0; virtual ~Wheels() = default; };
    class RacingSlicks : public Wheels { float getGripFactor() const override { return 1.4f; } };
    class AllTerrainWheels : public Wheels { float getGripFactor() const override { return 0.9f; } };

    class Gears { public: virtual float getRatio() const = 0; virtual ~Gears() = default; };
    class SequentialGears : public Gears { float getRatio() const override { return 1.3f; } };
    class AutomaticGears : public Gears { float getRatio() const override { return 0.7f; } };

    class Frame { public: virtual int getWeight() const = 0; virtual ~Frame() = default; };
    class CarbonFrame : public Frame { int getWeight() const override { return 1100; } };
    class HeavyDutyFrame : public Frame { int getWeight() const override { return 7500; } };

    class Suspension { public: virtual std::string describe() const = 0; virtual ~Suspension() = default; };
    class SportSuspension : public Suspension { std::string describe() const override { return "hart und direkt"; } };
    class AirSuspension : public Suspension { std::string describe() const override { return "sanft gleitend"; } };
}
#endif