#include <iostream>
#include <cstring>
#include <conio.h>
#include <windows.h>
using namespace std;

#define MAX_LEN 100

// Три разных способа вычисления длины строки

// Способ 1 — классический цикл с индексом массива
int strLengthWay1(const char* str) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

// Способ 2 — чистая указательная арифметика
int strLengthWay2(const char* str) {
    const char* p = str;
    while (*p != '\0') p++;
    return p - str;             // разность указателей = длина
}

// Способ 3 — инкремент указателя + счётчик
int strLengthWay3(const char* str) {
    int count = 0;
    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}

// Ручное копирование строки
void strCopy(char* dest, const char* src) {
    while (*src != '\0') {
        *dest++ = *src++;       // копируем символ и сдвигаем оба указателя
    }
    *dest = '\0';
}

// Ручная конкатенация
void strConcat(char* dest, const char* src) {
    while (*dest != '\0') dest++;
    while (*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0';
}

// Cравнение строк — только по длине
int strCompareByLength(const char* a, const char* b) {
    return strLengthWay1(a) - strLengthWay1(b);
    // > 0 — первая строка длиннее
    // < 0 — вторая строка длиннее
    // = 0 — одинаковая длина
}

void printStr(const char* label, const char* str) {
    cout << label << " = \"" << str << "\"\n";
}

int main() {
    SetConsoleOutputCP(1251);

    char string1[MAX_LEN] = "Пр";
    char string2[MAX_LEN] = "ла313";

    char buffer[MAX_LEN * 2] = { 0 };

    cout << "Исходные строки:\n";
    printStr("string1", string1);
    printStr("string2", string2);
    cout << "\n";

    // Тест длины
    cout << "Длина string1 (три способа):\n";
    cout << "  Способ 1 => " << strLengthWay1(string1) << "\n";
    cout << "  Способ 2 => " << strLengthWay2(string1) << "\n";
    cout << "  Способ 3 => " << strLengthWay3(string1) << "\n\n";

    cout << "Длина string2 (три способа):\n";
    cout << "  Способ 1 => " << strLengthWay1(string2) << "\n";
    cout << "  Способ 2 => " << strLengthWay2(string2) << "\n";
    cout << "  Способ 3 => " << strLengthWay3(string2) << "\n\n";

    // Копирование и конкатенация
    strCopy(buffer, string1);
    strConcat(buffer, " ");
    strConcat(buffer, string2);

    cout << "После копирования string1 + \" \" + string2:\n";
    printStr("buffer", buffer);

    // Пример сравнения по длине
    cout << "\nСравнение по длине (разность):\n";
    cout << " \"string1\" и \"Привет мир\" => " << strCompareByLength(string1, "Привет мир") << "\n";
    cout << " \"string1\" и \"string2\" => " << strCompareByLength(string1, string2) << "\n";

    cout << "\nНажмите любую клавишу...\n";
    _getch();
    return 0;
}