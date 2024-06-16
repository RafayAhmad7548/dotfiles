#include "GameLevel.h"
#include "util.h"

class Level1 : public GameLevel{

public:

    Level1(){
        for(int i=0;i<25;i++){
            for(int j=0;j<15;j++){
                bricks[i][j] = new Brick();
            }
        }
    }

};