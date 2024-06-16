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

    Count c;
    cout<<"Inital value: "<<c.count<<endl;
    cout<<"Postfix increment "<<c++<<endl;
    cout<<"After post increment "<<c.count<<endl;
    cout<<"Prefix increment: "<<++c<<endl;
    cout<<"After pre increment "<<c.count<<endl;

    return 0;
}