#include "LLutils.h"
#include <stdio.h>
#include <stdlib.h>

struct node * LISTHEAD(struct node *list){
    if(list == NULL) return NULL;
    return list;
}

struct node * LISTTAIL(struct node* list){
    if(list == NULL) return NULL;
    struct node* cur = list;
    while(cur){
        if(!cur->next){
            return cur;
        }
        else cur = cur->next;
    }
    return NULL;
}

void LIST_DELETEAT(struct node **head, struct node *elem){
    if( *head == NULL){
        return;
    }
    struct node* prev = NULL;
    struct node* cur = *head;
    
    if(*head == elem){
        struct node* tmp = *head;
        *head = (*head)->next;
        free(tmp);
        return; 
    }
    while(cur && cur != elem){
        prev = cur;
        cur = cur->next;
    }
    if(cur == elem) {
        prev->next = cur->next;
        free(cur);
    }
    else{
        return ;
    }



    
}

void LIST_INSERT(struct node **head, struct node* elem){
    elem->next = NULL;

    if (*head == NULL) {
        *head = elem;
        return;
    }

    struct node* tail = LISTTAIL(*head);
    tail->next = elem;
}


void LIST_DELETEFIRST(struct node **head){
     if (!head || !*head) return;

    struct node* tmp = *head;
    *head = (*head)->next;
    free(tmp);
    
}

void LIST_DELETELAST(struct node **head){
   if (!head || !*head) return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct node* cur = *head;
    while (cur->next && cur->next->next){
        cur = cur->next;
    }
    free(cur->next);
    cur->next = NULL;
}