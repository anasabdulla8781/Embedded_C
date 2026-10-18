/*
 * File: 1-Binary search.c
 * Author: Anas Abdulla
 * Date: 2026-08-16
 * Description:
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int binary_search(int*array , int size , int number)
{
    int start = 0;
    int end = (size - 1);

    while (end >= start)
    {
        int index = (start + end )/2;
        if  (array[index] == number)
        {
            return index;
        }
        else
        {
            if (array[index] > number)
            {
                end = (index - 1);
                
            }
            else
            {
                start = (index + 1);
            }
        }
    }
    return -1;
}

int main(void)
{
    int array[] = {10,15,18,20,26,29,35};
    int size = sizeof (array)/sizeof (array[0]);

    int location = binary_search(array , size , 29);
    if (location >= 0)
    {
        printf ("Element is available in %d th index",location);
    }
    else
    {
        printf ("element is not avialble ");
    }
    return 0;
}