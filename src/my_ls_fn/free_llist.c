#include "../../include/main_header.h"

void print_and_free_llist(node_t* m_head, my_getopt_t *getopt_ptr) {

    node_t *tmp = m_head; 
    int index = 0;
    while (tmp != NULL) {
        if(getopt_ptr->count_str > 1) {
            printf("%s :\n",getopt_ptr->path_arr[index]);
        }  
        test_print_list(tmp->daughter_head, getopt_ptr->boll_arr);
        free_node(tmp->daughter_head);
        tmp = tmp->next;
        index +=1;
        if(index < getopt_ptr->count_str) {
            printf("\n");
        }
    }
    free_node(m_head);

}