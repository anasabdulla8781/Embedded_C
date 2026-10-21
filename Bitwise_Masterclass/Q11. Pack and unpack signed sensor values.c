/*
 * File: Q11. Pack and unpack signed sensor values.c
 * Author: Anas Abdulla
 * Date: 2026-10-20
 * Description:
 * 
 * ### Q11. Pack and unpack signed sensor values

        **Scenario:** A device transmits a signed 12-bit temperature measurement inside a 16-bit word.

        **Task:** Decode the 12-bit two's-complement value into a suitable signed C type.

        Checklist:
        - [ ] Extract the 12-bit raw value.
        - [ ] Detect the sign bit.
        - [ ] Sign-extend correctly.
        - [ ] Test zero, maximum positive, minimum negative and negative one.
        - [ ] Avoid relying on implementation-defined signed shifts.

        **Expected outcome:** Correct signed-value decoding.


 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint16_t word;
int temperature;

int main(void)
{
    temperature |= (word & (0xFFF));                                    /// Took the 12bits from the word to the temperature .. So the last bit will be sign here (11th)

    if (temperature & (1 << 11))
    {
        // Negative temperature
        temperature = 2048-temperature;
    }
    else
    {
        // Positive temperature 
        // Do nothing 
    }
    return 0;
}