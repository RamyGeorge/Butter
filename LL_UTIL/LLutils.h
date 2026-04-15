#ifndef LL_UTIL_H
#define LL_UTIL_H

struct node{
    struct node* next;
    int data;
};
#define LIST_ITERARE(head) while(head);
void LIST_INSERT(struct node* head,struct node* elem);
struct node* LISTHEAD(struct node* list);
struct node* LISTTAIL(struct node* list);
void LIST_DELETEAT(struct node* head, struct node* elem);

#endif