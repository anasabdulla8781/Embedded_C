/*
 * File: Question9.c
 * Author: Anas Abdulla
 * Date: 2026-05-16
 * Description:
 * 9. Memory Efficient Programming Using Bits
    Task
        Explain storing multiple values using bits.
    Learn
        Flags
        Permissions
        Bit-fields
    Concepts
        bitmasks
    Example
        READ = 1
        WRITE = 2
    Level
        ⭐ Intermediate
•
•
•
6
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define read_permission     1
#define no_permission       0
#define write_permission    2
#define toggle_permission   4
#define delete_permission   8

#define complete_permission ( no_permission| read_permission | write_permission | toggle_permission | delete_permission)

void give_permission(int* user , int permission)
{
    *user |= permission;
}

void check_permission(int user)
{
    if ((user & complete_permission) == 0x03)
    {
        printf("read and write permission");
    }
    else if ((user & complete_permission) == 0x01)
    {
        printf("read permission");
    }
    else if ((user & complete_permission) == 0x02)
    {
        printf("write permission");
    }
    else 
    {
        printf("invalid permission");
    }

    printf("\nThe current permission key is  - ");
    for (int i = 31; i>= 0; i--)
    {
        printf("%d" , ((user >> i)&1));
        if(i % 4 == 0)
        {
            printf (" ");
        }
    }

}

void remove_permission(int* user , int permission)
{
    *user &= ~ permission; 
}

int main(void)
{
    int user = 0;

    give_permission(&user , read_permission);

    give_permission(&user , write_permission);

    remove_permission(&user , read_permission);

    check_permission(user);
    
    return 0;
}