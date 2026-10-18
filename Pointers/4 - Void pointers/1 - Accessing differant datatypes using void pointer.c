/*
 * File: 1 - Accessing differant datatypes using void pointer.c
 * Author: Anas Abdulla
 * Date: 2026-09-30
 * Description:
 * 
 * Description:
    Demonstrates how a void pointer can be used to store the
    address of different datatypes and how the pointer is
    type-cast before dereferencing to access the stored value.

                         void *ptr
                         │
               ┌─────────┴─────────┐
               │                   │
               ▼                   ▼
             &x                    &y
               │                   │
              int                 float
               │                   │
        (int *)ptr           (float *)ptr
               │                   │
               ▼                   ▼
              15                  16.8
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void)
{
    int x = 15 ; 
    float y = 16.8 ;

    void* ptr = NULL;
    ptr = &x;
    printf ("%d\n",*(int*)ptr);

    ptr = &y;
    printf("%f\n",*(float*)ptr);
    return 0;
}