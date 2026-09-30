#include "student.h"

Student::Student() {
    id = ""; 
    name = ""; 
    semester = 0; 
    enrolledCourses = 0;
    totalCreditHours = 0; 
    percentage = 0; 
    grade = 'N'; 
    attendance = false;

    for (int i = 0; i < 5; i++) {
        marks[i] = 0;
    }
    for (int i = 0; i < MAX_COURSES; i++) {
        courseMarks[i] = -1;
    }
}

void Student::enrollSemesterCourses(Course coursePool[][MAX_COURSES], int coursesPerSemester[]) {
    if (semester < 1 || semester > MAX_SEMESTERS) 
    return;
    
    enrolledCourses = coursesPerSemester[semester - 1];
    totalCreditHours = 0;
    for (int i = 0; i < enrolledCourses; i++) {
        courses[i] = coursePool[semester - 1][i];
        totalCreditHours += courses[i].creditHours;
    }
}

bool Student::registerCourse(Course c, float maxCredits) {
    if (enrolledCourses >= MAX_COURSES) {
        cout << "Course limit reached.\n";
        return false;
    }
    if (totalCreditHours + c.creditHours > maxCredits) {
        cout << "Cannot register " << c.code << ". Max credit hours exceeded.\n";
        return false;
    }
    for (int i = 0; i < enrolledCourses; i++) {
        if (courses[i].code == c.code) {
            cout << "Already registered " << c.code << endl;
            break;
        }
    }
    courses[enrolledCourses++] = c;
    totalCreditHours += c.creditHours;
    cout << "Registered " << c.code << " successfully.\n";
    return true;
}

void Student::dropCourse(string code) {
    for (int i = 0; i < enrolledCourses; i++) {
        if (courses[i].code == code) {
            totalCreditHours -= courses[i].creditHours;
            for (int j = i; j < enrolledCourses - 1; j++) {
                courses[j] = courses[j + 1];
                courseMarks[j] = courseMarks[j + 1];
            }
            enrolledCourses--;
            cout << "Dropped " << code << " successfully.\n";
            return;
        }
    }
    cout << "Course not found.\n";
}

void Student::displayStudent() {
    cout << "ID: " << id << " | Name: " << name << " | Semester: " << semester 
         << " | Credit Hours: " << totalCreditHours << endl;
}

void Student::displayCourses() {
    if (enrolledCourses == 0) { 
        cout << "No courses enrolled.\n"; 
        return; 
    }
    for (int i = 0; i < enrolledCourses; i++) {
        cout << courses[i].code << " - " << courses[i].title << " (" 
             << courses[i].creditHours << " Cr) | Marks: ";
        if (courseMarks[i] == -1) cout << "N/A";
        else cout << courseMarks[i];
        cout << endl;
    }
}


StudentPortal::StudentPortal() {
    studentCount = 0;
}

void StudentPortal::initializeCourses() {
    coursesPerSemester[0] = 7;
    coursePool[0][0] = Course("CC120", "Application of ICT", 2);
    coursePool[0][1] = Course("CC120L", "Application of ICT Lab", 1);
    coursePool[0][2] = Course("CC141", "Discrete Structures", 3);
    coursePool[0][3] = Course("MA107", "Calculus & Analytical Geometry", 3);
    coursePool[0][4] = Course("EN110", "English-I", 3);
    coursePool[0][5] = Course("ISL112", "Islamic Thought", 2);
    coursePool[0][6] = Course("POL121", "Pakistan: Ideology & Society", 2);

    coursesPerSemester[1] = 8;
    coursePool[1][0] = Course("CC111", "Programming Fundamentals", 3);
    coursePool[1][1] = Course("CC111L", "Programming Fundamentals Lab", 1);
    coursePool[1][2] = Course("MA150", "Probability & Statistics", 3);
    coursePool[1][3] = Course("MA108", "Multivariable Calculus", 3);
    coursePool[1][4] = Course("NS125", "Applied Physics", 2);
    coursePool[1][5] = Course("NS125L", "Applied Physics Lab", 1);
    coursePool[1][6] = Course("EN123", "English-II", 3);
    coursePool[1][7] = Course("UE1", "University Elective I", 3);

}

