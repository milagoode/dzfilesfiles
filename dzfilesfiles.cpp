#include <iostream>
#include "student_grades.h"
#include "transliteration.h"

using namespace std;

int main() {
    system("chcp 1251>null");
    cout << "\t����\n1) ������ ��������\n2) Գ�������� ������������ ���\n3) �������������\n��� ����: ";
    short choice;
    cin >> choice;

    switch (choice) {
    case 1: student_grades(); break;
    case 2: cout << "\t\n\t�� ����� �� �������(((((\n\n"; break;
    case 3: transliteration(); break;
    default: cout << "������� ����\n"; break;
    }

    return 0;
}
