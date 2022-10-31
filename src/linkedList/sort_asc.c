#include "../../include/node_header.h"

void sort_asc(node_t* m_node) {

    node_t *tmp = NULL, *next = NULL;

    while(m_node != NULL) {
        tmp = m_node->daughter_head;
        while(tmp != NULL) {
            next = tmp;
            while(next != NULL) {
                
                if((tmp->st.st_mtim.tv_sec - next->st.st_mtim.tv_sec ) < 0 ){
                    m_node->daughter_head = swap(m_node->daughter_head, tmp->value, next->value);        
                    // printf("file tmp :%s - time :%lli \n",tmp->path_name, tmp->st.st_mtim.tv_sec );
                    // printf("file next :%s - time :%lli \n",next->path_name, next->st.st_mtim.tv_sec );
                    tmp = next;
                }
                next = next->next;
            }
        tmp = tmp->next;
        }
        m_node = m_node->next;
    }
}