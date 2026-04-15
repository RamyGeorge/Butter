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
            break;
        }
        else cur = cur->next;
    }
    return cur;
}

void LIST_DELETEAT(struct node *head, struct node *elem){
    if(head == NULL) return;
    struct node* prev = NULL;
    struct node* cur = head;
    while(cur != elem)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = cur->next;
    free(cur);
}