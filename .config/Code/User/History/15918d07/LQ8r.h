#pragma once
class Food{
protected:
    int x;
    int y;
    float *color;
public:

    Food(int x, int y, float *color);
    void fall();
    ~Food();


};