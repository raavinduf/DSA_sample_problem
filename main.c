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
typedef struct queuenode{
    int OrderNo;
    char OrderedGame [20];
    struct queuenode *next;
}QueueNode;


typedef struct orders{
    int count;
    QueueNode *rear;
    QueueNode *front;
}Orders;

void createOrders(Orders *o){
    int count=0;
    o->rear=NULL;
    o->front=NULL;
}

int isOrdersEmpty(Orders *o){
    if(o->count==0)
        return 1;
    return 0;
}

int insertOrder(Orders *o,int Order_number,char Orderedgame[] ){
    QueueNode *np;
    np=(QueueNode*)malloc(sizeof(QueueNode));
    np->OrderNo=Order_number;
    strcpy(np->OrderedGame,Orderedgame);
    if(isOrdersEmpty(o)){
        o->rear=np;
        o->head=np;
        o->count++;
    }
    //np->next=o->rear;
    o->rear->next=np;
    0->rear=np;
    o->count++;
    return 0;
}

int deleteOrder(Orders *o){
    if(isOrdersEmpty(&o)){
        return 0;
    }

    QueueNode *np;
    np=(QueueNode*)malloc(sizeof(QueueNode));
    np=o->front;
    o->front=o->front->next;
    free(np);
}

int completeOrder(Orders *o,Games *g){
    ListNode *np;
    np=(ListNode*)malloc(sizeof(ListNode));
    np=Games->head;


}
