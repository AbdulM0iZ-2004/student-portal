#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX_STUDENTS = 100;
const int MAX_COURSES = 20;
const int MAX_SEMESTERS = 8;
const float MAX_CREDIT_HOURS = 19;

class Course {
public:
    string code;
    string title;
    float creditHours;
    string prerequisite;

    Course() {
        code = "";
        title = "";
        creditHours = 0;
        prerequisite = "";
    }

    Course(string c, string t, float cr, string pre = "") {
        code = c;
        title = t;
        creditHours = cr;
        prerequisite = pre;
    }
};

class Student {
private:
    string id;
    string name;
    int semester;
    Course courses[MAX_COURSES];
    int enrolledCourses;
    float totalCreditHours;
    float courseMarks[MAX_COURSES];

public:
    float marks[5];
    float percentage;
    char grade;
    bool attendance;

    Student();

    void setId(string s) { id = s; }
    void setName(string n) { name = n; }
    void setSemester(int sem) { semester = sem; }

    string getId() { return id; }
    string getName() { return name; }
    int getSemester() { return semester; }
    int getEnrolledCourses() { return enrolledCourses; }
    float getTotalCreditHours() { return totalCreditHours; }

    string getCourseCode(int index) {
        if (index >= 0 && index < enrolledCourses) return courses[index].code;
        return "";
    }

    float getMarks(int index) {
        if (index >= 0 && index < enrolledCourses) return courseMarks[index];
        return -1;
    }

    bool isEnrolledIn(string code) {
        for (int i = 0; i < enrolledCourses; i++) {
            if (courses[i].code == code) return true;
        }
        return false;
    }

    void addMarksByCourse(string code, float m) {
        for (int i = 0; i < enrolledCourses; i++) {
            if (courses[i].code == code) {
                courseMarks[i] = m;
                return;
            }
        }
    }

    void displayStudent();
    void displayCourses();
    bool registerCourse(Course c, float maxCredits = MAX_CREDIT_HOURS);
    void dropCourse(string code);
    void enrollSemesterCourses(Course coursePool[][MAX_COURSES], int coursesPerSemester[]);
};

class StudentPortal {
private:
    Student students[MAX_STUDENTS];
    int studentCount;
    Course coursePool[MAX_SEMESTERS][MAX_COURSES];
    int coursesPerSemester[MAX_SEMESTERS];

public:
    StudentPortal();
    void initializeCourses();
    void initializeStudents();
    int searchStudent(string id);
    void addStudent();
    void updateStudentName(string id);
    void updateStudentSemester(string id);
    void deleteStudent(string id);
    void displayStudents();
    void addCourseToStudent(string id);
    void dropCourseFromStudent(string id);
    void displayStudentCourses(string id);
    void displayAvailableCourses(int semester);

    int getStudentCount() { return studentCount; }
    Student& getStudent(int idx) { return students[idx]; }
    
    int getStudentSemester(int idx) {
        return students[idx].getSemester();
    }
};

#endif