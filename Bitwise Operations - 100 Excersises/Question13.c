/*
 * File: Question13.c
 * Author: Anas Abdulla
 * Date: 2026-05-17
 * Description:
 * 13. Check Even or Odd
    Task
        Check EVEN or ODD using bitwise operator.
    Learn
        LSB concept
        Odd/even property
    Concepts
        n&1
    Example
        7 -> ODD
    Level
        ⭐ Beginner
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void check_even_or_odd(int x)
{
    if (x & 1)
    {
        printf("%d is Odd number\n",x);
    }
    else
    {
        printf("%d is even number\n",x);
    }
}

int main(void)
{
    
    check_even_or_odd(353);
    check_even_or_odd(360);
    check_even_or_odd(-360);
    return 0;
}