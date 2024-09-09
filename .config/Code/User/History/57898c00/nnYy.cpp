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
    a += b;
}

int main(){

    int a = 5;
    int b = 3;

    swapValues<int>(a, b);

    cout<<a<<"\n"<<b;



    return 0;
}