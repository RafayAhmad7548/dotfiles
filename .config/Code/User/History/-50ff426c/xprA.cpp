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
    print('*', n);
}

int main(){

    

    return 0;
}