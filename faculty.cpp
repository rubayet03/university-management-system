#include "headers.h"

using namespace std;
void faculty::menu()
{
    int n;
    string error = "Invalid Input!\n";
    while (true)
    {
        system("cls");
        cout << "Choose an option: \n";

        cout << "1. Upload Course Info\n";
        cout << "2. View Course Info\n";
        cout << "3. View Attendance\n";
        cout << "4. Update Attendance\n";
        cout << "5. Input/Edit Grades\n";
        cout << "6. Exit\n";
        cin >> n;
        switch (n)
        {
        case 1:
        {
            uploadcourseinfo();
            break;
        }
        case 2:
            viewcourseinfo();
            break;
        case 3:
            viewattnd();
            break;
        case 4:
            updateattnd();
            break;
        case 5:
            break;
        case 6:
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
void faculty::viewcourseinfo()
{
    system("cls");
    string s;
    cout << "Enter " << names[0] << " to view info: \n";
    cin >> s;
    for (int i = 0; i < courses.size(); i++)
    {
        if (courses[i][0] == s)
        {
            for (int j = 0; j < courses[i].size(); j++)
            {
                cout << names[j] << ": " << courses[i][j];
                if (j != courses[i].size() - 1)
                {
                    cout << ", ";
                }
                cout << "\n";
            }
            break;
        }
    }
    cout << "Enter anything to exit!\n";
    cin >> s;
}
void faculty::uploadcourseinfo()
{
    vector<string> x;
    string s;
    ofstream file("./data/courses.csv", ios_base::app);
    cin.ignore();
    for (int i = 0; i < names.size(); i++)
    {
        cout << "Enter " << names[i] << ": ";
        getline(cin, s);
        x.push_back(s);
    }
    for (int i = 0; i < x.size(); i++)
    {
        file << x[i];
        if (i != x.size() - 1)
        {
            file << ",";
        }
    }
    file << "\n";
    file.close();
    updatevector("courses", courses);
}
const vector<vector<string>> &faculty::viewcourses()
{
    return courses;
}
void faculty::getcourseid()
{
    for (int i = 0; i < courses.size(); i++)
    {
        if (courses[i][2] == username)
        {
            course = courses[i][0];
            return;
        }
    }
}
void faculty::updateattnd()
{
    ofstream file("./data/attendance.csv", ios_base::app);

    student var;
    string x;
    for (int i = 0; i < var.students.size(); i++)
    {
        if (var.students[i][1] == course)
        {
            cout << "Enter 1 if " << var.students[i][0] << " is present or 0 if not!\n";
            cin >> x;
            file << var.students[i][0] << ',' << course << ',' << "_time" << ',' << x << "\n";
        }
    }
    file.close();
    Sleep(3000);
}
void faculty::viewattnd()
{
    system("cls");
    map<pair<string, string>, pair<float, float>> var;
    vector<vector<string>> att;
    updatevector("attendance", att);
    for (int i = 0; i < att.size(); i++)
    {
        var[make_pair(att[i][0], att[i][1])].first++;
        if (stoi(att[i][3]))
        {
            var[make_pair(att[i][0], att[i][1])].second++;
        }
    }
    cout << "Student_id,";
    cout << "Course_code,";
    cout << "Total_Class,";
    cout << "Present_Percentage\n";
    for (auto i : var)
    {
        cout << i.first.first << ",";
        cout << i.first.second << ",";
        cout << i.second.first << ",";
        cout << ceil(i.second.second * 100.00 / i.second.first) << "%\n";
    }
    string pp;
    cout << "\nEnter anything to exit\n";
    cin >> pp;
}