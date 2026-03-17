/*
 * File: 3 - Constant pointer to constant.c
 * Author: Anas Abdulla
 * Date: 2026-03-17
 * Description:
 * // ─────────────────────────────────────────────
//  CASE 3 — Const Pointer to Const  (BONUS)
//  const int * const p = &x
//  - Cannot modify value through p  ✗
//  - Cannot re-point p  ✗
//  Everything is frozen.
// ─────────────────────────────────────────────
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void)
{
    printf("\n===== CASE 3: Const Pointer to Const =====\n");
 
    const int x = 42;
 
    const int * const p = &x;  // both pointer and value are locked
 
    printf("*p = %d\n", *p);
 
    // ✗ NOT ALLOWED — uncomment to see compiler errors:
    // *p = 5;      // error: assignment of read-only location
    // p  = &x;     // error: assignment of read-only variable 'p'
 
    printf("✗ Cannot write through p | ✗ Cannot re-point p\n");
    
    return 0;
}