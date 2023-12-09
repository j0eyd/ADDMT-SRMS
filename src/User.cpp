#include "User.h"

//TYPES: 0: Admin | 1: Teacher | 2: Student
bool newUser(sqlite3* db, string username, string password,
    string firstName, string lastName, int type){
    char* errMsg;
    string checkQuery = "SELECT COUNT(*) FROM Users WHERE username='" + username + "';";
    int count;
    int checkResult = sqlite3_exec(db, checkQuery.c_str(), [](void* data, int argc, char** argv, char** colNames) -> int {
        if (argc > 0 && argv[0]) {
            *static_cast<int*>(data) = std::stoi(argv[0]);
        }
        return 0;
    }, &count, &errMsg);
    // If the username already exists, return false
    if (count > 0) {
        cerr << "Error: Username '" << username << "' already exists." << endl;
        return false;
    }
    string query = "INSERT INTO Users (username, password, firstName, lastName, type) VALUES ('" +
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
    string query = "DELETE FROM Users WHERE ID=" + to_string(userID) + ";";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

int getUserID(sqlite3* db, string username) {
    char* errMsg;
    int userID = -1;  // Default value if no user is found
    string query = "SELECT ID FROM Users WHERE username='" + username + "';";
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
    string query = "SELECT username FROM Users WHERE ID='" + to_string(UserID) + "';";
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
    string query = "SELECT password FROM Users WHERE ID='" + to_string(UserID) + "';";
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
    string query = "SELECT firstName FROM Users WHERE ID='" + to_string(UserID) + "';";
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
    string query = "SELECT lastName FROM Users WHERE ID='" + to_string(UserID) + "';";
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
    string query = "SELECT Type FROM Users WHERE ID='" + to_string(UserID) + "';";
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
    string query = "UPDATE Users SET username='" + newUsername + "' WHERE ID=" + to_string(userID) + ";";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

bool modifyPassword(sqlite3* db, int userID, string newPassword) {
    char* errMsg;
    string query = "UPDATE Users SET password='" + newPassword + "' WHERE ID=" + to_string(userID) + ";";
    int result = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (result != SQLITE_OK) cerr << "Error: " << errMsg << endl;
    return result == SQLITE_OK;
}

void userTest(sqlite3* db){
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

bool userFillDatabase(sqlite3* db){
    assert(newUser(db, "NassimAdmin64", "Antifragile43-", "Nassim", "Taleb", 0));
    assert(newUser(db, "RobAdmin128", "TheBigOne*74", "Rob", "Henderson", 0));
    assert(newUser(db, "TheTemp54","Idontexist32=", "Will", "Disappear", 0));
    cout<<"Users (admins) inserted\n"<<endl;
    return true;
}

bool userTestDatabase(sqlite3* db){
    cout<<"Operations on temporary admin: retrieve parameters, modify them then delete him:\n"<<endl;
    int ID = getUserID(db, "TheTemp54");
    cout<<"ID of TheTemp54: "<<ID<<endl;
    cout<<"Username of user with id "<<ID<<": "<<getUsername(db, ID)<<endl;
    cout<<"Password of user with id "<<ID<<": "<<getPassword(db, ID)<<endl;
    cout<<"First Name of user with id "<<ID<<": "<<getFirstName(db, ID)<<endl;
    cout<<"Last Name of user with id "<<ID<<": "<<getLastName(db, ID)<<endl;
    cout<<"Type of user with id "<<ID<<": "<<getUserType(db, ID)<<"\n"<<endl;
    cout<<"Modification..."<<endl;
    assert(modifyUsername(db, ID, "newUsername324"));
    assert(modifyPassword(db, ID, "newPassword76-"));
    cout<<"Modification successful"<<endl;
    cout<<"Username of user with id "<<ID<<": "<<getUsername(db, ID)<<endl;
    cout<<"Password of user with id "<<ID<<": "<<getPassword(db, ID)<<endl;
    assert(deleteUser(db, ID));
    cout<<"Temporary user deleted.\n"<<"User tests successful.\n"<<endl;
    return true;
}