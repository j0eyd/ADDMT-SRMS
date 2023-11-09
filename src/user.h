#ifndef USER_H
#define USER_H

#include <string>

class User{
protected:
    std::string userID;
    std::string username;
    std::string password;

public:
    User(const std::string& userID, const std::string& username, const std::string& password);
    virtual ~User() {}

    //Accessor Methods
    std::string getUserID() const;
    std::string getUsername() const;

    //Mutator Methods
    void setPassword(const std::string& newPassword);
};

#endif 