#ifndef LEVEL3_H
#define LEVEL3_H

#include "GameLevel.h"

class Level3 : public GameLevel{
public:
    Level3(){
        pattern(0);       
    }
    void pattern(int i){
        if(i<15){
            patternHelper(i, 0);
            pattern(i+1);
        }
    }
    void patternHelper(int i, int j){
        if(j<15){
            // bricks[i][j] = new Brick();
            if(i == 0 || i == 14) bricks[i][j] = new Brick();
            if(j<7-i+1 || j>7+i-1) bricks[i][j] = new Brick();
            else if(j<i-7+1 || j>7+i) bricks[i][j] = new Brick();
            // else if(j <= j-i && j >= j+i) bricks[i][j] = new Brick();
            patternHelper(i, j+1);
        }
    }



};
#endif