/*
 * File: Q2. Update a multi-bit field.c
 * Author: Anas Abdulla
 * Date: 2026-10-18
 * Description:
 * 
 * ### Q2. Update a multi-bit field

    **Scenario:** A timer's control register contains a 3-bit clock prescaler field at bits 4–6.

    **Task:** Write a function that changes the prescaler value without modifying other register fields.

    Checklist:
    - [ ] Construct the field mask.
    - [ ] Clear the old field before inserting the new value.
    - [ ] Shift the new value into position.
    - [ ] Reject values that do not fit into 3 bits.
    - [ ] Explain why simply OR-ing the new value into the register is incorrect.

 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


#define THREE_BIT_CLEAR             UINT32_C(0X07) 
#define MAX_LIMIT_THREEBIT_CHANGE   UINT32_C(0X07)

void three_bit_changes (uint32_t *number , uint32_t bit_position , uint32_t value)
{
    if (value > MAX_LIMIT_THREEBIT_CHANGE || bit_position > 29U || number == NULL)
    {
        return ;
    }
    
    *number &= ~(THREE_BIT_CLEAR << bit_position);   // Cleared the bits needed to change
    *number |= (value << bit_position);
}

int main(void)
{
    
    return 0;
}