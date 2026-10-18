/*
 * File: Question14.c
 * Author: Anas Abdulla
 * Date: 2026-05-17
 * Description:
 * 14. Multiply Using Left Shift
    Task
        Multiply using left shift.
    Learn
        Left shifting
        Bit movement
    Concepts
        n<<k
        •
        •
        •
        •
        9
    Example
        5 << 2 = 20
 * 
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void multiplication(int x , int y)
{
    int number_of_bits = 0;
    while (y)
    {
        y = y>>1;
        number_of_bits++;

    }
    int result = x << (number_of_bits - 1);

    printf("%d is the result\n", result);
}

int main(void)
{
    multiplication(6,2);
    multiplication(6,8);

    multiplication(5,4);
    multiplication(6,16);
    
    return 0;
}