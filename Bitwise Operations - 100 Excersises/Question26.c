/*
 * File: Question26.c
 * Author: Anas Abdulla
 * Date: 2026-05-17
 * Description:
 * 
 * 26. Count SET Bits
    Task
        Count total set bits.
    Learn
        Bit counting
    Concepts
        n&1
    Example
        13 -> 3
    Level
        ⭐ Beginner

 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void count_setbits(int x)
{
    int counter = 0;
    int temp = x;
    while (x)
    {
        if (x & 0x01)
        {
            counter++;
        }
        x = x>>1;
    }
    printf("The number %d has %d set bits\n",temp,counter);
}

void print_binary_fourbits(int x)
{
    printf("\nfour bit output - ");
    for (int i = 31; i>= 0; i--)
    {
        printf("%d" , ((x >> i)&1));
        if(i % 4 == 0)
        {
            printf (" ");
        }
    }
}

int main(void)
{
    count_setbits(634);
    print_binary_fourbits(634);
    
    return 0;
}