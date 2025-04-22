#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int main()
{
    system("cls");
    cout << "Enter student's Info:";
    getchar();
    vector<string> optn = {"roll", "name", "dept", "attendance", "physics_marks", "chemistry_marks", "biology_marks"};
    vector<string> temp;
    string s;
    for (int i = 0; i < optn.size(); i++)
    {
        cout << "Enter student's " << optn[i] << ":";
        getline(cin,s);
        temp.push_back(s);
    }
    
    
}