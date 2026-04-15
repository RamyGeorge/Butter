#include "../src/LL_utilities/LLutils.h"
#include <stdlib.h>
#include <stdio.h>

void test_insert();
void test_head();
int main(){
    test_head();
    test_insert();

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
        printf("List head functions as intended \n");
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