#include "headers.h"

using namespace std;

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
        cout << "5. View Student Leaderboard\n";
        cout << "6. Exit\n";
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
            viewleaderboard();
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
void admin::viewlist()
{
    int n;
    updateconst();
    system("cls");
    cout << "Student List:\n";
    cout << "Roll,Name,Dept,Attendance,Physics,Chemistry,Biology\n";
    cout << "-------------------------------------------------\n";
    do
    {
        for (auto &row : v)
        {
            for (auto &item : row)
            {
                cout << item << " ";
            }
            cout << "\n";
        }
        cout << "Type 1 to exit\n";

        cin >> n;
    } while (n != 1);
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
            cout << "Enter " << v[i][1] << "'s updated " << optn[n - 1] << ": ";
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
void admin::updatevector(string add,vector<vector<string>>&data)
{
    ifstream file("./data/" + add + ".csv");
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
        data.push_back(temp);
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
void admin::viewleaderboard()
{
    system("cls");
    map<int, vector<string>> xx;
    vector<int> x;
    int len, ans;
    for (int i = 0; i < v.size(); i++)
    {
        ans = 0;
        len = v[i].size();
        for (int j = 4; j < len; j++)
        {
            ans += stoi(v[i][j]);
        }
        x.push_back(ans);
    }
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            xx[x[i]].push_back(v[i][j]);
        }
    }
    for (auto it = xx.rbegin(); it != xx.rend(); ++it)
    {
        for (const auto &s : it->second)
        {
            cout << s << " ";
        }
        cout << it->first << "\n";
    }

    Sleep(5000);
}
void admin::viewusr()
{
    window usr;
    vector<vector<string>> users = usr.viewusers();
}
