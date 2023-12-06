#include "User.h"
#include "Course.h"

int main() {
    sqlite3 *db;
    //open the database or create it if it doesn't exist
    int rc = sqlite3_open("data/database.db", &db);
    if (rc != SQLITE_OK){
        cout<<"Can't open database: "<<sqlite3_errmsg(db)<<endl;
        return -1;
    }
    UserTester(db);
    courseTester(db);
    sqlite3_close(db);
    return 0;
}
