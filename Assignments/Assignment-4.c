
/* Assignment 4 

    Author name : anas abdulla
    date : 29 - 7 - 2021
    Description:

    Print the Decimal numbers from 0 to 127 in Octal, Hexadecimal and in ASCII representation.
    Display as 'Non Printable' for non-printable characters
    Pr-requisites:-

    Loops
    Objective: -

    To understand the concept of
    Loops and ASCII characters
    Inputs: -

    None
    Sample execution: -
    Test Case 1:
    user@emertxe] ./ascii
    Dec       Oct         Hex        Ascii
    ---          ---            ---          -----
    0           000         00          Non Printable
    1           001         01          Non Printable
    output : ascii table 
*/

#include <stdio.h>

int main ()
{
    printf ("               ASCII TABLE\n");
    printf ( "Dec       Hex         Oct         Char\n---------------------------------------\n" );     /// this line is for printing the heading 
    for (unsigned char i = 0; i <= 127 ; i++)                                                           /// we need to use unsigned , otherwise by default the compiler will set signed and then the count will go to -128 after 127
    {
        if (i <= 32 || i == 127)
        {
            printf ("%03d       %03x         %03o      Not printable\n", i,i,i);                        /// we dont have printable charecter equalant for numbers till 32 and for 127
        }
        else
        {
            printf ("%03d       %03X         %03o       %03c\n", i,i,i,i);                              /// here we have the printable charecter eqvalant .. so we are filling that too
        }
        
    } 

}