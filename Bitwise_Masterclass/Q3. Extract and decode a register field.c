/*
 * File: Q3. Extract and decode a register field.c
 * Author: Anas Abdulla
 * Date: 2026-10-18
 * Description:
 * 
 * ### Q3. Extract and decode a register field

    **Scenario:** A peripheral's status register stores a 4-bit operating mode at bits 8–11.
    
    **Task:** Extract the mode and convert it into meaningful enumerated states.
    
    Checklist:
    - [ ] Apply the mask and right shift.
    - [ ] Define valid mode values.
    - [ ] Handle reserved and unsupported values.
    - [ ] Avoid accidentally including unrelated status bits.
    
    **Expected outcome:** Robust register decoding.
    
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum{
    MODE_0,
    MODE_3 = 3,
    MODE_10 = 10,
    MODE_15 = 15,
    MODE_INVALID = 255,
}reg_modes;

#define GET_MODE_MASK       (UINT32_C(0X0F) << 8)
#define STATE_BIT_POSITION  UINT32_C(8)

reg_modes get_mode (uint32_t number)
{
    uint8_t mode;
    mode = (number & GET_MODE_MASK) >> STATE_BIT_POSITION;

    switch (mode)
    {
    case MODE_0:
    case MODE_3:
    case MODE_10:
    case MODE_15:
        return (reg_modes)mode;
    default:
        return (MODE_INVALID);
    }
}

int main(void)
{
    return 0;
}