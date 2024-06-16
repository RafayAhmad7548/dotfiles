#ifndef LEVEL2_H
#define LEVEL2_H

#include "GameLevel.h"

class Level2 : public GameLevel{
public:
    Level2(){
        for(int i=0;i<25;i++){
            for(int j=0;j<15;j++){
                if(i<5 && j<5) bricks[i][j] = new Brick();
                else if(i<10 && i>4 && j<10 && j>4) bricks[i][j] = new Brick();
                else if(i<15 && i>9 && j<15 && j>9) bricks[i][j] = new Brick();
                else if(i<20 && i>14 && j<10 && j>4) bricks[i][j] = new Brick();
                else if(i<25 && i>19 && j<5) bricks[i][j] = new Brick();
            }
        }
    }
};
#endif