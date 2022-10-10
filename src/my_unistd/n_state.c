#include "../../include/main_header.h"
#include <stdio.h>

void n_state(char opt, my_getopt_t *getopt_ptr) {

    switch (opt) {
    case '1':
        getopt_ptr->boll_arr[0] = true;
    break;
    case 'a':
        getopt_ptr->boll_arr[1] = true;
    break;
    case 'b':
        getopt_ptr->boll_arr[2] = true;
    break;
    case ':':
        printf("test\n");
        getopt_ptr->optindex += 1;
    break;
    default /*?*/:
        //getopt_ptr->optindex += 1;
        break;
    }
}