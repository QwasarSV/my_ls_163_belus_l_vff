#include "../../include/node_header.h"
#include <stdio.h>


void recur_concatenate_llist(node_t* node_a, node_t* node_b) {
    if(node_a->next == NULL) {
        node_a->next = node_b;
    } else {
    recur_concatenate_llist(node_a->next, node_b);
    }
}


void concatenate_llist(node_t* node_a, node_t* node_b) {
    while(node_a != NULL) {
        node_a = node_a->next;
        if(node_a->next == NULL){
            node_a->next = node_b;
            break;
        }
    }
}

/* append from list 
    int index = 0;
    node_t *tmp = NULL;
    if(head == NULL){return NULL;}
    
     while(index < 15) {
         head = head->next;
         index++;
     }
    index = 0;
    while (index < 1) {
        head->next = head_to_insert;
        head_to_insert = head_to_insert->next;
        //head = head->next;
        index++;
    }
//    node_t *tmp = head->next;
//    head->next = NULL;
*/