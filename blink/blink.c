/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"

int main() {
#ifndef PICO_DEFAULT_LED_PIN
#warning blink example requires a board with a regular LED
#else
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    uint led_array[] = {12, 17, 18, 19, 20, 21, 22, 26};
    uint led_array_size = sizeof(led_array) / sizeof(led_array[0]);
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    for (int i = 0; i < led_array_size; i++) {
        gpio_init(led_array[i]);
        gpio_set_dir(led_array[i], GPIO_OUT);
    }
    while (true) {
        gpio_put(LED_PIN, 1);
        for (int i = 0; i < led_array_size; i++) {
            gpio_put(led_array[i], 1);
        }
        sleep_ms(250);
        gpio_put(LED_PIN, 0);
        for (int i = 0; i < led_array_size; i++) {
            gpio_put(led_array[i], 0);
        }
        sleep_ms(250);
    }
#endif
}
