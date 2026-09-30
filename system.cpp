#include "student.h"
#include <iostream>
using namespace std;

class SystemManager {
public:
    void showRegistrarMenu() {
        cout << "\nRegistrar Privileges:\n";
        cout << "- Manage students\n";
        cout << "- Update semesters\n";
        cout << "- Add / drop courses\n";
        cout << "- View all records\n";
    }

    void showStudentMenu() {
        cout << "\nStudent Privileges:\n";
        cout << "- View enrolled courses\n";
        cout << "- Register courses\n";
        cout << "- Drop courses\n";
        cout << "- View available courses\n";
    }

    bool authenticate(string user) {
        if (user == "admin") return true;
        if (user[0] == 'S') return true;
        return false;
    }
};
