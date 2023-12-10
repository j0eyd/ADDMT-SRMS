#include "Grade.h"

bool newGrade(sqlite3* db, int studentID, int courseID, string name, float points, float outOf, float coeff){
	char* errMsg;
    string query = "INSERT INTO Grades (name, points, outOf, value, coeff, studentID, courseID) VALUES ('"
                   + name + "', '"
                   + to_string(points) + "', '"
                   + to_string(outOf) + "', '"
                   + to_string(100.0*points/outOf) + "', '"
                   + to_string(coeff) + "', '"
				   + to_string(studentID) + "', '"
                   + to_string(courseID) + "');";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

bool deleteGrade(sqlite3* db, int gradeID){
	char* errMsg;
    string query = "DELETE FROM Grades WHERE ID='" + to_string(gradeID) + "';";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

int getGradeID(sqlite3* db, string name, int studentID, int courseID){
    char* errMsg;
    int ID = -1;
    string query = "SELECT ID FROM Grades WHERE name = '" + name
        + "' AND studentID = " + to_string(studentID) + " AND courseID = " + to_string(courseID) +  ";";
    int result = sqlite3_exec(db, query.c_str(), [](void* data, int argc, char** argv, char** colNames) {
        // Assuming only one row is returned
        if (argc > 0) {
            reinterpret_cast<int*>(data)[0] = atof(argv[0]);
        }
        return 0;
    }, &ID, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return ID;
}

vector<int> getStudentCourseGradeIDs(sqlite3* db, int studentID, int courseID){
	char* errMsg;
	vector<int> gradeIDs;
	string query = "SELECT ID FROM Grades WHERE studentID = '" + to_string(studentID) +
				"' AND courseID = '" + to_string(courseID) + "';";
	int result = sqlite3_exec(db, query.c_str(), [](void* data, int argc, char** argv, char** colNames) {
        // Assuming only one row is returned
        if (argc > 0) {
            static_cast<vector<int>*>(data)->push_back(atoi(argv[0]));
        }
        return 0;
    }, &gradeIDs, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return gradeIDs;
}

int getGradeStudentID(sqlite3* db, int gradeID){
    char* errMsg;
    int studentID = -1;
    string query = "SELECT studentID FROM Grades WHERE ID = '" + to_string(gradeID) + "';";
    int result = sqlite3_exec(db, query.c_str(), [](void* data, int argc, char** argv, char** colNames) {
        // Assuming only one row is returned
        if (argc > 0) {
            reinterpret_cast<int*>(data)[0] = atoi(argv[0]);
        }
        return 0;
    }, &studentID, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return studentID;
}

int getGradeCourseID(sqlite3* db, int gradeID){
    char* errMsg;
    int courseID = -1;
    string query = "SELECT courseID FROM Grades WHERE ID = '" + to_string(gradeID) + "';";
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

string getGradeName(sqlite3* db, int gradeID){
    char* errMsg;
    string name = "no name";
    string query = "SELECT name FROM Grades WHERE ID = '" + to_string(gradeID) + "';";
    int result = sqlite3_exec(db, query.c_str(), [](void* data, int argc, char** argv, char** colNames) {
        // Assuming only one row is returned
        if (argc > 0) {
            reinterpret_cast<string*>(data)->assign(argv[0]);
        }
        return 0;
    }, &name, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return name;
}

float getGradePoints(sqlite3* db, int gradeID){
    char* errMsg;
    float points = -1.0;
    string query = "SELECT points FROM Grades WHERE ID = '" + to_string(gradeID) + "';";
    int result = sqlite3_exec(db, query.c_str(), [](void* data, int argc, char** argv, char** colNames) {
        // Assuming only one row is returned
        if (argc > 0) {
            reinterpret_cast<float*>(data)[0] = atof(argv[0]);
        }
        return 0;
    }, &points, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return points;
}

float getGradeOutOf(sqlite3* db, int gradeID){
    char* errMsg;
    float outOf = -1.0;
    string query = "SELECT outOf FROM Grades WHERE ID = '" + to_string(gradeID) + "';";
    int result = sqlite3_exec(db, query.c_str(), [](void* data, int argc, char** argv, char** colNames) {
        // Assuming only one row is returned
        if (argc > 0) {
            reinterpret_cast<float*>(data)[0] = atof(argv[0]);
        }
        return 0;
    }, &outOf, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return outOf;
}

float getGradeValue(sqlite3* db, int gradeID){
    char* errMsg;
    float value = -1.0;
    string query = "SELECT value FROM Grades WHERE ID = '" + to_string(gradeID) + "';";
    int result = sqlite3_exec(db, query.c_str(), [](void* data, int argc, char** argv, char** colNames) {
        // Assuming only one row is returned
        if (argc > 0) {
            reinterpret_cast<float*>(data)[0] = atof(argv[0]);
        }
        return 0;
    }, &value, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return value;
}

float getGradeCoeff(sqlite3* db, int gradeID){
    char* errMsg;
    float coeff = -1.0;
    string query = "SELECT coeff FROM Grades WHERE ID = '" + to_string(gradeID) + "';";
    int result = sqlite3_exec(db, query.c_str(), [](void* data, int argc, char** argv, char** colNames) {
        // Assuming only one row is returned
        if (argc > 0) {
            reinterpret_cast<float*>(data)[0] = atof(argv[0]);
        }
        return 0;
    }, &coeff, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return coeff;
}


bool setGradeStudentID(sqlite3* db, int gradeID, int newStudentID){
    char* errMsg;
    string query = "UPDATE Grades SET studentID='" + to_string(newStudentID)
        + "' WHERE ID=" + to_string(gradeID) + ";";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

bool setGradeCourseID(sqlite3* db, int gradeID, int newCourseID){
    char* errMsg;
    string query = "UPDATE Grades SET courseID='" + to_string(newCourseID)
        + "' WHERE ID=" + to_string(gradeID) + ";";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

bool setGradeName(sqlite3* db, int gradeID, string newName){
    char* errMsg;
    string query = "UPDATE Grades SET name ='" + newName
        + "' WHERE ID=" + to_string(gradeID) + ";";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return (result == SQLITE_OK);
}

bool setGradePoints(sqlite3* db, int gradeID, float newPoints){
    char* errMsg;
    string query = "UPDATE Grades SET points='" + to_string(newPoints)
        + "' WHERE ID=" + to_string(gradeID) + ";";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return (result == SQLITE_OK && setGradeValue(db, gradeID));
}

bool setGradeOutOf(sqlite3* db, int gradeID, float newOutOf){
    char* errMsg;
    string query = "UPDATE Grades SET outOf='" + to_string(newOutOf)
        + "' WHERE ID=" + to_string(gradeID) + ";";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return (result == SQLITE_OK && setGradeValue(db, gradeID));
}

bool setGradeValue(sqlite3* db, int gradeID){
    float points = getGradePoints(db, gradeID);
    float outOf = getGradeOutOf(db, gradeID);
    char* errMsg;
    string query = "UPDATE Grades SET value='" + to_string(100*points/outOf)
        + "' WHERE ID=" + to_string(gradeID) + ";";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

bool setGradeCoeff(sqlite3* db, int gradeID, float newCoeff){
    char* errMsg;
    string query = "UPDATE Grades SET coeff='" + to_string(newCoeff)
        + "' WHERE ID=" + to_string(gradeID) + ";";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

bool gradeFillDatabase(sqlite3* db){
    assert(newGrade(db, 4, 1, "Midterm Exam", 85.0, 100.0, 3.0));
    assert(newGrade(db, 4, 1, "Homework 1", 92.0, 100.0, 2.0));
    assert(newGrade(db, 4, 3, "Project 1", 88.5, 90.0, 4.0));
    assert(newGrade(db, 4, 3, "Quiz 1", 75.0, 80.0, 1.5));
    assert(newGrade(db, 4, 2, "Essay", 94.0, 100.0, 2.5));
    assert(newGrade(db, 4, 2, "Lab Report", 87.0, 90.0, 2.0));
    assert(newGrade(db, 4, 5, "Presentation", 96.5, 100.0, 3.5));
    assert(newGrade(db, 4, 5, "Group Project", 89.0, 95.0, 4.0));
    assert(newGrade(db, 5, 1, "Midterm Exam", 100.0, 100.0, 1.0));
    assert(newGrade(db, 5, 1, "Homework 1", 80.0, 100.0, 1.0));
    assert(newGrade(db, 5, 3, "Pop Quiz", 70.0, 80.0, 1.0));
    assert(newGrade(db, 5, 3, "Peer Review", 91.0, 95.0, 2.0));
    assert(newGrade(db, 5, 4, "Code Review", 85.5, 90.0, 2.5));
    assert(newGrade(db, 5, 4, "Journal Entry", 93.0, 100.0, 1.5));
    assert(newGrade(db, 5, 6, "Debate", 88.0, 95.0, 3.0));
    assert(newGrade(db, 5, 6, "Reflection Paper", 97.0, 100.0, 2.0));
    assert(newGrade(db, 6, 1, "Field Trip Report", 82.5, 90.0, 2.5));
    assert(newGrade(db, 6, 1, "Online Quiz", 78.0, 80.0, 1.0));
    assert(newGrade(db, 6, 2, "Research Paper", 95.0, 100.0, 5.0));
    assert(newGrade(db, 6, 2, "Peer Presentation", 86.0, 90.0, 3.0));
    assert(newGrade(db, 6, 4, "Lab Exam", 88.0, 100.0, 3.0));
    assert(newGrade(db, 6, 4, "Discussion Forum", 96.0, 100.0, 2.5));
    assert(newGrade(db, 6, 5, "Peer Evaluation", 90.5, 95.0, 1.5));
    assert(newGrade(db, 6, 5, "Coding Assignment", 82.0, 90.0, 4.0));
    assert(newGrade(db, 7, 1, "Class Presentation", 94.0, 100.0, 3.0));
    assert(newGrade(db, 7, 1, "Group Discussion", 85.5, 90.0, 2.0));
    assert(newGrade(db, 7, 3, "Critical Analysis", 89.0, 95.0, 2.0));
    assert(newGrade(db, 7, 3, "Interactive Quiz", 75.0, 80.0, 1.0));
    assert(newGrade(db, 7, 2, "Peer Project Review", 91.5, 95.0, 3.5));
    assert(newGrade(db, 7, 2, "Response Paper", 97.0, 100.0, 1.0));
    assert(newGrade(db, 8, 2, "Case Study", 84.0, 90.0, 2.0));
    assert(newGrade(db, 8, 2, "Oral Examination", 93.5, 100.0, 3.0));
    assert(newGrade(db, 8, 4, "Simulation Exercise", 79.0, 80.0, 1.0));
    assert(newGrade(db, 8, 4, "Group Report", 86.5, 90.0, 2.5));
    assert(newGrade(db, 9, 2, "Online Discussion", 92.0, 100.0, 1.0));
    assert(newGrade(db, 9, 2, "Portfolio Assessment", 88.0, 95.0, 3.0));
    assert(newGrade(db, 9, 7, "Critical Thinking Assignment", 81.5, 90.0, 2.0));
    assert(newGrade(db, 9, 7, "Team Project", 95.0, 100.0, 4.0));
    assert(newGrade(db, 9, 6, "Capstone Project", 94.5, 100.0, 4.5));
    assert(newGrade(db, 9, 6, "Critical Review", 87.0, 90.0, 2.0));
    cout<<"Grades inserted\n"<<endl;
    return true;
}

bool gradeTestDatabase(sqlite3* db){
    assert(newGrade(db, 4, 1, "Temporary grade", 100.0, 200.0, 1.0));
    cout<<"Test grade created"<<endl;
    int gradeID = getGradeID(db, "Temporary grade", 4, 1);
    cout<<"ID of the student the grade belongs to: "<<getGradeStudentID(db, gradeID)<<endl;
    cout<<"ID of the course the grade belongs to: "<<getGradeCourseID(db, gradeID)<<endl;
    cout<<"Name of the grade: "<<getGradeName(db, gradeID)<<endl;
    cout<<"Points of the grade: "<<getGradePoints(db, gradeID)<<endl;
    cout<<"OutOf of the grade: "<<getGradeOutOf(db, gradeID)<<endl;
    cout<<"Value of the grade: "<<getGradeValue(db, gradeID)<<endl;
    cout<<"Coeff of the grade: "<<getGradeCoeff(db, gradeID)<<endl;
    cout<<"modification of the grade..."<<endl;
    assert(setGradeStudentID(db, gradeID, 5));
    assert(setGradeCourseID(db, gradeID, 3));
    assert(setGradeName(db, gradeID, "New temporary name"));
    assert(setGradePoints(db, gradeID, 50.0));
    assert(setGradeOutOf(db, gradeID, 60.0));
    assert(setGradeCoeff(db, gradeID, 3.0));
    cout<<"ID of the student the grade belongs to: "<<getGradeStudentID(db, gradeID)<<endl;
    cout<<"ID of the course the grade belongs to: "<<getGradeCourseID(db, gradeID)<<endl;
    cout<<"Name of the grade: "<<getGradeName(db, gradeID)<<endl;
    cout<<"Points of the grade: "<<getGradePoints(db, gradeID)<<endl;
    cout<<"OutOf of the grade: "<<getGradeOutOf(db, gradeID)<<endl;
    cout<<"Value of the grade: "<<getGradeValue(db, gradeID)<<endl;
    cout<<"Coeff of the grade: "<<getGradeCoeff(db, gradeID)<<endl;
    cout<<"deletion of the grade..."<<endl;
    assert(deleteGrade(db, gradeID));
    return true;
}