#include "Teacher.h"
#include "Lecture.h"
#include "Grade.h"
#include "Database.h"
#include "unistd.h"
#include <iomanip>



int USER_ID = 0;
int COURSE_ID = 0;

void teacherCoursePage(sqlite3* db);
void teacherCoursesPage(sqlite3* db);
void teacherGradesPage(sqlite3* db);
void teacherViewGradesPage(sqlite3* db);
void teacherAddNewGradePage(sqlite3* db);
void studentCourseGradePage(sqlite3* db);
void studentCoursePage(sqlite3* db);
void studentCoursesPage(sqlite3* db);
void studentMenu(sqlite3* db);
void teacherMenu(sqlite3* db);
void adminMenu(sqlite3* db);
void setup(sqlite3* db);
int login(sqlite3* db);
bool createFillTest(sqlite3* db);
bool testDatabase(sqlite3* db);
bool fillDatabase(sqlite3* db);
bool createTables(sqlite3* db);


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

bool createFillTest(sqlite3* db){
    createTables(db);
    fillDatabase(db);
    testDatabase(db);
    return true;
}

void setup(sqlite3* db){
    cout<<"SETUP: Do you want to create, fill, and test the database? (y/n)"<<endl;
    char c;
    cin>>c;
    if (c == 'y'){
        createFillTest(db);
    }
    cout<<"\nSetup complete. Press enter to continue."<<endl;
    cin.ignore();
    cin.get();
    system("clear");
}

int login(sqlite3* db){
    bool correctUsername = false, correctPassword = false;
    cout<<"Please enter your credentials to login.\n"<<endl;
    while(!correctUsername){
        cout<<"username: ";
        string username;
        cin>>username;
        int userID = getUserID(db, username);
        if (userID == -1){
            cout<<"User not found, please try again!"<<endl;
        }
        else {
            correctUsername = true;
            USER_ID = userID;
        }
    }
    while (!correctPassword){
        cout<<"password: ";
        string password;
        cin>>password;
        if (getPassword(db, USER_ID) != password){
            cout<<"Incorrect password, please try again!"<<endl;
        }
        else {
            correctPassword = true;
        }
    }
    return getUserType(db, USER_ID);
}

void teacherMenu(sqlite3* db){
    system ("clear");
    cout<<"Welcome, "<<getFirstName(db, USER_ID)<<" "<<getLastName(db, USER_ID)<<"!\n"<<endl;
    cout<<"What would you like to do?\n"<<endl;
    cout<<"View my courses (1)"<<endl;
    cout<<"View my the profile of my students (2)\n"<<endl;
    cout<<"Enter your choice: ";
    int choice = 0;
    cin>>choice;
    switch (choice){
        case 1:
            teacherCoursesPage(db);
            break;
        case 2:
            //teacherStudentsPage(db);
            break;
        default:
            teacherMenu(db);
            break;
    }
}

void studentMenu(sqlite3* db){
    system ("clear");
    cout<<"Welcome, "<<getFirstName(db, USER_ID)<<" "<<getLastName(db, USER_ID)<<"!\n"<<endl;
    cout<<"What would you like to do?\n"<<endl;
    cout<<"View my courses (1)"<<endl;
    cout<<"View my profile (2)\n"<<endl;
    cout<<"Enter your choice: ";
    int choice;
    cin>>choice;
        switch (choice){
        case 1:
            studentCoursesPage(db);
            break;
        case 2:
            cout<<"Sorry, but this has not been implemented yet!"<<endl;
            usleep(2000000);
            studentMenu(db);
            break;
        default:
            studentMenu(db);
            break;
    }
}

void studentCoursesPage(sqlite3* db){
    system ("clear");
    cout<<"Please select a course to view:\n"<<endl;
    vector<int> courseIDs = getEnrolledCourseIDs(db, USER_ID);
    int choice = 0;
    for (int i = 0; i < courseIDs.size(); i++){
        cout<<getCourseName(db, courseIDs[i])<<" ("<<i+1<<")"<<endl;
    }
    cout<<"\n("<<courseIDs.size()+1<<")"<<" Go back\n"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    if (choice == courseIDs.size()+1){
        studentMenu(db);
    }
    else if (choice > courseIDs.size()+1 || choice < 1){
        cout<<"Invalid choice, please try again!"<<endl;
        studentCoursesPage(db);
    }
    else {
        COURSE_ID = courseIDs[choice-1];
        studentCoursePage(db);
    }
}

