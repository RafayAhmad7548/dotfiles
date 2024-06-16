#include "Food.h"
#include "util.h"

class BlueFood : public Food{
    
    const int radius = 10;

public:

    BlueFood(int x, int y) : Food(x, y, colors[BLUE]){}
    void draw() override{
        DrawCircle(x, y, radius, color);
    }
    ~BlueFood(){}

};