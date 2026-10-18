/*
 * File: Question12.c
 * Author: Anas Abdulla
 * Date: 2026-05-16
 * Description:
 * 
 * 12. Count Total Bits Required
    Task
        Count total bits needed for a number.
    Learn
        Binary length
        Right shifting
    Concepts
        n>>1
    Example
        19 -> 5 bits
    Level
    ⭐ Beginner
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void count_bits_needed (int number)
{
    int count = 0;
    while (number)
    {
        number = number >> 1 ;
        count ++;
    }

    printf("Number of bits needed is %d ",count);
}

int main(void)
{
    int x = 365;
    count_bits_needed(x);
    
    return 0;
}