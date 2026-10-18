/*
 * File: 01 - Bubble sort.c
 * Author: Anas Abdulla
 * Date: 2026-04-05
 * Description:
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void)
{

    int arr[] = {10,5,6,7};

    int n = (sizeof(arr)/sizeof(arr[0]));
    int min_index;

    for (int pass = 0 ; pass < n-1 ; pass++)
    {
        for (int comp = 0; comp< n-1-pass ; comp++)
        {
            if (arr[comp] > arr[comp+1])
            {
                int temp = arr[comp];
                arr[comp] = arr[comp+1];
                arr[comp+1] = temp;
            }
        }
    }

    for (int i = 0; i<n ; i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
}