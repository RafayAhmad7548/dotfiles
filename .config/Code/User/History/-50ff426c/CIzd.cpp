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
void helper(int i){

}
void pattern(int n){
    if(n>0){
        print('*', n);
        cout<<endl;
        pattern(n-1);
    }
}

int main(){

    

    return 0;
}