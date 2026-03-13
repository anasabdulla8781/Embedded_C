/*
 * File: 04 - Array of function pointers.c
 * Author: Anas Abdulla
 * Date: 2026-03-11
 * Description: Create the array of function pointers for 2 functions and call them 
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void function_1 (int x)
{
    printf(" Called through function 1 and number is %d\n",x);
}

void function_2 (int x)
{
    printf("Printed througnh function 2");
}

int main(void)
{

    void (*fp[2])(int);

    fp[0] = function_1;
    fp[1] = function_2;

    fp[0](5);
    fp[1](0);
    
    return 0;
}