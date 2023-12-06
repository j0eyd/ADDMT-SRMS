#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
#include "lib/sqlite3.h"
using namespace std;

// Constructor
bool newUser(sqlite3* db, string& username,  string& password,
     string& firstName,  string& lastName, int& type);
// Destructor
bool deleteUser(sqlite3* db, int userID);

// Accessor Methods
int getUserID(sqlite3* db, string username);
string getUsername(sqlite3* db, int UserID);
string getPassword(sqlite3* db, int UserID);
string getFirstName(sqlite3* db, int UserID);
string getLastName(sqlite3* db, int UserID);
int getUserType(sqlite3* db, int UserID);

bool modifyUsername(sqlite3* db, int UserID, string newUsername);
bool modifyPassword(sqlite3* db, int UserID, string newPassword);

void UserTester(sqlite3* db);
#endif // USER_H
