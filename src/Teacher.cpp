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

vector<int> getTaughtCourseIDs(sqlite3* db, int userID) {
    char* errMsg;
    int result;
    vector<int> courseIDs;
    for (int i = 1; i <= 5; i++) {
        string query = "SELECT COURSE" + to_string(i) + "ID FROM Teachers WHERE userID = " + to_string(userID) + ";";
        int courseID = 0;
        result = sqlite3_exec(db, query.c_str(), [](void* data, int argc, char** argv, char** colNames) {
            if (argc > 0 && argv[0] != nullptr) {
                reinterpret_cast<int*>(data)[0] = atoi(argv[0]);
            } else {
                reinterpret_cast<int*>(data)[0] = 0; // Set to 0 if NULL
            }
            return 0;
        }, &courseID, &errMsg);
        if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
        if (courseID != 0) courseIDs.push_back(courseID);
    }
    return courseIDs;
}

bool addTaughtCourse(sqlite3* db, int userID, int courseID){
    char* errMsg;
    string query;
    int i = 1;
    bool isNull = false;
    while(i<6 && !isNull){
        query = "SELECT Course" + to_string(i) + "ID FROM Teachers WHERE userID = '"
            + to_string(userID) + "';";
        int resultSelect = sqlite3_exec(db, query.c_str(), [](void* data, int argc, char** argv, char** colNames) {
            if (argc > 0 && argv[0] == nullptr) {
                *reinterpret_cast<bool*>(data) = true;
            }
            return 0;
        }, &isNull, &errMsg);
        if (resultSelect != SQLITE_OK) {
            std::cerr << "Error: " << errMsg << std::endl;
            return false;
        }
        if (isNull) break;
        i++;
    }
    query = "UPDATE Teachers SET Course"+to_string(i)+"ID='" + to_string(courseID) +
            "' WHERE userID=" + to_string(userID) + ";";    
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

bool dropTaughtCourse(sqlite3* db, int userID, int courseID){
    vector<int> courseIDs = getTaughtCourseIDs(db, userID);
    int i = 1;
    while (courseIDs[i-1]!=courseID){
        if (i==6){
            cout<<"This Teacher is not in charge of this course!"<<endl;
            return false;
        }
        i++;
    }
    char* errMsg;
    string query = "UPDATE Teachers SET Course"+to_string(i)+"ID=NULL WHERE userID=" + to_string(userID) + ";";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

//fill the student database. Affect courses to students.
bool teacherFillDatabase(sqlite3* db){
    int ID_CS361 = getCourseID(db, "CS361");
    int ID_CS362 = getCourseID(db, "CS362");
    int ID_CS444 = getCourseID(db, "CS444");
    int ID_MTH231 = getCourseID(db, "MTH231");
    int ID_CS321 = getCourseID(db, "CS321");
    int ID_CS372 = getCourseID(db, "CS372");
    int ID_CS544 = getCourseID(db, "CS544");
    assert(newTeacher(db, "deamicisr", "DeAmPW3", "Raffaele", "De Amicis"));
    int userID_deamicisr = getUserID(db, "deamicisr");
    assert(addTaughtCourse(db, userID_deamicisr, ID_CS361));
    assert(addTaughtCourse(db, userID_deamicisr, ID_CS362));
    assert(newTeacher(db, "rundels", "RuSaPW6", "Samuel", "Rundel"));
    int userID_rundels = getUserID(db, "rundels");
    assert(addTaughtCourse(db, userID_rundels, ID_CS444));
    assert(addTaughtCourse(db, userID_rundels, ID_MTH231));
    assert(addTaughtCourse(db, userID_rundels, ID_CS321));
    assert(addTaughtCourse(db, userID_rundels, ID_CS372));
    assert(newTeacher(db, "ficttea", "FiTe9", "Fictio", "Nalteach"));
    int userID_ficttea = getUserID(db, "ficttea");
    assert(addTaughtCourse(db, userID_ficttea, ID_CS544));
    cout<<"Teachers inserted\n"<<endl;
    return true;
}

bool teacherTestDatabase(sqlite3* db){
    cout<<"courses taught by rundels:"<<vect_to_string(getTaughtCourseIDs(db, getUserID(db, "rundels")))<<endl;
    cout<<"dropping CS372.."<<endl;
    assert(dropTaughtCourse(db, getUserID(db, "rundels"), getCourseID(db, "CS372")));
    cout<<"courses taught by rundels:"<<vect_to_string(getTaughtCourseIDs(db, getUserID(db, "rundels")))<<endl;
    cout<<"adding CS372 back.."<<endl;
    assert(addTaughtCourse(db, getUserID(db, "rundels"), getCourseID(db, "CS372")));
    cout<<"courses taught by rundels:"<<vect_to_string(getTaughtCourseIDs(db, getUserID(db, "rundels")))<<endl;
    cout<<"\n";
    return true;
}