#include "../../include/node_header.h"

node_t *create_new_node(int value, char* path) {
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    result->daughter_head = NULL;
    // printf("THIS IS PATH : %s \n", path);
    result->path_name = path;
    lstat(path, &result->st);
    // printf("repport :creating node\n");
    // printf("file :%s\n", result->path_name);
    // printf("size :%li\n", result->st.st_size);
    // printf("time :%li\n", result->st.st_mtim.tv_nsec);
    // printf("end repport :creating node\n");
    // printf("\n");


    return result;
}