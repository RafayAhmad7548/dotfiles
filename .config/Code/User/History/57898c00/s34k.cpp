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

    swapValues<int>(a, b);
    swapValues(c, d);

    cout<<a<<"\n"<<b<<endl;
    cout<<c<<"\n"<<d<<endl;



    return 0;
}