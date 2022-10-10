#include "../../include/node_header.h"

node_t *min_sort(node_t *head, char *path) {
    
    node_t *tmp = 0;
    node_t *new_head = 0;

    while (head != NULL) {
        tmp = create_new_node(node_get_max(head),path);
        insert_at_head(&new_head, tmp);
        delete_node_on_key(&head, tmp->value);
    }
    
    return new_head;
}