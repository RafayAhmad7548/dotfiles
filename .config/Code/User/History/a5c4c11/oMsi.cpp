#include "GameLevel.h"
#include "util.h"

class Level1 : public GameLevel{

public:

    Level1(Paddle paddle, Ball ball) : GameLevel(paddle, ball){
        for(int i=0;i<15;i++){
            for(int j=0;j<25;j++){
                if(j<5) bricks[i][j] = new Brick(colors[GREEN]);
                else if(j<10) bricks[i][j] = new Brick(colors[PINK]);
                else if(j<15) bricks[i][j] = new Brick(colors[BLUE]);
                else if(j<20) bricks[i][j] = new Brick(colors[RED]);
                else bricks[i][j] = new Brick(colors[YELLOW]);
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