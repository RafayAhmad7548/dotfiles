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

    // getters
    int getStdID(){
        return stdID;
    }
    string getName(){
        return name;
    }
    string* getCourseCodes(){
        return courseCodes;
    }
    int getNumOfCourses(){
        return numOfCourses;
    }
    int* getCourseGrades(){
        return courseGrades;
    }
    float getGPA(){
        return gpa;
    }






};

int main(){

    

    return 0;
}