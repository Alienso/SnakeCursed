#ifndef __RENDER__H
#define __RENDER__H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define FIELD_SIZE 13

void setCursorPosition(int x, int y)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    fflush(stdout);
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}

void setConsoleColour(unsigned short colour)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    fflush(stdout);
    SetConsoleTextAttribute(hOut, colour);
}

void render(){
    setCursorPosition(0,0);
    setConsoleColour(128);

    printf("%d\n",score);
    //TOP WRAP
    for(int i=0;i<FIELD_SIZE;i++)
        putc('-',stdout);
    printf("\n");
    //MAIN FIELD
    for(int i=0;i<FIELD_SIZE;i++){
        for(int j=0;j<FIELD_SIZE;j++){
            if (j==0)
                putc('|',stdout);
            if(field[i][j]=='@'){
                setConsoleColour(16);
                putc(' ',stdout);
                setConsoleColour(128);
            }
            else if(field[i][j]=='#'){
                setConsoleColour(32);
                putc(' ',stdout);
                setConsoleColour(128);
            }
            else printf("%c",field[i][j]);
            if (j==FIELD_SIZE-1)
                putc('|',stdout);
        }
        printf("\n");
    }
    //BOT WRAP
    for(int i=0;i<FIELD_SIZE;i++)
        putc('-',stdout);
    printf("\n");
}


#endif