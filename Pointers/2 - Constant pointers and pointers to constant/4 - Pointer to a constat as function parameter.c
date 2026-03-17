/*
 * File: 4 - Pointer to a constat as function parameter.c
 * Author: Anas Abdulla
 * Date: 2026-03-17
 * Description:
 * // ─────────────────────────────────────────────
//  BONUS — Common use in function parameters
//  When a function takes const int *p, it promises
//  it will only READ the value, never modify it.
// ─────────────────────────────────────────────
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


void print_value(const int *p) {  // promises: "I won't touch your data"
    printf("Value = %d\n", *p);
    // *p = 999;  // ✗ compiler won't allow this here
}

int main(void)
{
 
    printf("\n===== BONUS: const in function parameters =====\n");
 
    int a = 55;
    print_value(&a);   // safe — function can't accidentally modify a
 
    const int b = 77;
    print_value(&b);   // also works — both const and non-const can be passed
    return 0;
}