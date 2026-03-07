
/* assignment 1

    Author name : anas abdulla
    date : 29 - 7 - 2021
    Description:

    • The user entered number should identified whether its a odd or a even number. Mention its sign too.

    Pr-requisites:-

    • Loops

    • Arithmetic Operators

    • Nested if-else construct

    Objective: -

    • To understand the concept of Nested if-else

    Inputs: -

    Integer 'N'. Where -2^20 < 'N' < 2^20
    Sample execution: -

    Test Case 1:

    user@emertxe] ./even_odd

    Enter the value of 'n' : -4

    -4 is -ve even number

    Do you want to continue(y/Y): y

    Enter the value of 'n' : 4

    4 is +ve even number

    Do you want to continue(y/Y): y

    Enter the value of 'n' : 2000000

    Number out of range

    Do you want to continue(y/Y): y

    Enter the value of 'n' : 0

    0 is neither odd nor even

    Do you want to continue(y/Y): n
    outputs : whether its odd or even and its sign 
*/

#include <stdio.h>

int main ()
{
    int x ;                                     /// variable for storing the entered number 
    char o;                                     /// variable for storing the condition 
    int limit = 1048576;                        /// maximum number 

    do 
    {
        printf ("enter the number \n");         /// number to be checked , this has to store in x
        scanf ("%d",&x);
        if (x >= limit)                         /// to check whether the number crossed the limit or not 
        {
            printf ("this number is above the limit \n");
        }
        else if (x == 0)
        {
            printf ("there is no sign for 0 \n");
        }
        else if (x<0)                             /// condition for negative number 
        {
            if (x%2 == 0)                        /// condition for even number 
                {
                    printf("%d is -ve even number \n",x);
                } 
                else 
                {
                    printf ("%d is -ve odd number \n",x);
                }
        }
        else                                     /// condition for positive number 
        {
           if (x%2 == 0)                        /// condition for even number 
           {
               printf("%d is +ve even number \n",x);
           } 
           else 
           {
               printf ("%d is +ve odd number \n",x);
           }

        }
        getchar();                                   /// this is for storing the enter charecter from the buffer 
        printf ("do you want to continue ? \n");        /// option for continuation 
        scanf ("%c",&o);
    }
    while (o == 'y' || o == 'Y');                                   /// contnuation only if we press the 'y'

    return 0;
}