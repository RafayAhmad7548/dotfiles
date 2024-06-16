/*
Rafay Ahmad
23I-2526
*/
#include <iostream>
using namespace std;

void print(char c, int i){
    if(i>=0){
        cout<<c;
        print(c, i-1);
    }
}

int main(){

    

    return 0;
}