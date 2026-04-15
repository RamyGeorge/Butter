#include "LLutils.h"
#include <stdio.h>
#include <stdlib.h>

struct node * LISTTHEAD(struct node *list){
    return list;
}

struct node * LISTTAIL(struct node* list){
    struct node* cur = list;
    while(cur){
        if(cur->next){
            break;
        }
        else cur = cur->next;
    }
}

void LIST_DELETEAT(struct node *head, struct node *elem){
    struct node* prev = NULL;
    struct node* cur = head;
    while(cur != head)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = cur->next;
    free(cur);
}