void studentCoursePage(sqlite3* db){
    system ("clear");
    cout<<"Course: "<<getCourseName(db, COURSE_ID)<<"\n"<<endl;
    cout<<"What would you like to do?\n"<<endl;
    cout<<"See all grades associated with this course (1)"<<endl;
    cout<<"See your attendance to all lectures associated with this course (2)"<<endl;
    cout<<"\nGo back (3)\n"<<endl;
    cout<<"Enter your choice: ";
    int choice = 0;
    cin>>choice;
    switch (choice){
        case 1:
            studentCourseGradePage(db);
            break;
        case 2:
            cout<<"Sorry, but this has not been implemented yet!"<<endl;
            usleep(3000000);
            studentCoursePage(db);
            break;
        case 3:
            studentCoursesPage(db);
            break;
        default:
            studentCoursePage(db);
            break;
    }
}

void studentCourseGradePage(sqlite3* db){
    system("clear");
    vector<int> gradeIDs = getStudentCourseGradeIDs(db, USER_ID, COURSE_ID);
    cout << "List of grades for " << getCourseName(db, COURSE_ID) << "\n"
         << endl;
    cout << setw(20) << "Grade Name" << setw(10) << "Points" << setw(10) << "OutOf" << setw(10) << "Value" << setw(15) << "Coefficient" << "\n"
         << endl;
    for (int gradeID : gradeIDs) {
        cout << setw(20) << getGradeName(db, gradeID)
             << setw(10) << getGradePoints(db, gradeID)
             << setw(10) << getGradeOutOf(db, gradeID)
             << setw(10) << getGradeValue(db, gradeID)
             << setw(15) << getGradeCoeff(db, gradeID) << "\n";
    }
    cout << "\nPress enter to go back to the Grades page." << endl;
    cin.ignore();
    cin.get();
    studentCoursePage(db);
}

void teacherCoursesPage(sqlite3* db){
    vector<int> courseIDs = getTaughtCourseIDs(db, USER_ID);
    int choice = 0;
    system ("clear");
    cout<<"Please select a course to view:\n"<<endl;
    for (int i = 0; i < courseIDs.size(); i++){
        cout<<getCourseName(db, courseIDs[i])<<" ("<<i+1<<")"<<endl;
    }
    cout<<"\n("<<courseIDs.size()+1<<")"<<" Go back\n"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    if (choice == courseIDs.size()+1){
        teacherMenu(db);
    }
    else if (choice > courseIDs.size()+1 || choice < 1){
        cout<<"Invalid choice, please try again!"<<endl;
        teacherCoursesPage(db);
    }
    else {
        COURSE_ID = courseIDs[choice-1];
        teacherCoursePage(db);
    }
}

void teacherCoursePage(sqlite3* db){
    system ("clear");
    cout<<"Course: "<<getCourseName(db, COURSE_ID)<<"\n"<<endl;
    cout<<"What would you like to do?\n"<<endl;
    cout<<"Access the lectures associated with this course (1)"<<endl;
    cout<<"Access the grades associated with this course (2)"<<endl;
    cout<<"\nGo back (3)\n"<<endl;
    cout<<"Enter your choice: ";
    int choice;
    cin>>choice;
    switch (choice){
        case 1:
            cout<<"Sorry, but this has not been implemented yet!"<<endl;
            usleep(3000000);
            teacherCoursePage(db);
            break;
        case 2:
            teacherGradesPage(db);
            break;
        case 3:
            teacherCoursesPage(db);
            break;
        default:
            teacherCoursePage(db);
            break;
    }
}

void teacherGradesPage(sqlite3* db){
    system ("clear");
    cout<<"Course: "<<getCourseName(db, COURSE_ID)<<"\n"<<endl;
    cout<<"What would you like to do?\n"<<endl;
    cout<<"View the grades of all students in this course (1)"<<endl;
    cout<<"Add a new grade (2)"<<endl;
    cout<<"delete a grade (3)"<<endl;
    cout<<"\nGo back (4)\n"<<endl;
    cout<<"Enter your choice: ";
    int choice;
    cin>>choice;
    switch (choice){
        case 1:
            teacherViewGradesPage(db);
            break;
        case 2:
            teacherAddNewGradePage(db);
            break;
        case 3:
            cout<<"Sorry, but this has not been implemented yet!"<<endl;
            usleep(3000000);
            teacherGradesPage(db);
            break;
        case 4:
            teacherCoursePage(db);
            break;
        default:
            teacherGradesPage(db);
            break;
    }
}

