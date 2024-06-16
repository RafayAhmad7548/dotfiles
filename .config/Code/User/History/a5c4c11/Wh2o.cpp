#include "GameLevel.h"

class Level1 : public GameLevel{


    Level1(Paddle paddle, Ball ball) : GameLevel(paddle, ball){
        bricks = new Brick**[15];
    }




};