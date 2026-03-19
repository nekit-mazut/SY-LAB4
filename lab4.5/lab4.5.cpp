#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

using namespace std;

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
    int lenA = strLengthWay1(a);
    int lenB = strLengthWay1(b);
    return lenA - lenB;
}

void printStr(const char* label, const char* str) {
    cout << label << " = \"" << str << "\"\n";
}

void main(void) {
    SetConsoleOutputCP(1251);

    // Количество строк в массиве
    const int ARRAY_SIZE = 5;

    const char* initialTexts[ARRAY_SIZE] = {
        "Привет",
        "Мир",
        "это",
        "я",
        " "
    };

    // Выделяем память под массив указателей
    char** stringArray = (char**)calloc(ARRAY_SIZE, sizeof(char*));
    if (!stringArray) {
        cout << "Ошибка выделения массива указателей!\n";
        _getch();
        return;
    }

    // Выделяем память под каждую строку и копируем содержимое
    for (int i = 0; i < ARRAY_SIZE; i++) {
        int len = strlen(initialTexts[i]);
        stringArray[i] = (char*)calloc(len + 1, sizeof(char));
        if (!stringArray[i]) {
            cout << "Ошибка выделения строки " << i << "!\n";
            // Освобождаем уже выделенное
            for (int j = 0; j < i; j++) free(stringArray[j]);
            free(stringArray);
            _getch();
            return;
        }
        strCopy(stringArray[i], initialTexts[i]);
    }

    // Буфер для операций копирования и конкатенации
    char* buffer = (char*)calloc(200, sizeof(char));
    if (!buffer) {
        cout << "Ошибка выделения буфера!\n";
        for (int i = 0; i < ARRAY_SIZE; i++) free(stringArray[i]);
        free(stringArray);
        _getch();
        return;
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << "  [" << i << "] ";
        printStr("", stringArray[i]);
    }
    cout << "\n";

    cout << "// Тест 1: Длина всех строк массива\n";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << "Строка [" << i << "]: \"" << stringArray[i] << "\"\n";
        cout << "  Способ 1 (индекс)     => " << strLengthWay1(stringArray[i]) << "\n";
        cout << "  Способ 2 (указатели)  => " << strLengthWay2(stringArray[i]) << "\n";
        cout << "  Способ 3 (инкремент)  => " << strLengthWay3(stringArray[i]) << "\n\n";
    }

    cout << "// Тест 2: Копирование stringArray[1] в buffer\n";
    strCopy(buffer, stringArray[1]);
    printStr("buffer после копирования", buffer);
    cout << "\n";

    cout << "// Тест 3: Конкатенация \" \" и stringArray[3] к buffer\n";
    strConcat(buffer, " ");
    strConcat(buffer, stringArray[3]);
    printStr("buffer после конкатенации", buffer);
    cout << "\n";

    cout << "// Тест 4: Сравнение по разнице длин (все пары)\n";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = i + 1; j < ARRAY_SIZE; j++) {
            int diff = strCompareByLength(stringArray[i], stringArray[j]);
            cout << "  [" << i << "] vs [" << j << "] => " << diff;
            if (diff > 0) cout << " (левая длиннее на " << diff << ")";
            else if (diff < 0) cout << " (правая длиннее на " << -diff << ")";
            else cout << " (равны по длине)";
            cout << "\n";
        }
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        free(stringArray[i]);
    }
    free(stringArray);
    free(buffer);

    cout << "\nНажмите любую клавишу для выхода...\n";
    _getch();
}