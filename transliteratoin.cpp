#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string translit_char(char c) {
    switch (c) {
    case 'а': return "a"; case 'б': return "b"; case 'в': return "v";
    case 'г': return "h"; case 'ґ': return "g"; case 'д': return "d";
    case 'е': return "e"; case 'є': return "ye"; case 'ж': return "zh";
    case 'з': return "z"; case 'и': return "y"; case 'і': return "i";
    case 'ї': return "yi"; case 'й': return "j"; case 'к': return "k";
    case 'л': return "l"; case 'м': return "m"; case 'н': return "n";
    case 'о': return "o"; case 'п': return "p"; case 'р': return "r";
    case 'с': return "s"; case 'т': return "t"; case 'у': return "u";
    case 'ф': return "f"; case 'х': return "kh"; case 'ц': return "ts";
    case 'ч': return "ch"; case 'ш': return "sh"; case 'щ': return "shch";
    case 'ь': return ""; case 'ю': return "yu"; case 'я': return "ya";

    case 'А': return "A"; case 'Б': return "B"; case 'В': return "V";
    case 'Г': return "H"; case 'Ґ': return "G"; case 'Д': return "D";
    case 'Е': return "E"; case 'Є': return "Ye"; case 'Ж': return "Zh";
    case 'З': return "Z"; case 'И': return "Y"; case 'І': return "I";
    case 'Ї': return "Yi"; case 'Й': return "J"; case 'К': return "K";
    case 'Л': return "L"; case 'М': return "M"; case 'Н': return "N";
    case 'О': return "O"; case 'П': return "P"; case 'Р': return "R";
    case 'С': return "S"; case 'Т': return "T"; case 'У': return "U";
    case 'Ф': return "F"; case 'Х': return "Kh"; case 'Ц': return "Ts";
    case 'Ч': return "Ch"; case 'Ш': return "Sh"; case 'Щ': return "Shch";
    case 'Ю': return "Yu"; case 'Я': return "Ya";

    default: return string(1, c);
    }
}

int transliteration() {
    system("chcp 1251>null");
    cout << "\t\n\tТранслітерація\n\n";
    ifstream input("ukrainian_text.txt");
    if (!input) {
        cout << "Файл не знайдено\n";
        return 1;
    }

    ofstream output("transliterated_text.txt");
    if (!output) {
        cout << "Не вдалося створити файл для запису\n";
        return 1;
    }

    string line;
    while (getline(input, line)) {
        for (char& c : line) {
            output << translit_char(c);
        }
        output << endl;
    }

    cout << "Транслітерація завершена. Результат у файлі transliterated_text.txt\n";
    input.close();
    output.close();
    return 0;
}
