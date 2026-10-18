/*
 * File: Question21.c
 * Author: Anas Abdulla
 * Date: 2026-05-17
 * Description:
 * 
 * 21. Extract Upper and Lower Nibble
    Task
        Extract upper and lower nibble.
    Learn
        Nibble operations
        Masking
    Concepts
        0x0F
        0xF0
    Example
        AB -> A and B
    Level
        ⭐ Beginner
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void extract_nibbles(int number)
{
    if (number < 256)
    {
        int upper_nibble = 0, lower_nibble = 0;
        upper_nibble = ((number & 0xf0)>>4);
        lower_nibble = (number & 0x0f);

        printf("Upper nibble is %x and lower nibble is %x \n",upper_nibble , lower_nibble);
    }
    else
    {
        int nibble = 0;
        int mask = 0x0f;

        for (int i = 7; i>=0 ;i--)
        {
            nibble = (number & (mask << (i*4)))>>(i*4);
            printf("Nibble is %x ", nibble);
            nibble = 0;

        }
    }
}

int main(void)
{
    int number = 0xab;
    extract_nibbles(number);
    extract_nibbles(0xABCD);
    
    return 0;
}