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
class D : public C, public B{
public:
    D(){
        cout<<"D cstr\n";
    }
    void show(){
        cout<<"d show\n";
    }
};


int main(){

    D obj;
    obj.C::show();

    return 0;
}