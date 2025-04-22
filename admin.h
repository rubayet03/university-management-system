#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

class admin
{
public:
    string name, pass, p = "password";
    vector<vector<string>> v;
    void addlist();
    void editlist();
    void deletelist();

    void login();
    void viewlist();
    void menu();
    void updatelist();
    admin()
    {
        // add student info from csv file🗿🗿
        ifstream file("data.csv");
        string s;
        while (getline(file, s))
        {
            vector<string> temp;
            int len = s.length();
            int start = 0, ind;
            for (int i = 0; i < len; i++)
            {
                if (s[i] == ',' || i == len - 1)
                {
                    string sub;
                    if (i == len - 1)
                    {
                        ind = i - start + 1;
                    }
                    else
                    {
                        ind = i - start;
                    }
                    sub = s.substr(start, ind);
                    temp.push_back(sub);
                    if (i != len - 1)
                    {
                        temp.push_back(",");
                    }
                    start = i + 1;
                }
            }
            v.push_back(temp);
        }
        file.close();
    }
};

void admin::login()
{
    system("cls");
    int res, t = 0;
    string a, b;
    do
    {

        cout << "Enter Username: \n";
        cin >> a;
        cout << "Enter Password: \n";
        cin >> b;
        t++;
        if (b != p)
        {
            if (t == 10)
            {
                cout << "No more tries\n";
                Sleep(2000);
                return;
            }
            cout << "Wrong username or password!\nTry again\n";
            cout << "You have " << 10 - t << " tries left\n";
            Sleep(2000);
            system("cls");
        }

    } while (t < 10 && b != p);
    cout << "Login Complete!\n";
    cout << "Welcome " << a << "\n";
    Sleep(2000);
    name = a;
    menu();
}
void admin::menu()
{
    int n;
    string error = "Invalid Input!\n";
    while (true)
    {
        system("cls");
        cout << "Choose an option: \n";

        cout << "1. View student list\n";
        cout << "2. Add student Info\n";
        cout << "3. Edit student Info\n";
        cout << "4. Delete student Info\n";
        cout << "5. Exit\n";
        cin >> n;
        switch (n)
        {
        case 1:
        {
            viewlist();
            break;
        }
        case 2:
            addlist();
            break;
        case 3:
            editlist();
            break;
        case 4:
            deletelist();
            break;
        case 5:
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
void admin::viewlist()
{
    updatelist();
    system("cls");
    cout << "Student List:\n";
    cout << "Roll,Name,Dept,Attendance,Physics,Chemistry,Biology\n";
    cout << "-------------------------------------------------\n";
    for (auto &row : v)
    {
        for (auto &item : row)
        {
            cout << item << " ";
        }
        cout << "\n";
    }
    cout << "Type 1 to exit\n";
    int n;
    cin >> n;
    if (n)
    {
        return;
    }
}
void admin::addlist()
{
    string roll, name, dept, attendance, phy, chem, bio;
    system("cls");
    cout << "Add student Info\n";
    cout << "Enter student's roll:";
    cin >> roll;
    getchar();
    cout << "Enter student's name:";
    getline(cin, name);
    cout << "Enter student's department:";
    getline(cin, dept);
    cout << "Enter student's attendance:";
    getline(cin, attendance);
    cout << "Enter student's physics_marks:";
    getline(cin, phy);
    cout << "Enter student's chemistry_marks:";
    getline(cin, chem);
    cout << "Enter student's biology_marks:";
    getline(cin, bio);
    string new_record = roll + "," + name + "," + dept + "," + attendance + "," + phy + "," + chem + "," + bio;
    // add new record
    vector<string> temp;
    int len = new_record.length();
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            if (new_record[j] == ',' || j == len - 1)
            {
                temp.push_back(new_record.substr(i, (j - i) + 1));
                i = j;
                break;
            }
        }
    }
    v.push_back(temp);
    ofstream outfile("data.csv", ios::app);
    outfile << new_record << "\n";
    outfile.close();
}
void admin::editlist()
{
    system("cls");
    // viewlist();
    cout << "Enter student's roll:";
    string roll, s;
    cin >> roll;
    system("cls");
    string optn[] = {"name","dept","attendance","physics_marks","chemistry_marks","biology_marks"};
    cout << "Enter 1 to edit " << optn[0] << "\n";
    cout << "Enter 2 to edit " << optn[1] << "\n";
    cout << "Enter 3 to edit " << optn[2] << "\n";
    cout << "Enter 4 to edit " << optn[3] << "\n";
    cout << "Enter 5 to edit " << optn[4] << "\n";
    cout << "Enter 6 to edit " << optn[5] << "\n";
    int n;

    cin >> n;
    cin >> s;
    for (int i = 0; i < v.size(); i++)
    {

        for (int j = 0; j < v[i].size(); j++)
        {
        }
        cout << "\n";
    }
}
void admin::deletelist()
{
    system("cls");
    string roll;
    cout << "Add student's roll to delete info: \n";
    cin >> roll;
    vector<vector<string>> temp;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i][0] != roll)
        {
            temp.push_back(v[i]);
        }
    }
    v = temp;
    ofstream outfile("data.csv");
    for (auto &row : v)
    {
        for (auto &item : row)
        {
            outfile << item;
        }
        outfile << "\n";
    }
    outfile.close();
}
void admin::updatelist()
{
    admin newobj;
    v = newobj.v;
}