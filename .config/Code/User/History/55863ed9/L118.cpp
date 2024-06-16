/*
Rafay Ahmad
23I-2526
*/
#include <iostream>
using namespace std;

class Student{
    int stdID;
    string name;
    string *courseCodes;
    int numOfCourses;
    int *courseGrades;
    float gpa;

public:

    int getStdID(){
        return stdID;
    }
    string getName(){
        return name;
    }
    string getCourseCodes(int i){
        return courseCodes[i];
    }
    int getNumOfCourses(){
        return numOfCourses;
    }
    int getCourseGrade(int i){
        return courseGrades[i];
    }
    float getGPA(){
        return gpa;
    }

    void setStdID(int stdID){
        this->stdID = stdID;
    }
    void setName(string name){
        this->name = name;
    }

    void setCourseGrade(string courseCode, int grade){
        for(int i=0;i<numOfCourses;i++){
            if(courseCodes[i] == courseCode){
                courseGrades[i] = grade;
                break;
            }
        }
    }

    void addCourse(string courseCode, int grade){

    }

    void calcGPA(){
        
    }

};

Student getStudentAt(Student students[], int index){
    return students[index];
}

float calcClassGPA(Student students[], int numStudents){
    int sum = 0;
    for(int i=0;i<numStudents;i++) sum += students[i].getGPA();
    return sum/numStudents;
}

int getMinGPA(Student students[], int numStudents){
    int min = students[0].getGPA();
    for(int i=1;i<numStudents;i++) if(students[i].getGPA()<min) min = students[i].getGPA();
    return min;
}

void printStudentRecord(Student student){
    cout<<"ID: "<<student.getStdID()<<endl;
    cout<<"Name: "<<student.getName()<<endl;
    for(int i=0;i<student.getNumOfCourses();i++) cout<<"Course Code"<<student.getCourseCodes(i)<<" Grade: "<<student.getCourseGrade(i)<<endl;
    cout<<"No of Course: "<<student.getNumOfCourses()<<endl;
    cout<<"GPA: "<<student.getGPA()<<endl;
}

int main(){

    

    return 0;
}