#pragma once

// using namespace std;

class faculty : public admin
{
    string username, password,course;
    vector<string> names = {"Course_ID", "Course_Name", "Faculty_Name"};
    void updateattnd();
    void viewattnd();
    void uploadcourseinfo();
    void viewgrades();
    void inputgrades();
    void getcourseid();
    const vector<vector<string>> &viewcourses();

public:
    vector<vector<string>> courses;

    void viewcourseinfo();
    void menu() override;
    faculty()
    {
        updatevector("courses", courses);
        getcourseid();
    }
    faculty(string u)
    {
        username = u;
        getcourseid();
        updatevector("courses", courses);
    }
};
