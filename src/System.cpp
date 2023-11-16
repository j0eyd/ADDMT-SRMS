#include "System.h"



User* authenticateUser(const std::string& username, const std::string& password) {
    
    // check the user from a list of users ( though nor sure where we put 
    // all the users' name and password)
    for (User* user : users) {
        if (user->getUsername() == username && user->getPassword() == password) {
            // User is authenticated
            return user;
        }
    }
    // No match found, return nullptr
    return nullptr;
}

void showStudentMenu(Student* student) {
    int choice = 0;
    while (choice != 4) {
        std::cout << "1. View Grades\n2. View Courses\n3. Modify Profile\n4. Logout\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                student->getCourseGrades();
                break;
            case 2:
                student->getCoursesEnrolled();
                break;
            case 3:
                student->setBiography();
                break;
            case 4:
                std::cout << "Logging out...\n";
                break;
            default:
                std::cout << "Invalid option. Please try again.\n";
                break;
        }
    }
}

void showTeacherMenu(Teacher* teacher) {
    int choice = 0;
    while (choice != 4) {
        std::cout << "1. Show Courses Teach\n2. View Grades and Attendance\n3. Modify Grades\n4. Logout\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                teacher->getCoursesTaught();
                break;
            case 2:
                teacher->getStudentCourseGrades();
                teacher -> getStudentLectureAttendance();
                break;
            case 3:
                teacher->modifyStudentGrade();
                break;
            case 4:
                std::cout << "Logging out...\n";
                break;
            default:
                std::cout << "Invalid option. Please try again.\n";
                break;
        }
    }
}
