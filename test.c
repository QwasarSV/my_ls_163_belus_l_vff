#include "include/node_header.h"
#include "include/my_string.h"
#include "include/main_header.h"

//#include <sys/ioctl.h>

int main(int argc, char** argv) {

    struct dirent *pDirent = 0;
    //struct stat st;

    node_t *m_head = 0, *tmp_m_head = 0, *head = 0, *tmp_node = 0;
    
    char valid_args[] = "1at";

    my_getopt_t*    getopt_ptr = malloc(sizeof(my_getopt_t));

    getopt_ptr->boll_arr = malloc(sizeof(bool) * my_strlen(valid_args));
    DIR * pDir = NULL;
    if(argc > 1) {
        flag_parser(argc, argv, valid_args, getopt_ptr);
    }
    
    printf("%i",getopt_ptr->optindex);
    
    if(getopt_ptr->count_str == 0) {
        char cwd[PATH_MAX];
        getcwd(cwd, sizeof(cwd));
        printf("cwd : %s\n", cwd);
        pDir = opendir(cwd);
        create_llist(pDirent, pDir, head, tmp_node);
    } else {
        int index = 0;
        while(index < getopt_ptr->count_str) {
            pDir = opendir(getopt_ptr->path_arr[index]);
            tmp_m_head = create_new_mother_node(0, create_llist(pDirent, pDir, head, tmp_node));
            m_head = insert_at_head(&m_head, tmp_m_head);
            index++;
            printf("\n");
        }
    }
    
    lexi_sort(m_head);
    test_print_list(m_head->daughter_head);

    printf("m_node test :%ld\n",m_head->daughter_head->st.st_atim.tv_sec);
    printf("m_node test :%s\n",m_head->daughter_head->path_name);

    return 0;
}

    //struct timespec ts;
    //char* test[6][30] = {'\0'};


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