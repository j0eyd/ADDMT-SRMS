#include "Database.h"

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
    const char* query = "CREATE TABLE IF NOT EXISTS Users ("
                        "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "username VARCHAR(25) NOT NULL,"
                        "password VARCHAR(25),"
                        "firstName VARCHAR(25),"
                        "lastName VARCHAR(25),"
                        "type INT);"; //TYPES: 0: Admin | 1: Teacher | 2: Student
    int result = sqlite3_exec(db, query, 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

bool createCoursesTable(sqlite3* db){
    char* errMsg;
    const char* query = "CREATE TABLE IF NOT EXISTS Courses ("
                        "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "name VARCHAR(100));";
    int result = sqlite3_exec(db, query, 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

bool createLecturesTable(sqlite3* db){
    char* errMsg;
    const char* query = "CREATE TABLE IF NOT EXISTS Lectures ("
                        "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "name VARCHAR(100),"
                        "attendanceTableName VARCHAR(50),"
                        "courseID INTEGER REFERENCES Courses(ID));";
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


bool createTables(sqlite3 *db){
    assert(createUsersTable(db));
    cout<<"Users table created."<<endl;
    assert(createCoursesTable(db));
    cout<<"Courses table created."<<endl;
    assert(createStudentsTable(db));
    cout<<"Students table created."<<endl;
    assert(createTeachersTable(db));
    cout<<"Teachers table created."<<endl;
    assert (createGradesTable(db));
    cout<<"Grades table created."<<endl;
    assert(createLecturesTable(db));
    cout<<"Lectures table created.\n"<<endl;
    return true;
}