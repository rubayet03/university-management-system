#pragma once
using namespace std;

class window : public admin
{
    string id, username, password, role;
    vector<vector<string>> users;

public:
    static void main_menu();
    void login();
    void registerusr();
    void viewvector();
    const vector<vector<string>> &viewusers();
    window()
    {
        updatevector("users", users);
    }
    
};
