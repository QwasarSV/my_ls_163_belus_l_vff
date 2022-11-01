#include "../../include/main_header.h"

void lexi_sort(node_t* m_node) {

    node_t *tmp = NULL, *next = NULL;
    //char* tmp_str1, * tmp_str2;

    while(m_node != NULL) {
        tmp = m_node->daughter_head;
        while(tmp != NULL) {
            next = tmp;
            while(next != NULL) {
                if(str_cmp_check(tmp, next) == true) {
                    m_node->daughter_head = swap(m_node->daughter_head, tmp->value, next->value);        
                    tmp = next;
                }
                next = next->next;
            }
        tmp = tmp->next;
        }
        m_node = m_node->next;
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