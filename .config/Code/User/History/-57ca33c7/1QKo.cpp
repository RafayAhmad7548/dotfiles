#include <iostream>
using namespace std;

// Global Variables/functions not allowed

// Recursive function to calculate the length of a string
int getStringLength(char* s){ // Default arguments not allowed
    if(s[0] == '\0') return 0;
    else return 1 + getStringLength(s+1);
}

int main() {
    // Test cases, don't modify
    string test1 = "123456";
    string test2 = "moyeMoye";
    string test3 = "";  // Empty string
    string test4 = "OOP Lab";
    string test5 = "Recursion is fun!";

    // You can make modifications down here....//
    
    cout << " String = " << test1 << ", Expected = 6, Your output = " << getStringLength(&test1[0]) << endl;
    cout << " String = " << test2 << ", Expected = 8, Your output = " << getStringLength(&test2[0]) << endl;
    cout << " String = " << test3 << ", Expected = 0, Your output = " << getStringLength(&test3[0]) << endl;
    cout << " String = " << test4 << ", Expected = 7, Your output = " << getStringLength(&test4[0]) << endl;
    cout << " String = " << test5 << ", Expected = 17, Your output = " << getStringLength(&test5[0]) << endl;

    

    return 0;
}