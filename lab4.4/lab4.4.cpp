#include <iostream>
#include <cstring>
#include <conio.h>
#include <windows.h>
using namespace std;

#define MAX_LEN 100


int strLengthWay1(const char* str) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

int strLengthWay2(const char* str) {
    const char* p = str;
    while (*p != '\0') p++;
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
        *dest++ = *src++;
    }
    *dest = '\0';
}

void strConcat(char* dest, const char* src) {
    while (*dest != '\0') dest++;
    while (*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0';
}

int strCompareByLength(const char* a, const char* b) {
    return strLengthWay1(a) - strLengthWay1(b);
}

void printStr(const char* label, const char* str) {
    cout << label << " = \"" << str << "\"\n";
}

int main() {
    SetConsoleOutputCP(1251);

    const char* text1 = "Пр";
    const char* text2 = "ла31";

    //   calloc вместо malloc => выделяет память и сразу заполняет её нулями
    char* string1 = (char*)calloc(strlen(text1) + 1, sizeof(char));
    char* string2 = (char*)calloc(strlen(text2) + 1, sizeof(char));

    // Проверка на ошибку выделения
    if (!string1 || !string2) {
        cout << "Ошибка выделения памяти для строк!\n";
        if (string1) free(string1);
        if (string2) free(string2);
        _getch();
        return 1;
    }

    strCopy(string1, text1);
    strCopy(string2, text2);

    char* buffer = (char*)calloc(MAX_LEN * 2, sizeof(char));

    if (!buffer) {
        cout << "Ошибка выделения буфера!\n";
        free(string1);
        free(string2);
        _getch();
        return 1;
    }

    cout << "Исходные строки (динамическая память через calloc):\n";
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

    free(buffer);
    free(string2);
    free(string1);

    cout << "\nНажмите любую клавишу для выхода...\n";
    _getch();

    return 0;
}