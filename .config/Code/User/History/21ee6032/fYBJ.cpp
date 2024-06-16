/*
Rafay Ahmad
23I-2526
*/
#include <iostream>
using namespace std;

class Count{
public:
    int count;

    Count() : count(0){}

    int operator++(){
        count++;
        return count;
    }
    int operator++(int){
        count++;
        return count-1;
    }
};

int main(){

    Count c1;
    cout<<"Inital value: "<<c1.count<<endl;
    cout<<"Postfix increment"<<c1++<<endl;
    cout<<"After post increment"<<c1.count<<endl;
    cout<<"Prefix increment: "<<++c1<<endl;


    return 0;
}