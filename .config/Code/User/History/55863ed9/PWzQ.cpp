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

int main(){

    

    return 0;
}