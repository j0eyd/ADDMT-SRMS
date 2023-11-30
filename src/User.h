#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <algorithm>
#include "sqlite3.h"
using namespace std;

class User {
protected:
    int ID;
    string username;
    string password;
    string firstName;
    string lastName;
public:
    // Constructors
    User();
    User(const int& ID, const string& username, const string& password,
        const string& firstName, const string& lastName);
    // Destructor
    virtual ~User(); // Virtual if inheritance is used

    // Accessor Methods
    int getID() const;
    string getUsername() const;
    string getPassword() const;
    string getFirstName() const;
    string getLastName() const;

    // Mutator Methods
    void setID(const int& newID);
    void setUsername(const string& newUsername);
    void setPassword(const string& newPassword);
    void setFirstName(const string& newFirstName);
    void setLastName(const string& newLastName);
};

#endif // USER_H
