/*
Rafay Ahmad
23I-2526
*/
#include <iostream>
using namespace std;

class A{
public:
    A(){
        cout<<"A cstr\n";
    }
};
class B{
public: 
    B(){
        cout<<"B cstr\n";
    }
};
class C : public A, public B{
public:
    C(){
        cout<<"C cstr\n";
    }
    void show(){
        cout<<"c show\n";
    }
};


int main(){

    

    return 0;
}