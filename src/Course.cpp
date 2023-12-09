#include "Course.h"

string vect_to_string(vector<int> IDs){
    string ret = "[";
    int n = IDs.size();
    if (IDs.empty()) return "void";
    for (int i = 0; i<n-1; i++){
        ret+=to_string(IDs[i]);
        ret+=", ";
    }
    ret += to_string(IDs[n-1]);
    ret += "]";
    return ret;
}

// Constructor
bool newCourse(sqlite3* db, string name){
	char* errMsg;
    string query = "INSERT INTO Courses (NAME) VALUES ('" + name + "');";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

// Destructor
bool deleteCourse(sqlite3* db, int courseID){
	char* errMsg;
    string query = "DELETE FROM Courses WHERE ID=" + to_string(courseID) + ";";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

// Accessor Methods
int getCourseID(sqlite3* db, string name){
    char* errMsg;
    int courseID = -1;  // Default value if no user is found
    string query = "SELECT ID FROM Courses WHERE NAME ='" + name + "';";
    int result = sqlite3_exec(db, query.c_str(), [](void* data, int argc, char** argv, char** colNames) {
        // Assuming only one row is returned
        if (argc > 0) {
            reinterpret_cast<int*>(data)[0] = atoi(argv[0]);
        }
        return 0;
    }, &courseID, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return courseID;
}

string getCourseName(sqlite3* db, int courseID){
	char* errMsg;
    string courseName = "error: notfound";  // Default value if no user is found
    string query = "SELECT NAME FROM Courses WHERE ID ='" + to_string(courseID) + "';";
    int result = sqlite3_exec(db, query.c_str(), [](void* data, int argc, char** argv, char** colNames) {
        // Assuming only one row is returned
        if (argc > 0) {
            *reinterpret_cast<string*>(data) = argv[0];
        }
        return 0;
    }, &courseName, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return courseName;
}

vector<int> getLecturesIDFromCourse(sqlite3* db, int courseID){
    char* errMsg;
    vector<int> lectureIDs;
    string query = "SELECT ID FROM Lectures WHERE courseID = " + to_string(courseID) + ";";
    int result = sqlite3_exec(db, query.c_str(), [](void* data, int argc, char** argv, char** colNames) {
        // Assuming only one row is returned
        if (argc > 0) {
            static_cast<vector<int>*>(data)->push_back(atoi(argv[0]));
        }
        return 0;
    }, &lectureIDs, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return lectureIDs;
}

//Mutator method
bool modifyCourseName(sqlite3* db, int courseID, string newCourseName){
	char* errMsg;
    string query = "UPDATE Courses SET Name='" + newCourseName + "' WHERE ID=" + to_string(courseID) + ";";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

vector<int> getCourseStudentIDs(sqlite3* db, int courseID){
    vector<int> studentIDs;
    char* errMsg;
    string query = "SELECT UserID FROM Students WHERE Course1ID = " + to_string(courseID) +
                   " OR Course2ID = " + to_string(courseID) +
                   " OR Course3ID = " + to_string(courseID) +
                   " OR Course4ID = " + to_string(courseID) +
                   " OR Course5ID = " + to_string(courseID) + ";";
    int result = sqlite3_exec(db, query.c_str(), [](void* data, int argc, char** argv, char** colNames) {
        // Assuming only one row is returned
        if (argc > 0) {
            static_cast<vector<int>*>(data)->push_back(atoi(argv[0]));
        }
        return 0;
    }, &studentIDs, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return studentIDs;
}

bool courseFillDatabase(sqlite3* db){
    assert(newCourse(db, "CS361"));
    assert(newCourse(db, "CS362"));
    assert(newCourse(db, "CS444"));
    assert(newCourse(db, "MTH231"));
    assert(newCourse(db, "CS321"));
    assert(newCourse(db, "CS372"));
    assert(newCourse(db, "CS544"));
    cout<<"Courses inserted"<<endl;
    return true;
}

bool courseTestDatabase(sqlite3* db){
    cout<<"Operations on temporary course (ID 2): return the ids of its associated students, ids of its associated lectures, then change its name\n"<<endl;
    cout<<"Name of temporary course: "<<getCourseName(db, 2)<<endl;
    cout<<"just to check, id of CS362: "<<getCourseID(db, "CS362")<<endl;
    cout<<"Associated lectures IDs: \n"<<vect_to_string(getLecturesIDFromCourse(db, 2))<<endl;
    cout<<"Enrolled Students IDs: \n"<<vect_to_string(getCourseStudentIDs(db, 2))<<endl;
    cout<<"changing name...\n";
    assert(modifyCourseName(db, 2, "CS363"));
    cout<<"New name: "<<getCourseName(db, 2)<<endl;
    cout<<"Course tests complete.\n"<<endl;
    return true;
}