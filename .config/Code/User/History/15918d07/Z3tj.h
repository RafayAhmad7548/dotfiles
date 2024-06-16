#pragma once
class Food{
protected:
    int x;
    int y;
    float *color;
public:

    Food(int x, int y, float *color);
    virtual void draw() = 0;
    void fall();
    void activatePowerup() = 0;

    int getX();
    int getY();
    ~Food();

};