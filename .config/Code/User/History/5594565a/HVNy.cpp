/*
Rafay Ahmad
23I-2526
Assignment 3
*/
#include <iostream>
#include <cstring>
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
    HotelBooking(){}
    HotelBooking(string bookingID, string customerName, string hotelName, string roomType, string checkIn, string checkOut) :
        bookingID(bookingID), customerName(customerName), hotelName(hotelName), roomType(roomType), checkIn(checkIn), checkOut(checkOut){
            if(this->checkIn.length()==10 || this->checkOut.length()==10){
                this->stayDuration = calculateStayDuration();
                this->roomRate = calculateRoomRate();
            }
        }
    
    bool validateBookingID() const{
        if(this->bookingID.length()!=14){
            cout<<"Invalid input\n";
            return false;
        }
        for(int i=0;this->bookingID[i]!='\0';i++){
            if(i<8){
                switch(this->bookingID[i]){
                    case 'a'...'z':
                    case 'A'...'Z':
                    break;
                    default: cout<<"Invalid input\n"; return false;
                }
            }
            else if(i<10){
                switch(this->bookingID[i]){
                    case 'a'...'z':
                    case 'A'...'Z':
                    case '0'...'9':
                    cout<<"Invalid input\n";
                    return false;
                }
            }
            else if(i<14){
                switch(this->bookingID[i]){
                    case '0'...'9':
                    break;
                    default: cout<<"Invalid input\n"; return false;
                }
            }
            else{
                cout<<"Invalid input\n";
                return false;
            }
        }
        int sum = 0;
        for(int i=0;i<4;i++) sum += this->bookingID[i+10] - '0';
        return sum<18;
    }

    int calculateStayDuration() const{
        int checkInDay = (this->checkIn[0]-'0')*10 + (this->checkIn[1]-'0');
        int checkInMonth = (this->checkIn[3]-'0')*10 + (this->checkIn[4]-'0');
        int checkInYear = (this->checkIn[6]-'0')*1000 + (this->checkIn[7]-'0')*100 + (this->checkIn[8]-'0')*10 + (this->checkIn[9]-'0');
        int checkOutDay = (this->checkOut[0]-'0')*10 + (this->checkOut[1]-'0');
        int checkOutMonth = (this->checkOut[3]-'0')*10 + (this->checkOut[4]-'0');
        int checkOutYear = (this->checkOut[6]-'0')*1000 + (this->checkOut[7]-'0')*100 + (this->checkOut[8]-'0')*10 + (this->checkOut[9]-'0');
        int days = 0;
        days = (checkOutYear-checkInYear)*365 + (checkOutMonth-checkInMonth)*30 + checkOutDay - checkInDay;
        return days;
    }

    int calculateRoomRate() const{
        if(this->roomType == "single") return 10;
        else if(this->roomType == "double") return 20;
        else if(this->roomType == "suite") return 50;
        return 0;
    }

    int calculateTotalCost() const{
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

    string bookingID, customerName, hotelName, roomType, checkIn, checkOut;
    HotelBooking booking1;
    do{
        cout<<"Enter booking ID: ";
        getline(cin, bookingID);
        booking1 = HotelBooking(bookingID, customerName, hotelName, roomType, checkIn, checkOut);
    }while(!booking1.validateBookingID());

    cout<<"Enter customer name: ";
    getline(cin, customerName);
    cout<<"Enter hotel name: ";
    getline(cin, hotelName);
    cout<<"Enter room type(single, double, suite): ";
    getline(cin, roomType);
    cout<<"Enter check in date: ";
    getline(cin, checkIn);
    cout<<"Enter check out date: ";
    getline(cin, checkOut);

    booking1 = HotelBooking(bookingID, customerName, hotelName, roomType, checkIn, checkOut);

    booking1.getBookingDetails();
    booking1.updateBookingInfo();
    booking1.getBookingDetails();

    

    return 0;
}