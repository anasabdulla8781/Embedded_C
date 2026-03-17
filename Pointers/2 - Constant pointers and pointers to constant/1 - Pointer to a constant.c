/*
 * File: 1 - Pointer to a constant.c
 * Author: Anas Abdulla
 * Date: 2026-03-17
 * Description:
 * // ─────────────────────────────────────────────
//  CASE 1 — Pointer to Constant
//  const int *p   OR   int const *p
//  - Cannot modify value through p  (*p = x  ✗)
//  - CAN re-point p to another variable  (p = &y  ✓)
// ─────────────────────────────────────────────
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void)
{
    printf("\n===== CASE 1: Pointer to Constant =====\n");
 
    const int x = 42;   // x is a constant — locked forever
    const int y = 99;
 
    const int *p = &x;  // p points to x
    printf("p points to x  -->  *p = %d\n", *p);
 
    // ✓ ALLOWED: re-point p to y
    p = &y;
    printf("p re-pointed to y  -->  *p = %d\n", *p);
 
    // ✗ NOT ALLOWED — uncomment to see compiler error:
    // *p = 5;   // error: assignment of read-only location
 
    printf("✓ Re-pointing works | ✗ Writing through p is blocked\n");
    return 0;
}