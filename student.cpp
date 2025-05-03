#include "headers.h"

using namespace std;

void student::menu()
{
    int n;
    string error = "Invalid Input!\n";
    while (true)
    {
        system("cls");
        cout << "Choose an option: \n";

        cout << "1. View Course Info\n";
        cout << "2. Enroll in Course\n";
        cout << "3. View Leaderboards\n";
        cout << "4. Exit\n";
        cin >> n;
        switch (n)
        {
        case 1:
        {
            viewcourseinfo();
            break;
        }
        case 2:
        {
            enrollcourse();
            break;
        }
        case 3:
        {
            viewleaderboard();
            break;
        }
        case 4:
            cout << "Logged Out!\n";
            Sleep(2000);
            return;
        default:
            system("cls");
            cout << error << "\n";
            Sleep(2000);
        }
    }
}
int student::isvalid(string c)
{
    for (int i = 0; i < courses.size(); i++)
    {
        if (courses[i][0] == c)
        {
            return 1;
        }
    }
    return 0;
}
void student::enrollcourse()
{
    string course;
    cout << "Enter Course name: ";
    cin >> course;
    ofstream file("./data/student_course.csv", ios_base::app);
    if (isvalid(course))
    {
        if (alreadyenrolled(username, course))
        {
            cout << "Student " << username << " has already enrolled in " << course << "!\n";
            Sleep(2000);
        }
        else
        {
            file << id << ',' << course << "\n";
            cout << "Successfully enrolled! :D\n";
            Sleep(2000);
        }
    }
    else
    {
        cout << "Course Doesn't Exist!\n";
        Sleep(2000);
    }
    file.close();
}
int student::alreadyenrolled(string u, string c)
{
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i][0] == u && students[i][1] == c)
        {
            return 1;
        }
    }
    return 0;
}
