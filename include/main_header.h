#ifndef __HEADERFILE_K_
#define __HEADERFILE_K_



#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h> 

#include <string.h>
#include <stdlib.h>

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

#endif