#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
using namespace std;

#define INITIAL_TEXT1 "Привет 332"   // исходный текст первой строки
#define INITIAL_TEXT2 "сила"      // исходный текст второй строки
#define MAX_LEN 100

int strLengthWay1(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int strLengthWay2(const char* str) {
    const char* p = str;
    while (*p != '\0') {
        p++;
    }
    return p - str;
}

int strLengthWay3(const char* str) {
    int count = 0;
    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}

void strCopy(char* dest, const char* src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}


void strConcat(char* dest, const char* src) {
    while (*dest != '\0') {
        dest++;
    }
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}


int strCompareByLength(const char* a, const char* b) {
    int lenA = strLengthWay1(a);
    int lenB = strLengthWay1(b);
    return lenA - lenB;
}

void printStr(const char* label, const char* str) {
    cout << label << " = \"" << str << "\"\n";
}

void main(void)
{
    SetConsoleOutputCP(1251);
// ─── Выделение памяти под две исходные строки
    char* string1 = (char*)malloc(strlen(INITIAL_TEXT1) + 1);
    char* string2 = (char*)malloc(strlen(INITIAL_TEXT2) + 1);

    // Проверка на успешное выделение памяти
    if (!string1 || !string2) {
        cout << "Ошибка выделения памяти для строк!\n";
        if (string1) free(string1);
        if (string2) free(string2);
        _getch();
        return;
    }

    strCopy(string1, INITIAL_TEXT1);
    strCopy(string2, INITIAL_TEXT2);

    // ─── Выделение буфера для результатов операций
    char* buffer = (char*)malloc(MAX_LEN * 2);
    if (!buffer) {
        cout << "Ошибка выделения буфера!\n";
        free(string1);
        free(string2);
        _getch();
        return;
    }

    // Делаем буфер пустой строкой
    buffer[0] = '\0';


    cout << "Исходные строки (динамическая память через malloc):\n";
    printStr("string1", string1);
    printStr("string2", string2);
    cout << "\n";

    cout << "// Тест 1: Длина string1\n";
    cout << " Способ 1 (индекс)     => " << strLengthWay1(string1) << "\n";
    cout << " Способ 2 (указатели)  => " << strLengthWay2(string1) << "\n";
    cout << " Способ 3 (инкремент)  => " << strLengthWay3(string1) << "\n\n";

    cout << "// Тест 2: Длина string2\n";
    cout << " Способ 1 (индекс)     => " << strLengthWay1(string2) << "\n";
    cout << " Способ 2 (указатели)  => " << strLengthWay2(string2) << "\n";
    cout << " Способ 3 (инкремент)  => " << strLengthWay3(string2) << "\n\n";

    strCopy(buffer, string1);
    cout << "// Тест 3: После копирования string1 в buffer\n";
    printStr("buffer", buffer);
    cout << "\n";

    strConcat(buffer, " ");
    strConcat(buffer, string2);
    cout << "// Тест 4: После конкатенации \" \" и string2\n";
    printStr("buffer", buffer);
    cout << "\n";

    cout << "// Тест 5: Сравнение по разнице длин (положительное — левая длиннее)\n";
    cout << " string1 и \"Привет\"    => " << strCompareByLength(string1, "Привет") << "\n";
    cout << " string1 и string2             => " << strCompareByLength(string1, string2) << "\n";
    cout << " string2 и \"Учеба это сила\"   => " << strCompareByLength(string2, "Учеба это сила") << "\n";
    cout << " \"abc\" и \"abcd\"             => " << strCompareByLength("abc", "abcd") << "\n";

    // освобождаем всю выделенную память
    free(buffer);
    free(string2);
    free(string1);

    cout << "\nНажмите любую клавишу для выхода...\n";
    _getch();
}