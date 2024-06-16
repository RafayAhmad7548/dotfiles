#include "GameLevel.h"

class Level3 : public GameLevel{
    Paddle paddle2;
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
            if(i == 0 || i == 14) bricks[i][j] = new Brick();
            if(j<7-i+1 || j>7+i-1) bricks[i][j] = new Brick();
            else if(j<7-(14-i)+1 || j>7+(14-i)-1) bricks[i][j] = new Brick();
            patternHelper(i, j+1);
        }
    }



};