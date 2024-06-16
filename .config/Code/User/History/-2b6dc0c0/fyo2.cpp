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
    void show(){
        cout<<"a show\n";
    }
};
class B : public A{
public: 
    B(){
        cout<<"B cstr\n";
    }
    void show(){
        cout<<"b show\n";
    }
};
class C : public A{
public:
    C(){
        cout<<"C cstr\n";
    }
    void show(){
        cout<<"c show\n";
    }
};
class D : public A, public B{

};


int main(){

    C obj;
    obj.show();
    // obj.A::show();

    return 0;
}