#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string userID;
    std::string username;
    std::string password;

public:
    // Constructors
    User();
    User(const std::string& uID, const std::string& uName, const std::string& pWord);
    // Destructor
    virtual ~User(); // Virtual if inheritance is used

    // Accessor Methods
    std::string getUserID() const;
    std::string getUsername() const;

    // Mutator Methods
    void setPassword(const std::string& newPassword);
};

#endif // USER_H
