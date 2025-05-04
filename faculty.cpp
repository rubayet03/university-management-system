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
        cout << "5. View Grades\n";
        cout << "6. Add marks\n";
        cout << "7. Exit\n";
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
            viewgrades();
            break;
        case 6:
            addmarks();
            break;
        case 7:
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
    string x,t;
    for (int i = 0; i < var.students.size(); i++)
    {
        if (var.students[i][1] == course)
        {
            timestamp = time(nullptr);
            t = ctime(&timestamp);
            t = t.substr(0,t.size() - 1);
            cout << "Enter 1 if " << var.students[i][0] << " is present or 0 if not!\n";
            cin >> x;
            file << var.students[i][0] << ',' << course << ',' << t << ',' << x << "\n";
        }
    }
    file.close();
    Sleep(3000);
}
void faculty::viewattnd()
{
    int total = 1;
    system("cls");
    map<pair<string, string>, pair<int, int>> var;
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
        total = max(i.second.first,total);
        cout << i.first.first << ",";
        cout << i.first.second << ",";
        cout << total<< ",";
        cout << ceil(i.second.second * 100.00 / total) << "%\n";
    }
    string pp;
    cout << "\nEnter anything to exit\n";
    cin >> pp;
}
void faculty::addmarks()
{
    ofstream file("./data/marks.csv",ios_base::app);
    vector<vector<string>>marks;
    updatevector("marks",marks);
    student var;
    string mark,title;
    int flag;
    for (int i = 0; i < var.students.size(); i++)
    {
        if (var.students[i][1] == course)
        {
            flag = 1;
            cout << "Enter marks for " << var.students[i][0] << " in course " <<course<<"\n";
            
            cin >> mark;
            cout << "Enter exam title(mid/interim/final)\n";
            cin >> title;
            for(int j = 0; j < marks.size();j++)
            {
                // len = marks[i].size();
                // for (int j = 0; j < len; j++)
                if(marks[j][0] == var.students[i][0] && marks[j][3] == title)
                {
                    system("cls");
                    cout << title << "-Mark already given for " << marks[j][0] << "\n";
                    Sleep(2000);
                    flag = 0;
                    break;
                }
                
            }
            if(flag)
            {
                file <<  var.students[i][0] << ',' << course << ',' << mark << ',' << title << "\n"; 
            }
        }
    }
    file.close();
}
void faculty::addgrades()
{
    vector<vector<string>>marks;
    updatevector("marks",marks);
    
    map<pair<string, string>, int> var;
    for (int i = 0; i < marks.size(); i++)
    {
        int res = stod(marks[i][2]);
        if(marks[i][3] == "interim")
        {
            res = res * (10.00 / 100.00);
        }
        else if(marks[i][3] == "mid")
        {
            res = res * (40.00/ 100.00);
        }
        else 
        {
            res = res * (50.00 / 100.00);
        }
        var[make_pair(marks[i][0], marks[i][1])] += res;    
    }
    ofstream file("./data/grades.csv");
    for(auto i : var)
    {
        file << i.first.first << ',';
        file << i.first.second << ',';
        int m = i.second;
        switch (m / 10)
        {     
        case 10:
        case 9:   
        case 8:
            file << "A+" << "\n";
            break;
        case 7:
            file << "A"<< "\n";
            break;
        case 6:
            file << "B"<< "\n";
            break;
        case 5:
            file << "C"<< "\n";  
            break;
        case 4:
            file << "D"<< "\n";
            break;        
        default:
            file << "F"<< "\n";
            break;
        }
        
    }
    file.close();
}
void faculty::viewgrades()
{
    system("cls");
    faculty obj;
    grades = obj.grades;
    for(auto i : grades)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    string exit;
    cout << "Enter anything to exit!\n";
    cin >> exit;
}