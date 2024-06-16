/*
Rafay Ahmad
23I-2526
*/
#include <iostream>
using namespace std;

struct Address{
    string street;
    int zipCode;
};

struct Student{
   string name;
   int rollNumber;
   Address address;

    void setStudentInfo(const string& studentName, int rollNo, const string& street, int zipCode){
        name = studentName;
        rollNumber = rollNo;
        address.street = street;
        address.zipCode = zipCode;
    }

    void displayStudentInfo(){
        cout<<"Name: "<<name<<endl;
        cout<<"Roll No: "<<rollNumber<<endl;
        cout<<"street: "<<address.street<<endl;
        cout<<"zipcode: "<<address.zipCode<<endl;
    }
};

struct ExamRoom{
    int numRows;
    int numCols;
    int noOfStudents;
    Student* students;
    Student** seatingArrangment;

    void inputStudentRecords(int n){
        noOfStudents = n;
        students = new Student[n];
        for(int i=0;i<n;i++){
            cout<<"Enter student name: ";
            cin>>students[i].name;
            cout<<"Enter student rollno: ";
            cin>>students[i].rollNumber;
            cout<<"Enter student street: ";
            cin>>students[i].address.street;
            cout<<"Enter student zipcode: ";
            cin>>students[i].address.zipCode;
        }
    }

    void makeSeatingPlan(int rows, int cols){
        numRows = rows;
        numCols = cols;
        seatingArrangment = new Student*[numRows];
        for(int i=0;i<numRows;i++) seatingArrangment[i] = new Student[numCols];

        for(int i=0;i<noOfStudents;i++){
            for(int j=i;j<noOfStudents;j++){
                if(students[i].rollNumber>students[j].rollNumber){
                    int temp = students[i].rollNumber;
                    students[i].rollNumber = students[j].rollNumber;
                    students[j].rollNumber = temp;
                }
            }
        }

        for(int i=0, k=0;i<numCols;i++) for(int j=0;j<numRows;j++, k++) seatingArrangment[j][i] = students[k];

    }

    void displaySeatingPlan(){
        for(int i=0;i<numRows;i++){
            for(int j=0;j<numCols;j++) cout<<seatingArrangment[i][j].name<<" ";
            cout<<endl;
        }
    }

};

int main(){

    Student john;
    john.setStudentInfo("John Doe", 231234 ,"123 Main Street", 1234);
    john.displayStudentInfo();


    ExamRoom examRoom;
    cout<<"Enter Students\n";
    examRoom.inputStudentRecords(4);
    cout<<"Enter seating plan\n";
    examRoom.makeSeatingPlan(2, 2);
    cout<<endl;
    examRoom.displaySeatingPlan();

    delete[] examRoom.students;
    for(int i=0;i<3;i++) delete[] examRoom.seatingArrangment[i];
    delete[] examRoom.seatingArrangment;



    return 0;
}