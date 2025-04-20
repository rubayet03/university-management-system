#include<iostream>
#include<stdlib.h>


using namespace std;

class student : public admin{
    void menu();
    
};

void student::menu()
{
    int n;
    string error = "Invalid Input!\n";
    while (true)
    {
        system("cls");
        cout << "Choose an option: \n";

        cout << "1. View student list\n";
        cout << "2. Exit\n";
        cin >> n;
        switch (n)
        {
        case 1:
        {
            viewlist();
            break;
        }
        case 2:
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