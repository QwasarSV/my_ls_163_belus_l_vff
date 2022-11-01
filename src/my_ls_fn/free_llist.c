#include "../../include/main_header.h"

void print_and_free_llist(node_t* m_head, bool *flags) {

    node_t *tmp = m_head; 

    while (tmp != NULL) {
        test_print_list(tmp->daughter_head, flags);
        free_node(tmp->daughter_head);
        tmp = tmp->next;
    }
    free_node(m_head);

}