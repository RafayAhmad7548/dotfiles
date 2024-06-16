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

    int getReal(){
        return real;
    }

    int operator+(Complex c){
        Complex res;
        res.real = real + c.real;
        // res.img = img + c.img;
        return res.real;
    }

       

    friend ostream& operator<<(ostream&, Complex&);

    

    
};

int operator+(int a, Complex c){
    return a + c.getReal();
}

ostream& operator<<(ostream& out, Complex& c){
    out<<c.real<<"+"<<c.img<<"i\n";
    return out;
}

int main(){

    Complex c1(1, 2);
    Complex c2(2, 3);
    Complex c4(2, 3);

    // Complex c3 = c1 + c2 + c4;
    int c3 = c1 + c2 + c4;
    cout<<c3;

    return 0;
}