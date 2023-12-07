#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Course.h"
#include "Teacher.h"
#include <vector>

bool newAdmin(sqlite3* db,  string username, string password,
    string firstName, string lastName);

bool deleteAdmin(sqlite3* db, int userID);

#endif
