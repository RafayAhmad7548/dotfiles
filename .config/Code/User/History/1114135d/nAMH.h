#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"

class GameLevel{

    int score;

    Ball ball;
    Paddle paddle1;
    Brick ***bricks;

public:
    GameLevel(Ball ball, Paddle paddle);
};