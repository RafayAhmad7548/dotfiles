#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Binary {
private:
    string binaryString;
    int base;
    int decimalNo;

public:
	
    // Constructor (If base is greater than 2 first convert into base 10 using that base and then convert back into binary and change the base to 2)
    Binary(string binaryStr, int base = 2){
        toDecimal();
    }

    void toBinary(){
        binaryString = "";
        int temp = decimalNo;
        while(temp > 0){
            binaryString = char(temp%2 + '0') + binaryString;
            temp /= 2;
        }
    }

    void toDecimal(){
        decimalNo = 0;
        for(int i=0;i<binaryString.length();i++) decimalNo += (binaryString[i] - '0')*pow(2, binaryString.length()-1-i);
    }

    // Overloading + operator for addition
    Binary operator+(const Binary& other) const{
        Binary result("");
        result.decimalNo = this->decimalNo + other.decimalNo;
        result.toBinary();
        return result;
	}

    // Overloading - operator for subtraction
    Binary operator-(const Binary& other) const{
        Binary result("");
        result.decimalNo = this->decimalNo - other.decimalNo;
        result.toBinary();
        return result;
	}
    
    // Overloading += operator for addition
    Binary& operator+=(const Binary& other){
        this->decimalNo += other.decimalNo;
        this->toBinary();
        return *this;
	}

    // Overloading -= operator for subtraction
    Binary& operator-=(const Binary& other){
        this->decimalNo -= other.decimalNo;
        this->toBinary();
        return *this;	
	}

    // Overloading * operator for multiplication (Convert to base 10 multiply and convert back into base 2)
    Binary operator*(const Binary& other) const{
        Binary result("");
        result.decimalNo = this->decimalNo * other.decimalNo;
        result.toBinary();
        return result;       
	}

    // Overloading / operator for division  (Convert to base 10 divide and convert back into base 2)
    Binary operator/(const Binary& other) const{
        Binary result("");
        result.decimalNo = this->decimalNo / other.decimalNo;
        result.toBinary();
        return result;
	}

    // Overloading % operator for modulus  (Convert to base 10 modulus and convert back into base 2)
    Binary operator%(const Binary& other) const{
        Binary result("");
        result.decimalNo = this->decimalNo % other.decimalNo;
        result.toBinary();
        return result;
	}
    
    // Overloading | operator for or
    Binary operator|(const Binary& other) const{
        Binary result("");
        // if(this->binaryString.length() < other.binaryString.length()){
        //     for(int i=0;i<other.binaryString.length() - this->binaryString.length();i++) this->binaryString = '0' + this->binaryString;
        // }
        // else if(this->binaryString.length() > other.binaryString.length()){
        //     for(int i=0;i<this->binaryString.length() - other.binaryString.length();i++) other.binaryString = '0' + other.binaryString;
        // }

        // for(int i=0;i<this->binaryString.length();i++){
        //     result.binaryString += this->binaryString[i] || other.binaryString[i];
        // }

        result.decimalNo = this->decimalNo | other.decimalNo;
        result.toBinary();
        return result;
	}
    
    // Overloading ^ operator for xor
    Binary operator^(const Binary& other) const{
        Binary result("");
        result.decimalNo = this->decimalNo ^ other.decimalNo;
        result.toBinary();
        return result;
	}

    // Overloading & operator for and
    Binary operator&(const Binary& other) const{
        Binary result("");
        result.decimalNo = this->decimalNo & other.decimalNo;
        result.toBinary();
        return result;       
	}

    // Overloading ! operator for 2's Compliment
    Binary operator!() const{
        Binary result("");
        result.decimalNo = ~this->decimalNo + 1; // 2's complement is 1's complement + 1
        result.toBinary();
        return result;
	}
    
    // Overloading ~ operator for 1's Compliment
    Binary operator~() const{
        Binary result("");
        result.decimalNo = ~this->decimalNo;
        result.toBinary();
        return result;
	}
    
    // Overloading left shift operator
    Binary operator<<(int shiftAmount) const{
        Binary result("");
        result.decimalNo = this->decimalNo << shiftAmount; 
        result.toBinary();
        return result;
	}

    // Overloading right shift operator
    Binary operator>>(int shiftAmount) const{
        Binary result("");
        result.decimalNo = this->decimalNo >> shiftAmount; 
        result.toBinary();
        return result;	
	}

    // Overloading input operator
    friend istream& operator>>(istream& input, Binary& other);

    // Overloading output operator (Display Both Binary as well as Integer value)
    friend ostream& operator<<(ostream& output, const Binary& other);

};

istream& operator>>(istream& input, Binary& other){
    cout<<"Enter binary: ";
    input>>other.binaryString;
    cout<<"Enter base: ";
    input>>other.base;
    other.toBinary();
    return input;
}
ostream& operator<<(ostream& output, const Binary& other){
    cout<<"Binary: ";
    output<<other.binaryString<<endl;
    cout<<"Decimal value: ";
    output<<other.decimalNo<<endl;
    cout<<"Base: ";
    output<<other.base<<endl;
}
