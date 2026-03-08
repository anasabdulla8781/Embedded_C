/*
 * File: 02 - Array of pointers.c
 * Author: Anas Abdulla
 * Date: 2026-03-07
 * Description:
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void)
{
    /// Part 1 - array of pointers
    printf("Part1\n");
    int a=10,b=20,c=30,d=40,e=50;
    int *p[5] = {&a,&b,&c,&d,&e};

    for(int i=0;i<5;i++)
    printf("%d\n ", *p[i]);
    printf("%p\n ", *p);
    printf("%p\n ", *(p+1));
    printf("%p\n ", *(p[1]));
    printf("\n");
    printf("\n");

    /// Part 2 - pointers to array  
    printf("Part 2 \n");
    int arr2[5] = {10,20,30,40,50};
    int (*p2)[5] = &arr2;

    printf("%d\n", *(*p2 + 1));
    printf("%d\n", (*p2)[2]);
    printf("\n");

    /// Part 3 - Pointers to array 2nd
    printf("Part 3 \n");
    int arr3[5]={10,20,30,40,50};
    int (*p3)[5] = &arr3;

    printf("%d\n", *(*p3));
    printf("%d\n", (*p3)[3]);
    printf("\n");

    /// Part 4 - Mixing all
        /* Step 1: Create 5 arrays of 10 integers */

    printf("Part 4 \n");
    int a1[10] = {0,1,2,3,4,5,6,7,8,9};
    int b1[10] = {10,11,12,13,14,15,16,17,18,19};
    int c1[10] = {20,21,22,23,24,25,26,27,28,29};
    int d1[10] = {30,31,32,33,34,35,36,37,38,39};
    int e1[10] = {40,41,42,43,44,45,46,47,48,49};
    /*
       Step 2:
       arr4 → array of 5 pointers
       each pointer → array of 10 integers
    */

    int (*arr4[5])[10] = {&a1, &b1, &c1, &d1, &e1};
    /*
       Step 3:
       p4 → pointer to the entire arr4 array
    */

    int (*(*p4)[5])[10] = &arr4;

    printf("Accessing elements using arr4:\n");

    printf("arr4[0][3] = %d\n", (*arr4[0])[3]);   // a[3]
    printf("arr4[1][4] = %d\n", (*arr4[1])[4]);   // b[4]
    printf("arr4[2][5] = %d\n", (*arr4[2])[5]);   // c[5]

    printf("\nAccessing elements using p4:\n");

    printf("(*p4)[0][3] = %d\n", (*(*p4)[0])[3]); // a[3]
    printf("(*p4)[1][4] = %d\n", (*(*p4)[1])[4]); // b[4]
    printf("(*p4)[2][5] = %d\n", (*(*p4)[2])[5]); // c[5]

    printf("\n");

    return 0;
}