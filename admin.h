#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

class admin
{
private:
    string name, pass, p = "password";
    void addlist();
    void deletelist();
public:
    void login();
    void viewlist();
    void menu();
    
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
                break;
            }
            cout << "Wrong username or password!\nTry again\n";
        }

    } while (b != p);
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
        cout << "2. Delete student Info\n";
        cout << "3. Add student Info\n";
        cout << "4. Exit\n";
        cin >> n;
        switch (n)
        {
        case 1:
        {
            viewlist();
            break;
        }
        case 2:
            cout << "Delete student Info\n";
            break;
        case 3:
            addlist();
            break;
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
void admin::viewlist()
{
    system("cls");
    ifstream file("data.csv");
    string s;
    while (getline(file, s))
    {
        cout << s << "\n";
    }
    cout << "\n\n";
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
    ifstream file("data.csv");
    vector<string> v;
    string s;
    while (getline(file, s))
    {
        v.push_back(s);
    }
    file.close();
    string roll, name, dept, attendance, phy, chem, bio;
    cout << "Enter student details: \n";
    cout << "Enter student's roll:";
    cin >> roll;
    getchar();
    cout << "Enter student's name:";
    getline(cin,name);
    cout << "Enter student's department:";
    getline(cin,dept);
    cout << "Enter student's attendance:";
    getline(cin,attendance);
    cout << "Enter student's physics_marks:";
    getline(cin,phy);
    cout << "Enter student's chemistry_marks:";
    getline(cin,chem);
    cout << "Enter student's biology_marks:";
    getline(cin,bio);
    string new_record = roll + "," + name + "," + dept + "," + attendance + "," + phy + "," + chem + "," + bio;
    v.push_back(new_record);
    ofstream outfile("data.csv");
    for(const auto& i : v)
    {
        outfile << i << "\n";
    }
    outfile.close();
}