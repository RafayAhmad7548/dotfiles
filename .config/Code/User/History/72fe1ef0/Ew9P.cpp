#include<iostream>
#include<string>
using namespace std;

class Student {
private:
    int stdID;
    string name;
    string* courseCodes;
    int numOfCourses;
    int* courseGrades; 
    float gpa;

public:
    // Constructor with initial empty arrays
    Student() : stdID(0), name(""), numOfCourses(0), gpa(0.0) {
        courseCodes = nullptr; 
        courseGrades = nullptr;
    }

    // Constructor with initial empty arrays
    Student(int id, string firstName) : stdID(id), name(firstName), numOfCourses(0), gpa(0.0) {
        courseCodes = nullptr;
        courseGrades = nullptr;
    }

    ~Student() {
        delete[] courseCodes;
        delete[] courseGrades;
    }
	
    //getters
    int getStdID() { return stdID; }
    string getName() { return name; }
    int getNumOfCourses() { return numOfCourses; }
    string getCourseCodes(int i) { return courseCodes[i]; }
    int getCourseGrades(int i) { return courseGrades[i]; }
    float getGPA() { return gpa; }

    //setters
    void setStdID(int id) { stdID = id; }
    void setName(string firstName) { name = firstName; }

    void setCourseGrades(string codeCourses, int grade) {
        for (int i = 0; i < numOfCourses; i++) {
            if (courseCodes[i] == codeCourses) {
                courseCodes[i] = grade;
                return;
            }
        }
        cout << "Course code not found." << endl;
    }

    //Other member functions
    void addCourse(string courseCode, int grade) {
        string* newCourseCodes = new string[numOfCourses + 1];
        int* newCourseGrades = new int[numOfCourses + 1];

        // Copy existing data to new arrays
        for (int i = 0; i < numOfCourses; i++) {
            newCourseCodes[i] = courseCodes[i];
            newCourseGrades[i] = courseGrades[i];
        }

        // Add new course code and grade
        newCourseCodes[numOfCourses] = courseCode;
        newCourseGrades[numOfCourses] = grade;

        // Delete old arrays (if they exist)
        delete[] courseCodes;
        delete[] courseGrades;

        // Update member variables with new arrays and increment course count
        courseCodes = newCourseCodes;
        courseGrades = newCourseGrades;
        numOfCourses++;
    }

    void calcGPA() {
       float sum = 0.0;
       for (int i = 0; i < numOfCourses; i++) {
           sum += courseGrades[i];         
       }
       if (numOfCourses != 0) {
           gpa = sum / numOfCourses; 
       } else {
           gpa = 0.0; 
       }
    }
    
};

//Global Functions
Student getStudentAt(Student students[], int index) { return students[index]; }

float calcClassGPA(Student students[], int numStudents) {
    float totalGPA = 0.0;
    for (int i = 0; i < numStudents; i++) {
        students[i].calcGPA();
        totalGPA += students[i].getGPA();
    }
    if (numStudents != 0) {
        totalGPA = totalGPA / numStudents;
    } else {
        totalGPA = 0.0;
    }
    return totalGPA;
}

float getMaxGPA(Student students[], int numStudents) {
    float maxGPA = 0.0;
    for (int i = 0; i < numStudents; i++) {
        students[i].calcGPA();
        if (students[i].getGPA() > maxGPA) {
            maxGPA = students[i].getGPA();
        }
    }
    return maxGPA;
}

float getMinGPA(Student students[], int numStudents) {
    float minGPA = 100.0;
    for (int i = 0; i < numStudents; i++) {
        students[i].calcGPA();
        if (students[i].getGPA() < minGPA) {
            minGPA = students[i].getGPA();
        }
    }
    return minGPA;
}

void printStudentRecord(Student student) {
   cout << "Student ID: " << student.getStdID() << endl;
   cout << "Name: " << student.getName() << endl;
   cout << "Taken courses: " << student.getNumOfCourses() << endl;
   for (int i = 0; i < student.getNumOfCourses(); i++) {
       cout << "Course code: " << student.getCourseCodes(i) << "Grade: " << student.getCourseGrades(i) << endl; 
   }     
   cout << "GPA: " << student.getGPA() << endl;
}

void printAllStudentRecords(Student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        cout << "Student " << i + 1 << ": " << endl;
        printStudentRecord(students[i]);
        cout << endl; 
    }
}

int main() {
    int numStudents;
    cout << "Enter total number of students in class: ";
    cin >> numStudents;

    Student students[numStudents];
    for (int i = 0; i < numStudents; i++) {
        string name;
        int id;
        int numCourses;

        cout << "Enter the name and ID of Student " << i + 1 << ": " << endl;
        cout << "Name: ";
        cin >> name;
        cout << "ID: ";
        cin >> id;
        cout << "Enter the number of courses taken by the student: ";
        cin >> numCourses;

        students[i] = Student(id, name);
        for (int j = 0; j < numCourses; j++) {
            int grade;
            string courseCode;

            cout << "Enter course code for course " << j + 1 << ": ";
            cin >> courseCode;
            cout << "Enter grade for course " << j + 1 << ": ";
            cin >> grade;

            students[i].addCourse(courseCode, grade);
        }

    }

    cout << "Class GPA: " << calcClassGPA(students, numStudents) << endl;
    cout << "Maximum GPA: " << getMaxGPA(students, numStudents) << endl;
    cout << "Minimum GPA: " << getMinGPA(students, numStudents) << endl;

    cout << "Printing Student Records: " << endl;
    printAllStudentRecords(students, numStudents);

    return 0;
}