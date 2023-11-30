#include "sqlite3.h"
#include "Teacher.h"
#include "Admin.h"

int createStudentTable(){

    rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
}

void displayAllTables(sqlite3 *db) {
    const char *sql = "SELECT name FROM sqlite_master WHERE type='table';";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        cerr << "Error preparing statement: " << sqlite3_errmsg(db) << endl;
        return;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        const char *tableName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        cout << "Table: " << tableName << endl;

        // Retrieve and display data from each table
        const char *query = ("SELECT * FROM " + string(tableName) + ";").c_str();
        if (sqlite3_exec(db, query, [](void *data, int argc, char **argv, char **colNames) -> int {
            for (int i = 0; i < argc; i++) {
                cout << colNames[i] << ": " << (argv[i] ? argv[i] : "NULL") << " | ";
            }
            cout << endl;
            return 0;
        }, nullptr, nullptr) != SQLITE_OK) {
            cerr << "Error executing query for table " << tableName << ": " << sqlite3_errmsg(db) << endl;
        }
    }

    sqlite3_finalize(stmt);
}

bool createUsersTable(sqlite3 *db){
    char* errMsg;
    string query = "CREATE TABLE IF NOT EXISTS Users (
                      ID INTEGER PRIMARY KEY,
                      username TEXT NOT NULL,
                      password TEXT NOT NULL,
                      firstName TEXT,
                      lastName TEXT,
                      userType TEXT NOT NULL);"
    return (sqlite3_exec(db, query, 0, 0, errMsg) == 0);
}

int main(){
    //INTIALIZATION
    sqlite3 *db;
    char *errMsg = 0;
    //open the database or create it if it doesn't exist
    int rc = sqlite3_open("data/database.db", &db);
    if (rc != SQLITE_OK){
        cout<<"Can't open database: "<<sqlite3_errmsg(db)<<endl;
        return -1;
    }

    //OP Choice
    cout<<"choose operation (fill | display)"<<endl;
    string choice;
    cin>>choice;
    switch choice{
        case "fill":
            createUsertables(db);
        case "display":
            displayAllTables(db);
            break;
        default:
            cout<<"wrong choice"<<endl;
            break;
    }

    sqlite3_close(db);
    return 0;
}