/*
 * File: 06 - Typedef in function pointer.c
 * Author: Anas Abdulla
 * Date: 2026-03-11
 * Description:
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef void(*device_function)();

typedef struct
{
    char* name;
    device_function communincation_function;
}device_param;

void spi_function()
{
    printf("device is working though SPI\n");
}

void i2c_function()
{
    printf("device is working though I2C\n");
}

int main(void)
{              
    device_param device_parameters[3] = 
    {
        {"Device1",  spi_function},
        {"Device2",  i2c_function},
        {"Device3",  spi_function}
    };
    
    for (int i = 0; i<3 ; i++)
    {
        printf("The device is %s and the function is -> ",device_parameters[i].name);
        device_parameters[i].communincation_function();
    }

    return 0;
}