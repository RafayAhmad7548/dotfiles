#pragma once
class Food{
protected:
    int x;
    int y;
    float *color;
public:

    Food(int x, int y, float *color);
    virtual void draw() = 0;
    virtual void activatePowerup(Paddle& paddle, Ball& ball) = 0;
    void fall();

    int getX();
    int getY();
    ~Food();

};