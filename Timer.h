#ifndef TIMER_H
#define TIMER_H

class Timer {
public:
    Timer() {}

    virtual void start() {}
    virtual void stop() {}
    virtual void reset() {}

    virtual float nanoseconds() {}
    virtual float miliseconds() {}
    virtual float seconds() {}

};

#endif