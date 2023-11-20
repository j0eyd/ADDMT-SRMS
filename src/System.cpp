#include "System.h"
#include <sstream>

std::vector<User*> usersData;

void initializeSystem() {
    using namespace std;
    
    ifstream inFile("temp.txt");
    if (!inFile.is_open()) { // Correct usage to check if the file is open
        cerr << "Unable to open file data/temp.txt" << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        istringstream iss(line);
        vector<string> tokens;
        string token;
        
        // Simple txt parsing
        while (getline(iss, token, ',')) {
            tokens.push_back(token);
        }

        int id = stoi(tokens[0]);
        string username = tokens[1];
        string password = tokens[2];
        string firstName = tokens[3];
        string lastName = tokens[4];
        string type = tokens[5];
        string bioOrCourses = tokens[6];

        if (type == "Student") {
            Student* student = new Student(id, username, password, firstName, lastName, {}, {});
            student->setBiography(bioOrCourses);
            usersData.push_back(student);
        } else if (type == "Teacher") {
            vector<Course*> courses; // Placeholder for actual courses
            Teacher* teacher = new Teacher(id, username, password, firstName, lastName, courses);
            // teacher->setCoursesTaughtFromString(bioOrCourses); // Placeholder for actual implementation
            usersData.push_back(teacher);
        }
    }

    inFile.close();
}

User* authenticateUser(const std::string& username, const std::string& password) {
    
    // check the user from a list of users ( though nor sure where we put 
    // all the users' name and password)
    for (User* user : usersData) {
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
            case 1: {
                vector<Course*> courses = student->getCoursesEnrolled();
                
                for (Course* course : courses) {
                    vector<Grade*> grades = student->getCourseGrades(*course);
                    
                    std::cout << "Grades for " << course->getName() << ":" << std::endl;
                    for (Grade* grade : grades) {
                        std::cout << "  - Grade ID: " << grade->getIdentifier()
                                  << ", Score: " << grade->getPoints() 
                                  << " out of " << grade->getOutOf()
                                  << ", Weighted: " << grade->getValue() << std::endl;
                    }
                }
                break;  // Ensure you include a break after each case where you declare new variables
            }
            case 2: {
                vector<Course*> courses = student->getCoursesEnrolled();
                for (Course* course : courses) {
                    std::cout << "Course: " << course->getName() << std::endl; 
                }
                break;
            }
            case 3: {
                std::string newBiography;
                std::cout << "Enter new biography: ";
                std::cin.ignore(); // To ignore the newline character from previous input
                std::getline(std::cin, newBiography); // Use getline to handle spaces in the biography
                student->setBiography(newBiography);
                break;
            }
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
        std::cout << "1. Show Courses Teach\n"
                  << "2. View Grades and Attendance\n"
                  << "3. Modify Grades\n"
                  << "4. Logout\n"
                  << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1: {
                // Get the courses the teacher is teaching
                vector<Course*> courses = teacher->getCoursesTaught();
                std::cout << "Courses taught by " << teacher->getFirstName() << ":" << std::endl;
                for (Course* course : courses) {
                    std::cout << "  - " << course->getName() << std::endl;
                }
                break;
            }
            case 2: {
                for (auto& course : teacher->getCoursesTaught()) {
                    std::cout << "Course: " << course->getName() << std::endl;
                    std::cout << "Student's name and grades:" << std::endl;

                    // For each course, iterate through each student enrolled
                    for (auto& student : course->getStudents()) {
                        // Get student's name
                        std::cout << student->getFirstName() + student->getLastName() << std::endl;

                        // Now get and display the student's grade for the course
                        auto grades = teacher->getStudentCourseGrades(*student, *course);
                        for (auto& grade : grades) {
                            std::cout << "  Grade: " << grade->getPoints() << std::endl;  
                        }
                    }
                    std::cout << std::endl; 
                }
                break;
            }
            case 3: {
                // we need to select a student and grade first
                Student* selectedStudent = nullptr; // Set to a valid student
                // Course* selectedCourse; // Set to a valid course
                Grade* gradeToModify = nullptr; // Set to the grade to modify
                string newIdentifier;
                float newPoints, newOutOf, newCoeff;

                // enter the new grades
                cout << "Enter the new points for the grade: ";
                cin >> newPoints;
                cout << "Enter the new total points possible for the grade: ";
                cin >> newOutOf;
                // Maybe add newIdentifier and newCoeff?

                // Perform the grade modification
                if (teacher->modifyStudentGrade(*selectedStudent, *gradeToModify, newIdentifier, newPoints, newOutOf, newCoeff)) {
                    cout << "Grade modified successfully.\n";
                } else {
                    cout << "Failed to modify grade.\n";
                }
                break;
            }
            case 4:
                std::cout << "Logging out...\n";
                return;
            default:
                std::cout << "Invalid option. Please try again.\n";
                break;
        }
    }
}


void cleanupSystem(){
    for(User* user : usersData){
        delete user;
    }
    usersData.clear();
}