/*
 * File: 2 - Common function for differant datatypes.c
 * Author: Anas Abdulla
 * Date: 2026-09-30
 * Description:
 *                
 * 
     *               print()
                      │
            ┌─────────┴─────────┐
            │                   │
          void *               char
            │                   │
        "where?"            "what type?"
            │                   │
            ▼                   ▼
         address                i / f
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void print (void* ptr , char x)
{
    if (x =='i')
    {
        printf("%d\n",*(int*)ptr);
    }
    else if (x == 'f')
    {
        printf("%f\n", *(float*)ptr);
    }
}

int main(void)
{
    int i = 15;
    float y= 26.8;
    void *ptr = NULL;
    ptr = &i;
    print(ptr,'i');
    ptr = &y;
    print(ptr,'f');
    return 0;
}