#include "Student.h"

bool newStudent(sqlite3* db, string biography,  string username, string password,
        string firstName, string lastName){
    newUser(db, username, password, firstName, lastName, 2);
    int lastUserID = sqlite3_last_insert_rowid(db);
    char* errMsg;
    string query = "INSERT INTO Students (UserID, biography) VALUES ('" +
                   to_string(lastUserID) + "', '" + biography + "');";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

bool deleteStudent(sqlite3* db, int userID){
    char* errMsg;
    string query = "DELETE FROM Students WHERE userID=" + to_string(userID) + ";";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    deleteUser(db, userID);
    //add grade deletion?
    return result == SQLITE_OK;
}

vector<int> getEnrolledCourseIDs(sqlite3* db, int userID){
    char* errMsg;
    int courseID, result;
    string query;
    vector<int> courseIDs;
    for (int i = 1; i<=5; i++){
        query = "SELECT COURSE"+to_string(i)+"ID FROM Students WHERE userID =  " + to_string(userID) + ";";
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

string getBiography(sqlite3* db, int userID){
    char* errMsg;
    string biography = "";  // Default value if no user is found
    string query = "SELECT biography FROM Students WHERE userID='" + to_string(userID) + "';";
    int result = sqlite3_exec(db, query.c_str(), [](void* data, int argc, char** argv, char** colNames) {
        // Assuming only one row is returned
        if (argc > 0) {
            *reinterpret_cast<string*>(data) = argv[0];
        }
        return 0;
    }, &biography, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return biography;
}

bool modifyBiography(sqlite3* db, int userID, string newBiography){
    char* errMsg;
    string query = "UPDATE Students SET biography='" + newBiography + "' WHERE ID=" + to_string(userID) + ";";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

bool addEnrolledCourse(sqlite3* db, int userID, int courseID){
    vector<int> courseIDs = getEnrolledCourseIDs(db, userID);
    int i = 1;
    while (courseIDs[i-1]>0){
        if (i==6){
            cout<<"Courses saturated for this student!"<<endl;
            return false;
        }
        i++;
    }
    char* errMsg;
    string query = "UPDATE Students SET Course"+to_string(i)+"ID='" + to_string(courseID) +
         "' WHERE ID=" + to_string(userID) + ";";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

bool dropEnrolledCourse(sqlite3* db, int userID, int courseID){
    vector<int> courseIDs = getEnrolledCourseIDs(db, userID);
    int i = 1;
    while (courseIDs[i-1]!=courseID){
        if (i==6){
            cout<<"This Student is not part of this course!"<<endl;
            return false;
        }
        i++;
    }
    char* errMsg;
    string query = "UPDATE Students SET Course"+to_string(i)+"ID='" + to_string(0) +
         "' WHERE ID=" + to_string(userID) + ";";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}