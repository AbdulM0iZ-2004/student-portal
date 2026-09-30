#include "student.h"
#include <iostream>
#include <string>

using namespace std;

class TeacherManager {
public:
    void teacherInterface(StudentPortal &portal) {
        string subjectCode;
        cout << "\n--- Teacher Portal ---" << endl;
        cout << "Enter the Subject Code you teach (e.g., CC120): ";
        cin >> subjectCode;

        cout << "\nStudents enrolled in " << subjectCode << ":" << endl;
        bool foundAny = false;
        
        for (int i = 0; i < portal.getStudentCount(); i++) {
            Student &s = portal.getStudent(i);
            if (s.isEnrolledIn(subjectCode)) {
                foundAny = true;
                float marks;
                cout << "Roll No: " << s.getId() << " | Name: " << s.getName() << endl;
                cout << "Enter Marks: ";
                cin >> marks;
                s.addMarksByCourse(subjectCode, marks);
                cout << "Marks saved for " << s.getName() << ".\n" << endl;
            }
        }

        if (!foundAny) {
            cout << "No students found enrolled in course " << subjectCode << endl;
        }
        cout << "Mark entry complete. Returning to Login..." << endl;
    }
};

int main() {
    StudentPortal portal;
    TeacherManager teacherMgmt;
    
    portal.initializeCourses();
    portal.initializeStudents();

    while (true) {
        string username;
        cout << "\n==========================================" << endl;
        cout << "      UNIVERSITY MANAGEMENT SYSTEM" << endl;
        cout << "==========================================" << endl;
        cout << "Login (Enter Student ID, 'admin', 'teacher', or 'exit' to quit): ";
        cin >> username;

        if (username == "exit") {
            cout << "Exiting system. Goodbye!" << endl;
            break; 
        }

        if (username == "admin") {
            int choice;
            do {
                cout << "\n Registrar Menu \n";
                cout << "1. Display Students\n2. Add Student\n3. Update Name\n4. Update Semester\n";
                cout << "5. Delete Student\n6. Display Student Courses\n7. Add Course\n8. Drop Course\n0. Logout\n";
                cout << "Enter choice: "; cin >> choice;

                string id;
                switch(choice){
                    case 1: portal.displayStudents(); break;
                    case 2: portal.addStudent(); break;
                    case 3: cout<<"Enter ID: "; cin>>id; portal.updateStudentName(id); break;
                    case 4: cout<<"Enter ID: "; cin>>id; portal.updateStudentSemester(id); break;
                    case 5: cout<<"Enter ID: "; cin>>id; portal.deleteStudent(id); break;
                    case 6: cout<<"Enter ID: "; cin>>id; portal.displayStudentCourses(id); break;
                    case 7: cout<<"Enter ID: "; cin>>id; portal.addCourseToStudent(id); break;
                    case 8: cout<<"Enter ID: "; cin>>id; portal.dropCourseFromStudent(id); break;
                    case 0: cout<<"Logging out admin...\n"; break;
                    default: cout<<"Invalid choice\n";
                }
            } while(choice != 0);
        } 

        else if (username == "teacher") {
            teacherMgmt.teacherInterface(portal);
        }

        else {
            int idx = portal.searchStudent(username);
            if(idx == -1){ 
                cout << "Login Failed: User not found!" << endl;
                continue;
            }
            int sem = portal.getStudentSemester(idx);
            int choice;
            do {
                cout << "\nStudent Menu (" << portal.getStudent(idx).getName() << ")\n";
                cout << "1. Display My Courses\n2. Register Course\n3. Drop Course\n4. Available Courses\n0. Logout\n";
                cout << "Enter choice: "; 
                cin >> choice;
                switch(choice){
                    case 1: portal.displayStudentCourses(username); break;
                    case 2: portal.addCourseToStudent(username); break;
                    case 3: portal.dropCourseFromStudent(username); break;
                    case 4: portal.displayAvailableCourses(sem); break;
                    case 0: cout<<"Logging out student...\n"; break;
                    default: cout<<"Invalid choice\n";
                }
            } while(choice != 0);
        }
    }

    return 0;
}