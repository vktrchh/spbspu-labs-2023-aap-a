#include "removeDuplicate.hpp"
#include <iostream>
#include <cstring>

char* removeDuplicate(const char* str1, const char* str2) {
    char result[100];  // предполагаем максимальный размер новой строки
    strcpy(result, str1);  // копируем str1 в result - будем работать с копией

    int len1 = strlen(result);
    int len2 = strlen(str2);

    for (int i = 0; i < len2; i++) {
        char* pos = nullptr;
        while ((pos = strchr(result, str2[i])) != nullptr) {
            memmove(pos, pos + 1, strlen(pos));  // сдвигаем все символы после найденного влево на одну позицию
            len1--;  // уменьшаем длину результирующей строки
        }
    }
    result[len1] = '\0';  // устанавливаем новый конец строки
    return result;
}
