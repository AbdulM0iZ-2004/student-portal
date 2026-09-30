#include "student.h"
#include <iostream>
using namespace std;

class MarksManager {
public:
    void addMarks(Student &s) {
        int count = s.getEnrolledCourses();
        if (count == 0) {
            cout << "No courses enrolled.\n";
            return;
        }

        for (int i = 0; i < count; i++) {
            cout << "Enter marks for course " << s.getCourseCode(i) << ": ";
            float mark;
            cin >> mark;
            s.addMarksByCourse(s.getCourseCode(i), mark); 
        }

        cout << "Marks added successfully.\n";
    }

    
    void displayOverall(Student &s) {
    int count = s.getEnrolledCourses();
    if (count == 0) { cout << "No courses enrolled.\n"; return; }

    float sum = 0;
    int gradedCourses = 0;

    for (int i = 0; i < count; i++) {
        float m = s.getMarks(i);
        if (m >= 0) { 
            sum += m;
            gradedCourses++;
        }
    }

    if (gradedCourses > 0) {
        float percentage = sum / gradedCourses;
        cout << "Overall Percentage (based on graded courses): " << percentage << "%\n";
    } else {
        cout << "No marks have been entered by teachers yet.\n";
    }
}
};
