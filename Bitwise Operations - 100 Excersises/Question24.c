/*
 * File: Question24.c
 * Author: Anas Abdulla
 * Date: 2026-05-17
 * Description:
 * 24. Check Positive or Negative
    Task
        Check sign using bits.
    Learn
        Sign bit
        MSB
    Concepts
        n>>31
    Example
        -5 -> negative
    Level
        ⭐ Beginner
 * 
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void checksign(int x)
{
    if (x & (1<<31))
    {
        printf("%d is a negative number\n",x);
    }
    else
    {
        printf("%d is a positive number\n",x);
    }
}

int main(void)
{
    checksign(-36);
    checksign(9);
    
    return 0;
}