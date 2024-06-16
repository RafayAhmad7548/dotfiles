#include <iostream>
using namespace std;

class Set{
// You will need an array to store the elements of the set.
// You will also need a variable to keep track of the size of the array.
    int* elements;
    int size;
public:
    Set() : elements(nullptr), size(0){}
    Set(const int* elements, int size) : elements(int*(elements)), size(size){}
    Set(const Set& copy) : size(copy.size){
        elements = new int[size];
        for(int i=0;i<size;i++) elements[i] = copy.elements[i];
    }
    // Binary Operators
    // Set Operators
    Set operator+(const Set& val) const; // Union
    Set operator*(const Set& val) const; // Intersection
    Set operator-(const Set& val) const; // Difference
    // Compound Assignment Operators
    Set& operator+=(const Set& rhs); // Union Assignment
    Set& operator*=(const Set& rhs); // Intersection Assignment
    Set& operator-=(const Set& rhs); // Difference Assignment
    // Logical Operators
    bool operator==(const Set& val) const;
    bool operator!=(const Set& val) const;
    //  Functional Operators
    Set& operator>(Set&); // Sort the elements in the set
    int& operator[](int element); // Access element at index
    bool operator()(int element) const; // Check if element is in the set
    bool operator()(int element, int dumy); // Add element to the set if it is not already in set, The dumy element to differenciate from the other operator
    bool operator()(int element, int dumy,int dumy2);// Add element to the set if it is not already in set and element is lcm between any to numbers of the set, 
                                                    // Two dumy elements to differenciate from the other operator
    // Additional Functions for functional operators
    int find(int element) const; // Find element in the set
    void display();
    ~Set(); // destructor
    friend std::ostream& operator<<(std::ostream& output, const Set& val); // outputs the Set
    friend std::istream& operator>>(std::istream& input, Set& val); // inputs the Set
};