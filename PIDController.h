#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

#include "Timer.h"

class PIDController {
private:
    Timer* timer;
    bool started;

    float pCoeff;
    float iCoeff;
    float dCoeff;

    float integral;

    float (*valueSupplier)();
    float lastValue;
    float target;

public:

    PIDController() {
        this->timer = nullptr;
        this->started = false;

        this->pCoeff = 1.0;
        this->iCoeff = 0.0;
        this->dCoeff = 0.0;

        this->integral = 0.0;

        this->valueSupplier = nullptr;
        this->lastValue = 0.0;
        this->target = 0.0;
    }

    PIDController(Timer* timer = nullptr, float pCoeff = 1.0, float iCoeff = 0.0, float dCoeff = 0.0, float (*valueSupplier)() = nullptr, float target = 0.0) {
        this->timer = timer;
        this->started = false;

        this->pCoeff = pCoeff;
        this->iCoeff = iCoeff;
        this->dCoeff = dCoeff;

        this->integral = 0.0;

        this->valueSupplier = valueSupplier;
        this->lastValue = 0.0;
        this->target = target;
    }

    ~PIDController() {}

    void start() {
        if (this->valueSupplier != nullptr) {
            this->started = true;
            this->lastValue = this->valueSupplier();
            this->timer->start();
        }
    }
};

#endif