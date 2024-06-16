#ifndef GAMELEVEL_H
#define GAMELEVEL_H

#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"

class GameLevel{
    int score;
    int lives;
protected:
    Ball **balls;
    Paddle paddle;
    Brick ***bricks;
    Food ***food;
public:

    GameLevel();
    void draw();
    void checkBrickCollision();
    void moveFood();
    void checkFoodCollision();


    Ball**& getBalls();
    Paddle& getPaddle();
    virtual Paddle*& getPaddle2();

    ~GameLevel();

};
#endif