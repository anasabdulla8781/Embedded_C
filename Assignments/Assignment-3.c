/* Assignment 3

    Author name : anas abdulla
    date : 29 - 7 - 2021
    Description:

    • In number theory, a perfect number is a positive integer that is equal to the sum of its proper positive divisors, that is, the sum of its positive divisors excluding the number itself (also known as its aliquot sum).

    • Equivalently, a perfect number is a number that is half the sum of all of its positive divisors (including itself).

    Example:

    • The first perfect number is 6, because 1, 2, and 3 are its proper positive divisors, and 1 + 2 + 3 = 6. Equivalently, the number 6 is equal to half the sum of all its positive divisors: ( 1 + 2 + 3 + 6 ) / 2 = 6

    • The next perfect number is 28 = 1 + 2 + 4 + 7 + 14. This is followed by the perfect numbers 496 and 8128

    Pr-requisites:-

    • Loops

    • Operators

    Objective: -

    • To understand the concept of

    •  If-else constructs

    Inputs: -

    A positive integer say 'N'. Where N < 220
    Sample execution: -

    user@emertxe] ./perfect_number

    Enter a number: 6

    Yes, entered number is perfect number

    Do you want to continue (y/Y) : y

    Enter a number: 10

    No, entered number is not a perfect number

    Do you want to continue (y/Y) : y

    Enter a number: -1

    Error : Invalid Input, Enter only positive number

    Do you want to continue (y/Y) : y

    Enter a number: 2000000

    Number out of range

    Do you want to continue (y/Y) : n
    outputs : print whether the number is perfect or not .
*/

#include <stdio.h>

int main ()
{
    int x ;                                                 /// this variable stores the input data 
    int sum = 0;                                            /// we have to sum up the numbers to see if the sum matches the entered number ... then only the number will be perfect .. this variable is for that purpose 
    char op;
    do 
    {
        printf ("enter the number \n");                         
        scanf ("%d",&x);

        if (x < 1)                                              /// checking for negative numbers
        {
            printf("Invalid Input, Enter only positive number\n");
        }

        else if (x > 1048576)                                        /// checking for the limit ( 2^20 )
        {
            printf ("crossed the limit \n");
        }

        else 
        {
            for (int i = 1 ; i<x ; i++)                             /// we have to devide the number with numbers from 1 to ( x-1 ) and then add those ... for loop is used for  that 
            {
                if (!(x%i))
                {
                    sum = sum +i;
                }
            }
            sum == x ? printf ("%d is a perfect number\n",x):printf ("%d is not a perfect number\n",x);     /// this line checks whether the number is perfect or not ... used ternary operator to make the code modular
        }
        printf ("do you want to continue ?\n");
        getchar ();
        scanf ("%c",&op);
    }
    while (op == 'y' || op == 'Y');
    return 0;
}