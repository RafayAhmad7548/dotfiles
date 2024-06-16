#include <iostream>
#include <string>

using namespace std;

class Car{
private:
    string name;
    int year;
    double sellingPrice;
    int kmDriven;
    string fuel;
    string sellerType;
    string transmission;
    int owner;
    double mileage;
    double engine;
    double maxPower;
    double torque;
    int seats;

public:

    Car(){}
    // Constructor
    Car(string n, int y, double sp, int km, string f, string st, string tr, int own, double ml, double eng, double mp, double tq, int s) 
        : name(n), year(y), sellingPrice(sp), kmDriven(km), fuel(f), sellerType(st), transmission(tr), owner(own), mileage(ml), engine(eng), maxPower(mp), torque(tq), seats(s){}

    // Overloading + operator to combine details of 2 cars i.e. Add their SellingPrice, Mileage, Engine, MaxPower, Torque, Assign name with your name Take the rest for 1st Car
    Car operator+(const Car& other) const{
        Car result("Honda Civic", this->year, this->sellingPrice+other.sellingPrice, this->kmDriven, this->fuel, this->sellerType, this->transmission, this-> owner, this->mileage+other.mileage, this->engine+other.engine, this->maxPower+other.maxPower, this->torque+other.torque, this->seats);
        return result;
    }

    // Overloading += operator to combine details of 2 cars i.e. Add their SellingPrice, Mileage, Engine, MaxPower, Torque
    Car& operator+=(const Car& other){
        this->sellingPrice += other.sellingPrice;
        this->mileage += other.mileage;
        this->engine += other.engine;
        this->maxPower += other.maxPower;
        this->torque += other.torque;
    }

    // Overloading - operator to subtract selling prices of two cars
    double operator-(const Car& other) const{
        return this->sellingPrice - other.sellingPrice;
    }

    // Overloading -= operator to subtract details of 2 cars i.e. subtract their SellingPrice, Mileage, Engine, MaxPower, Torque
    Car& operator-=(const Car& other){
        this->sellingPrice -= other.sellingPrice;
        this->mileage -= other.mileage;
        this->engine -= other.engine;
        this->maxPower -= other.maxPower;
        this->torque -= other.torque;       
    }

    // Overloading == operator to compare details of two cars
    bool operator==(const Car& other) const{
        return this->name == other.name && this->year == other.year && this->sellingPrice == other.sellingPrice && this->kmDriven == other.kmDriven && this->fuel == other.fuel && this->sellerType == other.sellerType && this->transmission == other.transmission && this->owner == other.owner && this->mileage == other.mileage && this->engine == other.engine && this->maxPower == other.maxPower && this->torque == other.torque && this->seats == other.seats;
    }

    // Overloading > operator to compare details of (int, float and Double Datatype)
    bool operator>(const Car& other) const{
        return this->year>other.year && this->sellingPrice>other.sellingPrice && this->kmDriven>other.kmDriven && this->owner>other.owner && this->mileage>other.mileage && this->engine>other.engine && this->maxPower>other.maxPower && this->torque>other.torque && this->seats>other.seats;
    }

    // Overloading < operator to compare details of (int, float and Double Datatype)
    bool operator<(const Car& other) const{
        return sellingPrice < other.sellingPrice;
    }

    // Overloading >= operator to compare details of (int, float and Double Datatype)
    bool operator>=(const Car& other) const{
        return this->year>=other.year && this->sellingPrice>=other.sellingPrice && this->kmDriven>=other.kmDriven && this->owner>=other.owner && this->mileage>=other.mileage && this->engine>=other.engine && this->maxPower>=other.maxPower && this->torque>=other.torque && this->seats>=other.seats;
    }

    // Overloading <= operator to compare details of (int, float and Double Datatype)
    bool operator<=(const Car& other) const{
        return this->year<=other.year && this->sellingPrice<=other.sellingPrice && this->kmDriven<=other.kmDriven && this->owner<=other.owner && this->mileage<=other.mileage && this->engine<=other.engine && this->maxPower<=other.maxPower && this->torque<=other.torque && this->seats<=other.seats;
    }

    // Overloading != operator to compare details of (int, float and Double Datatype)
    bool operator!=(const Car& other) const{
        return !(this->year==other.year && this->sellingPrice==other.sellingPrice && this->kmDriven==other.kmDriven && this->owner==other.owner && this->mileage==other.mileage && this->engine==other.engine && this->maxPower==other.maxPower && this->torque==other.torque && this->seats==other.seats);
    }

    // Display car details
    friend ostream& operator<<(ostream& output, const Car& car);
    
    //Input Car Details 
    friend istream& operator>>(istream& input, Car& car);

    string getName(){
        return name;
    }
    double getSellingPrice(){
        return sellingPrice;
    }
    double getMaxPower(){
        return maxPower;
    }
    double getMileage(){
        return mileage;
    }
    double getTorque(){
        return torque;
    }
    
};


ostream& operator<<(ostream& output, const Car& car){
    output<<"Name"<<car.name<<endl;
    output<<"Year"<<car.year<<endl;
    output<<"Selling Price"<<car.sellingPrice<<endl;
    output<<"KM Driven"<<car.kmDriven<<endl;
    output<<"Fuel"<<car.fuel<<endl;
    output<<"Seller Type"<<car.sellerType<<endl;
    output<<"Transmission"<<car.transmission<<endl;
    output<<"Owner"<<car.owner<<endl;
    output<<"Mileage"<<car.mileage<<endl;
    output<<"Engine"<<car.engine<<endl;
    output<<"Max Power"<<car.maxPower<<endl;
    output<<"Torque"<<car.torque<<endl;
    output<<"Seats"<<car.seats<<endl;
}

