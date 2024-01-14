/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include "fib.h"

uint fib_helper(uint a, uint b, uint n) {
    if (n == 0) {
        return a;
    } else {
        return fib_helper(b, a + b, n - 1);
    }
}

uint fib(uint n) { // an iterative computation
    int a = 0;
    int b = 1;
    for (int i = 0; i < n; i++) {
        int c = a + b;
        a = b;
        b = c;
    }
    return a;
}