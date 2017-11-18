#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "move.h"

#define SIZE 15

char codes[3] = {'*','@','#'};
char codes_init[6] = {'0','1','2','3','4','5'};
int location_now = 0,location_next = 0;
int winer;
int user2[2] = {0};
LO lo[6];

void init(void);
void printbg(char l1,char l2,char l3,char l4,char l5);
void move(int gamer);
int check_ok(int value);
int check_success(void);

int main(int argc, const char *argv[])
{
    unsigned long int count = 0;
    init();
    while(1)
    {
        move(count % 2 + 1);
        winer = check_success();
        switch(winer)
        {
            case 0:
                break;
            case 1:
                printf("You win!\r\n");
                return 0;
            case 2:
                printf("You default!\r\n");
                return 0;
        }
        count ++;
    }
    return 0;
}

int check_success(void)
{

    if(lo[1].value == 2 && lo[2].value == 2 && lo[3].value == 1 && lo[4].value == 1)
    {
        return 1;
    }
    if(lo[4].value == 2 && lo[5].value == 2 && lo[3].value == 1 && lo[1].value == 1)
    {
        return 1;
    }
    if(lo[1].value == 1 && lo[2].value == 1 && lo[3].value == 2 && lo[4].value == 2)
    {
        return 2;
    }
    if(lo[4].value == 1 && lo[5].value == 1 && lo[3].value == 2 && lo[1].value == 2)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
int check_ok(int value)
{
    if(value == lo[location_now].value)
    {
        switch(location_now)
        {
            case 1:
                if(location_next == 2 || location_next == 3 || location_next == 4)
                {
                    if(lo[location_next].value == 0)
                    {
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    return 0;
                }
            case 2:
                if(location_next == 1 || location_next == 3)
                {
                    if(lo[location_next].value == 0)
                    {
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    return 0;
                }
            case 3:
                if(location_next == 1 || location_next == 2 || location_next == 4 || location_next == 5)
                {
                    if(lo[location_next].value == 0)
                    {
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    return 0;
                }
            case 4:
                if(location_next == 1 || location_next == 3 || location_next == 5)
                {
                    if(lo[location_next].value == 0)
                    {
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    return 0;
                }
            case 5:
                if(location_next == 3 || location_next == 4)
                {
                    if(lo[location_next].value == 0)
                    {
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    return 0;
                }
        }
    }
    else
    {
        return 0;
    }
}
void move(int gamer)
{
    int* chessroute;

    if(gamer == 1)
    {
        printf("Gamer%d Please enter two number by \" \":\r\n",gamer);
        scanf("%d %d",&location_now,&location_next);
        if(!((location_now > 0 && location_now < 6) && (location_next > 0 && location_next < 6)))
        {
            printf("You have entered a wrong number! Please enter again!\r\n ");
            move(gamer);
        }
    }
    else if(gamer == 2)
    {
        chessroute = movechess(user2,lo);
        printf("data from move.c:%d\t%d\r\n",chessroute[0],chessroute[1]);
        if(chessroute[0] == user2[0])
        {
            user2[0] = chessroute[1];
        }
        else if(chessroute[0] == user2[1])
        {
            user2[1] = chessroute[1];
        }
        location_now = chessroute[0];
        location_next = chessroute[1];
    }
    if(check_ok(gamer) == 0)
    {
        printbg(codes[lo[1].value],codes[lo[2].value],codes[lo[3].value],codes[lo[4].value],codes[lo[5].value]);
        printf("Cant't move,please enter again!\r\n");
        move(gamer);
    }
    else
    {
        lo[location_now].value = 0;
        lo[location_next].value = gamer;
        printbg(codes[lo[1].value],codes[lo[2].value],codes[lo[3].value],codes[lo[4].value],codes[lo[5].value]);
    }
}
void init(void)
{
    char start;
    printbg(codes_init[1],codes_init[2],codes_init[3],codes_init[4],codes_init[5]);
    printf("Your chess will move from  the first number to the second number location!\r\n");
    printf("Can we start it?(y/n):\r\n");
    start = getchar();
    printf("%c\r\n",start);
    if(start == 'y' || start == 'Y')
    {
        lo[1].value = 1;
        lo[2].value = 2;
        lo[3].value = 0;
        lo[4].value = 2;
        lo[5].value = 1;
        user2[0] = 2;
        user2[1] = 4;
        printbg(codes[lo[1].value],codes[lo[2].value],codes[lo[3].value],codes[lo[4].value],codes[lo[5].value]);
    }
    else if (start == 'n' || start == 'N')
    {
        printf("Goodby!\r\n");
        exit(EXIT_SUCCESS);
    }
    else
    {
        exit(EXIT_SUCCESS);
    }
}
void printbg(char l1,char l2,char l3,char l4,char l5)
{
    system("clear");
    int i,j;
    for(i = 0; i < SIZE; i ++)
    {
        for(j = 0;j < SIZE; j ++)
        {
            if(i == 0 || j == 0 || j == SIZE - 1 || i == j || i == SIZE - 1 - j)
            {
                if(i == 0 && j == 0)
                {
                    printf("%c ",l1);
                }
                else if(j == 0 && i == SIZE - 1)
                {
                    printf("%c ",l2);
                }
                else if(j == (SIZE - 1) / 2 && i == (SIZE - 1) / 2)
                {
                    printf("%c ",l3);
                }
                else if(j == SIZE - 1 && i == 0)
                {
                    printf("%c ",l4);
                }
                else if (j == SIZE - 1 && i == SIZE - 1)
                {
                    printf("%c ",l5);
                }
                else
                {
                    printf("* ");
                }
            }
            else
            {
                printf("  ");
            }
        }
        printf("\r\n");
    }
}
