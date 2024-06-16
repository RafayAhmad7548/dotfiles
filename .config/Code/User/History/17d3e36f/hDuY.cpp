/*
Rafay Ahmad
23I-2526
*/
#include <iostream>
using namespace std;

class BasicShape{
    double area;
public:
    double getArea(){
        return area;
    }
    virtual void calcArea() = 0;
};

class Circle : public BasicShape{
    long int centerX;
    long int centerY;
    double radius;
public:
    Circle(long int centerX, long int centerY, double radius) : centerX(centerX), centerY(centerY){
        calcArea();
    }
    void calcArea() override{
        
    }
};

int main(){

    

    return 0;
}