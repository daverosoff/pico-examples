/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"

const uint LED_PIN = 20;
const uint BOARD_LED = PICO_DEFAULT_LED_PIN;
int fib(uint n) { // an iterative computation
    int a = 0;
    int b = 1;
    for (int i = 0; i < n; i++) {
        int c = a + b;
        a = b;
        b = c;
    }
    return a;
}

void blinks(uint n) {
    for (int i = 0; i < n; i++) {
        gpio_put(LED_PIN, 1);
        gpio_put(BOARD_LED, 1);
        sleep_ms(250);
        gpio_put(LED_PIN, 0);
        gpio_put(BOARD_LED, 0);
        sleep_ms(250);
    }
    sleep_ms(500);
}

int main() {
    gpio_init(LED_PIN);
    gpio_init(BOARD_LED);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_set_dir(BOARD_LED, GPIO_OUT);
    while (true) {
    // blink the number of fibs from 0 to 6
        for (int i = 0; i < 7; i++) {
            blinks(fib(i));
        }
    }
}
