# a2-boot

## kernel - simple boot code example

Sets up a limited addressing scheme using ERAT-only translation mode.  Configuration block allows
thread enablement and some per-thread configuration for MSR, code/stack addresses, and print buffer.

Provides system call support for basic info and print buffer access.

*a2lib* includes C functions for using system calls.

