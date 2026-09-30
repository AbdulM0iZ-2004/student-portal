#include "student.h"
#include <iostream>
using namespace std;

class Algorithms {
public:
    void searchByName(Student students[], int count, string name) {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (students[i].getName() == name) {
                students[i].displayStudent();
                found = true;
            }
        }
        if (!found)
            cout << "No student found with this name.\n";
    }

    void sortBySemester(Student students[], int count) {
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                if (students[j].getSemester() > students[j + 1].getSemester()) {
                    Student temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }
        cout << "Students sorted by semester.\n";
    }
};
