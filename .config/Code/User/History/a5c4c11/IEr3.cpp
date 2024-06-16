#include "GameLevel.h"

class Level1 : public GameLevel{


    Level1(Paddle paddle, Ball ball) : GameLevel(paddle, ball){
        for(int i=0;i<25;i++){
            for(int j=0;j<15;j++){
                if(i<5) bricks[i][j] = new Brick(1);
                if(i<10) bricks[i][j] = new Brick(1);
                if(i<15) bricks[i][j] = new Brick(1);
                if(i<20) bricks[i][j] = new Brick(1);
                if(i<25) bricks[i][j] = new Brick(1);
            }
        }
    }


};