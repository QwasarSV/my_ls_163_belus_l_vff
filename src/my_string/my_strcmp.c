#include "../../include/my_string.h"

int my_strcmp(char* str1, char* str2) {
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    int result = len2 - len1;
    return result;
}

