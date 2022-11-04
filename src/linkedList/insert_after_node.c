#include "../../include/main_header.h"

void insert_after_node(node_t* node_to_insert, node_t* new_node) {
    
    new_node->next = node_to_insert->next;
    node_to_insert->next = new_node;
}