#include "Ball.h"
#include "Food.h"

class Brick{

    const int width = 70;
    const int height = 20;
    int x;
    int y;

    int strength;
    float *color;

public:

    Brick();

    void draw(int row, int col);
    bool checkCollision(Ball& ball);

    float* getColor();

    ~Brick();

};