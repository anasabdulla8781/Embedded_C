/*
 * File: Question25.c
 * Author: Anas Abdulla
 * Date: 2026-05-17
 * Description:
 * 25. Toggle All Bits
    Task
        Toggle all bits of number.
    Learn
        Complement operation
    Concepts
        ~n
    Example
        ~5 = -6
    Level
        ⭐ Beginner
 * 
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void toggle_bits(int x , int*y)
{
    for (int i = 31 ; i>=0 ; i--)
    {
        if (((x ^ (1<<i))>> i) & 0x01)
        {
            *y |= (1<<i);
        }
        else
        {
            *y &= ~(1<<i);
        }
    }
}

void print_binary_fourbits(int x)
{
    printf("\nfour bit output -");
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
    int number = 363;
    int toggled_number = 0;
    print_binary_fourbits(number);

    toggle_bits(number , &toggled_number);

    print_binary_fourbits(toggled_number);
    
    return 0;
}