/*
Rafay Ahmad
23I-2526
*/
#include <iostream>
using namespace std;

class MathOperations{
public:
    int add(int a, int b){
        return a + b;
    }
    double add(double a, double b, double c){
        return a + b + c;
    }
};

int main(){

    MathOperations m;
    cout<<"Sum of 5 and 6: ";
    cout<<m.add(5,6)<<endl;
    cout<<"Sum of 4.5, 2.3, 9.7: ";
    cout<<m.add(4.5, 2.3, 9.7)<<endl;

    return 0;
}