#include "User.h"

User::User(){}

User::User(const int& ID, const string& username, const string& password)
    : ID(ID), username(username), password(password) {}

User::~User(){}

int User::getID() const {return ID;}

string User::getUsername() const {return username;}

string User::getPassword() const {return password;}

string User::getFirstName() const {return firstName;}

string User::getLastName() const {return lastName;}

void User::setID(const int& newID) {
    ID = newID;
}

void User::setUsername(const string& newUsername) {
    username = newUsername;
}

void User::setPassword(const string& newPassword) {
    password = newPassword;
}

void User::setFirstName(const string& newFirstName) {
    firstName = newFirstName;
}

void User::setLastName(const string& newLastName) {
    lastName = newLastName;
}
