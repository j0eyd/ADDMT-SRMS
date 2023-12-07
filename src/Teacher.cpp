#include "Teacher.h"

bool newTeacher(sqlite3* db,  string username, string password,
        string firstName, string lastName){
    newUser(db, username, password, firstName, lastName, 1);
    int lastUserID = sqlite3_last_insert_rowid(db);
    char* errMsg;
    string query = "INSERT INTO Teachers (UserID) VALUES ('" +
                   to_string(lastUserID)+"');";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

bool deleteTeacher(sqlite3* db, int userID){
    char* errMsg;
    string query = "DELETE FROM Teachers WHERE userID=" + to_string(userID) + ";";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    deleteUser(db, userID);
    //add grade deletion?
    return result == SQLITE_OK;
}

vector<int> getTaughtCourseIDs(sqlite3* db, int userID){
    char* errMsg;
    int courseID, result;
    string query;
    vector<int> courseIDs;
    for (int i = 1; i<=5; i++){
        query = "SELECT COURSE"+to_string(i)+"ID FROM Teachers WHERE userID =  " + to_string(userID) + ";";
        result = sqlite3_exec(db, query.c_str(), [](void* data, int argc, char** argv, char** colNames) {
            // Assuming only one row is returned
            if (argc > 0) {
                reinterpret_cast<int*>(data)[0] = atoi(argv[0]);
            }
            return 0;
        }, &courseID, &errMsg);
        if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
        courseIDs.push_back(courseID);
    }
    return courseIDs;
}

bool addTaughtCourse(sqlite3* db, int userID, int courseID){
    vector<int> courseIDs = getTaughtCourseIDs(db, userID);
    int i = 1;
    while (courseIDs[i-1]>0){
        if (i==6){
            cout<<"Courses saturated for this Teacher!"<<endl;
            return false;
        }
        i++;
    }
    char* errMsg;
    string query = "UPDATE Teachers SET Course"+to_string(i)+"ID='" + to_string(courseID) +
         "' WHERE ID=" + to_string(userID) + ";";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

bool dropTaughtCourse(sqlite3* db, int userID, int courseID){
    vector<int> courseIDs = getTaughtCourseIDs(db, userID);
    int i = 1;
    while (courseIDs[i-1]!=courseID){
        if (i==6){
            cout<<"This Teacher is teaching this course!"<<endl;
            return false;
        }
        i++;
    }
    char* errMsg;
    string query = "UPDATE Teachers SET Course"+to_string(i)+"ID='" + to_string(0) +
         "' WHERE ID=" + to_string(userID) + ";";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}