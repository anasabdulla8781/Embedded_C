/*
 * File: 5 - Embedded system example.c
 * Author: Anas Abdulla
 * Date: 2026-03-17
 * Description:
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void)
{
    
    printf("\n===== EMBEDDED SYSTEMS STYLE =====\n");
 
    int fake_register = 0;  // pretending this is a hardware register
 
    // In real embedded code: int * const gpio_ptr = (int*) 0x40001000;
    int * const gpio_ptr = &fake_register;
 
    *gpio_ptr = 1;   // ✓ turn ON  (write to hardware register)
    printf("Register value after ON  = %d\n", fake_register);
 
    *gpio_ptr = 0;   // ✓ turn OFF
    printf("Register value after OFF = %d\n", fake_register);
 
    // gpio_ptr = &fake_register;  // ✗ can't move the pointer — it's fixed to that address
    return 0;
}