#include "lib/sqlite3.h"
#include <string>
#include <iostream>
using namespace std;

void displayAllTables(sqlite3 *db){
    const char *query = "SELECT name FROM sqlite_master WHERE type='table';";
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) != SQLITE_OK) {
        cerr << "Error preparing statement: " << sqlite3_errmsg(db) << endl;
        return;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        const char *tableName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        cout << "Table: " << tableName << endl;
        // Retrieve and display data from each table
        const char *query = ("SELECT * FROM " + string(tableName) + ";").c_str();
        if (sqlite3_exec(db, query, [](void *data, int argc, char **argv, char **colNames) -> int {
            for (int i = 0; i < argc; i++) {
                cout << colNames[i] << ": " << (argv[i] ? argv[i] : "NULL") << " | ";
            }
            cout << endl;
            return 0; 
        }, nullptr, nullptr) != SQLITE_OK) {
            cerr << "Error executing query for table " << tableName << ": " << sqlite3_errmsg(db) << endl;
        }
    }
    sqlite3_finalize(stmt);
}

bool deleteTable(sqlite3* db, const string& tableName){
    char* errMsg;
    string query = "DROP TABLE IF EXISTS " + tableName + ";";
    return sqlite3_exec(db, query.c_str(), 0, 0, &errMsg) == SQLITE_OK;
}

bool createUsersTable(sqlite3* db){
    char* errMsg;
    const char* query = "CREATE TABLE IF NOT EXISTS User ("
                        "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "username VARCHAR(25) NOT NULL,"
                        "password VARCHAR(25),"
                        "firstName VARCHAR(25),"
                        "lastName VARCHAR(25),"
                        "Type INT);"; //TYPES: 0: Admin | 1: Teacher | 2: Student
    int result = sqlite3_exec(db, query, 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

bool createCoursesTable(sqlite3* db){
    char* errMsg;
    const char* query = "CREATE TABLE IF NOT EXISTS Courses ("
                        "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "NAME VARCHAR(100));";
    int result = sqlite3_exec(db, query, 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

bool createLecturesTable(sqlite3* db){
    char* errMsg;
    const char* query = "CREATE TABLE IF NOT EXISTS Lectures ("
                        "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "name VARCHAR(100),"
                        "CourseID INTEGER REFERENCES Courses(ID));";
    int result = sqlite3_exec(db, query, 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

bool createStudentsTable(sqlite3* db){
    char* errMsg;
    const char* query = "CREATE TABLE IF NOT EXISTS Students ("
                        "userID INTEGER PRIMARY KEY,"
                        "biography VARCHAR(5000),"
                        "Course1ID INT REFERENCES Courses(ID),"
                        "Course2ID INT REFERENCES Courses(ID),"
                        "Course3ID INT REFERENCES Courses(ID),"
                        "Course4ID INT REFERENCES Courses(ID),"
                        "Course5ID INT REFERENCES Courses(ID),"
                        "FOREIGN KEY (userID) REFERENCES User(ID));";
    int result = sqlite3_exec(db, query, 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

bool createTeachersTable(sqlite3* db){
    char* errMsg;
    const char* query = "CREATE TABLE IF NOT EXISTS Teachers ("
                        "userID INTEGER PRIMARY KEY,"
                        "Course1ID INT REFERENCES Courses(ID),"
                        "Course2ID INT REFERENCES Courses(ID),"
                        "Course3ID INT REFERENCES Courses(ID),"
                        "Course4ID INT REFERENCES Courses(ID),"
                        "Course5ID INT REFERENCES Courses(ID),"
                        "FOREIGN KEY (userID) REFERENCES User(ID));";
    int result = sqlite3_exec(db, query, 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

bool createGradesTable(sqlite3* db){
    char* errMsg;
    const char* query = "CREATE TABLE IF NOT EXISTS Grades ("
                        "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "points DECIMAL(10,5),"
                        "outOf DECIMAL(10,5),"
                        "value DECIMAL(10,5),"
                        "coeff DECIMAL(10,5),"
                        "studentID INT REFERENCES Students(userID),"
                        "courseID INT REFERENCES Courses(ID));";
    int result = sqlite3_exec(db, query, 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}


int main(){
    //INITIALIZATION
    sqlite3 *db;
    //open the database or create it if it doesn't exist
    int rc = sqlite3_open("data/database.db", &db);
    if (rc != SQLITE_OK){
        cout<<"Can't open database: "<<sqlite3_errmsg(db)<<endl;
        return -1;
    }
    //create tables
    if (createUsersTable(db)) cout<<"ok1"<<endl;
    if (createCoursesTable(db)) cout<<"ok2"<<endl;
    if (createStudentsTable(db)) cout<<"ok3"<<endl;
    if (createTeachersTable(db)) cout<<"ok4"<<endl;
    if (createGradesTable(db)) cout<<"ok5"<<endl;
    if (createLecturesTable(db)) cout<<"ok6"<<endl;
    sqlite3_close(db);
    return 0;
}