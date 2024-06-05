#include <iostream>
#include <string>
#include <windows.h>
#include <locale>

using namespace std;

typedef bool (*CharCheckFunction)(const char*, const char*);

int main() {
    setlocale(LC_ALL, "Russian");

    // запросить пользовательский ввод
    cout << "Введите строку для поиска символов в ней:";
    string inputStr;
    getline(cin, inputStr);

    cout << "Введите символы для поиска:";
    string searchChars;
    getline(cin, searchChars);

    // загрузить динамическую библиотеку
    HMODULE hDLL = LoadLibraryW(L"DinamicLib.dll");
    if (hDLL == NULL) {
        cerr << "Не удалось загрузить библиотеку DLL." << endl;
        return 1;
    }

    // получить адреса функции из динамической библиотеки
    CharCheckFunction checkCharsInString = (CharCheckFunction)GetProcAddress(hDLL, "serchstr");
    if (checkCharsInString == NULL) {
        cerr << "Не удалось получить адрес функции." << endl;
        FreeLibrary(hDLL);
        return 1;
    }

    // вызовать функции из динамической библиотеки
    bool result = checkCharsInString(inputStr.c_str(), searchChars.c_str());

    // вывести результат
    if (result) {
        cout << "Все символы найдены!" << endl;
    }
    else {
        cout << "Символы не найдены!" << endl;
    }

    // очистить ресурсы после работы с динамической библиотекой
    FreeLibrary(hDLL);

    return 0;
}
