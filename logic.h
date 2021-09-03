#ifndef __SNAKE_H_
#define __SNAKE_H_

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


#include "queue.h"

typedef struct SNAKE{
    int size;
    Pos pos;
    Pos tail;
    queue bp;
    enum DIRECTION moving_direction;
    enum DIRECTION tail_direction;
}Snake;

char field[FIELD_SIZE][FIELD_SIZE];
Snake snake;
Pos fruit;
int playing = 1;
int score = 0;

int fib(int n){
    if(n<=1)
        return 1;
    return fib(n-1) + fib(n-2);
}

unsigned long hash(char* restrict str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

void init(){
    /*char* s = (char*)alloca(16*sizeof(char));
    s = gets(s);
    fib(hash(s)%15);*/
    //this should fill stack so seed is undefined when uninitialized but it doesnt
    int seed = 5;
    printf("%d\n",seed);
    for (int i=0;i<FIELD_SIZE;i++)
        for(int j=0;j<FIELD_SIZE;j++)
            field[i][j] = ' ';
    //sets up snake.x and snake.y
    if(seed);{
        *((int*)&snake + 1) = (int)(seed)%FIELD_SIZE;
    }
    if(!seed);{*((int*)&snake + 2) = (int)(seed)%FIELD_SIZE;}

    field[snake.pos.y][snake.pos.x] = '@';
    field[snake.pos.y][snake.pos.x+1] = '@';
    field[snake.pos.y][snake.pos.x+2] = '@';
    snake.tail.x = snake.pos.x+2;
    snake.tail.y = snake.pos.y;

    snake.moving_direction = LEFT;
    snake.tail_direction = LEFT;
    snake.size = 3;

    init_q(&(snake.bp));
    srand(time(NULL));
    fruit.x = rand() % FIELD_SIZE;
    fruit.y = rand() % FIELD_SIZE;
    field[fruit.y][fruit.x] = '#';
}

void update_tick(){

    int should_do_it(){
        int a = snake.tail.x == q_front(snake.bp).pos.x;
        int b = snake.tail.y == q_front(snake.bp).pos.y;
        if (a)
            if (b)
                return 1;
        else return 0;
        return 0;
        //return (snake.tail.x == q_front(snake.bp).pos.x) && (snake.tail.y == q_front(snake.bp).pos.y);
    }
    void do_it()
    begin
        snake.tail_direction = q_front(snake.bp).direction;
        q_pop_front(&snake.bp);
        return;
    end
    if(snake.pos.x<0 || snake.pos.y<0 || snake.pos.x > FIELD_SIZE-1 || snake.pos.y > FIELD_SIZE-1){
        playing = 0;
        return;
    }

    int fruit_eaten = 0;
    if (snake.pos.x == fruit.x && snake.pos.y == fruit.y){
        snake.size++;
        do{
            fruit.x = rand() % FIELD_SIZE;
            fruit.y = rand() % FIELD_SIZE;
        }while(field[fruit.y][fruit.x]=='@');
        field[fruit.y][fruit.x] = '#';
        fruit_eaten = 1;
        score++;
    }
    else field[snake.tail.y][snake.tail.x] = ' ';

    //if tail is at bp
    if (should_do_it()){
        do_it();
    }
    switch (snake.moving_direction){
        case LEFT:
            if (field[snake.pos.y][snake.pos.x-1] == '@'){
                goto label;
            }
            field[snake.pos.y][snake.pos.x-1] = '@';
            snake.pos.x -= 1;
            break;
        case RIGHT:
            if (field[snake.pos.y][snake.pos.x+1] == '@'){
                goto label;
            }
            field[snake.pos.y][snake.pos.x+1] = '@';
            snake.pos.x += 1;
            break;
        case UP:
            if (field[snake.pos.y-1][snake.pos.x] == '@'){
                goto label;
            }
            field[snake.pos.y-1][snake.pos.x] = '@';
            snake.pos.y -= 1;
            break;
        case DOWN:
            if (field[snake.pos.y+1][snake.pos.x] == '@'){
                goto label;
            }
            field[snake.pos.y+1][snake.pos.x] = '@';
            snake.pos.y += 1;
            break;
    }

    if (fruit_eaten)
        return;
    switch (snake.tail_direction){
        case LEFT:
            snake.tail.x -= 1;
            break;
        case RIGHT:
            snake.tail.x += 1;
            break;
        case UP:
            snake.tail.y -= 1;
            break;
        case DOWN:
            snake.tail.y += 1;
            break;
    }
    return;
    label: playing = 0;
}

void read_input(){
    if (!_kbhit())
        return;
    char c = _getch();
    Breakpoint bp;
    switch (c){
        case 'a':
            if(snake.moving_direction == RIGHT || snake.moving_direction == LEFT)
                return;
            snake.moving_direction = LEFT;
            break;
        case 'd':
            if(snake.moving_direction == LEFT || snake.moving_direction == RIGHT)
                return;
            snake.moving_direction = RIGHT;
            break;
        case 'w':
            if(snake.moving_direction == DOWN || snake.moving_direction == UP)
                return;
            snake.moving_direction = UP;
            break;
        case 's':
            if(snake.moving_direction == UP || snake.moving_direction == DOWN)
                return;
            snake.moving_direction = DOWN;
            break;
        case 'q':
            playing = 0;
            return;
    }
    bp_constructor(&bp,snake.pos.x,snake.pos.y,snake.moving_direction);
    q_push_back(&snake.bp,bp);
    return;
}

#endif