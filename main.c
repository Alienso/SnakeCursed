#include <stdio.h>
#include <stdlib.h>

#include "logic.h"
#include "render.h"

int main(){
    init();
	printf("\e[1;1H\e[2J");
    printf("\e[?25l");
    while(playing){
        read_input();
        update_tick();
        render();
        Sleep(200);
    }
    printf("\e[1;1H\e[2J");
    printf("GAME OVER!\n");
    printf("Score:%d\n",score);
    return 0;
}