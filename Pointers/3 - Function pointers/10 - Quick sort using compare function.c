/*
 * File: 10 - Quick sort using compare function.c
 * Author: Anas Abdulla
 * Date: 2026-03-14
 * Description:
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int compare (const void*a , const void*b)
{
    int x = *(int*)a;
    int y = *(int*)b;

    if (x>y)
    return 1;
    else if (x == y)
    return 0;
    else 
    return -1;
}

int main(void)
{
    int a[] = { 5 , 8 , 3 , 4 , 7 , 5};

    for (int i = 0 ; i< (sizeof(a)/sizeof(int) - 1) ; i++)
    {
        int x = compare(a+i , a+(i+1));
        if (x == 1)
        {
            int p = a[i];
            a[i] = a[i++];
            a[i++] = p;
        }
    }

    for (int i = 0 ; i< (sizeof(a)/sizeof(int)) ; i++)
    {
        printf(" %d", a[i]);
    }
    
    return 0;
}