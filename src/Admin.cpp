#include "Admin.h"

// Constructor
Admin::Admin(Database& db) : db(db) {}

// Student Part
void Admin::createStudentProfile(const int& ID, const string& username, const string& password, 
            const string& firstName, const string& lastName) {
    db.saveStudent(new Student(ID, username, password, firstName, lastName)); // Assuming a copy constructor for Student
}

void Admin::deleteStudentProfile(Student& oldStudent) {
    db.deleteStudent(to_string(oldStudent.getID()));
}

// Teacher Part
void Admin::createTeacherProfile(const int& ID, const string& username, const string& password, 
            const string& firstName, const string& lastName) {
    db.saveTeacher(new Teacher(ID, username, password, firstName, lastName)); 
}

void Admin::deleteTeacherProfile(const Teacher& teacher) {
    db.deleteTeacher(to_string(teacher.getID()));
}

// Course Part
void Admin::createCourse(int& ID, const string& name, Teacher& teacher, vector<Lecture*> lectures, vector<Student*>& students){
    Course newCourse = Course();
    // prompt for create ID
    cout << ("Think of an ID of the Course: ");
    cin >> ID;
    newCourse.setID(ID);
    
    // prompt for name.
    newCourse.setName(name);
    
    // prompt for teacher.
    newCourse.setTeacher(teacher);

    // add lectures
    for(Lecture* lecture : lectures){
        newCourse.addLecture(*lecture);
    }
    
    // add students
    for(Student* student : students){
        newCourse.addStudent(*student);
    }

    // The system insert it into the database
}

void Admin::deleteCourse(const int& ID){
    
}

void Admin::modifyStudentGrade(const string& studentId, const string& courseId, float newGrade) {
    db.modifyStudentGrade(studentId, courseId, newGrade);
    db.saveToFile("database.csv"); // Save the updated data to the CSV file
}
