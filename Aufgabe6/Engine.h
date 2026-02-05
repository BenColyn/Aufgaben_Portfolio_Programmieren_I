//
// Created by benco on 05.02.2026.
//

#ifndef TESTPROJEKT_ENGINE_H
#define TESTPROJEKT_ENGINE_H
#include <string>

namespace car:: component {
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
};


#endif //TESTPROJEKT_ENGINE_H
