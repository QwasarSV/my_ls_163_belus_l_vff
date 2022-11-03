#include "../../include/main_header.h"

bool str_cmp_check(node_t* tmp, node_t* next) {
    
    // char* tmp_str1, * tmp_str2;
    bool result = false;

    // tmp_str1 = malloc(sizeof(char)*my_strlen(tmp->path_name)+1);
    // tmp_str2 = malloc(sizeof(char)*my_strlen(next->path_name)+1);               
    // my_strcpy(tmp_str1, tmp->path_name);
    // my_strcpy(tmp_str2, next->path_name);
    
    //if(my_strcmp(my_to_lower_case(tmp_str1), my_to_lower_case(tmp_str2)) > 0 ) {       
    if(my_strcmp(tmp->path_name, next->path_name) > 0 ) {
        result = true;
        tmp = next;
    }
    // free(tmp_str1);
    // free(tmp_str2);
    return result;
}