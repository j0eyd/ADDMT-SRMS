#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Student.h"
#include "Teacher.h"
// #include "Course.h"
// #include "Grade.h"
// #include "Attendance.h"
#include <vector>

class Admin : public User {
public:
    Admin(const std::string& userID, const std::string& username, const std::string& password);
    ~Admin();

    void createProfile(int userType, const std::string& uID, const std::string& uName, const std::string& pWord);
    void deleteProfile(const std::string& uID);
    void modifyProfile(const std::string& uID);
    void saveBackup(const std::string& filepath);
    void loadBackup(const std::string& filepath);

    // Additional methods as required...
};

#endif