#ifndef __HEADERFILE_K_
#define __HEADERFILE_K_

#ifndef STRUCT_MY_GETOPT
#define STRUCT_MY_GETOPT

#include <stdbool.h>

typedef struct s_my_getopt
{
    int optindex;
    int optpos;
    bool *boll_arr; // activate each option
} my_getopt_t;
#endif

#define BADCHAR (int)'?'
#define BADARG (int)':'

void flag_parser(int argc, char **argv, char *valid_args, my_getopt_t *getopt_ptr);
    int my_getopt(int argc, char **argv, char *optstr, my_getopt_t *getopt_ptr);
    void n_state(char opt, my_getopt_t *getopt_ptr);


#endif