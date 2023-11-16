#include <iostream>
#include <vector>
#include <string>
#include "Admin.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "Lecture.h"
#include "Grade.h"
#include "User.h"
using namespace std;

int main() {
    // test
    Admin admin("admin1", "adminuser", "adminpassword");
    Student student(1, "studentuser", "studentpassword", "John", "Doe", std::vector<Course*>(), std::vector<Grade*>());
    Teacher teacher(2, "teacheruser", "teacherpassword", "Jane", "Smith", std::vector<Course*>());

    Course course;
    Lecture lecture;

    // Example of creating a Grade
    Grade grade(student, course, "grade1", 95.0, 100.0, 95.0, 1.0);

    while(true){
        string username;
        string password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        //Check if username and password matched
        // code: ...


        
    }

    return 0;
}