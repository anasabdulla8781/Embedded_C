/*
 * File: Q5. Configure multiple independent control bits.c
 * Author: Anas Abdulla
 * Date: 2026-10-20
 * Description:
 * 
 * ### Q5. Configure multiple independent control bits

        **Scenario:** A peripheral must be enabled, its interrupt enabled, and its low-power mode disabled through one control register.

        **Task:** Implement the configuration while preserving unrelated bits.

        Checklist:
        - [ ] Set multiple selected bits in one operation.
        - [ ] Clear a different group of bits.
        - [ ] Combine masks without confusing bit positions with bit values.
        - [ ] Compare sequential read-modify-write operations with a combined operation.

        **Expected outcome:** Correct multi-bit configuration.


 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define PERIPHERAL_ENABLE_BIT_POS   8
#define INTERRUPT_ENALBE_BIT_POS    12
#define LOW_POWER_MODE_BIT_POS      5


#define PERIPHERAL_ENABLE_BIT_DISABLE  0
#define PERIPHERAL_ENABLE_BIT_ENABLE   1

#define INTERRUPT_ENALBE_BIT_ENABLE    1
#define INTERRUPT_ENALBE_BIT_DISABLE   0

#define LOW_POWER_MODE_BIT_DISABLE    0
#define LOW_POWER_MODE_BIT_ENABLE     1

void static inline clear_and_set_bit (uint32_t * control_reg , uint32_t clear_mask , uint32_t set_mask)
{
    if (control_reg == NULL)
    {
        return;
    }

    *control_reg &= ~(clear_mask);
    *control_reg |= (set_mask);
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