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
    void setArea(double area){
        this->area = area;
    }
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
        setArea(3.14159*radius*radius);
    }
};

class Rectangle : public BasicShape{
    long int width;
    long int length;
public:
    Rectangle(long int width, long int length) : width(width), length(length){
        calcArea();
    }
    long int getWidth(){
        return width;
    }
    long int getLength(){
        return length;
    }
    void calcArea() override{
        setArea(width*length);
    }
};

int main(){

    BasicShape **shapes;

    return 0;
}