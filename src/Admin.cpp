#include "Admin.h"

// Constructor
Admin::Admin(Database& db) : db(db) {}

void Admin::createStudentProfile(const int& ID, const string& username, const string& password, 
            const string& firstName, const string& lastName) {
    db.saveStudent(new Student(ID, username, password, firstName, lastName)); // Assuming a copy constructor for Student
}

void Admin::deleteStudentProfile(Student& oldStudent) {
    db.deleteStudent(to_string(oldStudent.getID()));
}

void Admin::createTeacherProfile(const int& ID, const string& username, const string& password, 
            const string& firstName, const string& lastName) {
    db.saveTeacher(new Teacher(ID, username, password, firstName, lastName)); 
}

void Admin::deleteTeacherProfile(const Teacher& teacher) {
    db.deleteTeacher(to_string(teacher.getID()));
}

void Admin::modifyStudentGrade(const string& studentId, const string& courseId, float newGrade) {
    db.modifyStudentGrade(studentId, courseId, newGrade);
    db.saveToFile("database.csv"); // Save the updated data to the CSV file
}