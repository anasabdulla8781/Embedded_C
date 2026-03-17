/*
 * File: 02 - Common function pointer for all the operations.c
 * Author: Anas Abdulla
 * Date: 2026-03-08
 * Description:
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int add (int x , int y)
{
    return x+y;
}

int sub (int x , int y)
{
    return x-y;
}

int mul (int x , int y)
{
    return x*y;
}

int main(void)
{
    int (*fp)(int , int );

    /// Addition
    fp = add;
    printf ("sum is %d\n", fp(3,4));

    /// Substraction
    fp = sub;
    printf ("sub is %d\n", fp(3,4));

    /// Multiplicaiton
    fp = mul;
    printf ("mul is %d\n", fp(3,4));
    return 0;
}