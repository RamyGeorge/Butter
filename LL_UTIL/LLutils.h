#ifndef LL_UTIL_H
#define LL_UTIL_H

struct node{
    struct node* next;
    void * data;
};

struct node* LISTHEAD(struct node* list);
struct node* LISTTAIL(struct node* list);
void LIST_DELETEAT(struct node* head, struct node* elem);

#endif