void teacherViewGradesPage(sqlite3* db) {
    system("clear");
    vector<int> studentIDs = getCourseStudentIDs(db, COURSE_ID);
    vector<int> gradeIDs;
    for (int ID : studentIDs) {
        vector<int> temp = getStudentCourseGradeIDs(db, ID, COURSE_ID);
        gradeIDs.insert(gradeIDs.end(), temp.begin(), temp.end());
    }
    cout << "List of grades for " << getCourseName(db, COURSE_ID) << "\n"
         << endl;
    cout << setw(20) << "Student Name" << setw(20) << "Grade Name" << setw(10) << "Points" << setw(10) << "OutOf" << setw(10) << "Value" << setw(15) << "Coefficient" << "\n"
         << endl;

    // TODO: Replace this with actual data from your database
    for (int gradeID : gradeIDs) {
        cout << setw(20) << getFirstName(db, getGradeStudentID(db, gradeID)) + " " + getLastName(db, getGradeStudentID(db, gradeID))
             << setw(20) << getGradeName(db, gradeID)
             << setw(10) << getGradePoints(db, gradeID)
             << setw(10) << getGradeOutOf(db, gradeID)
             << setw(10) << getGradeValue(db, gradeID)
             << setw(15) << getGradeCoeff(db, gradeID) << "\n";
    }
    cout << "\nPress enter to go back to the Grades page." << endl;
    cin.ignore();
    cin.get();
    teacherGradesPage(db);
}

void teacherAddNewGradePage(sqlite3* db){
    system("clear");
    cout<<"Course: "<<getCourseName(db, COURSE_ID)<<"\n"<<endl;
    cout<<"Please enter the following information about the new grade:\n"<<endl;
    cout << "Name of the grade: ";
    string name;
    cin.ignore();  // Clear any remaining characters in the input buffer
    getline(cin, name);
    cout<<"Points: ";
    float points;
    cin>>points;
    cout<<"Out of: ";
    float outOf;
    cin>>outOf;
    cout<<"Coefficient: ";
    float coeff;
    cin>>coeff;
    cout<<"Select the student to whom you want to assign this grade:\n"<<endl;
    vector<int> studentIDs = getCourseStudentIDs(db, COURSE_ID);
    int choice = 0;
    for (int i = 0; i < studentIDs.size(); i++){
        cout<<getFirstName(db, studentIDs[i])<<" "<<getLastName(db, studentIDs[i])<<" ("<<i+1<<")"<<endl;
    }
    cout<<"\n"<<"Cancel, and go back ("<<studentIDs.size()+1<<")\n"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    if (choice == studentIDs.size()+1){
        teacherGradesPage(db);
    }
    else if (choice > studentIDs.size()+1 || choice < 1){
        cout<<"Invalid choice, please try again!"<<endl;
        teacherAddNewGradePage(db);
    }
    newGrade(db, studentIDs[choice-1], COURSE_ID, name, points, outOf, coeff);
    cout<<"\nGrade added successfully! Press enter to go back to the Grades page."<<endl;
    cin.ignore();
    cin.get();
    teacherGradesPage(db);
}

void adminMenu(sqlite3* db){
    cout<<"not implemented yet"<<endl;
    login(db);
}
    

int main() {
    sqlite3 *db;
    int rc = sqlite3_open("data/database.db", &db);
    if (rc != SQLITE_OK){
        cout<<"Can't open database: "<<sqlite3_errmsg(db)<<endl;
        return -1;
    }
    system("clear");
    setup(db);
    cout<<"Welcome to the Student Record Management System!\n"<<endl;
    while (login(db)==0){
        cout<<"You're trying to login as an admin!\n"<<endl;
    }
    switch (getUserType(db, USER_ID)){
        case 0:
            adminMenu(db);
            break;
        case 1:
            teacherMenu(db);
            break;
        case 2:
            studentMenu(db);
            break;
        default:
            cout<<"Error: User type not found, please ask the test superviser to start over!"<<endl;
            break;
    }
    return 0;
}
