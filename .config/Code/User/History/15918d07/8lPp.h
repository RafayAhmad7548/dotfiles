#pragma once
#include "Paddle.h"
#include "Ball.h"

class Food{
protected:
    int x;
    int y;
    float *color;
    static int counter;
    static bool powerActive;
public:

    Food(int x, int y, float *color);
    virtual void draw() = 0;
    virtual void activatePowerup(Paddle& paddle, Ball**& balls) = 0;
    void fall();

    int getX();
    int getY();
    static int getCounter();
    static bool getPowerActive();

    static void count();
    static void resetPowerup(Paddle& paddle, Ball**& balls);
    ~Food();

};