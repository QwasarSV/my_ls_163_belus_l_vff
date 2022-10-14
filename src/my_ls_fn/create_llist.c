#include "../../include/main_header.h"
#include "../../include/node_header.h"
   
void create_llist(struct dirent * pDirent, DIR *pDir, node_t *head, node_t *tmp_node) {  
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

    //tmp_m_head = create_new_mother_node(0, head);
    //m_head = insert_at_head(&m_head, tmp_m_head);

} 