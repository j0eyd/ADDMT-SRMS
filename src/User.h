#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
protected:
    int ID;
    string username;
    string password;
public:
    // Constructors
    User();
    User(const int& ID, const string& uName, const string& pWord);
    // Destructor
    virtual ~User(); // Virtual if inheritance is used

    // Accessor Methods
    int getID() const;
    string getUsername() const;

    // Mutator Methods
    void setPassword(const string& newPassword);
    void setUsername(string newUsername);
    void setID(int ID);
};

#endif // USER_H
