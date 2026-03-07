
/* assignment 2

    Author name : anas abdulla
    date : 29 - 7 - 2021
    Description :
    Description:

    • In mathematics, the Fibonacci numbers or Fibonacci sequence are the numbers in the following integer sequence 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 . . . OR 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 . . .

    • By definition, the first two numbers in the Fibonacci sequence are 0 and 1, each subsequent number is the sum of the previous two

    Pr-requisites:-

    • Loops

    • Operators

    Objective: -

    To understand the concept of

    ◦ Continuos looping.

    ◦ If-else constructs

    Inputs: -

    A integer say 'N' , Where -2^20 < 'N' < 2^20

    Sample execution: -

    user@emertxe] ./fibbonacci_series

    Enter a number: 8

    0, 1, 1, 2, 3, 5, 8

    Do you want to continue (y/Y) : y

    Enter a number: 10

    0, 1, 1, 2, 3, 5, 8

    Do you want to continue (y/Y) : y

    Enter a number: -21

    0, 1, -1, 2, -3, 5, -8, 13, -21

    Do you want to continue (y/Y) : y

    Enter a number: -13

    0, 1, -1, 2, -3, 5, -8, 13

    Do you want to continue (y/Y) : y

    Enter a number: 2000000

    Error : Number out of range, please enter the value -2^20 < 'N' < 2^20

    Do you want to continue (y/Y) : n
    output : fibanocci series
*/

#include <stdio.h>

int main ()
{
    int num ;                                                           /// we are storing the number to which we print here 
    int a , b ;                                                         /// this is for storing 0 and 1 . we are initialising this inside the loop , so just declared here 
    int temp = a+b;                                                     /// this variable is for the next number of b
    char o;                                                             /// for the option ( is it continues or not  )

    do 
    {
        printf("enter the number \n");
        scanf ("%d",&num);
        if (num >1048576)                                               /// statement for checking the limit 
        {
            printf("input is out og range\n");
        }
        else                                                        
        {
            a = 0 , b = 1;
            printf ("%d , ",a);
            if (num > 0 )                                               /// if the numbers are greater than 0 , we can print the numbers till it reaches the maximum limit we have given
            {
                
                do
                {
                    printf("%d , ",b);
                    temp = a+b;
                    a = b;
                    b = temp;
                    
                }
                while (temp<=num);
            }
            else if (num < 0)                                           /// if the numbers are less than 0 , we need to check with the modulas of the number .. we are using one more variable to store this modulas 
            {
                int k = -num;
                int m;                                                  /// variable to store absolute value of the number 
                do
                {
                    printf("%d , ",b);
                    temp = a-b;
                    a = b;
                    b = temp;
                    temp < 0 ? (m = -temp) : (m = temp);
                    
                }
                while (m<=k);    
            }
            
        }
        getchar();
        printf ("\ndo you wanat to continue ? ( y/n )");                 /// continuation option 
        scanf ("%c",&o);
    }
    while (o == 'y' || o == 'Y');
    return 0;

}