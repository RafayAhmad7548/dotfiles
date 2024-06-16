#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"

class GameLevel{

    int score;

    Ball ball;
    Paddle paddle;
    Brick ***bricks;

public:
    GameLevel(Paddle paddle, Ball ball);
};