void StudentPortal::initializeStudents() {
    string ids[5] = {"S001","S002","S003","S004","S005"};
    string names[5] = {"Ali","Ahmed","Abdul Moiz","Hassan","Hamza"};
    int semesters[5] = {1,1,2,2,1};
    
    for (int i = 0; i < 5; i++) {
        students[i].setId(ids[i]);
        students[i].setName(names[i]);
        students[i].setSemester(semesters[i]);
        students[i].enrollSemesterCourses(coursePool, coursesPerSemester);
        studentCount++;
    }
}

int StudentPortal::searchStudent(string id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getId() == id) 
            return i;
    }
    return -1;
}

void StudentPortal::addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Student limit reached.\n";
        return;
    }
    string id, name; int sem;
    cout << "Enter ID: "; 
    cin >> id;
    if (searchStudent(id) != -1) {
        cout << "Student exists!\n";
        return;
    }
    cout << "Enter Name: "; 
    cin >> name;
    cout << "Enter Semester (1-8): "; 
    cin >> sem;
    
    students[studentCount].setId(id);
    students[studentCount].setName(name);
    students[studentCount].setSemester(sem);
    students[studentCount].enrollSemesterCourses(coursePool, coursesPerSemester);
    studentCount++;
    cout << "Student added successfully!\n";
}

void StudentPortal::displayStudents() {
    if (studentCount == 0) {
        cout << "No students.\n";
        return;
    }
    for (int i = 0; i < studentCount; i++) {
        students[i].displayStudent();
    }
}

void StudentPortal::updateStudentName(string id) {
    int idx = searchStudent(id);
    if (idx != -1) {
        string n; 
        cout << "New Name: "; 
        cin >> n;
        students[idx].setName(n);
    }
}

void StudentPortal::updateStudentSemester(string id) {
    int idx = searchStudent(id);
    if (idx != -1) {
        int s; 
        cout << "New Semester: "; 
        cin >> s;
        students[idx].setSemester(s);
        students[idx].enrollSemesterCourses(coursePool, coursesPerSemester);
    }
}

void StudentPortal::deleteStudent(string id) {
    int idx = searchStudent(id);
    if (idx != -1) {
        for (int i = idx; i < studentCount - 1; i++) 
            students[i] = students[i+1];
        studentCount--;
        cout << "Deleted.\n";
    }
}

void StudentPortal::addCourseToStudent(string id) {
    int idx = searchStudent(id);
    if (idx != -1) {
        string c, t; 
        float cr;
        cout << "Code: "; cin >> c;
        cout << "Title: "; 
        getline(cin >> ws, t);
        cout << "Credits: "; cin >> cr;
        
        students[idx].registerCourse(Course(c, t, cr), 21.0);
    } else {
        cout << "Student not found.\n";
    }
}

void StudentPortal::dropCourseFromStudent(string id) {
    int idx = searchStudent(id);
    if (idx != -1) {
        string c; 
        cout << "Code to drop: "; 
        cin >> c;
        students[idx].dropCourse(c);
    }
}

void StudentPortal::displayStudentCourses(string id) {
    int idx = searchStudent(id);
    if (idx != -1) students[idx].displayCourses();
}

void StudentPortal::displayAvailableCourses(int sem) {
    if (sem < 1 || sem > MAX_SEMESTERS) return;
    cout << "\nCourses for Semester " << sem << ":\n";
    for (int i = 0; i < coursesPerSemester[sem-1]; i++) {
        cout << coursePool[sem-1][i].code << " - " << coursePool[sem-1][i].title << endl;
    }
}