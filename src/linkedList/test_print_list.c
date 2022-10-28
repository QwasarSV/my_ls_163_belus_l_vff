#include "../../include/node_header.h"
#include <stdio.h> 

void test_print_list(node_t *head){
    node_t *tmp = head;

    while(tmp != NULL){
            printf("%d-", tmp->value);
            printf("%s-\n", tmp->path_name);
            tmp = tmp->next;
    }
    if(tmp == NULL){printf("null");}
}