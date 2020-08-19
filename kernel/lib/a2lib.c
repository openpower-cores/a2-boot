// © IBM Corp. 2020
// Licensed under and subject to the terms of the CC-BY 4.0
// license (https://creativecommons.org/licenses/by/4.0/legalcode). 
// Additional rights, including the right to physically implement a softcore 
// that is compliant with the required sections of the Power ISA 
// Specification, will be available at no cost via the OpenPOWER Foundation. 
// This README will be updated with additional information when OpenPOWER's 
// license is available.

// Functions for accessing a2 kernel syscalls

// whoami()    - get thread id
// tick()      - get timer tick
// _putchar(c) - write char c to print buffer 

#include "a2lib.h"

// sc 0x0001
uint32_t whoami(void) {
   uint32_t thread;
   asm volatile(
       "li   3,0x0001\n"
       "sc\n"
       "mr   %0,3\n"
       : "=r"(thread)               // outputs
       :                            // inputs
       : "r0","r3"                  // clobbers       
       );
   return thread;
}

// sc 0x0010
uint64_t tick(void) {
   uint64_t t;
   asm volatile(
       "li   3,0x0010\n"
       "sc\n"
       "mr   %0,3\n"      
       : "=r"(t)                    // outputs
       :                            // inputs
       : "r0","r3"                  // clobbers       
      );
   return t;
}

// sc 0x0100
void _putchar(char c) {
   asm volatile(
       "mr   4,%0\n"
       "li   3,0x0100\n"
       "sc\n"
       :                            // outputs
       : "r"(c)                     // inputs
       : "r0","r3","r4","r5","r6","r7","r8" // clobbers
       );
}

