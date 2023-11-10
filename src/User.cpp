#include "User.h"

User::User(const std::string& uID, const std::string& uName, const std::string& pWord)
    : userID(uID), username(uName), password(pWord) {}

std::string User::getUserID() const {
    return userID;
}

std::string User::getUsername() const {
    return username;
}

void User::setPassword(const std::string& newPassword) {
    password = newPassword;
}