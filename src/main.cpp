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
#include "System.h" 

int main() {
    // Initialize the system (load users)
    initializeSystem();

    while (true) {
        std::string username;
        std::string password;

        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;

        // Check if username and password matched
        User* user = authenticateUser(username, password);

        if (user) {
            // Determine the role of the user and call the appropriate menu
            Student* student = dynamic_cast<Student*>(user);
            Teacher* teacher = dynamic_cast<Teacher*>(user);
            Admin* admin = dynamic_cast<Admin*>(user);

            if (student) {
                // Show student menu
                showStudentMenu(student);
            } else if (teacher) {
                // Show teacher menu
                showTeacherMenu(teacher);
            } else if (admin) {
                // If there is a specific menu for admin, call it here
                // showAdminMenu(admin);
            } else {
                std::cerr << "Authenticated user has an unknown role." << std::endl;
            }
        } else {
            std::cerr << "Login failed. Please try again." << std::endl;
        }

        // Potentially add a way to exit the loop and close the application
        std::cout << "Enter 'exit' to close the application, or anything else to try logging in again: ";
        std::string command;
        std::cin >> command;
        if (command == "exit") {
            break;
        }
    }

    // Perform any necessary cleanup
    cleanupSystem(); // Make sure this function deallocates memory and performs other cleanup tasks

    return 0;
}
