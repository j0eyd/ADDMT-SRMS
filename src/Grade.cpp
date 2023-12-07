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
    string query = "DELETE FROM Grades WHERE ID=" + to_string(gradeID) + ";";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

vector<int> getStudentCourseGradeIDs(sqlite3* db, int studentID, int courseID){
	char* errMsg;
	vector<int> gradeIDs;
	string query = "SELECT ID FROM Grades WHERE studentID = " + to_string(studentID) +
				" AND courseID = " + to_string(courseID) + ";";
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
