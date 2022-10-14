#include "../../include/main_header.h"
#include "../../include/my_string.h"

void dynamic_malloc(int argc, char** argv, my_getopt_t *getopt_ptr) {    
    int index = 1;
    while(index < argc ) {
        if (argv[index][0] != '-') {
            getopt_ptr->path_arr[index-1] = malloc(sizeof(char)* (my_strlen(argv[index])+1) );
        }
        index++;
    }
}