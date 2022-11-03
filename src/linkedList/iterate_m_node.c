#include "../../include/main_header.h"

void iterate_m_node(node_t *m_node, bool* bool_arr, char ** str_arr) {
    node_t  *tmp = m_node;
    int index = 0;

    while(tmp != NULL) {

        printf("%s : /n", str_arr[index]); 
        print_and_free_llist(tmp, bool_arr);
        printf("/n");
        tmp = tmp->next;
    }
    
}