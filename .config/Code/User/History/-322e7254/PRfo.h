#include "Ball.h"
#include "Food.cpp"

class Brick{

    const int width = 70;
    const int height = 20;
    int x;
    int y;

    int strength;
    float *color;

    Food *food;

public:

    Brick();

    void draw(int row, int col);
    bool checkCollision(Ball& ball);

    ~Brick();

};