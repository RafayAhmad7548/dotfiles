/*
Rafay Ahmad
23I-2526
*/
#include <iostream>
using namespace std;

class HotelBooking{
    string bookingID;
    string customerName;
    string hotelName;
    string roomType;
    string checkIn;
    string checkOut;
    int stayDuration;
    double roomRate;

public:
    // iniitalzing cstr
    HotelBooking(string bookingID, string customerName, string hotelName, string roomType, string checkIn, string checkOut) :
        bookingID(bookingID), customerName(customerName), hotelName(hotelName), roomType(roomType), checkIn(checkIn), checkOut(checkOut){}
    
    bool validateBookingID() const{
        for(int i=0;this->bookingID[i]!='\0';i++){
            if(i<8){
                switch(this->bookingID[i]){
                    case 'a'...'z':
                    case 'A'...'Z':
                    break;
                    default: return false;
                }
            }
            else if(i<10){
                switch(this->bookingID[i]){
                    case 'a'...'z':
                    case 'A'...'Z':
                    case '0'...'9':
                    return false;
                }
            }
            else if(i<14){
                switch(this->bookingID[i]){
                    case '0'...'9':
                    break;
                    default: return false;
                }
            }
            else return false;
        }
        int sum = 0;
        for(int i=0;i<4;i++) sum += this->bookingID[i+10] - '0';
        return sum<18;
    }

    int calculateRoomRate() const{
        if(this->roomType == "single"){
            return 10;
        }
        else if(this->roomType == "double"){
            return 20;
        }
        else if(this->roomType == "suite"){
            return 50;
        }
    }

    int calculateTotalCost(){
        return this->roomRate*this->stayDuration;
    }






};

int main(){

    

    return 0;
}