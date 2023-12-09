#ifndef DATABASE_H
#define DATABASE_H

#include "lib/sqlite3.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

void displayAllTables(sqlite3 *db);
bool deleteTable(sqlite3* db, const std::string& tableName);
bool createUsersTable(sqlite3* db);
bool createCoursesTable(sqlite3* db);
bool createLecturesTable(sqlite3* db);
bool createStudentsTable(sqlite3* db);
bool createTeachersTable(sqlite3* db);
bool createGradesTable(sqlite3* db);
bool createTables(sqlite3 *db);

#endif
