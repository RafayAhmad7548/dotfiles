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

    
       

    friend ostream& operator<<(ostream&, const Complex);

    

    
};

ostream& operator<<(ostream& out, const Complex& c){

    out<<"Real Part: "<<c.real<<endl;
    out<<"Imaginary Part: "<<c.img<<endl;


    return out;
}

int main(){

    Complex c1(1, 2);
    Complex c2(2, 3);

    

    return 0;
}