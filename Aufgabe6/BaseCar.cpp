#include "BaseCar.h"
#include <cmath>
#include <iomanip>

namespace car {
    float BaseCar::calculateAccelerationBase() const {
        // Physik: (PS * Getriebeübersetzung * Reifen-Grip) / (Gewicht / 100)
        return (engine->getHP() * gears->getRatio() * wheels->getGripFactor()) / (frame->getWeight() / 100.0f);
    }

    void BaseCar::startEngine() {
        engine->start();
        std::cout << "\n[System] Benutzer hat " << engine->getName() << " gestartet.\n";
    }

    void BaseCar::stopEngine() {
        engine->stop();
        currentSpeed = 0;
        std::cout << "[System] " << engine->getName() << " gestoppt.\n";
    }

    // --- SportsCar Implementation ---
    SportsCar::SportsCar() {
        modelName = "Sportwagen";
        engine = std::make_shared<component::V8Engine>();
        wheels = std::make_shared<component::RacingSlicks>();
        brakes = std::make_shared<component::CeramicBrakes>();
        gears = std::make_shared<component::SequentialGears>();
        frame = std::make_shared<component::CarbonFrame>();
        suspension = std::make_shared<component::SportSuspension>();
    }

    void SportsCar::accelerateForward(float t) {
        if (!engine->isRunning()) { std::cout << "-> Motor ist aus!\n"; return; }
        float acc = calculateAccelerationBase();
        currentSpeed += acc * t * 3.6f;
        std::cout << modelName << " fährt los und beschleunigt mit " << std::fixed << std::setprecision(2) << acc << " m/s^2.\n";
        std::cout << "Benutzer stoppt Beschleunigung und hat " << currentSpeed << " km/h.\n";
    }

    void SportsCar::brake() {
        // Bremswegformel: s = v^2 / (2 * a)
        float v_ms = (currentSpeed / 3.6f);
        float deccel = 9.81f * brakes->getBrakeEfficiency();
        float dist = (v_ms * v_ms) / (2 * deccel);
        std::cout << modelName << " bremst, hat " << dist << " Meter zum Stoppen gebraucht.\n";
        currentSpeed = 0;
    }

    void SportsCar::turnLeft() { std::cout << modelName << " lenkt " << suspension->describe() << " nach links.\n"; }
    void SportsCar::turnRight() { std::cout << modelName << " lenkt " << suspension->describe() << " nach rechts.\n"; }
    void SportsCar::accelerateBackward(float t) { std::cout << modelName << " setzt rasant zurück.\n"; }

    // --- HeavyTruck Implementation ---
    HeavyTruck::HeavyTruck() {
        modelName = "Schwerlaster";
        engine = std::make_shared<component::DieselEngine>();
        wheels = std::make_shared<component::AllTerrainWheels>();
        brakes = std::make_shared<component::SteelBrakes>();
        gears = std::make_shared<component::AutomaticGears>();
        frame = std::make_shared<component::HeavyDutyFrame>();
        suspension = std::make_shared<component::AirSuspension>();
    }

    void HeavyTruck::accelerateForward(float t) {
        if (!engine->isRunning()) { std::cout << "-> Motor ist aus!\n"; return; }
        float acc = calculateAccelerationBase();
        currentSpeed += acc * t * 3.6f;
        std::cout << modelName << " quält sich vorwärts und beschleunigt mit " << acc << " m/s^2.\n";
        std::cout << "Benutzer stoppt Beschleunigung und hat " << currentSpeed << " km/h.\n";
    }

    void HeavyTruck::brake() {
        float v_ms = (currentSpeed / 3.6f);
        float deccel = 9.81f * brakes->getBrakeEfficiency(); // Deutlich schlechter beim Truck
        float dist = (v_ms * v_ms) / (2 * deccel);
        std::cout << modelName << " bremst schwerfällig, hat " << dist << " Meter zum Stoppen gebraucht.\n";
        currentSpeed = 0;
    }

    void HeavyTruck::turnLeft() { std::cout << modelName << " neigt sich " << suspension->describe() << " weit nach links.\n"; }
    void HeavyTruck::turnRight() { std::cout << modelName << " neigt sich " << suspension->describe() << " weit nach rechts.\n"; }
    void HeavyTruck::accelerateBackward(float t) { std::cout << "PIEP-PIEP-PIEP! Der LKW setzt zurück.\n"; }
}