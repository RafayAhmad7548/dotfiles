#include "GameLevel.h"
#include "util.h"

class Level1 : public GameLevel{

public:

    Level1(Paddle paddle, Ball ball) : GameLevel(paddle, ball){
        for(int i=0;i<25;i++){
            for(int j=0;j<15;j++){
                if(i<5) bricks[i][j] = new Brick(colors[GREEN], 1);
                else if(i<10) bricks[i][j] = new Brick(colors[PINK], 2);
                else if(i<15) bricks[i][j] = new Brick(colors[BLUE], 3);
                else if(i<20) bricks[i][j] = new Brick(colors[RED], 3);
                else bricks[i][j] = new Brick(colors[YELLOW], 2);
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