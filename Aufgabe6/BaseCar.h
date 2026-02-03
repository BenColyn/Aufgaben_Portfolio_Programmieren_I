#ifndef BASECAR_H
#define BASECAR_H
#include "Component.h"
#include <memory>
#include <iostream>
#include "Brakes.h"
#include "Gears.h"
#include "Wheels.h"
#include "Frame.h"
#include "Suspension.h"
namespace car {
    class BaseCar {
    protected:
        std::string modelName;
        float currentSpeed = 0.0f;
        std::shared_ptr<component::Engine> engine;
        std::shared_ptr<component::Wheels> wheels;
        std::shared_ptr<component::Brakes> brakes;
        std::shared_ptr<component::Gears> gears;
        std::shared_ptr<component::Frame> frame;
        std::shared_ptr<component::Suspension> suspension;

        float calculateAccelerationBase() const;

    public:
        virtual ~BaseCar() = default;
        void startEngine();
        void stopEngine();
        virtual void accelerateForward(float t) = 0;
        virtual void accelerateBackward(float t) = 0;
        virtual void brake() = 0;
        virtual void turnLeft() = 0;
        virtual void turnRight() = 0;

        std::string getModelName() const { return modelName; }
    };

    class SportsCar : public BaseCar {
    public:
        SportsCar();
        void accelerateForward(float t) override;
        void accelerateBackward(float t) override;
        void brake() override;
        void turnLeft() override;
        void turnRight() override;
    };

    class HeavyTruck : public BaseCar {
    public:
        HeavyTruck();
        void accelerateForward(float t) override;
        void accelerateBackward(float t) override;
        void brake() override;
        void turnLeft() override;
        void turnRight() override;
    };
}
#endif