#include "Food.h"
#include "util.h"

class YellowFood : public Food{

    const int dimension = 20;
    
public:

    PinkFood(int x, int y) : Food(x, y, colors[PINK]){}
    void draw() override{
        DrawSquare(x, y, dimension, color);
    }
    ~PinkFood(){}


};