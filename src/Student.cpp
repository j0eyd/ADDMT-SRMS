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

vector<int> getEnrolledCourseIDs(sqlite3* db, int userID) {
    char* errMsg;
    int result;
    vector<int> courseIDs;
    for (int i = 1; i <= 5; i++) {
        string query = "SELECT COURSE" + to_string(i) + "ID FROM Students WHERE userID = " + to_string(userID) + ";";
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
    string query = "UPDATE Students SET biography='" + newBiography + "' WHERE userID=" + to_string(userID) + ";";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

bool addEnrolledCourse(sqlite3* db, int userID, int courseID){
    char* errMsg;
    string query;
    int i = 1;
    bool isNull = false;
    while(i<6 && !isNull){
        query = "SELECT Course" + to_string(i) + "ID FROM Students WHERE userID = '"
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
    query = "UPDATE Students SET Course"+to_string(i)+"ID='" + to_string(courseID) +
            "' WHERE userID=" + to_string(userID) + ";";    
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
         "' WHERE userID=" + to_string(userID) + ";";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

//fill the student database. Affect courses to students.
bool studentFillDatabase(sqlite3* db){
    cout<<"Start Students"<<endl;
    int ID_CS361 = getCourseID(db, "CS361");
    int ID_CS362 = getCourseID(db, "CS362");
    int ID_CS444 = getCourseID(db, "CS444");
    int ID_MTH231 = getCourseID(db, "MTH231");
    int ID_CS321 = getCourseID(db, "CS321");
    int ID_CS372 = getCourseID(db, "CS372");
    int ID_CS544 = getCourseID(db, "CS544");
    cout<<"Middle1 Students"<<endl;
    assert(newStudent(db, "I am Joey David, I love coding databases", "davidlhj", "NotApw64*", "Joey", "David"));
    int userID_davidlhj = getUserID(db, "davidlhj");
    cout<<userID_davidlhj<<endl;
    assert(addEnrolledCourse(db, userID_davidlhj, ID_CS361));
    assert(addEnrolledCourse(db, userID_davidlhj, ID_CS444));
    assert(addEnrolledCourse(db, userID_davidlhj, ID_CS362));
    assert(addEnrolledCourse(db, userID_davidlhj, ID_CS321));
    assert(newStudent(db, "I am Matthew Dickinson, I love writing UIs", "dickinma", "Alsonotapw3(", "Matthew", "Dickinson"));
    int userID_dickinma = getUserID(db, "dickinma");
    assert(addEnrolledCourse(db, userID_dickinma, ID_CS361));
    assert(addEnrolledCourse(db, userID_dickinma, ID_CS444));
    assert(addEnrolledCourse(db, userID_dickinma, ID_MTH231));
    assert(addEnrolledCourse(db, userID_dickinma, ID_CS372));
    assert(newStudent(db, "I am Andrew Craeton, I also love writing UIs", "craetona", "YepStill34^", "Drew", "Craeton"));
    int userID_craetona = getUserID(db, "craetona");
    assert(addEnrolledCourse(db, userID_craetona, ID_CS361));
    assert(addEnrolledCourse(db, userID_craetona, ID_CS362));
    assert(addEnrolledCourse(db, userID_craetona, ID_MTH231));
    assert(addEnrolledCourse(db, userID_craetona, ID_CS321));
    cout<<"Middle2 Students"<<endl;
    assert(newStudent(db, "I am Aic, I love writing documentation", "Aic01", "RandomBsGo!", "Xiaoyu", "Luo"));
    int userID_Aic01 = getUserID(db, "Aic01");
    assert(addEnrolledCourse(db, userID_Aic01, ID_CS361));
    assert(addEnrolledCourse(db, userID_Aic01, ID_CS444));
    assert(addEnrolledCourse(db, userID_Aic01, ID_CS362));
    assert(newStudent(db, "I am Kosei Yamauchi, Im a business student", "yamauchk", "SataaAndagii34", "Kosei", "Yamauchi"));
    int userID_yamauchk = getUserID(db, "yamauchk");
    assert(addEnrolledCourse(db, userID_yamauchk, ID_CS362));
    assert(addEnrolledCourse(db, userID_yamauchk, ID_MTH231));
    assert(newStudent(db, "Stand proud, you are nah Id win", "Jogoat99", "sukunaL+", "Jo", "Goat"));
    int userID_Jogoat99 = getUserID(db, "Jogoat99");
    assert(addEnrolledCourse(db, userID_Jogoat99, ID_CS361));
    assert(addEnrolledCourse(db, userID_Jogoat99, ID_CS544));
    assert(addEnrolledCourse(db, userID_Jogoat99, ID_CS372));
    cout<<"Students Inserted"<<endl;
    return true;
}

bool studentTestDatabase(sqlite3* db){
    cout<<"operations on temporary student (Jo Goat): display all of its characteristics, the courses he attends, the modify them\n"<<endl;
    int userID_Jogoat99 = getUserID(db, "Jogoat99"); 
    cout<<"UserID of Jogoat99: "<<userID_Jogoat99<<endl;
    cout<<"Password of Jogoat99: "<<getPassword(db, userID_Jogoat99)<<endl;
    cout<<"First name of Jogoat99: "<<getFirstName(db, userID_Jogoat99)<<endl;
    cout<<"Last name of Jogoat99: "<<getLastName(db, userID_Jogoat99)<<endl;
    cout<<"User type of Jogoat99: "<<getUserType(db, userID_Jogoat99)<<endl;
    cout<<"biography of Jogoat99: "<<getBiography(db, userID_Jogoat99)<<endl;
    cout<<"ID of the Courses Jogoat99 attends:\n"<<vect_to_string(getEnrolledCourseIDs(db, userID_Jogoat99))<<endl;
    cout<<"modifying biography...\n";
    assert(modifyBiography(db, userID_Jogoat99, "Lobotomy brainrot ^^"));
    cout<<"biography of Jogoat99: "<<getBiography(db, userID_Jogoat99)<<endl;
    cout<<"dropping CS361, enrolling into CS363..."<<endl;
    assert(dropEnrolledCourse(db, userID_Jogoat99, getCourseID(db, "CS361")));
    assert(addEnrolledCourse(db, userID_Jogoat99, getCourseID(db, "CS363")));
    cout<<"ID of the Courses Jogoat99 attends:\n"<<vect_to_string(getEnrolledCourseIDs(db, userID_Jogoat99))<<endl;;
    return true;
}