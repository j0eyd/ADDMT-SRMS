#include "Admin.h"

// Constructor
Admin::Admin(Database& db) : db(db) {}

void Admin::createStudentProfile(const Student& student) {
    db.saveStudent(new Student(student)); // Assuming a copy constructor for Student
}

void Admin::deleteStudentProfile(const std::string& studentId) {
    db.deleteStudent(studentId);
}


void Admin::createTeacherProfile(const Teacher& teacher) {
    db.saveTeacher(new Teacher(teacher)); // Assuming a copy constructor for Teacher
}

void Admin::deleteTeacherProfile(const std::string& teacherId) {
    db.deleteTeacher(teacherId);
}