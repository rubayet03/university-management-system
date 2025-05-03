#include "headers.h"


using namespace std;
void window::main_menu()
{
    int n;
    string error = "Invalid Input!";
    while (true)
    {
        system("cls");
        cout << "Choose an option to log-in: \n";
        cout << "1. Register User\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cin >> n;
        switch (n)
        {
        case 1:
        {
            window usr;
            usr.registerusr();
            break;
        }
        case 2:
        {
            window usr;
            usr.login();
            break;
        }

        case 3:
            cout << "Goodbye!\n";
            return;
        default:
            system("cls");
            Sleep(500);
            cout << error << "\n";
            Sleep(2000);
        }
    }
}
void window::registerusr()
{
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;
    cout << "Enter Role(student/faculty/admin): ";
    cin >> role;
    ofstream file("./data/users.csv", ios_base::app);
    file << id << ',' << username << ',' << password << ',' << role << '\n';
}
void window::login()
{
    string u, p, r;
    cout << "Enter Username: ";
    cin >> u;
    cout << "Enter Password: ";
    cin >> p;
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i][1] == u && users[i][2] == p)
        {
            cout << "Login Successful as " << users[i][3] << "\n";
            if (users[i][3] == "admin")
            {
                admin a;
                a.menu();
            }
            else if (users[i][3] == "faculty")
            {
                faculty f(u);
                f.menu();
            }
            else
            {
                student s(users[i][0],users[i][1]);
                s.menu();
            }
            return;
        }
    }
    cout << "Login Failed!\n";
    Sleep(2000);
}
void window::viewvector()
{
    for (auto i : users)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    // Sleep(5000);
}
const vector<vector<string>>&window::viewusers()
{
    return users;
}