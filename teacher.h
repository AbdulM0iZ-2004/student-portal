#ifndef TEACHER_H
#define TEACHER_H

#include <string>
using namespace std;

class Teacher {
public:
    string id;
    string name;
    string subjectCode;

    Teacher() {}
    Teacher(string i, string n, string s) {
        id = i; name = n; subjectCode = s;
    }
};

#endif
