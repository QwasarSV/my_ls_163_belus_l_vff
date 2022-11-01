#include "../../include/main_header.h"

int node_count(node_t *head) {
    
    int count = 0;
    node_t *tmp = head;

    while(tmp != NULL ){
        tmp = tmp->next;
        count++;
    }

    return count;
}

int recur_node_count(node_t *head, int count) {
    
    if(head == NULL){
        return count;
    }
   
    count++;
    
    return recur_node_count(head->next, count); 
} 