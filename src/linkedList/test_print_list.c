#include "../../include/node_header.h"
#include <stdio.h> 

void test_print_list(node_t *head, bool* flags){
    node_t *tmp = head;
    int state = 0;

    while(tmp != NULL) {
    
    if(flags[1] == 0 && tmp->path_name[0] == '.') {
        state = 0;
    } else {
        state = 1;
    }

    if (state && (head->st.st_mode & S_IFMT) == S_IFDIR) {
        printf("%s\n", tmp->path_name);
    }
    if (state && (head->st.st_mode & S_IFMT) == S_IFREG) {
        printf("%s\n", tmp->path_name);
    }
    free(tmp->path_name);
    tmp = tmp->next;
    }

    //if(tmp == NULL){printf("null");}
}