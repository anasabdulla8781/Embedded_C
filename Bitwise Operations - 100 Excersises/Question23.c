/*
 * File: Question23.c
 * Author: Anas Abdulla
 * Date: 2026-05-17
 * Description:
 * 23. Check Equality Using XOR
    Task
        Check equality using XOR.
    Learn
        XOR cancellation
    Concepts
        a^b
    Example
        5 ^ 5 = 0
    Level
        ⭐ Beginner
 * 
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void check_equality (int x , int y)
{
    if (x ^ y)
    {
        printf("%d and %d are not equal\n",x,y);
    }
    else
    {
        printf("%d and %d are equal\n",x,y);
    }
}

int main(void)
{

    check_equality(65,36);
    check_equality(65,65);

    return 0;
}