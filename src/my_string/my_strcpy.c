#include "../../include/my_string.h"



char* my_strcpy(char* str_dest, char* str_src) {
    int len = my_strlen(str_src), index = 0;

    while(index < len){
        str_dest[index] = str_src[index];
        index++;
    }

    return str_dest;
}
