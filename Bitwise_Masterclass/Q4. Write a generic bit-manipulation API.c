/*
 * File: Q4. Write a generic bit-manipulation API.c
 * Author: Anas Abdulla
 * Date: 2026-10-20
 * Description:
 * 
 * ### Q4. Write a generic bit-manipulation API

        **Scenario:** Your firmware uses the same register operations across GPIO, timer and communication drivers.

        **Task:** Design reusable functions or macros for setting, clearing, toggling, testing and updating bits.

        Checklist:
        - [ ] Define a consistent API.
        - [ ] Evaluate macro type safety and repeated evaluation.
        - [ ] Handle bit positions outside the supported width.
        - [ ] Decide when a `static inline` function is preferable.
        - [ ] Discuss volatile-qualified register pointers.

        **Expected outcome:** Maintainable, reusable embedded C utilities.


 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Macros 
#define E_OK    1
#define E_NOT_OK 0

#define MAX_POSITION_LIMIT  31

// Inline helper functions 
static inline void setbit (volatile uint32_t *number , uint8_t position)
{
    if ((number == NULL) || (position >MAX_POSITION_LIMIT))
    return ;

    *number |= (UINT32_C(1)<<position);
}

static inline void clearbit (volatile uint32_t *number , uint8_t position)
{
    if ((number == NULL) || (position >MAX_POSITION_LIMIT))
    return ;

    *number &= ~(UINT32_C(1)<<position);
}

static inline void togglebit (volatile uint32_t *number , uint8_t position)
{
    if ((number == NULL) || (position >MAX_POSITION_LIMIT))
    return ;

    *number ^= (UINT32_C(1)<<position);
}

static inline uint8_t testbit (volatile uint32_t number , uint8_t position)          // Funciton to check the bit value in the mentioned position 
{
    if (position >31)
    return E_NOT_OK;

    if (number & (1<<position))
    {
        return E_OK;                // Bit is set
    }
    return E_NOT_OK;                // Bit is not set 
}


static inline uint8_t update_bits (volatile uint32_t *number , uint8_t start_position , uint32_t width , uint32_t new_value)
{
    if ((number == NULL) ||(width == 0U) ||(start_position >= 32U) || (width > (32U - start_position)))
    {
        return E_NOT_OK;
    }

    uint32_t mask;

    if (width == 32U)
    {
        mask = UINT32_MAX;
    }
    else
    {
        mask = (UINT32_C(1) << width) - UINT32_C(1);
    }

    *number &= ~(mask<<start_position);           // Cleared the bits which we need to be replaced 

    new_value &= mask;                            // Considering only the bits upto width from the new value .. Rest all 0 

    *number |= (new_value << start_position);           // Added the new value 
    return E_OK;
    
}


typedef struct 
{
    volatile uint32_t CR1;
    volatile uint32_t SR;
}register_map_gpio;

// Register pointers 
volatile register_map_gpio * reg_pointer = (register_map_gpio*)(0X12345678);        // We created the volatile structure pointer pointing to the register map structure ( Now no more optimisation even if we are not doing any operations witht the read value )

// Execution

int main(void)
{
    // uint32_t number = reg_pointer->CR1;
    return 0;
}