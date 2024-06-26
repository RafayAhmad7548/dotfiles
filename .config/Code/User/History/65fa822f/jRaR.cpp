/*
Rafay Ahmad
23I-2526
*/
#include <iostream>
using namespace std;

struct Student{
    string name;
    int rollNo;
    Student(){}
    Student(string name, int rollNo) : name(name), rollNo(rollNo){}
};

class Course{

    string name;
    int code;
    Student **students;
    int i;

public: 

    Course(string name, int code) : name(name), code(code), i(0){
        students = new Student*[2];
    }

    void enrollStudent(Student *s){
        students[i] = s;
        i++;
    }

    friend ostream& operator<<(ostream& out, Course& course);

};

ostream& operator<<(ostream& out, Course& course){
    
}

int main() {
    Student student1("Shahood", 1001);
    Student student2("Hammad", 1002);
    Student student3("Ali", 1003);

    Course course1("Math", 2001);
    Course course2("Physics", 2002);

    course1.enrollStudent(&student1);
    course1.enrollStudent(&student2);
    course2.enrollStudent(&student2);
    course2.enrollStudent(&student3);

    cout << course1 << endl;
    cout << course1 << endl;
    return 0;
}