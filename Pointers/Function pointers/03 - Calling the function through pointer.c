/*
 * File: 03 - Calling the function through pointer.c
 * Author: Anas Abdulla
 * Date: 2026-03-11
 * Description:
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void fun()
{
    printf("HELLO\n");
}

void function2 ()
{
    printf("Hello2\n");
}

int main(void)
{

    /// Part 1
    void (*fp)() = fun;
    fp;                             /// This will not print anything since we are not calling the function through this . fp stores the address of function , and its just an expression . No function call

    /// Part 2
    void(*fp2)();
    fp2 = function2;
    fp2();                      /// This is the normal function call thrugh pointer 

    /// Part 3
    (*fp2);                     /// This is dereferencing the pointer . fine . so we reached the function . but nothing will happen , since we didnt do function call 
    

    /// Part 4
    printf("%p\n", *fp2);       /// This will print the address of the function since its pointing to that address 
    return 0;
}