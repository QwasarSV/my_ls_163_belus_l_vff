#ifndef __HEADERFILE_K_
#define __HEADERFILE_K_



#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h> 
#include <stdlib.h>
#include <string.h>

#include <stddef.h>

#include <sys/types.h>
#include <dirent.h> // not a sycall
#include "/usr/include/x86_64-linux-gnu/sys/stat.h"


#ifndef STRUCT_NODE
#define STRUCT_NODE
struct node {
    //hierarchy: n+1
    int value;
    struct node* daughter_head;
    //hierarchy: n
    char* path_name;
    struct stat st;
    struct node* next;
};
typedef struct node node_t;
#endif


#ifndef STRUCT_MY_GETOPT
#define STRUCT_MY_GETOPT

typedef struct s_my_getopt
{
    int optindex;
    int optpos;
    bool* boll_arr; // activate each option
    int count_str;
    int path_pos;
    char** path_arr; 
} my_getopt_t;
#endif






#define BADCHAR (int)'?'
#define BADARG (int)':'

int flag_parser(int argc, char **argv, char *valid_args, my_getopt_t *getopt_ptr);
    void count_path_array(int argc, char** argv,my_getopt_t *getopt_ptr);
    void dynamic_malloc(int argc, char** argv, my_getopt_t *getopt_ptr);
    int my_getopt(char **argv, char *optstr, my_getopt_t *getopt_ptr);
    void n_state(char opt, my_getopt_t *getopt_ptr, char** argv);
    
void dynamic_free(int argc, char** argv, my_getopt_t *getopt_ptr);
void free_opt(int argc, char** argv, my_getopt_t *getopt_ptr);
bool str_cmp_check(node_t* tmp, node_t* next);

//my ctype
int my_isalnum(char ch);






//my string

int my_strlen(char *str);
char* my_strcpy(char* str_dest, char* str_src);
char* my_strchr(char* str1, char ch);
char* my_strrchr(char* str1, char ch);
void my_bzero(void *generic_ptr, size_t n);
void my_reverse_string(char* str);
char* my_strstr(char* str, char* substr);
int my_strcmp(char* str1, char* str2);
//need to make specific header

char* my_to_lower_case(char* str);


// my node library

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
void test_print_list(node_t *head, bool* flags);
void free_node(node_t *head);
void recur_free_node(node_t *head);

node_t *go_to_node(node_t *head, int pos);
void remove_duplicate_on_node(node_t* head);

node_t *split_node_on_pos(node_t *head, int len);
int node_count(node_t *head);
int recur_node_count(node_t *head, int count);
void concatenate_llist(node_t* node_a, node_t* node_b);
void recur_concatenate_llist(node_t* node_a, node_t* node_b);
//node_t *sort_ascending(node_t *head);
void sort_ascending02(node_t* m_node);
node_t* create_llist(struct dirent * pDirent, DIR *pDir, node_t *head, node_t *tmp_node);
void lexi_sort(node_t* m_node);

node_t* swap(node_t* head, int node_index1, int node_index2);
void sort_asc(node_t* m_node);
void print_and_free_llist(node_t* m_head, bool *flags);

#endif