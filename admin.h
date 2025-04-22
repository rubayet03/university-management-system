#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

class admin
{
private:
    vector<string> optn = {"roll", "name", "dept", "attendance", "physics_marks", "chemistry_marks", "biology_marks"};

public:
    string name, pass, p = "password";
    vector<vector<string>> v;
    void addlist();
    void editlist();
    void deletelist();

    void login();
    void viewlist();
    void menu();
    void updateconst();
    void updatelist();
    void updatevector();
    admin()
    {
        // add student info from csv file🗿🗿
        updatevector();
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
    updateconst();
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
    system("cls");
    cout << "Enter student's Info:\n";
    getchar();
    vector<string> temp;
    string s;
    for (int i = 0; i < optn.size(); i++)
    {
        cout << "Enter student's " << optn[i] << ":";
        getline(cin, s);
        temp.push_back(s);
    }
    v.push_back(temp);
    updatelist();
}
void admin::editlist()
{
    system("cls");
    // viewlist();
    cout << "Enter student's roll:";
    string roll, s;
    cin >> roll;
    system("cls");

    for (int i = 0; i < optn.size(); i++)
    {
        cout << "Enter " << i + 1 << " to edit " << optn[i] << "\n";
    }
    int n;
    cin >> n;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i][0] == roll)
        {
            cout << "Enter " << v[i][1] << "'s updated " << optn[n - 1]<<": ";
            cin >> s;
            v[i][n - 1] = s;
            cout << v[i][1] << "'s " << optn[n - 1] << " has been updated! :D\n";
            Sleep(1500);
            break;
        }
    }
    updatelist();
}
void admin::deletelist()
{
    updateconst();
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
    updatelist();
}
void admin::updatevector()
{
    ifstream file("./data/data.csv");
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
                start = i + 1;
            }
        }
        v.push_back(temp);
    }
    file.close();
}
void admin::updatelist()
{
    int len;
    ofstream file("./data/data.csv");
    for (int i = 0; i < v.size(); i++)
    {
        len = v[i].size();
        for (int j = 0; j < len; j++)
        {
            file << v[i][j];
            if (j != len - 1)
            {
                file << ",";
            }
        }
        file << "\n";
    }
    file.close();
}
void admin::updateconst()
{
    admin newobj;
    v = newobj.v;
}