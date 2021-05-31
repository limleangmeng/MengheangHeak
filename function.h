/*
    [plist] --> [data][*next]-->[data][*next]--> ....-->[data_n][NULL]

    plist as head
    p as pointer [ for traverse all list (like temp)]

    !NOTE! =======================================================
    || Declare more variable if you need, but do not modify any ||
    || exist varialbe such as NAME or DATA TYPE.                ||
    ||============================================================

    !Function Owner! ==============================================
    || Do not make change to other function not belong to you if ||
    || NO PERMISSION from owner or team                          ||
    ||=============================================================

*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *next;
};

struct node *plist, *p;

//function list============================
int count(struct node *plist);
void traverse(struct node *plist);
void deleteAtFirst(struct node *plist);
void deleteAtEnd(struct node *plist);
int count(struct node *plist);
//=========================================

//Mengheang
void traverse(struct node *plist)
{
    p = plist;
    if (p == NULL)
    {
        printf("List is Empty!");
    }
    else
    {
        while (p != NULL)
        {
            printf("%c\t", p->data);
            p = p->next;
        }
    }
}

void deleteAtFirst(struct node *plist)
{
    p = plist;
    plist = plist->next;
    free(p);
}

void deleteAtEnd(struct node *plist)
{
    p = plist;
    while (p->next != 0)
    {
        p = p->next;
    }
    free(p);
    int c = count(plist);
    p = plist;
    for (int i = 1; i < c - 1; i++){ p = p->next; }     
    p->next = NULL;
}

void deleteAfterPos(struct node *plist, int pos){
    struct node *p1;
    int c=count(plist);
    if(pos>c){
        printf("invalid position!");
    }else{
        p=plist;
        for(int i = 1; i <= c; i++){ p = p->next; }
        p1=p->next;
        p->next = p1->next;
        free(p1);
    }
}

//leangmeng
int count(struct node *plist)
{
    int count = 1;
    p = plist;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

//SengKhim
void initlink(struct node *plist)
{
    plist = NULL;
}