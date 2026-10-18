/*
 * File: Q1. Modify a single bit without affecting other bits.c
 * Author: Anas Abdulla
 * Date: 2026-10-18
 * Description:
 * 
 * 
 * ### Q1. Modify a single bit without affecting other bits

    **Scenario:** A control register contains configuration for several peripherals. You must enable bit 5 while preserving every other bit.

    **Task:** Write reusable C code to set bit 5, clear bit 5, and toggle bit 5.

    Checklist:
    - [ ] Implement set, clear and toggle operations.
    - [ ] Explain why `|`, `& ~` and `^` are used.
    - [ ] Demonstrate that unrelated bits remain unchanged.
    - [ ] Use an unsigned integer type and a bit-position macro.

    **Expected outcome:** Reliable single-bit register manipulation.

 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void set_bit (uint32_t* number , uint32_t bit_position)
{
    if (bit_position > 31 || number == NULL)
    {
        return;
    }
    *number |= ((uint32_t)1 << bit_position);
}


void clear_bit(uint32_t* number , uint32_t bit_position)
{
    if (bit_position > 31 || number == NULL)
    {
        return;
    }
    *number &= ~((uint32_t)1 << bit_position);
}

void toggle_bit(uint32_t* number , uint32_t bit_position)
{
    if (bit_position > 31 || number == NULL)
    {
        return;
    }
    *number ^= ((uint32_t)1<< bit_position);
}

int main(void)
{
    
    return 0;
}