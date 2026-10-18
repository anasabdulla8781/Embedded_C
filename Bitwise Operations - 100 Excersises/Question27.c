/*
 * File: Question27.c
 * Author: Anas Abdulla
 * Date: 2026-05-17
 * Description:
 * 27. Brian Kernighan Algorithm
    Task
        Count set bits efficiently.
    Learn
        Optimized bit counting
    Concepts
        n=n&(n-1)
    Example
        Remove last set bit
    Level
    ⭐ Intermediate
 * 
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


void count_set_bits(int x)
{
    int counter = 0;
    int temp = x;
    while (x)
    {
        counter++;
        x = x & (x-1);
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
    count_set_bits(634);
    print_binary_fourbits(634);
    
    return 0;
}