#include <iostream>
#include "student_grades.h"
#include "transliteration.h"

using namespace std;

int main() {
    system("chcp 1251>null");
    cout << "\tМеню\n1) Оцінки студентів\n2) Фільтрація неприйнятних слів\n3) Транслітерація\nВаш вибір: ";
    short choice;
    cin >> choice;

    switch (choice) {
    case 1: student_grades(); break;
    case 2: cout << "\t\n\tне дійшло як зробити(((((\n\n"; break;
    case 3: transliteration(); break;
    default: cout << "Невірний вибір\n"; break;
    }

    return 0;
}
