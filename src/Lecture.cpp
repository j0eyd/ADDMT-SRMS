#include "Lecture.h"

bool newLecture(sqlite3* db, string name, int associatedCourseID){
	char* errMsg;
	
	//get the number of entries in lectures to generate the index of the attendance table
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
        "Attendance INTEGER);";
	result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
	else cout<<"AttendanceTable successfully created"<<endl;

    //insert the course students in the table, mark them as present by default
    vector<int> studentIDs = getCourseStudentIDs(db, associatedCourseID);
    for (int ID : studentIDs){
        query = "INSERT INTO AttendanceTable" + to_string(count + 1) + " (StudentID, Attendance) VALUES ('" +
            to_string(ID) + "', '" + to_string(1) + "');";
        result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
        if (result != SQLITE_OK){
            cerr << "Error: " << errMsg << endl;
            return false;
        }
    }

    //finally, create the entry in the Lectures table
    query = "INSERT INTO Lectures (NAME, AttendanceTableName, CourseID) VALUES ('" +
                   name + "', 'AttendanceTable"+to_string(count+1)+"', "
				   + to_string(associatedCourseID) + ");";
	result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

bool deleteLecture(sqlite3* db, int lectureID){
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


bool getAttendanceStatus(sqlite3* db, int lectureID, int studentID) {
    char* errMsg;
    bool attendance = false;
    string tableName = getAttendanceTableName(db, lectureID);
    string query = "SELECT Attendance FROM " + tableName + " WHERE StudentID = " + to_string(studentID) + ";";
    int result = sqlite3_exec(db, query.c_str(), [](void* data, int argc, char** argv, char** colNames) {
        // Assuming only one row is returned
        if (argc > 0) {
            *reinterpret_cast<bool*>(data) = stoi(argv[0]) != 0;
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

bool lectureFillDatabase(sqlite3* db){
    int ID_CS361 = getCourseID(db, "CS361");
    int ID_CS362 = getCourseID(db, "CS362");
    int ID_CS444 = getCourseID(db, "CS444");
    int ID_MTH231 = getCourseID(db, "MTH231");
    int ID_CS321 = getCourseID(db, "CS321");
    int ID_CS372 = getCourseID(db, "CS372");
    int ID_CS544 = getCourseID(db, "CS544");
	//CS361
    assert(newLecture(db, "Lecture 1: Introduction to Software Engineering", ID_CS361));
    assert(newLecture(db, "Lecture 2: Scrum methodology", ID_CS361));
    assert(newLecture(db, "Lecture 3: Team-working and risk-taking", ID_CS361));
    //CS362
    assert(newLecture(db, "Lecture 1: Introduction to backend", ID_CS362));
    assert(newLecture(db, "Lecture 2: Software life cycle", ID_CS362));
    assert(newLecture(db, "Lecture 3: Error tracking", ID_CS362));
    //CS444
    assert(newLecture(db, "Lecture 1: Kernel and bootloader", ID_CS444));
    assert(newLecture(db, "Lecture 2: Paging and protection", ID_CS444));
    assert(newLecture(db, "Lecture 3: Multiprocessing and threading", ID_CS444));
    //MTH_321
    assert(newLecture(db, "Lecture 1: Introduction to discrete math", ID_MTH231));
    assert(newLecture(db, "Lecture 2: Graph theory", ID_MTH231));
    assert(newLecture(db, "Lecture 3: Counting", ID_MTH231));
    //CS321
    assert(newLecture(db, "Lecture 1: Introduction to theory of computation", ID_CS321));
    assert(newLecture(db, "Lecture 2: Turing completeness", ID_CS321));
    assert(newLecture(db, "Lecture 3: NP problems", ID_CS321));
    //CS372
    assert(newLecture(db, "Lecture 1: Introduction to computer networks", ID_CS372));
    assert(newLecture(db, "Lecture 2: Link layer protocols", ID_CS372));
    assert(newLecture(db, "Lecture 3: Network layer protocols", ID_CS372));
    //CS544
    assert(newLecture(db, "Lecture 1: Advanced operating systems: introduction", ID_CS544));
    assert(newLecture(db, "Lecture 2: Severe grading", ID_CS544));
    assert(newLecture(db, "Lecture 3: This is the last lecture lol", ID_CS544));
    cout<<"Lectures inserted"<<endl;
    return true;
}

bool lectureTestDatabase(sqlite3* db){
    cout<<"Lectures of CS544: "<<vect_to_string(getLecturesIDFromCourse(db, getCourseID(db, "CS544")))<<endl;
    int lectureID = getLecturesIDFromCourse(db, getCourseID(db, "CS544"))[0];
    cout<<"name of lecture 1: "<<getLectureName(db, lectureID)<<endl;
    cout<<"name change"<<endl;
    assert(modifyLectureName(db, lectureID, "Lecture 1: Temporary name"));
    cout<<"name of lecture 1: "<<getLectureName(db, lectureID)<<endl;
    cout<<"name change"<<endl;
    assert(modifyLectureName(db, lectureID, "Lecture 1: Advanced operating systems: introduction"));
    cout<<"name of lecture 1: "<<getLectureName(db, lectureID)<<endl;
    cout<<"name of its attendance table: "<<getAttendanceTableName(db, lectureID)<<endl;
    cout<<"ID of the first lecture of CS544: "<<lectureID<<endl;
    cout<<"Jogoat99 was present for lecture 1 of cs544: "<<getAttendanceStatus(db, lectureID, getUserID(db, "Jogoat99"))<<endl;
    cout<<"operations: change attendance of Jo Goat to the Lecture 1 of CS544"<<endl;
    assert(addMissingStudent(db, lectureID, 9));
    cout<<"Jogoat99 was present for lecture 1 of cs544: "<<getAttendanceStatus(db, lectureID, getUserID(db, "Jogoat99"))<<endl;
    cout<<"operations: change attendance of Jo Goat to the Lecture 1 of CS544"<<endl;
    assert(addAttendingStudent(db, lectureID, getUserID(db, "Jogoat99")));
    cout<<"Jogoat99 was present for lecture 1 of cs544: "<<getAttendanceStatus(db, lectureID, getUserID(db, "Jogoat99"))<<endl;
    return true;
}