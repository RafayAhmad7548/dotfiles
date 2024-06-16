#include <iostream>
using namespace std;

// The helper function is similar to mid exam (hollow Diamond)
void printLine(int dimension, int stericCount,char character,int i=1) {
// character can be * or o
    if (i>dimension){
        return;
    }

    if (i <= stericCount || i > dimension - stericCount) {
        cout << character;    // printing a character
    }
    else {
        cout << " ";
    }
    printLine(dimension,stericCount,character,i+1);
}

void pattern1(const int dimension, int i=1) {

// Back tracking is mandatory, you can't use more than one if condition
    if(i<dimension/2+2){
        printLine(dimension, i, '*');
        printLine(dimension, i, 'O');
        cout<<endl;
        pattern1(dimension, i+1);
        printLine(dimension, i, 'O');
        printLine(dimension, i, '*');
        cout<<endl;
    }

}

int main(){
    cout << "Enter an odd integer: ";
    int number; cin >> number;
    cout << endl;
    pattern1(number); 
}
