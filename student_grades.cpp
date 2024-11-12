#include <iostream>
#include <fstream>
#include <string>
#include "student_grades.h"

using namespace std;

int student_grades() {
    system("chcp 1251>null");
    cout << "\t\n\t������ ��������\n\n";

    ifstream file("students.txt");
    if (!file) {
        cout << "���� �� ��������\n";
        return 1;
    }

    string name, surname;
    int grade;
    short total_students = 0;
    short total_score = 0;
    cout << "������ ��� ��� ���������� ��������: ";
    int threshold;
    cin >> threshold;

    cout << "\n�������� � ������� ����� " << threshold << ":\n";

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
        cout << "�� �������� ����� ������ ���� ��� ��� " << threshold << ".\n";
    }

    if (total_students > 0) {
        cout << "\n������� ���: " << static_cast<float>(total_score) / total_students << endl;
    }
    else {
        cout << "���� �������� ��� �������.\n";
    }
    file.close();
    return 0;
}