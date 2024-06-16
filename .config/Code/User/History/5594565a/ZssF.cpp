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

    void getBookingDetails() const{
        cout<<"Booking ID: "<<this->bookingID<<endl;
        cout<<"Room Type: "<<this->roomType<<endl;
        cout<<"Stay Duration: "<<this->stayDuration<<endl;
        cout<<"Room Rate: "<<this->roomRate<<endl;
        cout<<"Total Cost: "<<calculateTotalCost()<<endl;
    }

    void updateBookingInfo(){
        cout<<"What would you like to update:\n";
        cout<<"1. Room Type\n";
        cout<<"2. Stay Duration\n";
        cout<<"3. Check In Date\n";
        cout<<"4. Check Out Date\n";
        cout<<"5. Exit\n";
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter new room type: ";
                cin>>this->roomType;
            break;
            case 2:
                cout<<"Enter new stay duration: ";
                cin>>this->stayDuration;
            break;
            case 3:
                cout<<"Enter new check in date: ";
                cin>>this->checkIn;
            break;
            case 4:
                cout<<"Enter new check out date: ";
                cin>>this->checkOut;
            break;
            case 5:
            break;
            default: cout<<"Invalid choice\n";
        }
    }
    






};

int main(){

    

    return 0;
}