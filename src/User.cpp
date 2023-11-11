#include "User.h"

User::User(const std::string& uID, const std::string& uName, const std::string& pWord)
    : userID(uID), username(uName), password(pWord) {}

string User::getID() const {
    return userID;
}

string User::getName() const {
    return username;
}

void User::setPassword(const std::string& newPassword) {
    password = newPassword;
}