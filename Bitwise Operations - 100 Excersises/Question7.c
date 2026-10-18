/*
 * File: Question7.c
 * Author: Anas Abdulla
 * Date: 2026-05-16
 * Description:
 * 
 * 7. Bit Masking
        Task
            Explain bit masking techniques.
        Learn
            SET bit
            CLEAR bit
            TOGGLE bit
            CHECK bit
        Concepts
            |&^
        Example
            n | (1 << k)
        Level
            ⭐ Beginner
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void print_binary_groups(int x)
{
    printf("grouped output - ");
    if(x == 0)
    {
        /// Add the logic for 0 in the starting . this will avoid the problem with 0 in below logic and if we add it in starting , it will block creating new variable as well 
        printf("0");
        return;
    }

    int print = 0;
    for (int i = 31; i>=0 ;i--)
    {
        /// Right shifting x by i so that we will get the MSB first and from there .. then checking each bits and priting
        if ((x>>i)&1)
        {
            /// we have a flag which will set only in the set bit .. will not clear .. so we can avoid leading 0 bits from MSB
            print = 1;
        }
        if (print)
        {
            printf("%d ", (x>>i)&1);
        }
        
    }
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

void setbit (int *x , int num)
{
    if (num >31 || num <0)
    {
        printf("Not possible to set");
        return;
    }

    *x = (*x | (1 << num));

}

void clearbit (int*x , int num)
{
    if (num >31 || num <0)
    {
        printf("Not possible to clear");
        return;
    }

    *x = (*x & ~(1 << num));
}

void togglebit(int *x , int num)
{
    if (num >31 || num <0)
    {
        printf("Not possible to Toggle");
        return;
    }

    *x = *x ^ (1<<num);
}

void checkbit(int x , int num)
{
    if (num >31 || num <0)
    {
        printf("Not possible to check");
        return;
    }

    if (x & (1<<num))
    {
        printf ("bit %d is set - 1\n",num);
    }
    else 
    {
        printf ("bit %d is not set - 0\n",num);
    }
}

int main(void)
{
    int x = 353 ; 

    printf ("\n********* Normal printing ********\n");
    print_binary_groups(x);
    print_binary_fourbits(x);

    printf ("\n********* Setting bit ********\n");
    setbit(&x,2);

    print_binary_groups(x);
    print_binary_fourbits(x);

    printf ("\n********* Clearing bit ********\n");
    clearbit(&x,2);
    clearbit(&x,5);

    print_binary_groups(x);
    print_binary_fourbits(x);

    printf ("\n********* Toggling bit ********\n");
    togglebit(&x,6);
    togglebit(&x,1);

    print_binary_groups(x);
    print_binary_fourbits(x);

    printf ("\n********* Check bit ********\n");
    checkbit(x , 2);
    checkbit(x , 8);
    return 0;
}