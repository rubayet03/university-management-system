#pragma once

// using namespace std;

class faculty : public admin
{
    string username, password;
    vector<string> names = {"Course_ID", "Course_Name", "Faculty_Name"};
    void updateattnd();
    void viewattnd();
    void uploadcourseinfo();
    void updtgrades();
    void inputgrades();
    const vector<vector<string>> &viewcourses();

public:
    vector<vector<string>> courses;

    void viewcourseinfo();
    void menu() override;
    faculty()
    {
        updatevector("courses", courses);
    }
    faculty(string u)
    {
        username = u;
        updatevector("courses", courses);
    }
};
