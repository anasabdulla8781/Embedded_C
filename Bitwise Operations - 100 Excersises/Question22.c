/*
 * File: Question22.c
 * Author: Anas Abdulla
 * Date: 2026-05-17
 * Description:
 * 22. Swap Using XOR
    Task
        Swap two numbers without temp variable.
    Learn
        XOR swapping
        Concepts
        ^operator
        •
        •
        •
        14
    Example
        a=5 b=3
    Level
        ⭐ Beginner
 * 
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void swap_numbers(int* a , int*b)
{
    *b = (*b ^ *a);             
    *a = (*b ^ *a);             
    *b = (*b ^ *a);
}

int main(void)
{
    int a = 25;
    int b = 36;

    swap_numbers (&a , &b);

    printf("a is %d\n",a);
    printf("b is %d\n",b);
    
    return 0;
}