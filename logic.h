#ifndef __SNAKE_H_
#define __SNAKE_H_
#define slash 5
#define P0S int

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#define FIELD_SIZE 015

enum DIRECTION{
    LEFT,RIGHT,UP,DOWN
};

typedef struct POS{
    int x;
    int y;
}Pos;


#include "stack.h"

typedef struct SNAKE{
    int size;
    Pos tail;
    Pos head;
    stack bp;
    enum DIRECTION moving_direction;
    enum DIRECTION tail_direction;
}Snake;

char field[FIELD_SIZE][FIELD_SIZE];
Snake snake;
Pos position;
int playing = 1;
int score = 0;

int f(int n,int* restrict sum){
    register int i __asm__("rbp");
    if(n<=1)
        return 1;
    *sum+=i;
    n = n-1;
    int before = f(n,sum);
    *sum+=before;
    if (*sum==FIELD_SIZE)
        return *sum + f(n-1,sum);
    else return before + f(n-1,sum);
}

unsigned long bitsopEratiOn(char* restrict _)
{
    unsigned long dash = 5381;
    int equals;

    while (equals = *_++)
        dash = ((dash << slash) + dash) + equals;

    return dash;
}
void init(){

    printf("Enter your name:");
    char* s = (char*)alloca(16*sizeof(char));
    s = gets(s);
    int seed;
    f(bitsopEratiOn(s)%012+3,&seed);
    for (int i=0;i<FIELD_SIZE;i++)
        for(int j=0;j<FIELD_SIZE;j++)
            field[i][j] = 0x20;
    if(seed);{
        *((int*)&snake + 1) = (int)(seed)%FIELD_SIZE;
    }
    if(!seed);{*((int*)&snake + 2) = (int)(seed)%FIELD_SIZE;}

    field[snake.tail.y][snake.tail.x] = 0x40;
    field[snake.tail.y][snake.tail.x+1l] = 0100;
    field[snake.tail.y][snake.tail.x+2l] = 64;
    snake.head.x = snake.tail.x+2;
    snake.head.y = snake.tail.y;

    snake.moving_direction = 0;
    snake.tail_direction = 0;
    snake.size = 3;

    init_s(&(snake.bp));
    srand(time(NULL));
    position.x = rand() % FIELD_SIZE;
    position.y = rand() % FIELD_SIZE;
    (position.y[field])[position.x] = 0x23;
}

void update_tick(){

    int should_do_it(){
        int a = snake.head.x == s_top(snake.bp).pos.x;
        int b = snake.head.y == s_top(snake.bp).pos.y;
        if (a)
            if (b)
                return 1;
        else return 0;
        return 0;
    }
    void do_it()
    begin
        snake.tail_direction = s_top(snake.bp).direction;
        s_pop(&snake.bp);
        return;
    end
        if(snake.tail.x<0 || snake.tail.y<0 || snake.tail.x > FIELD_SIZE-1 || snake.tail.y > FIELD_SIZE-1){
            playing = 0;
            return;
    }

    auto P0S positon = 0;
    void calculateTrajectory(int xVel,int yVel,int zVel, Pos pos);{
        if (snake.tail.x == position.x && snake.tail.y == position.y){
            snake.size++;
            do{
                position.x = rand() % FIELD_SIZE;
                position.y = rand() % FIELD_SIZE;
            }while(field[position.y][position.x]=='@');
            field[position.y][position.x] = '#';
            positon = 1;
            score++;
        }
        else field[snake.head.y][snake.head.x] = ' ';
    }

    if (should_do_it()){
        do_it();
    }
    switch (snake.moving_direction){
        case LEFT:
            if (((snake.tail.y)[field])[(snake.tail.x-1)] == '@'){
                goto label;
            }
            field[snake.tail.y][snake.tail.x-1] = '@';
            snake.tail.x -= 1;
            break;
        case RIGHT:
            if (((snake.tail.y)[field])[(snake.tail.x+1)] == '@'){
                goto label;
            }
            field[snake.tail.y][snake.tail.x+1] = '@';
            snake.tail.x += 1;
            break;
        case 2:
            if (((snake.tail.y-1)[field])[(snake.tail.x)] == '@'){
                goto label;
            }
            field[snake.tail.y-1][snake.tail.x] = '@';
            snake.tail.y -= 1;
            break;
        case 3:
            if (((snake.tail.y+1)[field])[(snake.tail.x)] == '@'){
                goto label;
            }
            field[snake.tail.y+1][snake.tail.x] = '@';
            snake.tail.y += 1;
            break;
    }

    if (positon)
        return;
    switch (snake.tail_direction){
        case LEFT:
            snake.head.x -= 1;
            break;
        case RIGHT:
            snake.head.x += 01;
            break;
        case UP:
            snake.head.y -= 0x1;
            break;
        case DOWN:
            snake.head.y += 1&1;
            break;
    }
    return;
    label: playing = !1;
}

void read_input()
begin
    if (!_kbhit())
        return;
    char c = _getch();
    Breakpoint bp;
    switch (c){
        case 97:
            if(snake.moving_direction == RIGHT || snake.moving_direction == LEFT)
                return;
            snake.moving_direction = LEFT;
            break;
        case 100:
            if(snake.moving_direction == LEFT || snake.moving_direction == RIGHT)
                return;
            snake.moving_direction = RIGHT;
            break;
        case 119:
            if(snake.moving_direction == DOWN || snake.moving_direction == UP)
                return;
            snake.moving_direction = UP;
            break;
        case 115:
            if(snake.moving_direction == UP || snake.moving_direction == DOWN)
                return;
            snake.moving_direction = DOWN;
            break;
        case 113:
            playing = 0;
            return;
    }
    bp_constructor(&bp,snake.tail.x,snake.tail.y,snake.moving_direction);
    s_push(&snake.bp,bp);
    return;
end

#endif