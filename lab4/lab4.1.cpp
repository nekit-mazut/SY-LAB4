#include <iostream>
#include <string.h>
#include <conio.h>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    char str1[80] = "Привет";
    char str2[80] = "мир!";

    char buf[160];

    cout << "Исходные строки:\n";
    cout << "str1 = \"" << str1 << "\"\n";
    cout << "str2 = \"" << str2 << "\"\n\n";

    // 1. Длина строк с помощью библиотечной функции strlen
    cout << "Длина str1: " << strlen(str1) << " символов\n";
    cout << "Длина str2: " << strlen(str2) << " символов\n\n";

    // 2. Копирование строки с помощью strcpy_s
    strcpy_s(buf, str1);
    cout << "После strcpy(buf, str1):\n";
    cout << "buf = \"" << buf << "\"\n\n";

    // 3. Конкатенация (склейка) строк
    strcat_s(buf, " ");         // сначала добавляем пробел
    strcat_s(buf, str2);        // затем добавляем str2
    cout << "После strcat(buf, \" \") и strcat(buf, str2):\n";
    cout << "buf = \"" << buf << "\"\n\n";

    // 4. Сравнение строк (strcmp)
    // Возвращает:
    //   0   — строки равны
    //  <0   — str1 лексикографически меньше str2
    //  >0   — str1 лексикографически больше str2
    cout << "Сравнение str1 и str2: ";
    int res = strcmp(str1, str2);
    if (res == 0)      cout << "строки равны\n";
    else if (res < 0)  cout << "str1 < str2 (лексикографически)\n";
    else               cout << "str1 > str2 (лексикографически)\n";

    cout << "\nНажмите любую клавишу для выхода...\n";
    _getch();

    return 0;
}