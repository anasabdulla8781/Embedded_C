/*
 * File: Question30.c
 * Author: Anas Abdulla
 * Date: 2026-05-17
 * Description:
 * 30. Check Power of 4
    Task
        Check whether number is power of 4.
    Learn
        Position checking
    Concepts
        bitmasks
    Example
        64 -> YES
    Level
        ⭐ Intermediate
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void check_power_of_4 (int x)
{
    if (x > 0 && ((x & (x - 1)) == 0)&& (x&(0x55555555)))
    {
        printf("%d is power 4\n",x);
    }
    else
    {
        printf("%d is not power of 4\n",x);
    }
}

int main(void)
{
    check_power_of_4(670);
    check_power_of_4(671);
    check_power_of_4(673);
    check_power_of_4(672);
    check_power_of_4(32);
    check_power_of_4(16);
    return 0;
}
