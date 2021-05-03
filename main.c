#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"../c/main.h"
int menu(Node** start)
{
    int op;
    do{
    printf("\nEnter your option :\t1.Display\t2.Insert\t3.Delete\t4.Search\t55.Exit the project\nOption:");
    scanf("%d",&op);
    switch(op)
    {
        case 1:
            display(*start);
            break;
        case 2:
            *start=insert(*start);
            break;
        case 3:
            *start=delete(*start);
            break;
        case 4:
            search(*start);
            break;
    }
    }while(op!=55);
    return op;
}