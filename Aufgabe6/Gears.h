#ifndef GEARS_H
#define GEARS_H

namespace car::component {

    class Gears {
    public:
        virtual ~Gears() = default;
        virtual float getRatio() const = 0;
    };

    class SequentialGears : public Gears {
    public:
        float getRatio() const override { return 1.3f; }
    };

    class AutomaticGears : public Gears {
    public:
        float getRatio() const override { return 0.7f; }
    };

}

#endif

#