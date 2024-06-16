#pragma once
class Food{
protected:
    int x;
    int y;
    const float *color;
public:

    Food(int x, int y, float *color);
    ~Food();


};