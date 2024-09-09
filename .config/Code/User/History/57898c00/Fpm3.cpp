/*
Rafay Ahmad
23I-2526
*/
#include <iostream>
using namespace std;

template <class T>
void swapValues(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

int main(){

    swapValues<int>(1, 2);

    return 0;
}