#include "Grade.h"

bool newGrade(sqlite3* db, int studentID, int courseID, float points, float outOf, float coeff){
	char* errMsg;
    string query = "INSERT INTO Grades (points, outOf, value, coeff, studentID, courseID) VALUES ('" +
                   to_string(points) + "', '"
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