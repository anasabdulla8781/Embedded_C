/*
 * File: 09 - Funciton pointer as return.c
 * Author: Anas Abdulla
 * Date: 2026-03-14
 * Description:
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
int add (int x , int y)
{
    return (x+y);
}

int multiply (int x , int y)
{
    return (x*y);
}

int(*get_operation (char x))(int , int) 
{
    if (x == 'a')
    return add;
    else if (x == 'm')
    return multiply;
}

int main(void)
{
    printf ("result is %d \n",get_operation('m')(4 , 5));
    return 0;

}