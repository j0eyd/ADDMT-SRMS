#include "Admin.h"

bool newAdmin(sqlite3* db,  string username, string password,
    string firstName, string lastName){
    return newUser(db, username, password, firstName, lastName, 0);
}

bool deleteAdmin(sqlite3* db, int userID){
    return deleteUser(db, userID);
}