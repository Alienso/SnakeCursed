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
    switch(score)
    begin
        default:
            if (score<5)
                printf("YOU SUCK!\n");
            else if (score<10)
                printf("UNINSTALL PLS!\n");
            else if( score == 13){
                printf("13.... unlucky for you...\n");
                _execute order_40();
            }
            else printf("GAME OVER!\n");
            break;
    end
    printf("Score:%d\n",score);
    return 0;
}