#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"

class GameLevel{
    int score;
    int lives;
protected:
    Ball ball;
    Paddle paddle;
    Brick ***bricks;
    Food ***food;
public:

    GameLevel(Paddle& paddle, Ball& ball);
    void draw();
    void checkBrickCollision();
    void moveFood();
    void checkFoodCollision();


    Ball& getBall();
    Paddle& getPaddle();

    ~GameLevel();

};