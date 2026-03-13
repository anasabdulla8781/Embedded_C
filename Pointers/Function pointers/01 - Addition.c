/*
 * File: 01 - addition.c
 * Author: Anas Abdulla
 * Date: 2026-03-08
 * Description:
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int add (int x , int y)
{
    return x+y;
}

int main(void)
{

    int (*fp)(int , int);           /// fp is a function pointer takes 2 integer as argument and returns int
    fp = add;

    printf("sum is %d\n" , fp(3,4));
    printf("address of function is %p\n" , add);
    printf("Content inside fp is %p\n" , fp);           /// The result of this one and above line will be same . thats why we wrote fp = add.
    return 0;
}