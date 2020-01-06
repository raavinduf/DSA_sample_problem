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

    if(g->count==0){
        g->head=np;
        g->data=np;
    }
    g->data->next=np;
    g->data=np;
    g->count++;

}

void traverseGames(Games *g){
    ListNode *np;
    np=(ListNode*)malloc(sizeof(ListNode));
    np=g->head;
    printf("Hello %d",g->count);
    //printf("%s %d",g->data->Name,g->data->copies);
    //int i=0;
    //printf("name of the game=%s no of copies=%d",np->Name,np->copies);
    while(i<g->count){
        printf("\n name of the game=%s\t number of copies=%d",np->Name,np->copies);
        np=np->next;
        i++;
    }
}

int insertGameCopies(Games *g,char Name [],int copies){
    int y=0;
    ListNode *np;
    np=(ListNode*)malloc(sizeof(ListNode));
    np=g->head;
    for(i=0;i<g->count;i++){
        if(strcmp(np->Name,Name)==0){
            np->copies=np->copies+copies;
            y=1;
        }
        np=np->next;
    }
    i=0;
    if(y){
        return 0;
    }
    else{
        insertGame(g,Name,copies);
        return 0;
    }
}


typedef struct queuenode{
    char CustomerName[20];
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

int insertOrder(Orders *o,char Customer_name[],char Ordered_game[] ){
    QueueNode *np;
    np=(QueueNode*)malloc(sizeof(QueueNode));
    strcpy(np->CustomerName,Customer_name);
    strcpy(np->OrderedGame,Ordered_game);
    if(isOrdersEmpty(o)){
        o->rear=np;
        o->front=np;
        o->count++;
    }
    //np->next=o->rear;
    o->rear->next=np;
    o->rear=np;
    o->count++;
    return 0;
}



typedef struct stacknode{
    char game [20];
    char customer [20];
    struct stacknode *next;
}StackNode;

typedef struct SoldGames{
    StackNode *top;
    int no_of_sold_games;
}SGames;

int createSoldGamesStack(SGames *s){
    s->top=NULL;
    s->no_of_sold_games=0;
    return 0;
}

int isSoldGamesEmpty(SGames *s){
    if(s->top==NULL){
        return 1;
    }
    return 0;
}

int pushSGames(SGames *s,char g [20],char customer [20]){
    StackNode *np;
    np=(StackNode*)malloc(sizeof(StackNode));
    strcpy(np->customer,customer);
    strcpy(np->game,g);
    np->next=s->top;
    s->top=np;
    s->no_of_sold_games++;
    return 0;
}


int orderComplete(SGames *s,Orders *o){
    if(isSoldGamesEmpty(s)){
        createSoldGamesStack(s);
    }
    pushSGames(s,o->front->OrderedGame,o->front->CustomerName);

}

int main(){
    Games g; Orders o; SGames s;
    instializeGames(&g);
    insertGame(&g,"hi",20);
    insertGame(&g,"hello",13);
    insertGame(&g,"Forza",15);
    traverseGames(&g);
    insertGameCopies(&g,"hello",10);
    traverseGames(&g);
    createOrders(&o);
    insertOrder(&o,"Ravindu","Forza");

}

