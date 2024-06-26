#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int to_int(string s){
    int result = 0;
    for(int i=s.length()-1;i>=0;i++){
        if(s[i] != '-') result += (s[i] - '0')*pow(10, s.length()-1-i);
    }
    return result;
}

class BigFloat{
// think about the private data members
// You will need two string data members: one for the integer part and one for the fractional part.
// You will also need a boolean data member to store the sign of the number.
// Additionally, you will need an integer data member to store the precision of the number.

    string whole;
    string fraction;
    int precision;
    bool sign; // true = +, false = -

public:
    BigFloat(double val = 0.0, int precision = 2) : precision(precision), sign(val>=0){
        this->whole = to_string(int(val));
        this->fraction = to_string((val - int(val)) * pow(10, precision));
        if(this->fraction.length()<this->precision){
            for(int i=0;i<this->fraction.length()-this->precision;i++) this->fraction += '0';
        }
        else if(this->fraction.length()>this->precision){
            this->fraction = this->fraction.substr(0, this->fraction.find_first_of('.'));
        }
    }
    BigFloat(const string& text, int precision = 2) : precision(precision), sign(text[0] != '-'){
        whole = text.substr(0, text.find_first_of('.'));
        fraction = text.substr(text.find_first_of('.')+1, text.length());
        fraction = fraction.substr(0, precision); 
    }
    BigFloat(const BigFloat& copy){
        *this = copy;
    }
    // Binary Operators
    // Arithmetic Operators
    BigFloat operator+(const BigFloat& val) const{
        BigFloat result("");
        int i = 0, carry = 0, sum = 0;
        if(this->precision>val.precision){
            while(i<this->precision-val.precision){
                result.fraction = char(this->fraction[i]) + result.fraction;
                i++;
            }
        }
        while(i<this->fraction.length() && i<val.fraction.length()){
            sum = carry + this->fraction[this->fraction.length()-i] + val.fraction[val.fraction.length()-i];
            carry = sum/10;
            result.fraction = char(sum%10 + '0') + result.fraction;
            i++;
            /*
            
            8.456
            6.79
            ----
            15.246
            
            
            
            */


        }
        
    }
    BigFloat operator-(const BigFloat& val) const{
        BigFloat result;
        result.whole = to_string(to_int(this->whole) - to_int(val.whole));
        result.fraction = to_string(to_int(this->fraction) - to_int(val.fraction));
        if(to_int(result.fraction) < 0){
            // 2.5-1.7      0.8
            result.fraction = to_string(pow(10, result.precision) + to_int(result.fraction));
            result.whole = to_string(to_int(result.whole) - 1);
        }
        return result;
    }
    BigFloat operator*(const BigFloat& val) const{
        
    }
    BigFloat operator/(const BigFloat& val) const;
    BigFloat operator%(const BigFloat& val) const; // Modulus Operator
    // Compound Assignment Operators
    BigFloat operator+=(const BigFloat& rhs){
        return *this + rhs;
    }
    BigFloat operator-=(const BigFloat& rhs){
        return *this - rhs;
    }
    BigFloat operator*=(const BigFloat& rhs){
        return *this * rhs;
    }
    BigFloat operator/=(const BigFloat& rhs){
        return *this / rhs;
    }
    BigFloat operator%=(const BigFloat& rhs){
        return *this % rhs;
    }
    // Logical Operators
    bool operator==(const BigFloat& val) const{
        return this->whole == val.whole && this->fraction == val.fraction && this->sign == val.sign && this->precision == val.precision;
    }
    bool operator!=(const BigFloat& val) const{
        return !(*this == val);
    }
    bool operator<(const BigFloat& val) const{
        if(to_int(this->whole) < to_int(val.whole)) return true;
        else if(to_int(this->whole) > to_int(val.whole)) return false;
        else return to_int(this->fraction) < to_int(val.fraction);
    }
    bool operator<=(const BigFloat& val) const{
        if(to_int(this->whole) < to_int(val.whole)) return true;
        else if(to_int(this->whole) > to_int(val.whole)) return false;
        else return to_int(this->fraction) <= to_int(val.fraction);
    }
    bool operator>(const BigFloat& val) const{
        if(to_int(this->whole) > to_int(val.whole)) return true;
        else if(to_int(this->whole) < to_int(val.whole)) return false;
        else return to_int(this->fraction) > to_int(val.fraction);
    }
    bool operator>=(const BigFloat& val) const{
        if(to_int(this->whole) > to_int(val.whole)) return true;
        else if(to_int(this->whole) < to_int(val.whole)) return false;
        else return to_int(this->fraction) >= to_int(val.fraction);
    }
    // Unary Operators
    BigFloat operator+() const{
        return *this;
    } 
    BigFloat operator-() const{
        BigFloat result(*this);
        if(result.sign) result.sign = false;
        else result.sign = true;
        return result;
    }
    // Conversion Operator
    operator std::string() const{
        return this->whole + "." + this->fraction;
    }
    ~BigFloat(){} // destructor
    friend std::ostream& operator<<(std::ostream& output, const BigFloat& val);
    // outputs the BigFloat
    friend std::istream& operator>>(std::istream& input, BigFloat& val); // inputs the BigFloat

};
ostream& operator<<(ostream& output, const BigFloat& val){
    output<<val.operator string()<<endl;
}
istream& operator>>(istream& input, BigFloat& val){
    string text;
    input>>text;
    val = BigFloat(text);   
}

