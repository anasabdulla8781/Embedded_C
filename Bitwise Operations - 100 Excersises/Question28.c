/*
 * File: Question28.c
 * Author: Anas Abdulla
 * Date: 2026-05-17
 * Description:
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void count_zero_bits(int x)
{
    int counter = 0;
    int temp = ~x;
    while (temp)
    {
        counter++;
        temp = temp & (temp-1);
    }
    printf("The number %d has %d zero bits\n",x,counter);
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
    count_zero_bits(634);
    print_binary_fourbits(634);
    
    return 0;
}