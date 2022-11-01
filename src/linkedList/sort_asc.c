#include "../../include/main_header.h"

void sort_asc(node_t* m_node) {

    node_t *tmp = NULL, *next = NULL;

    while(m_node != NULL) {
        tmp = m_node->daughter_head;
        while(tmp != NULL) {
            next = tmp;
            while(next != NULL) {
                
                if(tmp->st.st_mtim.tv_sec < next->st.st_mtim.tv_sec ) {
                    m_node->daughter_head = swap(m_node->daughter_head, tmp->value, next->value);        
                    //printf("1st // swap %s  with %s \n",tmp->path_name, next->path_name);
                    tmp = next;
                }
                
                if(tmp->st.st_mtim.tv_sec == next->st.st_mtim.tv_sec ) {
                    if(tmp->st.st_mtim.tv_nsec < next->st.st_mtim.tv_nsec ) {
                        m_node->daughter_head = swap(m_node->daughter_head, tmp->value, next->value);        
                        //printf("2 nd //swap %s  with %s \n",tmp->path_name, next->path_name);
                        tmp = next;
                    } else  if(str_cmp_check(tmp, next) == true) {
                    m_node->daughter_head = swap(m_node->daughter_head, tmp->value, next->value);        
                    tmp = next;
                    }
                } 
                // printf("tmp name : %s time :%li \n",tmp->path_name,tmp->st.st_mtim.tv_nsec);
                // printf("next name : %s time :%li \n",next->path_name,next->st.st_mtim.tv_nsec);
                next = next->next;
            }
        tmp = tmp->next;
        }
        m_node = m_node->next;
    }
}