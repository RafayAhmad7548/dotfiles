#include "Food.h"
#include "util.h"

class YellowFood : public Food{

    const int dimension = 20;
    
public:

    YellowFood(int x, int y) : Food(x, y, colors[YELLOW]){}
    void draw() override{
        DrawSquare(x, y, dimension, color);
    }
    ~YellowFood(){}

};