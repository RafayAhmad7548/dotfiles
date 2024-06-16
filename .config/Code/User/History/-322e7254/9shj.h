#include "Ball.h"
#include "Food.h"

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
    int checkCollision(Ball& ball);

    int getX();
    int getY();
    float* getColor();
    Food* getFood();

    ~Brick();

};