#include "GameLevel.h"
#include "util.h"

class Level1 : public GameLevel{

public:

    Level1(Paddle paddle, Ball ball) : GameLevel(paddle, ball){
        for(int i=0;i<25;i++){
            for(int j=0;j<15;j++){
                if(i<5) bricks[j][i] = new Brick(colors[GREEN]);
                else if(i<10) bricks[j][i] = new Brick(colors[PINK]);
                else if(i<15) bricks[j][i] = new Brick(colors[BLUE]);
                else if(i<20) bricks[j][i] = new Brick(colors[RED]);
                else bricks[j][i] = new Brick(colors[YELLOW]);
            }
        }
    }

    Ball& getBall(){
        return ball;
    }
    Paddle& getPaddle(){
        return paddle;
    }


};