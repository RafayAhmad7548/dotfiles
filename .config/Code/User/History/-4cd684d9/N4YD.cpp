#include "Food.h"
#include "util.h"

class GreenFood : public Food{

    int height;

public: 

    GreenFood(int x, int y, int height, float *color) : height(height), Food(x, y, color){}

    void draw(){
        
    }

};