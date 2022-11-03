#include "../../include/main_header.h"

void sort_str_arr(my_getopt_t *getopt_ptr) {
    int index = 0, jndex = 0;
    while(index +1 < getopt_ptr->count_str -1) {
        while(getopt_ptr->path_arr[index][jndex] != '\0' && getopt_ptr->path_arr[index + 1][jndex] != '\0') {
            if(my_strcmp(getopt_ptr->path_arr[index],getopt_ptr->path_arr[index + 1]) > 0) {
                    printf("do sumthing");                        
                }
        }
        jndex += 1;
        index += 1;
    }
}

                // tmp_str1 = malloc(sizeof(char)*my_strlen(tmp->path_name)+1);
                // tmp_str2 = malloc(sizeof(char)*my_strlen(next->path_name)+1);               
                // my_strcpy(tmp_str1, tmp->path_name);
                // my_strcpy(tmp_str2, next->path_name);
                
                // if(my_strcmp(my_to_lower_case(tmp_str1), my_to_lower_case(tmp_str2)) > 0 ) {
                //     m_node->daughter_head = swap(m_node->daughter_head, tmp->value, next->value);        
                //     tmp = next;
                // }
                // free(tmp_str1);
                // free(tmp_str2);