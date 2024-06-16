#include "Ball.h"

class Brick{

    const int width = 65;
    const int height = 18;
    int x;
    int y;

    int strength;
    float *color;

public:

    Brick(float *color, int strength);

    void draw(int row, int col);

    bool checkCollision(Ball& ball);

};