/*
 * File: Q6. Test whether multiple flags satisfy a condition.c
 * Author: Anas Abdulla
 * Date: 2026-10-20
 * Description:
 * 
 * ### Q6. Test whether multiple flags satisfy a condition

        **Scenario:** A driver should proceed only when both `READY` and `CALIBRATED` are set, and `FAULT` is clear.

        **Task:** Implement the condition using masks.

        Checklist:
        - [ ] Check whether all required flags are set.
        - [ ] Check whether any prohibited flag is set.
        - [ ] Distinguish `(status & mask) == mask` from `(status & mask) != 0`.
        - [ ] Explain why logical operators and bitwise operators are not interchangeable.

        **Expected outcome:** Correct flag-condition logic.

 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define PERIPHERAL_ENABLE_BIT_POS   8
#define INTERRUPT_ENALBE_BIT_POS    12
#define LOW_POWER_MODE_BIT_POS      5
#define READY_BIT_POSITION          25
#define CALIBERATED_BIT_POSITION    26
#define FAULT_BIT_POSTION           27


#define PERIPHERAL_ENABLE_BIT_DISABLE  0
#define PERIPHERAL_ENABLE_BIT_ENABLE   1

#define INTERRUPT_ENALBE_BIT_ENABLE    1
#define INTERRUPT_ENALBE_BIT_DISABLE   0

#define LOW_POWER_MODE_BIT_DISABLE    0
#define LOW_POWER_MODE_BIT_ENABLE     1

#define FAULT_CLEARED       0
#define FAULT_NOT_CLEARED   1

#define CHIP_CALIBERATED        1
#define CHIP_NOT_CALIBERATED    0

#define CHIP_READY_STATE        1
#define CHIP_NOT_READY_STATE    0

void static inline clear_and_set_bit (uint32_t * control_reg , uint32_t clear_mask , uint32_t set_mask)
{
    if (control_reg == NULL)
    {
        return;
    }

    if ((*control_reg & ((CHIP_READY_STATE) << READY_BIT_POSITION)) && (*control_reg & ((CHIP_CALIBERATED) << CALIBERATED_BIT_POSITION)) && ((*control_reg & (FAULT_NOT_CLEARED << FAULT_BIT_POSTION)) == 0U))   // Doing the operation only if the chip is ready and caliberated and no fault in that
    {
        *control_reg &= ~(clear_mask);
        *control_reg |= (set_mask);
    }

}

void setup_mask(uint32_t* clear_mask , uint8_t bit_position , uint32_t* set_mask , uint8_t set_value)
{
    if ((bit_position > 31) || (clear_mask == NULL) || (set_value > 1)|| (set_mask == NULL))
    {
        return;
    }
    *clear_mask |= (1<< bit_position);                         // Setup the clear mask which we can use further
    *set_mask |= (set_value << bit_position);                  // Setup the set mask which we can use further
}

int main(void)
{
    uint32_t clear_mask = 0x00;
    uint32_t set_mask = 0x00;
    uint32_t Control_Reg = 0x00;                               // Defualt control register

    setup_mask(&clear_mask , PERIPHERAL_ENABLE_BIT_POS,  &set_mask , PERIPHERAL_ENABLE_BIT_DISABLE);
    setup_mask(&clear_mask , INTERRUPT_ENALBE_BIT_POS , &set_mask , INTERRUPT_ENALBE_BIT_ENABLE);
    setup_mask(&clear_mask , LOW_POWER_MODE_BIT_POS, &set_mask , LOW_POWER_MODE_BIT_ENABLE);                                // Made common mask

    clear_and_set_bit (&Control_Reg , clear_mask, set_mask);
    return 0;
}