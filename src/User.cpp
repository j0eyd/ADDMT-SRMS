#include "User.h"

//TYPES: 0: Admin | 1: Teacher | 2: Student
bool newUser(sqlite3* db, string username, string password,
    string firstName, string lastName, int type){
    char* errMsg;
    string query = "INSERT INTO User (username, password, firstName, lastName, type) VALUES ('" +
                   username + "', '"
                   + password + "', '"
                   + firstName + "', '"
                   + lastName + "', '"
                   + to_string(type) + "');";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
    }

bool deleteUser(sqlite3* db, int userID){
    char* errMsg;
    string query = "DELETE FROM User WHERE ID=" + to_string(userID) + ";";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

int getUserID(sqlite3* db, string username) {
    char* errMsg;
    int userID = -1;  // Default value if no user is found
    string query = "SELECT ID FROM User WHERE username='" + username + "';";
    int result = sqlite3_exec(db, query.c_str(), [](void* data, int argc, char** argv, char** colNames) {
        // Assuming only one row is returned
        if (argc > 0) {
            reinterpret_cast<int*>(data)[0] = atoi(argv[0]);
        }
        return 0;
    }, &userID, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return userID;
}

string getUsername(sqlite3* db, int UserID){
    char* errMsg;
    string username = "error: notfound";  // Default value if no user is found
    string query = "SELECT username FROM User WHERE ID='" + to_string(UserID) + "';";
    int result = sqlite3_exec(db, query.c_str(), [](void* data, int argc, char** argv, char** colNames) {
        // Assuming only one row is returned
        if (argc > 0) {
            *reinterpret_cast<string*>(data) = argv[0];
        }
        return 0;
    }, &username, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return username;
}

string getPassword(sqlite3* db, int UserID){
        char* errMsg;
    string password = "";  // Default value if no user is found
    string query = "SELECT password FROM User WHERE ID='" + to_string(UserID) + "';";
    int result = sqlite3_exec(db, query.c_str(), [](void* data, int argc, char** argv, char** colNames) {
        // Assuming only one row is returned
        if (argc > 0) {
            *reinterpret_cast<string*>(data) = argv[0];
        }
        return 0;
    }, &password, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return password;
}

string getFirstName(sqlite3* db, int UserID){
    char* errMsg;
    string firstName = "";  // Default value if no user is found
    string query = "SELECT firstName FROM User WHERE ID='" + to_string(UserID) + "';";
    int result = sqlite3_exec(db, query.c_str(), [](void* data, int argc, char** argv, char** colNames) {
        // Assuming only one row is returned
        if (argc > 0) {
            *reinterpret_cast<string*>(data) = argv[0];
        }
        return 0;
    }, &firstName, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return firstName;
}
string getLastName(sqlite3* db, int UserID){
    char* errMsg;
    string lastName = "";  // Default value if no user is found
    string query = "SELECT lastName FROM User WHERE ID='" + to_string(UserID) + "';";
    int result = sqlite3_exec(db, query.c_str(), [](void* data, int argc, char** argv, char** colNames) {
        // Assuming only one row is returned
        if (argc > 0) {
            *reinterpret_cast<string*>(data) = argv[0];
        }
        return 0;
    }, &lastName, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return lastName;
}

int getUserType(sqlite3* db, int UserID){
    char* errMsg;
    int Type = -1;  // Default value if no user is found
    string query = "SELECT Type FROM User WHERE ID='" + to_string(UserID) + "';";
    int result = sqlite3_exec(db, query.c_str(), [](void* data, int argc, char** argv, char** colNames) {
        // Assuming only one row is returned
        if (argc > 0) {
            reinterpret_cast<int*>(data)[0] = atoi(argv[0]);
        }
        return 0;
    }, &Type, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return Type;
}

bool modifyUsername(sqlite3* db, int userID, string newUsername) {
    char* errMsg;
    string query = "UPDATE User SET username='" + newUsername + "' WHERE ID=" + to_string(userID) + ";";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

bool modifyPassword(sqlite3* db, int userID, string newPassword) {
    char* errMsg;
    string query = "UPDATE User SET password='" + newPassword + "' WHERE ID=" + to_string(userID) + ";";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

void userTester(sqlite3* db){
    string username1 = "johndoe23", password1 = "givemeanA+please", firstName1 = "John", lastName1 = "Doe";
    string username2, password2, firstName2, lastName2;
    int type1 = 2;
    if (newUser(db, username1, password1, firstName1, lastName1, type1)) cout<<"New User Created"<<endl;
    int ID1 = getUserID(db, username1);
    int go;
    cin>>go;
    cout<<"ID: "<<ID1<<endl;
    cout<<"username: "<<getUsername(db, ID1)<<endl;
    cout<<"password: "<<getPassword(db, ID1)<<endl;
    cout<<"first name: "<<getFirstName(db, ID1)<<endl;
    cout<<"last name: "<<getLastName(db, ID1)<<endl;
    cout<<"Type: "<<getUserType(db, ID1)<<endl;
    cout<<"Choose new username: ";
    cin>>username2;
    modifyUsername(db, ID1, username2);
    cout<<"Choose new password: ";
    cin>>password2;
    modifyPassword(db, ID1, password2);
    cout<<"new username: "<<getUsername(db, ID1)<<endl;
    cout<<"new password: "<<getPassword(db, ID1)<<endl;
}

