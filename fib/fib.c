/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include "fib.h"

const uint LED_PIN = 20;
const uint BOARD_LED = PICO_DEFAULT_LED_PIN;

uint fib_helper(uint a, uint b, uint n) {
    if (n == 0) {
        return a;
    } else {
        return fib_helper(b, a + b, n - 1);
    }
}

uint fib(uint n) {
    return fib_helper(0, 1, n);
}

// int main() {
//     gpio_init(LED_PIN);
//     gpio_init(BOARD_LED);
//     gpio_set_dir(LED_PIN, GPIO_OUT);
//     gpio_set_dir(BOARD_LED, GPIO_OUT);
//     while (true) {
//     // blink the number of fibs from 0 to 6
//         for (int i = 0; i < 7; i++) {
//             blinks(fib(i));
//         }
//     }
// }
