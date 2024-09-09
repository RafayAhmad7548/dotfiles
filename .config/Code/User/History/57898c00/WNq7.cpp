/*
Rafay Ahmad
23I-2526
*/
#include <iostream>
using namespace std;

template <class T>
void swapValues(T& a, T& b){
    a += b;
    b = a - b;
    a = a - b;
}

int main(){

    int a = 5;
    int b = 3;
    char c = 'a';
    char d = 'e';
    double e = 5.5;
    double f = 7.5;

    swapValues(a, b);
    swapValues(c, d);
    swapValues(e, f);

    cout<<a<<"\n"<<b<<endl;
    cout<<c<<"\n"<<d<<endl;
    cout<<e<<"\n"<<f<<endl;



    return 0;
}