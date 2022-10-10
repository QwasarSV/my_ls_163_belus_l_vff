#include "../../include/my_string.h"

char* my_strchr(char* str, char ch) {

    int len = my_strlen(str), index = 0;

    while(str[index] != ch){
        index++;
        if(index == len) {
            return NULL;
        }
    }
    
    return &str[index];
}