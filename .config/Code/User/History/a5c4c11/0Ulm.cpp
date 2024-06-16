#include "GameLevel.h"

class Level1 : public GameLevel{


    Level1(Paddle paddle, Ball ball) : GameLevel(paddle, ball){
        for(int i=0;i<25;i++){
            for(int j=0;j<15;j++){
                bricks[i][j] = new Brick;
            }
        }
    }


};