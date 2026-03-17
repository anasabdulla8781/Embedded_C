/*
 * File: 05 - Embedded style array of function pointers.c
 * Author: Anas Abdulla
 * Date: 2026-03-11
 * Description:
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void spi_function()
{
    printf("device is working though SPI\n");
}

void i2c_function()
{
    printf("device is working though I2C\n");
}

int main(void)
{                       /*Device 1            Device 2            *Device 3*/
    void(*fp[3])() = {  spi_function ,      i2c_function,       spi_function};

    for (int i = 0; i<3 ; i++)
    {
        fp[i]();
    }

    return 0;
}