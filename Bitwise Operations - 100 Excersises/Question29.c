/*
 * File: Question29.c
 * Author: Anas Abdulla
 * Date: 2026-05-17
 * Description:
 * 29. Check Power of 2
    Task
        Check whether number is power of 2.
    Learn
        Single set bit logic
    Concepts
        n&(n-1)
    Example
        16 -> YES
    Level
        ⭐ Intermediate
 * 
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void check_power_of_2 (int x)
{
    if (x > 0 && ((x & (x - 1)) == 0))
    {
        printf("%d is power 2\n",x);
    }
    else
    {
        printf("%d is not power of 2\n",x);
    }
}

int main(void)
{
    check_power_of_2(670);
    check_power_of_2(671);
    check_power_of_2(673);
    check_power_of_2(672);
    check_power_of_2(32);
    return 0;
}