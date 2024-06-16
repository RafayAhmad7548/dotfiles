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

    Complex operator+(Complex c){
        Complex res;
        res.real = real + c.real;
        res.img = img + c.img;
        return res;
    }
       

    friend ostream& operator<<(ostream&, Complex&);

    

    
};

ostream& operator<<(ostream& out, Complex& c){
    out<<c.real<<"+"<<c.img<<"i\n";
    return out;
}

int main(){

    Complex c1(1, 2);
    Complex c2(2, 3);

    cout<<c1;

    return 0;
}