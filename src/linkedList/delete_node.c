#include "../../include/node_header.h"

void delete_node_on_key(node_t **head, int key) {
    node_t *tmp = *head;
    node_t *prev;

    if(tmp != NULL && tmp->value == key){
        *head = tmp->next;
        free(tmp);
        return;
    }
    while(tmp != NULL && tmp->value != key) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL){
        return;
    }
    prev->next = tmp->next;
    free(tmp);
}

void delete_node_on_pos(node_t **head, int pos) {
    node_t *tmp = *head;
    node_t *prev;
    int index = 1;

    if(tmp != NULL && tmp->value == pos){
        *head = tmp->next;
        free(tmp);
        return;
    }
    while(tmp != NULL && tmp->value != pos) {
        prev = tmp;
        tmp = tmp->next;
        index++;
    }
    if (tmp == NULL){
        return;
    }
    prev->next = tmp->next;
    free(tmp);
}