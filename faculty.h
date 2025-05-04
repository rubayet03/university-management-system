#pragma once

// using namespace std;

class faculty : public admin
{
    string username, password,course;
    time_t timestamp;
    vector<string> names = {"Course_ID", "Course_Name", "Faculty_Name"};
    void updateattnd();
    void viewattnd();
    void uploadcourseinfo();
    void addmarks();
    void addgrades();
    void viewgrades();
    void getcourseid();

    const vector<vector<string>> &viewcourses();

public:
    vector<vector<string>> courses;
    vector<vector<string>> grades;
    void viewcourseinfo();
    void menu() override;
    faculty()
    {
        updatevector("courses", courses);
        updatevector("grades",grades);

        getcourseid();
    }
    faculty(string u)
    {
        username = u;
        addgrades();
        updatevector("courses", courses);
        updatevector("grades",grades);
        getcourseid();
    }
};
