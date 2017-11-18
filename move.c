#include <stdio.h>
#include <stdlib.h>
#include "move.h"
#include "main.h"

//输入玩家2的位置，数组形式
//所有位置的棋子状态，LO结构体数组形式
int* movechess(int* data,LO* lo)
{
    int* data_final = NULL;
    data_final = (int*)malloc(2 * sizeof(int));
    int data_route[2][2] = {0};
    int count = 0;
    int i = 0;

    for( i = 0; i < 2; i ++)
    {
        switch(data[i])
        {
            case 1:
               data_route[count][0] = data[i];
               if(lo[2].value == 0)
               {
                    data_route[count][1] = 2;
                    count ++;
               }
               else if(lo[3].value == 0)
               {
                    data_route[count][1] = 3;
                    count ++;
               }
               else if(lo[4].value == 0)
               {
                    data_route[count][1] = 4;
                    count ++;
               }
               break;
            case 2:
               data_route[count][0] = data[i];
               if(lo[1].value == 0)
               {
                    data_route[count][1] = 1;
                    count ++;
               }
               else if(lo[3].value == 0)
               {
                    data_route[count][1] = 3;
                    count ++;
               }
               break;
            case 3:
               data_route[count][0] = data[i];
               if(lo[1].value == 0)
               {
                    data_route[count][1] = 1;
                    count ++;
               }
               else if(lo[2].value == 0)
               {
                    data_route[count][1] = 2;
                    count ++;
               }
               else if(lo[4].value == 0)
               {
                    data_route[count][1] = 4;
                    count ++;
               }
               else if(lo[5].value == 0)
               {
                    data_route[count][1] = 5;
                    count ++;
               }
               break;
            case 4:
               data_route[count][0] = data[i];
               if(lo[1].value == 0)
               {
                    data_route[count][1] = 1;
                    count ++;
               }
               else if(lo[3].value == 0)
               {
                    data_route[count][1] = 3;
                    count ++;
               }
               else if(lo[5].value == 0)
               {
                    data_route[count][1] = 5;
                    count ++;
               }
               break;
            case 5:
               data_route[count][0] = data[i];
               if(lo[3].value == 0)
               {
                    data_route[count][1] = 3;
                    count ++;
               }
               else if(lo[4].value == 0)
               {
                    data_route[count][1] = 4;
                    count ++;
               }
               break;
        }
    }
    if(count == 2)
    {
        if(data_route[0][0] == 2 || data_route[0][0] == 5)
        {
            data_final[0] = data_route[0][0];
            data_final[1] = data_route[0][1];
        }
        else if(data_route[1][0] == 2 || data_route[1][0] == 5)
        {
            data_final[0] = data_route[1][0];
            data_final[1] = data_route[1][1];
        }
        else
        {
            data_final[0] = data_route[0][0];
            data_final[1] = data_route[0][1];
        }
    }
    else
    {
        data_final[0] = data_route[0][0];
        data_final[1] = data_route[0][1];
    }
    return data_final;
}
