#include "../../include/my_string.h"

char* my_strstr(char* str, char* substr) {

    char *ptr_a = str, *ptr_b = substr;
    int index = 0;
    
    while(1){
        if(ptr_b[index] == '\0'){
            return &str[index]; 
        }
        if(ptr_a[index] == '\0'){
            return NULL;
        }
        if(ptr_a[index] != ptr_b[index]){
            ptr_a = &ptr_a[index];
            ptr_b = substr; 
        }
        index++;
    } 
}