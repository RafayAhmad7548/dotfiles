#include "Ball.h"

class Brick{

    const int width = 65;
    const int height = 18;
    int x;
    int y;

    int strength;
    float *color;

public:

    Brick(float *color);

    void draw(int row, int col);

    void checkCollision(Ball& ball);

};