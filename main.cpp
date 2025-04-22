#include <iostream>
#include <sstream>
#include <windows.h>
#include "admin.h"
#include "student.h"

using namespace std;

class window
{

public:
    static void main_menu()
    {
        int n;
        string error = "Invalid Input!";
        while (true)
        {
            system("cls");
            cout << "Choose an option to log-in: \n";
            cout << "1. Admin\n";
            cout << "2. Student\n";
            cout << "3. Exit\n";
            cin >> n;
            switch (n)
            {
            case 1:
            {
                admin user;
                user.login();
                break;
            }
            case 2:
            {
                student user;
                user.viewlist();
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
    // void loading_scrn(){
    // }
};

int main()
{
    // system("color 9F");
    window::main_menu();
    return 0;
}
