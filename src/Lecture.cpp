#include "Lecture.h"

bool newLecture(sqlite3* db, string name, int associatedCourseID){
	char* errMsg;
	
	//get the number of entries in lectures to generate a number for the attendance table
    int count = 0;
	string query = "SELECT COUNT(*) FROM Lectures;";
    int result = sqlite3_exec(db, query.c_str(), [](void* data, int argc, char** argv, char** colNames) {
        // Assuming only one row is returned
        if (argc > 0) {
            *reinterpret_cast<int*>(data) = atoi(argv[0]);
        }
        return 0;
    }, &count, &errMsg);
	if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
	
	//Now, we create an attendance table for this specific lecture, which monitors student attendance with ids and bools
	query = "CREATE TABLE IF NOT EXISTS AttendanceTable" + to_string(count + 1) + " ("
        "StudentID INTEGER PRIMARY KEY,"
        "Attendance BOOLEAN);";
	const char* c_query = query.c_str();
	result = sqlite3_exec(db, c_query, 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
	else cout<<"AttendanceTable successfully created"<<endl;

	//add section for filling the attendance table with attendance set to true by default.

    query = "INSERT INTO Lectures (NAME, AttendanceTableName, CourseID) VALUES ('" +
                   name + "', 'AttendanceTable"+to_string(count+1)+"', "
				   + to_string(associatedCourseID) + ");";
	result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

bool deleteLecture(sqlite3* db, int& lectureID){
	char* errMsg;
	string tableName = getAttendanceTableName(db, lectureID);
    string query = "DELETE FROM Lectures WHERE ID=" + to_string(lectureID) + ";";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;

	//then, drop the associated attendance table
	query = "DROP TABLE IF EXISTS "+tableName+";";
    result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

string getLectureName(sqlite3* db, int lectureID){
	char* errMsg;
    string lectureName = "error: notfound";  // Default value if no user is found
    string query = "SELECT NAME FROM Lectures WHERE ID ='" + to_string(lectureID) + "';";
    int result = sqlite3_exec(db, query.c_str(), [](void* data, int argc, char** argv, char** colNames) {
        // Assuming only one row is returned
        if (argc > 0) {
            *reinterpret_cast<string*>(data) = argv[0];
        }
        return 0;
    }, &lectureName, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return lectureName;
}

bool modifyLectureName(sqlite3* db, int lectureID, string newLectureName){
	char* errMsg;
    string query = "UPDATE Lectures SET Name='" + newLectureName + "' WHERE ID=" + to_string(lectureID) + ";";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

int getLectureCourseID(sqlite3* db, int lectureID){
	char* errMsg;
    int courseID = -1;  // Default value if no user is found
    string query = "SELECT CourseID FROM Lectures WHERE ID ='" + to_string(lectureID) + "';";
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

string getAttendanceTableName(sqlite3* db, int lectureID){
	char* errMsg;
    string tableName = "error: notfound";  // Default value if no user is found
    string query = "SELECT AttendanceTableName FROM Lectures WHERE ID ='" + to_string(lectureID) + "';";
    int result = sqlite3_exec(db, query.c_str(), [](void* data, int argc, char** argv, char** colNames) {
        // Assuming only one row is returned
        if (argc > 0) {
            *reinterpret_cast<string*>(data) = argv[0];
        }
        return 0;
    }, &tableName, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return tableName;
}


bool getAttendanceStatus(sqlite3* db, int lectureID, int studentID){
	char* errMsg;
	bool attendance = false;
	string tableName = getAttendanceTableName(db, lectureID);
    string query = "SELECT " + tableName + " FROM your_table_name WHERE id =" + to_string(studentID) + ";";
    int result = sqlite3_exec(db, query.c_str(), [](void* data, int argc, char** argv, char** colNames) {
        // Assuming only one row is returned
        if (argc > 0) {
            *reinterpret_cast<bool*>(data) = argv[0];
        }
        return 0;
    }, &attendance, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return attendance;
}

bool addAttendingStudent(sqlite3* db, int lectureID, int studentID){
	char* errMsg;
	string tableName = getAttendanceTableName(db, lectureID);
	// Use 1 for the boolean TRUE 
    string query = "UPDATE " + tableName +
		" SET Attendance = 1 WHERE StudentID = " + to_string(studentID) + ";";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

bool addMissingStudent(sqlite3* db, int lectureID, int studentID){
	char* errMsg;
	string tableName = getAttendanceTableName(db, lectureID);
	// Use 1 for the boolean TRUE 
    string query = "UPDATE " + tableName +
		" SET Attendance = 0 WHERE StudentID = " + to_string(studentID) + ";";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

void lectureTester(sqlite3* db){
	if (newLecture(db, "Lecture 0: Introduction", 231)) cout<<"Lecture created"<<endl;
}