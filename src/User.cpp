#include "User.h"

User::User(){}

User::User(const int& ID, const string& name, const string& password)
    : ID(ID), username(name), password(password) {}

int User::getID() const {
    return ID;
}

string User::getUsername() const {
    return username;
}

void User::setPassword(const string& newPassword) {
    password = newPassword;
}

void User::setUsername(string newName) {
    username = newName;
}

void User::setID(int newID){
    ID = newID;
}