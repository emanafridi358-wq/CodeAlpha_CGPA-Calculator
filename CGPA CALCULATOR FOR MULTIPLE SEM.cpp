#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;


double convertGrade(string grade) {
    if (grade == "A" || grade == "a") return 4.0;
    else if (grade == "A-" || grade == "a-") return 3.7;
    else if (grade == "B+" || grade == "b+") return 3.3;
    else if (grade == "B" || grade == "b") return 3.0;
    else if (grade == "B-" || grade == "b-") return 2.7;
    else if (grade == "C+" || grade == "c+") return 2.3;
    else if (grade == "C" || grade == "c") return 2.0;
    else if (grade == "C-" || grade == "c-") return 1.7;
    else if (grade == "D" || grade == "d") return 1.0;
    else if (grade == "F" || grade == "f") return 0.0;
    else return -1.0;
}


double stringToDouble(string s) {
    stringstream ss(s);
    double val;
    ss >> val;
    return val;
}

int main() {
    int numSemesters;
    cout << "Enter number of semesters: ";
    cin >> numSemesters;

    if (numSemesters <= 0) {
        cout << "Invalid number of semesters.\n";
        return 0;
    }

    double totalAllGradePoints = 0.0, totalAllCredits = 0.0;

    for (int sem = 1; sem <= numSemesters; sem++) {
        cout << "\n===== Semester " << sem << " =====\n";
        int numCourses;
        cout << "Enter number of courses in semester " << sem << ": ";
        cin >> numCourses;

        if (numCourses <= 0) {
            cout << "Invalid number of courses.\n";
            continue;
        }

        string gradeInput;
        double gradeValue, credit;
        double totalGradePoints = 0.0, totalCredits = 0.0;

        string courseGrade[50];
        double courseCredit[50];
        double courseGradePoint[50];

        cout << "\nEnter grade and credit hours for each course:\n";
        cout << "(Example: A or 3.7 for grade, and 3 or 4 for credit hours)\n\n";

        for (int i = 0; i < numCourses; i++) {
            cout << "Course " << i + 1 << " grade: ";
            cin >> gradeInput;

            if (isdigit(gradeInput[0]))
                gradeValue = stringToDouble(gradeInput);
            else {
                gradeValue = convertGrade(gradeInput);
                if (gradeValue < 0) {
                    cout << "Invalid grade entered! Please restart.\n";
                    return 0;
                }
            }

            cout << "Course " << i + 1 << " credit hours: ";
            cin >> credit;

            courseGrade[i] = gradeInput;
            courseCredit[i] = credit;
            courseGradePoint[i] = gradeValue * credit;

            totalGradePoints += courseGradePoint[i];
            totalCredits += credit;

            cout << endl;
        }

        double GPA = totalGradePoints / totalCredits;
        cout << fixed << setprecision(2);
        cout << "\n---------------------------------------------\n";
        cout << setw(10) << "Course"
             << setw(10) << "Grade"
             << setw(15) << "Credit Hours"
             << setw(15) << "Grade Points" << endl;
        cout << "---------------------------------------------\n";

        for (int i = 0; i < numCourses; i++) {
            cout << setw(10) << i + 1
                 << setw(10) << courseGrade[i]
                 << setw(15) << courseCredit[i]
                 << setw(15) << courseGradePoint[i] << endl;
        }

        cout << "---------------------------------------------\n";
        cout << "Semester GPA: " << GPA << endl;
        cout << "---------------------------------------------\n";

        totalAllGradePoints += totalGradePoints;
        totalAllCredits += totalCredits;
    }

    if (totalAllCredits == 0) {
        cout << "\nError: Total credits cannot be zero.\n";
        return 0;
    }

    double finalCGPA = totalAllGradePoints / totalAllCredits;

    cout << fixed << setprecision(2);
    cout << "\n=============================================\n";
    cout << "Final CGPA after " << numSemesters << " semesters: " << finalCGPA << endl;
    cout << "=============================================\n";

    return 0;
}

