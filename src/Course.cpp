#include "Course.h"

// Constructor
bool newCourse(sqlite3* db, string& name){
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


//Mutator method
bool modifyCourseName(sqlite3* db, int courseID, string newCourseName){
	char* errMsg;
    string query = "UPDATE Courses SET Name='" + newCourseName + "' WHERE ID=" + to_string(courseID) + ";";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

void courseTester(sqlite3* db){
	string name1= "MTH 231";
	if (newCourse(db, name1)) cout<<"New Course created"<<endl;
	int go;
	int ID = getCourseID(db, name1);
	cin>>go;
	cout<<"ID: "<<ID<<endl;
	cout<<"Name: "<<getCourseName(db, ID)<<endl;
	cout<<"Choose a new course name: ";
	string name2;
	cin>>name2;
	modifyCourseName(db, ID, name2);
	cout<<"New course name: "<<getCourseName(db, ID)<<endl;
}