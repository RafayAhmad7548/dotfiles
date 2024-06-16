/*
Rafay Ahmad
23I-2526
*/
#include <iostream>
using namespace std;

class Complex{
    int real;
    int img;

public:

    Complex(){}
    Complex(int real, int img) : real(real), img(img){}

    Complex operator++(int){
        Complex temp(*this);
        real++;
        img++;
        return temp;
    }
    Complex operator++(){
        real++;
        img++;
        return *this;
    }
    Complex operator--(int){
        Complex temp(*this);
        real--;
        img--;
        return temp;
    }
    Complex operator--(){
        real--;
        img--;
        return *this;
    }
    Complex operator+(Complex const& c){
        Complex res;
        res.real = real + c.real;
        res.img = img + c.img;
        return res;
    }

    void print(){
        cout<<real<<" + i"<<img<<endl;
    }
};
Complex operator+(Complex const& c){
        Complex res;
        res.real = real + c.real;
        res.img = img + c.img;
        return res;
}
int main(){

    Complex c1(1, 2);
    Complex c2(2, 3);

    Complex c3 = c1++;
    c1.print();
    c3.print();
    

    return 0;
}