istream& operator>>(istream& input, Car& car){
    cout<<"Enter Name: ";
    input>>car.name;
    cout<<"Enter Year: ";
    input>>car.year;
    cout<<"Enter Selling Price: ";
    input>>car.sellingPrice;
    cout<<"Enter KM Driven: ";
    input>>car.kmDriven;
    cout<<"Enter Fuel: ";
    input>>car.fuel;
    cout<<"Enter Seller Type: ";
    input>>car.sellerType;
    cout<<"Enter Transmission: ";
    input>>car.transmission;
    cout<<"Enter Owner: ";
    input>>car.owner;
    cout<<"Enter Mileage: ";
    input>>car.mileage;
    cout<<"Enter Engine: ";
    input>>car.engine;
    cout<<"Enter Max Power: ";
    input>>car.maxPower;
    cout<<"Enter Torque: ";
    input>>car.torque;
    cout<<"Enter Seats: ";
    input>>car.seats;
}


class Garage{
private:
	Car* cars;
	int numOfCars;

public:
    // Constructor to make cars null
    Garage() : cars(nullptr), numOfCars(0){}
    
    // Overloading + operator to Add car using user input use the operator overloading as done in Car Class
    Garage operator+(Car& other){
        cin>>other;
        Car* temp = new Car[numOfCars+1];
        if(cars != nullptr){
            for(int i=0;i<numOfCars;i++) temp[i] = cars[i];
            temp[numOfCars] = other;
        }
        else{
            cars = new Car[1];
            cars[0] = other;
        }
        delete[] cars;
        cars = temp;

        numOfCars++;
        return *this;
    }

    // Overloading += operator to Add car of another garage
    Garage& operator+=(const Car& other){
        Car* temp = new Car[numOfCars+1];
        if(cars != nullptr){
            for(int i=0;i<numOfCars;i++) temp[i] = cars[i];
            temp[numOfCars] = other;
            delete[] cars;
            cars = temp;
        }
        else{
            cars = new Car[1];
            cars[0] = other;
        }

        numOfCars++;       
        return *this;
    }

    // Overloading - operator to remove car using index
    Garage operator-(int index){
        if(index < numOfCars && index >= 0){
            Car* temp = new Car[numOfCars-1];
            if(cars != nullptr){
                for(int i=0;i<numOfCars;i++) if(i != index) temp[i] = cars[i];
                delete[] cars;
                cars = temp;
            }
        }
        return *this;
    }

    // Overloading -= operator to remove car using name
    Garage& operator-=(Car& other){
        Car* temp = new Car[numOfCars-1];
        if(cars != nullptr){
            for(int i=0;i<numOfCars;i++) if(cars[i].getName() != other.getName()) temp[i] = cars[i];
            delete[] cars;
            cars = temp;
        }
        return *this;
    }

    // Overloading == operator to compare details of two Garage for each car
    bool operator==(const Garage& other) const{
        if(this->numOfCars != other.numOfCars) return false;
        for(int i=0;i<this->numOfCars;i++){
            if(!(this->cars[i] == other.cars[i])) return false;
        }
        return true;
    }

    // Overloading > operator to compare Avg price of 2 garage
    bool operator>(const Garage& other) const{
        double avr1 = 0, avr2 = 0;
        for(int i=0;i<this->numOfCars;i++) avr1 += this->cars[i].getSellingPrice();
        avr1 /= this->numOfCars;
        for(int i=0;i<other.numOfCars;i++) avr2 += other.cars[i].getSellingPrice();
        avr2 /= other.numOfCars;
        return avr1 > avr2;
    }

    // Overloading < operator to average maxPower of cars of 2 garage
    bool operator<(const Garage& other) const{
        double avr1 = 0, avr2 = 0;
        for(int i=0;i<this->numOfCars;i++) avr1 += this->cars[i].getMaxPower();
        avr1 /= this->numOfCars;
        for(int i=0;i<other.numOfCars;i++) avr2 += other.cars[i].getMaxPower();
        avr2 /= other.numOfCars;
        return avr1 < avr2;
    }

    // Overloading >= operator to compare Average Mileage of 2 Garage
    bool operator>=(const Garage& other) const{
        double avr1 = 0, avr2 = 0;
        for(int i=0;i<this->numOfCars;i++) avr1 += this->cars[i].getMileage();
        avr1 /= this->numOfCars;
        for(int i=0;i<other.numOfCars;i++) avr2 += other.cars[i].getMileage();
        avr2 /= other.numOfCars;
        return avr1 >= avr2;       
    }

    // Overloading <= operator to compare Average torque of 2 garage
    bool operator<=(const Garage& other) const{
        double avr1 = 0, avr2 = 0;
        for(int i=0;i<this->numOfCars;i++) avr1 += this->cars[i].getTorque();
        avr1 /= this->numOfCars;
        for(int i=0;i<other.numOfCars;i++) avr2 += other.cars[i].getTorque();
        avr2 /= other.numOfCars;
        return avr1 <= avr2;       
    }

    // Overloading != operator to compare No of Cars of 2 garage
    bool operator!=(const Garage& other) const{
        return !(*this == other);
    }
    	
	friend ostream& operator<<(ostream& output, const Garage& garage);
    
};

ostream& operator<<(ostream& output, const Garage& garage){
    for(int i=0;i<garage.numOfCars;i++){
        cout<<"Car "<<i<<endl;
    }
}

int main(){
	//Test your classes here
    return 0;
}

