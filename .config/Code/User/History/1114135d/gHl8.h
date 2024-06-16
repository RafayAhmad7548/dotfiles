#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"

class GameLevel{

    int score;
    int lives;
    Ball ball;
    Paddle paddle;

protected:
    Brick ***bricks;
public:

    GameLevel(Paddle paddle, Ball ball);
    void draw();


};