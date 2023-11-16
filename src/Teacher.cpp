#include "Teacher.h"

Teacher::Teacher() {}

Teacher::Teacher(const int& ID, const string& username, const string& password,
            const string& firstName, const string& coursesTaught,
            vector<Course*> courses)
    : User(ID, username, password, firstName, lastName), coursesTaught(courses) {}

Teacher::~Teacher() {}


vector<Course*> Teacher::getCoursesTaught() const{
    return coursesTaught;
}

bool Teacher::getStudentLectureAttendance(const Lecture& lecture, Student& student) const{
    return lecture.getAttendanceStatus(student);
}

vector<Grade*> Teacher::getStudentCourseGrades(const Student& student,
        Course& course) const{
    return student.getCourseGrades(course);
}

bool Teacher::addCourseTaught(Course& course){
    auto it = find(coursesTaught.begin(), coursesTaught.end(), &course);
    if (it!=coursesTaught.end()) return false; //course already present
    coursesTaught.push_back(&course);
    return true;
}

bool Teacher::dropCourseTaught(Course& course){
    auto it = find(coursesTaught.begin(), coursesTaught.end(), &course);
    if (it==coursesTaught.end()) return false; //course already absent
    coursesTaught.erase(it);
    return true;
}

bool Teacher::addLecturePresentStudent(Lecture& lecture, Student& student){
    return lecture.addAttendingStudent(student);
}

bool Teacher::dropLectureMissingStudent(Lecture& lecture, Student& student){
    return lecture.addMissingStudent(student);
}

bool Teacher::addStudentGrade(Student& student, Grade& grade){
    return student.addGrade(grade);
}

bool Teacher::modifyStudentGrade(const Student& student, Grade& grade,
        const float& newIdentifier, const float& newPoints, const float& newOutOf,
        const float& newCoeff){
    return ;
}

bool Teacher::dropStudentGrade(Student& student, Grade& oldGrade){
    student.dropGrade(oldGrade);
}