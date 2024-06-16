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
            
            patternHelper(i, j+1);
        }
    }



};
#endif