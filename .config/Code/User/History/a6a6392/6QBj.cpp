#ifndef LEVEL2_H
#define LEVEL2_H

#include "GameLevel.h"

class Level2 : public GameLevel{
public:
    Level2(){
        for(int i=0;i<25;i++){
            for(int j=0;j<15;j++){
                if(i<5 && j<5) bricks[i][j] = new Brick();
                else if(i<10 && j<10) bricks[i][j] = new Brick();
                else if(i<15 && j<15) bricks[i][j] = new Brick();
                else if(i<20 && j<10 && j>5) bricks[i][j] = new Brick();
                else if(i<5 && j<5) bricks[i][j] = new Brick();
            }
        }
    }
};
#endif