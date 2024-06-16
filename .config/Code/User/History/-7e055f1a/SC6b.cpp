#include<iostream> 
using namespace std; 
class A { 
public: 
A(int ii = 0) : i(ii) {} 
A(int ii, int ss) : i(ii + ss) {} 
void show() { cout << "i = " << i << endl; } 
~A() { cout << "Out A" << i << endl; } 
A magic(int ss) { this->i = ss * this->i; return *this; } 
private: 
int i; 
}; 
int main() { 
A a(10, 5), s(10); 
a = s.magic(20).magic(10); 
}