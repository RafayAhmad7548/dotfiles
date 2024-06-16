/*
Rafay Ahmad
23I-2526
Assignment 3
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

    Student(){
        stdID = 0;
        name = "";
        courseCodes = nullptr;
        numOfCourses = 0;
        courseGrades = nullptr;
        gpa = 0;
    }

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
        string* newCourseCodes = new string[numOfCourses + 1];
        int* newCourseGrades = new int[numOfCourses + 1];
        for(int i = 0; i < numOfCourses; i++){
            newCourseCodes[i] = courseCodes[i];
            newCourseGrades[i] = courseGrades[i];
        }
        newCourseCodes[numOfCourses] = courseCode;
        newCourseGrades[numOfCourses] = grade;

        delete[] courseCodes;
        delete[] courseGrades;

        courseCodes = newCourseCodes;
        courseGrades = newCourseGrades;
        numOfCourses++;
        
    }

    void calcGPA(){
        float gpa = 0;
        for(int i=0;i<this->numOfCourses;i++)
            gpa += courseGrades[i]/100.0 * 4;
        gpa /= numOfCourses;
        this->gpa = gpa;
    }

};

Student getStudentAt(Student students[], int index){
    return students[index];
}

float calcClassGPA(Student students[], int numStudents){
    float sum = 0;
    for(int i=0;i<numStudents;i++) sum += students[i].getGPA();
    return (float)sum/numStudents;
}

float getMinGPA(Student students[], int numStudents){
    float min = students[0].getGPA();
    for(int i=1;i<numStudents;i++) if(students[i].getGPA()<min) min = students[i].getGPA();
    return min;
}

void printStudentRecord(Student student){
    cout<<"ID: "<<student.getStdID()<<endl;
    cout<<"Name: "<<student.getName()<<endl;
    for(int i=0;i<student.getNumOfCourses();i++) cout<<"Course Code "<<student.getCourseCodes(i)<<" Grade: "<<student.getCourseGrade(i)<<endl;
    cout<<"No of Course: "<<student.getNumOfCourses()<<endl;
    cout<<"GPA: "<<student.getGPA()<<endl;
}

void printAllStudentRecords(Student students[], int numStudents){
    for(int i=0;i<numStudents;i++){
        printStudentRecord(students[i]);
        cout<<endl;
    }
}


int main(){

    Student students[3];
    for(int i=0;i<3;i++){
        int id;
        string name;
        cout<<"Enter ID: ";
        cin>>id;
        cout<<"Enter Name: ";
        cin>>name;
        students[i].setStdID(id);
        students[i].setName(name);
        int numCourses;
        cout<<"Enter number of courses: ";
        cin>>numCourses;
        for(int j=0;j<numCourses;j++){
            string courseCode;
            int grade;
            cout<<"Enter course code: ";
            cin>>courseCode;
            cout<<"Enter grade: ";
            cin>>grade;
            students[i].addCourse(courseCode, grade);
        }
        students[i].calcGPA();
    }

    printAllStudentRecords(students, 3);

    printStudentRecord(getStudentAt(students, 1));

    cout<<"Class GPA: "<<calcClassGPA(students, 3)<<endl;

    cout<<"Minimum GPA: "<<getMinGPA(students, 3)<<endl;


    return 0;
}