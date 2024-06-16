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

    
    

    

    

    void print(){
        cout<<real<<" + i"<<img<<endl;
    }
};

Complex operator++(Complex &c){
    
}

int main(){

    Complex c1(1, 2);
    Complex c2(2, 3);

    

    return 0;
}