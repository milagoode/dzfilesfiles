#include <iostream>
#include <fstream>
#include <string>
#include "student_grades.h"

using namespace std;

int student_grades() {
    system("chcp 1251>null");
    cout << "\t\n\tОцінки студентів\n\n";

    ifstream file("students.txt");
    if (!file) {
        cout << "Файл не знайдено\n";
        return 1;
    }

    string name, surname;
    int grade;
    short total_students = 0;
    short total_score = 0;
    cout << "Введіть бал для фільтрації студентів: ";
    int threshold;
    cin >> threshold;

    cout << "\nСтуденти з оцінкою менше " << threshold << ":\n";

    bool no_students_below_threshold = true;

    while (file >> surname >> name >> grade) {
        if (grade < threshold) {
            cout << surname << " " << name << ": " << grade << endl;
            no_students_below_threshold = false;
        }
        total_score += grade;
        total_students++;
    }
    if (no_students_below_threshold) {
        cout << "Всі студенти мають оцінки вищі або рівні " << threshold << ".\n";
    }

    if (total_students > 0) {
        cout << "\nСередній бал: " << static_cast<float>(total_score) / total_students << endl;
    }
    else {
        cout << "Немає студентів для обробки.\n";
    }
    file.close();
    return 0;
}
