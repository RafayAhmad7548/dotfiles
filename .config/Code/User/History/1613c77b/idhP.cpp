#include <iostream>
using namespace std;

class Time{
// You will need three integer data members to store the hours, minutes, and seconds.
    int hours;
    int minutes;
    int seconds;
public:
    Time(int hours = 0, int minutes = 0, int seconds = 0) : hours(hours), minutes(minutes), seconds(seconds){}
    Time(const Time& copy){
        *this = copy;
    }
    // Binary Operators
    // Arithmetic Operators
    Time operator+(const Time& val) const{
        Time result;
        result.seconds = this->seconds + val.seconds;
        if(result.seconds>=60){
            result.seconds -= 60;
            result.minutes++;
        }
        result.minutes += this->minutes + val.minutes;
        if(result.minutes>=60){
            result.minutes -= 60;
            result.hours++;
        }
        result.hours += this->hours + val.hours;
        return result;
    }
    Time operator-(const Time& val) const{
        Time result;
        result.hours = this->hours - val.hours;
        if(result.hours<0) result.hours *= -1;
        result.minutes = this->minutes - val.minutes;
        if(result.minutes<0){
            result.hours--;
            result.minutes += 60;
        }
        result.seconds = this->seconds - val.seconds;
        if(result.seconds<0){
            result.minutes--;
            result.seconds += 60;
        }
        return result;
    }
    // Compound Assignment Operators
    Time operator+=(const Time& rhs){
        return *this + rhs;
    }
    Time operator-=(const Time& rhs){
        return *this - rhs;
    }
    // Logical Operators
    bool operator==(const Time& val) const{
        return this->seconds == val.seconds && this->minutes == val.minutes && this->hours == val.hours;
    }
    bool operator!=(const Time& val) const{
        return !(*this == val);
    }
    bool operator<(const Time& val) const{
        if(this->hours<val.hours) return true;
        else if(this->hours>val.hours) return false;
        else if(this->minutes<val.minutes) return true;
        else if(this->minutes>val.minutes) return false;
        else return this->seconds<val.seconds;
    }
    bool operator<=(const Time& val) const{
        if(this->hours<val.hours) return true;
        else if(this->hours>val.hours) return false;
        else if(this->minutes<val.minutes) return true;
        else if(this->minutes>val.minutes) return false;
        else return this->seconds<=val.seconds;
    }
    bool operator>(const Time& val) const{
        if(this->hours>val.hours) return true;
        else if(this->hours<val.hours) return false;
        else if(this->minutes>val.minutes) return true;
        else if(this->minutes<val.minutes) return false;
        else return this->seconds>val.seconds;
    }
    bool operator>=(const Time& val) const{
        if(this->hours>val.hours) return true;
        else if(this->hours<val.hours) return false;
        else if(this->minutes>val.minutes) return true;
        else if(this->minutes<val.minutes) return false;
        else return this->seconds>=val.seconds;
    }
    // Additional Functions
    Time elapsedTime() const{} // Calculate elapsed time
    ~Time(){} // destructor
    friend std::ostream& operator<<(std::ostream& output, const Time& val); // outputs the Time
    friend std::istream& operator>>(std::istream& input, Time& val); // inputs the Time
};
ostream& operator<<(std::ostream& output, const Time& val){
    output<<"Hours "<<val.hours<<" Minutes "<<val.minutes<<" Seconds "<<val.seconds<<endl;
}
istream& operator>>(std::istream& input, Time& val){
    cout<<"Enter Hours: ";
    input>>val.hours;
    cout<<"Enter Minutes: ";
    input>>val.minutes;
    cout<<"Enter Seconds: ";
    input>>val.seconds;
}