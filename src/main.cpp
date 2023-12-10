#include "Teacher.h"
#include "Lecture.h"
#include "Grade.h"
#include "Database.h"

bool fillDatabase(sqlite3 *db){
    assert(userFillDatabase(db));
    assert(courseFillDatabase(db));
    assert(studentFillDatabase(db));
    assert(teacherFillDatabase(db));
    assert(lectureFillDatabase(db));
    assert(gradeFillDatabase(db));
    return true;
}

bool testDatabase(sqlite3* db){
    assert(userTestDatabase(db));
    assert(courseTestDatabase(db));
    assert(studentTestDatabase(db));
    assert(teacherTestDatabase(db));
    assert(lectureTestDatabase(db));
    assert(gradeTestDatabase(db));
    return true;
}

int main() {
    sqlite3 *db;
    //open the database or create it if it doesn't exist
    int rc = sqlite3_open("data/database.db", &db);
    if (rc != SQLITE_OK){
        cout<<"Can't open database: "<<sqlite3_errmsg(db)<<endl;
        return -1;
    }
    assert(createTables(db));
    assert(fillDatabase(db));
    assert(testDatabase(db));
    cout<<"done"<<endl;
    return 0;
}
