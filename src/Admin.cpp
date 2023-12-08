#include "Admin.h"

bool newAdmin(sqlite3* db,  string username, string password,
    string firstName, string lastName){
    return newUser(db, username, password, firstName, lastName, 0);
}

bool deleteAdmin(sqlite3* db, int userID){
    return deleteUser(db, userID);
}

vector<int> getAllCoursesIDs(sqlite3* db){
    char* errMsg;
    vector<int> IDs;
    string query = "SELECT ID FROM Courses";
    int result = sqlite3_exec(db, query.c_str(), [](void* data, int argc, char** argv, char** colNames) {
        // Assuming only one row is returned
        if (argc > 0) {
            static_cast<vector<int>*>(data)->push_back(atoi(argv[0]));
        }
        return 0;
    }, &IDs, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return IDs;
}

vector<int> getAllUsersIDs(sqlite3* db){
    char* errMsg;
    vector<int> IDs;
    string query = "SELECT ID FROM U";
    int result = sqlite3_exec(db, query.c_str(), [](void* data, int argc, char** argv, char** colNames) {
        // Assuming only one row is returned
        if (argc > 0) {
            static_cast<vector<int>*>(data)->push_back(atoi(argv[0]));
        }
        return 0;
    }, &IDs, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return IDs;
}