using namespace std;

class admin
{
private:
    vector<string> optn = {"roll", "name", "dept", "attendance", "physics_marks", "chemistry_marks", "biology_marks"};
    string name, pass, p = "password";
    vector<vector<string>> v;
    void addlist();
    void editlist();
    void deletelist();
    void updateconst();
    void updatelist();
    void viewlist();
    void enrollstudent();
    void viewusr();

public:
    void viewleaderboard();
    virtual void menu();
    void updatevector(string a, vector<vector<string>> &data);

    admin()
    {
        // add student info from csv file🗿🗿
        updatevector("data", v);
    }
};
