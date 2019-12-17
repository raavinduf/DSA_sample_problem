#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int i;
typedef struct node{
    char Name[20];
    int copies;
    struct node * next;
}ListNode;

typedef struct games{
    int count;
    ListNode *head;
    ListNode *data;
}Games;

int isGamesEmpty(Games *g){
    if(g->head==NULL){
        return 1;
    }
    return 0;
}

void instializeGames(Games *g){
    g->count=0;
}

void insertGame(Games *g,char Name [],int copies){
    ListNode *np;
    np=(ListNode*)malloc(sizeof(ListNode));
    strcpy(np->Name,Name);
    np->copies=copies;
    g->count++;
    if(g->head==NULL){
        g->head=np;
    }
    else{
        g->data=np;
    }
}

int insertGameCopies(Games *g,char Name [],int copies){
    int y=0;
    ListNode *np;
    np=(ListNode*)malloc(sizeof(ListNode));
    np=g->head;
    for(i=0;i<copies;i++){
        if(strcmp(np->Name,Name)==0){
            np->copies=+copies;
            y=1;
        }
    }
    if(y){
        return 0;
    }
    else{
        insertGame(g,Name,copies);
        return 0;
    }
}
typedef struct stacknode{
    int OrderNo;
    char OrderedGame [20];
    struct stacknode *next;
}StackNode;


typedef struct order{
    int count;
    StackNode *next;
}Order;

