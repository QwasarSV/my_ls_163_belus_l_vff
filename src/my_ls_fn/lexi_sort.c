#include "../../include/node_header.h"
#include "../../include/my_string.h"
#include "../../include/main_header.h"

node_t* swap(node_t* head, int node_index1, int node_index2) {
    node_t* curr1 = head, * prev1 = NULL, * curr2 = head, * prev2 = NULL, * tmp = NULL;

    if(node_index1 == node_index2 || node_index2 == head->value){
        return head;
    }

    while(curr2 != NULL &&  curr2->value != node_index2) {
        prev2 = curr2; 
        curr2 = curr2->next;
    }

    if(head->value != node_index1 && head->value != node_index2){

        while(curr1 != NULL &&  curr1->value != node_index1) {
            prev1 = curr1; 
            curr1 = curr1->next;
        }
        prev1->next = curr2;
    }

    prev2->next = curr1;

    tmp = curr1->next;
    curr1->next = curr2->next;
    curr2->next = tmp;

    if(head->value == node_index1 || head->value == node_index2){
        head = curr2;
    }
    
    return head;
}


char* my_to_lower_case(char* str) {
    
    int index = 0;
    while(str[index] != '\0') { 
        if(str[index] >= 'A' && str[index] <= 'Z') {
            str[index] = str[index] + ' ';
        } 
        index += 1;
    }
    return str;
}

void lexi_sort(node_t* m_node) {

    node_t *tmp = NULL, *next = NULL;
    char* tmp_str1, * tmp_str2;

    while(m_node != NULL) {
        tmp = m_node->daughter_head;
        while(tmp != NULL) {
            next = tmp;
            while(next != NULL) {
                tmp_str1 = malloc(sizeof(char)*my_strlen(tmp->path_name)+1);
                tmp_str2 = malloc(sizeof(char)*my_strlen(next->path_name)+1);               
                my_strcpy(tmp_str1, tmp->path_name);
                my_strcpy(tmp_str2, next->path_name);
                
                if(my_strcmp(my_to_lower_case(tmp_str1), my_to_lower_case(tmp_str2)) > 0 ){
                    m_node->daughter_head = swap(m_node->daughter_head, tmp->value, next->value);        
                    tmp = next;
                }
                free(tmp_str1);
                free(tmp_str2);
                next = next->next;
            }
        tmp = tmp->next;
        }
        m_node = m_node->next;
    }
}


void sort_ascending02(node_t* m_node) {

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


            // printf("index N %i :  - ",index);
            // test_print_list(m_node->daughter_head);
            // printf("\n\n");