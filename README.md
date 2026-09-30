# University Management System (C++)

A modular, console-based University Management System written in C++. The program provides dedicated portals for administrators (registrars), teachers, and students to manage student records, course enrollment, credit tracking, and grade recording.

---

## Features

### 1. Registrar Portal (`admin`)
* **Student Record Management**: View all enrolled students, register new students, edit personal details (name, semester), and remove records.
* **Course Administration**: Manually enroll students into new courses or process course drops while respecting semester limits.

### 2. Teacher Portal (`teacher`)
* **Subject-Specific Grading**: Enter a course code (e.g., `CC120`) to view enrolled students and submit their respective evaluation marks.

### 3. Student Portal (`<Student_ID>`)
* **Course Oversight**: View currently enrolled courses and real-time grades.
* **Self-Service Registration**: Add or drop courses under credit hour constraints.
* **Curriculum Exploration**: Browse available courses tailored to the student's active semester.

---

## File Structure

| File | Description |
| :--- | :--- |
| `main.cpp` | Main application entry point; handles login dispatch and teacher grading workflows. |
| `student.h` | Core class declarations for `Course`, `Student`, and `StudentPortal`. |
| `student.cpp` | Implementation of student life cycle, course pools, and portal operations. |
| `teacher.h` | Header model representing instructor entities and assigned subject codes. |
| `marks.cpp` | Evaluation and average calculation utility routines. |
| `algoritms.cpp` | Helper search and sorting algorithms (e.g., sort students by semester, search by name). |
| `system.cpp` | Access-level privilege definitions and basic authentication validation helpers. |

---

## Getting Started

### Prerequisites
* A C++ compiler supporting C++11 or higher (e.g., `g++`, `clang++`, or MSVC).

### Compilation
Compile all implementation files together using `g++`:

```bash
g++ -std=c++11 main.cpp student.cpp marks.cpp algoritms.cpp system.cpp -o UniversityManagementSystem
