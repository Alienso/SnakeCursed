#ifndef __QUEUEUE__H
#define __QUEUEUE__H

#include <stdlib.h>
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
    return q.data[q.start];
}

Breakpoint q_pop_front(queue* q){
    q->top++;
    q->size--;
    return q->data[q->top-1];
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
#undef MAX_SIZE
#endif