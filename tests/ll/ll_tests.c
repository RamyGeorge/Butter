#include "../../src/Linkedlist/LLutils.h"
#include <stdlib.h>
#include <stdio.h>

void test_insert();
void test_head();
void test_deletehead();
void test_deletetail();
void test_deleteat();

int main(){
    test_head();
    test_insert();
    test_deletehead();
    test_deletetail();
    test_deleteat();
    return 0;
}

void test_head(){
    struct node* nodelist = NULL;
    for(int i =0; i < 3; i ++){
        struct node* x = malloc(sizeof(struct node));
        x->data=i;
        x->next = NULL;

        LIST_INSERT(&nodelist, x);
    }

    if (LISTHEAD(nodelist)->data == 0 && LISTHEAD(nodelist)->next->data == 1){
        printf("Passed: LISTHEAD() functions as intended \n");
    }
    else {
        printf("LISTHEAD() failed..\n");
    }
}

void test_insert(){
    struct node* nodelist = NULL;

    for(int i = 0; i < 3; i++){
        struct node* x = malloc(sizeof(struct node));
        x->data = i;
        x->next = NULL;

        LIST_INSERT(&nodelist, x);
    }

    int size = 0;
    int sum = 0;
    struct node* x = nodelist;
    while(x){
        size++;
        sum+=x->data;
        x = x->next;
    }

    if(size == 3 && sum == 3){
        printf("Passed: List Insert functions as intended\n");
    }
    else{
        printf("size expected 3 sum expected 2 result was %d %d\n",size,sum);
    }
}

void test_deletehead(){
    struct node* nodelist = NULL;

    for(int i = 0; i < 3; i++){
        struct node* x = malloc(sizeof(struct node));
        x->data = i;
        x->next = NULL;

        LIST_INSERT(&nodelist, x);
    }
    LIST_DELETEFIRST(&nodelist);
    int sum = 0;
    struct node* tmp = nodelist;
    LIST_ITERATE(tmp){
        sum+= tmp->data;
        tmp= tmp->next;
    }
    if(sum == 3){
        printf("Passed: DELETEFIRST() functions as intended\n");
    }
    else{
        printf("sum expected 3 result was  %d\n",sum);
    }
    
}

void test_deletetail(){
    struct node* nodelist = NULL;

    for(int i = 0; i < 3; i++){
        struct node* x = malloc(sizeof(struct node));
        x->data = i;
        x->next = NULL;

        LIST_INSERT(&nodelist, x);
    }
    LIST_DELETELAST(&nodelist);
    int sum =0;
    struct node* tmp = nodelist;
    LIST_ITERATE(tmp){
        sum+=tmp->data;
        tmp = tmp->next;
    }
    if(sum == 1){
        printf("Passed: DELETELAST() functions as intended\n");
    }
    else{
        printf("sum expected 1 result was  %d\n",sum);
    }
    
}

void test_deleteat(){
    struct node* nodelist = NULL;

    for(int i = 0; i < 3; i++){
        struct node* x = malloc(sizeof(struct node));
        x->data = i;
        x->next = NULL;

        LIST_INSERT(&nodelist, x);
    }
    struct node* tmp = nodelist;
    int sum = 0;
    LIST_DELETEAT(&nodelist, nodelist->next);
    LIST_ITERATE(tmp){
        sum += tmp->data;
        tmp = tmp->next;
    }
    if(sum == 2){
        printf("Passed: DELETEAT() functions as intended\n");
    }
    else{
        printf("sum expected 2 result was  %d\n",sum);
    }
    
}