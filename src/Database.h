#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include "User.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"

class Database {
private:
    std::vector<Teacher*> teacherList;
    std::vector<Student*> studentList;
    std::vector<Course*> courseList;

public:
    Database();
    ~Database();

    void saveStudent(Student* student);
    void deleteStudent(const std::string& studentId);
    void saveTeacher(Teacher* teacher);
    void deleteTeacher(const std::string& teacherId);
    void saveCourse(Course* course);
    void deleteCourse(const std::string& courseId);

    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);
    void modifyStudentGrade(const std::string& studentId, const std::string& courseId, float newGrade);

    // Prevent copying and assignment
    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;

    // Allow move semantics
    Database(Database&&) noexcept;
    Database& operator=(Database&&) noexcept;
};

#endif // DATABASE_H