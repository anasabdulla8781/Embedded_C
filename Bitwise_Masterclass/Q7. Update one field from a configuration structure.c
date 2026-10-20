/*
 * File: Q7. Update one field from a configuration structure.c
 * Author: Anas Abdulla
 * Date: 2026-10-20
 * Description:
 * ### Q7. Update one field from a configuration structure

        **Scenario:** A device has a 16-bit configuration word containing mode, data width, parity and stop-bit fields.

        **Task:** Implement independent setters for each field so changing parity never corrupts the mode or data width.

        Checklist:
        - [ ] Define non-overlapping masks and shifts.
        - [ ] Validate each field's allowed range.
        - [ ] Ensure setters preserve all unrelated bits.
        - [ ] Create a test that changes fields in different orders.

        **Expected outcome:** Reliable configuration-word management.
 * 
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define SIXTEEN_BIT_CLEAR_MASK  ((1 << 16) - 1)
#define SIXTEEN_BIT_MAX_RANGE   ((1 << 16) - 1)

#define FOUR_BIT_CLEAR_MASK  ((1 << 4) - 1)
#define FOUR_BIT_MAX_RANGE   ((1 << 4) - 1)

#define DATA_WIDTH  1
#define MODE        2
#define PARITY      3
#define STOP_BIT    4

typedef struct
{
    uint32_t data_width     :16;
    uint32_t mode           :4;
    uint32_t parity         :4;
    uint32_t stop_bit       :4; 
}device_config;

void clear_set_bit (device_config* config, uint8_t member_position , uint32_t new_value)
{
    if (config == NULL)
    {
        return;
    }
    switch (member_position)
    {
    case DATA_WIDTH:
        if (SIXTEEN_BIT_MAX_RANGE < new_value)
        {
            return;
        }
        config->data_width = (uint16_t) new_value;
        break;
    
    default:
        break;
    }
}

int main(void)
{
    device_config device1_config;

    clear_set_bit(&device1_config , DATA_WIDTH , 0X53);
    
    return 0;
}