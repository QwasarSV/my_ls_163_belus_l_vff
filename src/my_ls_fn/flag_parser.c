#include "../../include/main_header.h"

void flag_parser(int argc, char **argv,char *valid_args, my_getopt_t *getopt_ptr) {   
    int opt = 0;

    count_path_array(argc,argv, getopt_ptr);
    if(getopt_ptr->count_str > 0) { 
        getopt_ptr->path_arr = malloc(sizeof(char*) * (getopt_ptr->count_str + 1));
        dynamic_malloc(argc,argv, getopt_ptr);
    }

    while(getopt_ptr->optindex < argc) {
        if((opt = my_getopt(argc, argv, valid_args, getopt_ptr)) == -1) {
        } else {
            n_state(opt, getopt_ptr, argv);
        }
    }
}