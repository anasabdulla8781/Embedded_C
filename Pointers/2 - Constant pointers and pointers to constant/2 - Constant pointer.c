/*
 * File: 2 - Constant pointer.c
 * Author: Anas Abdulla
 * Date: 2026-03-17
 * Description:
 * // ─────────────────────────────────────────────
//  CASE 2 — Constant Pointer
//  int * const p = &x
//  - CAN modify value through p  (*p = 5  ✓)
//  - Cannot re-point p  (p = &z  ✗)
//  Use case: embedded systems — fixed hardware address
// ─────────────────────────────────────────────
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void)
{
    printf("\n===== CASE 2: Constant Pointer =====\n");
 
    int x = 42;
    int z = 7;
 
    int * const p = &x;  // p is locked to address of x — forever
 
    printf("Before: *p = %d\n", *p);
 
    // ✓ ALLOWED: modify the value at the address
    *p = 100;
    printf("After *p = 100  -->  x = %d\n", x);
 
    // ✗ NOT ALLOWED — uncomment to see compiler error:
    // p = &z;   // error: assignment of read-only variable 'p'
 
    printf("✓ Writing through p works | ✗ Re-pointing is blocked\n");
    
    return 0;
}