#include "../../include/main_header.h"
#include "../../include/node_header.h"
#include "../../include/my_string.h"
   
node_t* create_llist(struct dirent * pDirent, DIR *pDir, node_t *head, node_t *tmp_node) {  
    int index = 0;
    while((pDirent = readdir(pDir)) != NULL) {
        
        printf("d_name : [%s]\n", pDirent->d_name);
        tmp_node = create_new_node(index, pDirent->d_name);
        head = insert_at_head(&head, tmp_node);
        
        // printf("repport\n");
        // printf("file :%s\n", head->path_name);
        // printf("size :%li\n", head->st.st_size);
        // printf("time :%li\n", head->st.st_mtim.tv_nsec);
        // printf("end repport\n");
        // printf("\n");
        //printf("d_type : [%d]\n", pDirent->d_type);
        
        if ((head->st.st_mode & S_IFMT) == S_IFREG) {
           // printf("files :%s\n", head->path_name);
        }

        if ((head->st.st_mode & S_IFMT) == S_IFDIR) {
            //printf("dir :%s\n", head->path_name);
            //st.st_mode++;
        }

        if ((head->st.st_mode & S_IFMT) == S_IFLNK) {
            //printf("LNK :%s\n", head->path_name);
            //st.st_mode++;
        }
        //printf("d_ino : [%ld]\n", pDirent->d_ino);
        //printf("d_off : [%ld]\n", pDirent->d_off);
        //printf("d_reclen : [%d]\n", pDirent->d_reclen);
        //printf("d_type : [%d]\n", pDirent->d_type);
        //printf("st_test : %li \n",head->st.st_ino);
        //printf("pathname : %s \n",head->path_name);
        //test[index][0] = '.';
        //test[index][1] = '/';
        //strcat(test[index], (char *)pDirent->d_name);
        //printf("%s \n",test[index]);
        index++;
    }
    return head;
} 