/*
 * File: 01 - Pointer differance and addition with number.c
 * Author: Anas Abdulla
 * Date: 2026-03-07
 * Description:
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void)
{

    /// Part 1 - pointer on array 
    int arr[] = {10 , 20 , 30, 40, 50};
    printf("%p is the address of the first element \n" , arr);                  /// This will print address of the first element 
    printf("%p is the address of the 3rd element\n" , (arr+2));                 /// address of 3rd elment
    printf("%d is the value of the 3rd element\n" , arr[2]);                    /// value at index 2
    printf("%d is the value of the 3rd element\n" , *(arr + 2));                /// arr[2] = *(arr + 2 )


    printf("\n");

    int *p1 = &arr[4];
    int *p2 = &arr[1];

    /// Part 2 - pointer operations 

            /*
            Valid operations in pointerz
            p + n
            p - n
            p1 - p2
            p++
            p--


            Invalid operations 
            p1 + p2
            p1 * p2
            p1 / p2
        */
    /// Addition and subtraction
    printf("%d is the differance between p1 and P2\n" , (p1 - p2));                      /// Possible (p1 - p2 = differance is address / size of element)
    /// printf("%d is the differance between \n" , (p1 + p2));                           /// Not possible
    
    /// Post and pre increment
    int arr2[5] = {10,20,30,40,50};
    int *p = arr2;

    printf("%d\n", *(p++));                                                             /// Post increment . perform all the operations in the line first 
    printf("%d\n", *p);                                                                 /// Then incremented 
    printf("%d\n", *(++p));                                                             /// Pre increment . incrment Operation happened first and then rest of the line 

    /// Part 3 - Address of array element and address of whole array 
    printf("part 3\n");
    int arr3[5] = {10,20,30,40,50};

    printf("%p\n", arr3);                                                               /// arr3 is the array and the address means the address of first element
    printf("%p\n", arr3+1);                                                             /// Incrementing by 1 means , address of arr3 + 1(size of arr3) - ( arr3 is of int type )

    printf("%p\n", &arr3);                                                      /// arr3 is the array and we are explicitly mentionning address of arr3 . address of starting array . so address of first element
    printf("%p\n", &arr3+1);                                                    /// ncrementing by 1 means , address of arr3 array + 1(size of arr3 arrya) - ( arr3 array is of int[5] type )
    printf("%d\n", *(&arr3 + 1) - arr3);
    printf("\n");


    /// Part 4 - dereferencing the pointer to array
    printf("part 4\n");
    int arr4[5] = {10,20,30,40,50};
    printf("%d\n", *(arr4+3));
    printf("%d\n", *(&arr4+0));
    printf("%d\n", (*(&arr4))[0]);
    printf("\n");


    /// Part 5 - Trick to find the size of array
    printf("part 5\n");
    int arr5[5] = {10,20,30,40,50};
    printf("%d", *(&arr5 + 1) - arr5);

    /// Part 6 - *p++ , (*p)++ and *(++p)
    printf("part 6\n");
    int arr6[3] = {10,20,30};
    int *t = arr6;

    printf("Initial values: %d %d %d\n", arr6[0], arr6[1], arr6[2]);

    printf("*t++ = %d\n", *t++);
    printf("(*t)++ = %d\n", (*t)++);
    printf("*(++t) = %d\n", *(++t));

    printf("Final array values: %d %d %d\n", arr6[0], arr6[1], arr6[2]);
    printf("\n");

    return 0;
}