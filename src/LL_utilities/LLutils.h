#ifndef LL_UTIL_H
#define LL_UTIL_H

struct node{
    struct node* next;
    int data;
};
#define LIST_ITERATE(head) while(head)
struct node* LISTHEAD(struct node* list);
struct node* LISTTAIL(struct node* list);
void LIST_INSERT(struct node **head, struct node* elem);
void LIST_DELETEAT(struct node **head, struct node *elem);
void LIST_DELETEFIRST(struct node** head);
void LIST_DELETELAST(struct node** head);

#endif