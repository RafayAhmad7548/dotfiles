#include "Food.h"
#include "util.h"

class GreenFood : public Food{

    int height;
    int width;

public: 

    GreenFood(int x, int y, int height, int width, float *color) : height(height), Food(x, y, color){}

    void draw(){
        DrawTriangle(x, y, )       
    }

};