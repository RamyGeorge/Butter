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

void LIST_INSERT(struct node **head, struct node* elem){
    elem->next = NULL;

    if (*head == NULL) {
        *head = elem;
        return;
    }

    struct node* tail = LISTTAIL(*head);
    tail->next = elem;
}