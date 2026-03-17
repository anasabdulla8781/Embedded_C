/*
 * File: 08 - Function pointer as argument without typedef.c
 * Author: Anas Abdulla
 * Date: 2026-03-14
 * Description:
 * We will have 2 functions , add and multiply ..we will have another function . and we will pass numbers and function pointer to this function
 * so that the calculate function will do what needed 
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


int add (int x , int y)
{
    return (x+y);
}

int multiply (int x , int y)
{
    return (x*y);
}

void calculate (int x , int y ,  int(*fp)(int, int))
{
    printf("The calculated value is %d\n", fp(x,y));
}

int main(void)
{
    calculate (5,8, add);
    calculate (5,8,multiply);
    return 0;
}