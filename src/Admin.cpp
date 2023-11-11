#include <iostream>
#include <vector>
#include <string>

#include "User.h"

class Admin : public User{
public:
    Admin(const std::string& userID, const std::string& username, const std::string& password)
    : User(userID, username, password){

    }

    //Method to create a profile
    void createProfile(int userType, const std::string& uID, const std::string& uName, const std::string& pWord){
        //note: requires database interaction
    }

    //Method to delete a profile
    void deleteProfile(const std::string& uID){
        //note: requires database interaction
    }

    //Method to modify a profile
    void modifyProfile(const std::string& uID){
        //note: requires database interaction
    }

    //Method to manually save a local backup file
    void saveBackup(const std::string& filepath){
        
    }

    //Method to load a local backup file
    void loadBackup(const std::string& filepath){
        
    }
};