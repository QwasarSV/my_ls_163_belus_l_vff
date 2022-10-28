#ifndef __HEADERFILE_I_
#define __HEADERFILE_I_

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h> // not a sycall
#include "/usr/include/x86_64-linux-gnu/sys/stat.h"

    #ifndef STRUCT_NODE
    #define STRUCT_NODE
    struct node {
        //hierarchy: n
        int value;
        struct node* next;
        struct stat st ;
        char* path_name;
        //hierarchy: n-1
        struct node* daughter_head;
    };
    typedef struct node node_t;
    #endif

node_t *create_new_mother_node(int value, node_t *head);

node_t *create_new_node(int value, char *path);
void delete_node_on_key(node_t **head, int key);
void delete_node_on_pos(node_t **head, int pos);

node_t *find_node_at_pos(node_t *head, int pos);
node_t *find_node_at_key(node_t *head, int value);
node_t *recur_find_node_at_key(node_t *head, int value);

int node_get_max(node_t* head);
int node_get_min(node_t* head);
void insert_after_node(node_t *node_to_insert, node_t *newnode);

node_t *insert_at_head(node_t **head, node_t *node_to_insert);
void reverse_node_order(node_t **head);
void test_print_list(node_t *head);
void free_node(node_t *head);
void recur_free_node(node_t *head);

node_t *go_to_node(node_t *head, int pos);
void remove_duplicate_on_node(node_t* head);

node_t *split_node_on_pos(node_t *head, int len);
int node_count(node_t *head);
int recur_node_count(node_t *head, int count);
void concatenate_llist(node_t* node_a, node_t* node_b);
void recur_concatenate_llist(node_t* node_a, node_t* node_b);
node_t *sort_ascending(node_t *head);

node_t* create_llist(struct dirent * pDirent, DIR *pDir, node_t *head, node_t *tmp_node);
void lexi_sort(node_t* m_node);
#endif