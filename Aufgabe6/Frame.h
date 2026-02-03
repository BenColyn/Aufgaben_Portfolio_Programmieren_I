#ifndef FRAME_H
#define FRAME_H

namespace car::component {

    class Frame {
    public:
        virtual ~Frame() = default;
        virtual int getWeight() const = 0;
    };

    class CarbonFrame : public Frame {
    public:
        int getWeight() const override { return 1100; }
    };

    class HeavyDutyFrame : public Frame {
    public:
        int getWeight() const override { return 7500; }
    };

}

#endif