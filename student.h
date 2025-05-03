#pragma once

using namespace std;

class student : public faculty
{
    string username,id, password;
    int isvalid(string c);

public:
    vector<vector<string>> students;
    void menu() override;
    void enrollcourse();
    int alreadyenrolled(string u, string c);
    student()
    {
        updatevector("student_course", students);
    }
    student(string i,string u)
    {
        id = i;
        username = u;
        updatevector("student_course", students);
    }
};
