#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
void deletelist(vector<vector<string>> &v);
int main()
{
    // admin user;
    // for (int i = 0; i < user.v.size(); i++)
    // {
    //     for(int j = 0; j < user.v[i].size(); j++)
    //     {
    //         cout << user.v[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    vector<vector<string>> x;
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
        x.push_back(temp);
    }
    file.close();
    deletelist(x);
}
void deletelist(vector<vector<string>> &v)
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
    for (auto &i : temp)
    {
        for (auto &j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}