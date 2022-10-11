
#include "include/node_header.h"
#include "include/my_string.h"
#include "include/main_header.h"

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h> 
#include <dirent.h> // not a sycall
#include <string.h>
//#include <sys/ioctl.h>

int main(int argc, char** argv) {

    struct dirent * pDirent;
    
    node_t *m_head              = 0;
    node_t *tmp_m_head          = 0;
    node_t *head                = 0;
    node_t *tmp_node            = 0;
    struct stat st;
    
    my_getopt_t *getopt_ptr     = malloc(sizeof(my_getopt_t));
    char valid_args[]           = "1at";
    getopt_ptr->boll_arr        = malloc(sizeof(bool)*my_strlen(valid_args));
        
    //struct timespec ts;
    //char* test[6][30] = {'\0'};
    flag_parser(argc, argv, valid_args, getopt_ptr);

    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));
    printf("cwd : %s\n", cwd);
    DIR * pDir = opendir(cwd);
    
    int index = 0;

    while((pDirent = readdir(pDir)) != NULL){
        tmp_node = create_new_node(index, pDirent->d_name);
        head = insert_at_head(&head, tmp_node);
        
        //printf("d_type : [%d]\n", pDirent->d_type);
        printf("d_name : [%s]\n", pDirent->d_name);
        if ((head->st.st_mode & S_IFMT) == S_IFREG) {
            //printf("files :%s\n", head->path_name);
            //st.st_mode++;
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

    tmp_m_head = create_new_mother_node(0, head);
    m_head = insert_at_head(&m_head, tmp_m_head);
    
    printf("m_node test :%ld\n",m_head->daughter_head->st.st_size);
    printf("m_node test :%s\n",m_head->daughter_head->path_name);

    // printf("%c",opt = my_getopt(argc, argv, "ab:", getopt_ptr));
    // printf("%c",opt = my_getopt(argc, argv, "ab:", getopt_ptr));
    // printf("%c",opt = my_getopt(argc, argv, "ab:", getopt_ptr));
    
    // printf("%c",opt = my_getopt(argc, argv, "ab:", getopt_ptr));
    return 0;
}



    // lstat("./README.md", &st);
    // char *timeIs = ctime(&st.st_ctim.tv_sec);




    // //lstat("/home/cbutnotonly/Documents/Projects/my_ls/README.md", &ts);
    // //printf("%c",st.st_atim); struct timespec
    // printf("st_blksize: %ld \n",st.st_blksize);
    // printf("st.st_blocks : %ld \n",st.st_blocks);
    // printf("the time is %s", timeIs);
    // printf("st_ctim.tv_sec : %ld \n",st.st_ctim.tv_sec);
    // printf("st_ctim.tv_nsec : %ld \n",st.st_ctim.tv_nsec);
    // printf("st_dev : %ld \n",st.st_dev); //
    // printf("st_gid : %d \n",st.st_gid);
    // printf("st_ino : %ld \n",st.st_ino);
    // printf("st_mode : %d \n",st.st_mode);
    // printf("st_mtim.tv_sec : %ld \n",st.st_mtim.tv_sec);
    // printf("st_mtim.tv_nsec : %ld \n",st.st_mtim.tv_nsec);
    // printf("st_nlink : %ld \n",st.st_nlink);
    // printf("st_rdev : %ld \n",st.st_rdev); 
    // printf("st_size : %ld  \n",st.st_size);
    // printf("st_uid : %d \n",st.st_uid);    
       

    // if ((st.st_mode & S_IFMT) == S_IFREG) {
    //     printf("TRUE");
    //     st.st_mode++;
    // }