#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string translit_char(char c) {
    switch (c) {
    case '�': return "a"; case '�': return "b"; case '�': return "v";
    case '�': return "h"; case '�': return "g"; case '�': return "d";
    case '�': return "e"; case '�': return "ye"; case '�': return "zh";
    case '�': return "z"; case '�': return "y"; case '�': return "i";
    case '�': return "yi"; case '�': return "j"; case '�': return "k";
    case '�': return "l"; case '�': return "m"; case '�': return "n";
    case '�': return "o"; case '�': return "p"; case '�': return "r";
    case '�': return "s"; case '�': return "t"; case '�': return "u";
    case '�': return "f"; case '�': return "kh"; case '�': return "ts";
    case '�': return "ch"; case '�': return "sh"; case '�': return "shch";
    case '�': return ""; case '�': return "yu"; case '�': return "ya";

    case '�': return "A"; case '�': return "B"; case '�': return "V";
    case '�': return "H"; case '�': return "G"; case '�': return "D";
    case '�': return "E"; case '�': return "Ye"; case '�': return "Zh";
    case '�': return "Z"; case '�': return "Y"; case '�': return "I";
    case '�': return "Yi"; case '�': return "J"; case '�': return "K";
    case '�': return "L"; case '�': return "M"; case '�': return "N";
    case '�': return "O"; case '�': return "P"; case '�': return "R";
    case '�': return "S"; case '�': return "T"; case '�': return "U";
    case '�': return "F"; case '�': return "Kh"; case '�': return "Ts";
    case '�': return "Ch"; case '�': return "Sh"; case '�': return "Shch";
    case '�': return "Yu"; case '�': return "Ya";

    default: return string(1, c);
    }
}

int transliteration() {
    system("chcp 1251>null");
    cout << "\t\n\t�������������\n\n";
    ifstream input("ukrainian_text.txt");
    if (!input) {
        cout << "���� �� ��������\n";
        return 1;
    }

    ofstream output("transliterated_text.txt");
    if (!output) {
        cout << "�� ������� �������� ���� ��� ������\n";
        return 1;
    }

    string line;
    while (getline(input, line)) {
        for (char& c : line) {
            output << translit_char(c);
        }
        output << endl;
    }

    cout << "������������� ���������. ��������� � ���� transliterated_text.txt\n";
    input.close();
    output.close();
    return 0;
}
