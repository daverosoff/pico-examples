/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define EVENT_PIN 15
#define DELAY 125
#define ONES_PIN 16
#define TWOS_PIN 17
#define FOURS_PIN 18
#define EIGHTS_PIN 19
#define SIXTEENS_PIN 20
#define THIRTYTWOS_PIN 21
#define SIXTYFOURS_PIN 22
#define ONETWENTYEIGHTS_PIN 26
#define NUM_PINS 8

static char event_str[128];

// void gpio_event_string(char *buf, uint32_t events);

void gpio_callback(uint pins[], uint num_pins) {
    // Display the fib sequence
    uint i = 0;
    while (fib(i) < (1 << NUM_PINS)) {
        uint f = fib(i++);
        if (f < 0x100) {
            if (f > 1) {
                leave_value(f, pins, num_pins, 3 * DELAY);
            }
            else {
                flash_value(f, pins, num_pins, 3 * DELAY / 2);
            }
        }
        else {
            for (int count = 0; count < 1; count++) {
                leave_value(0x01, pins, num_pins, DELAY);
                leave_value(0x03, pins, num_pins, DELAY);
                leave_value(0x06, pins, num_pins, DELAY);
                leave_value(0x0C, pins, num_pins, DELAY);
                leave_value(0x18, pins, num_pins, DELAY);
                leave_value(0x30, pins, num_pins, DELAY);
                leave_value(0x60, pins, num_pins, DELAY);
                leave_value(0xC0, pins, num_pins, DELAY);
                leave_value(0x80, pins, num_pins, DELAY);
                leave_value(0xC0, pins, num_pins, DELAY);
                leave_value(0x60, pins, num_pins, DELAY);
                leave_value(0x30, pins, num_pins, DELAY);
                leave_value(0x18, pins, num_pins, DELAY);
                leave_value(0x0C, pins, num_pins, DELAY);
                leave_value(0x06, pins, num_pins, DELAY);
                leave_value(0x03, pins, num_pins, DELAY);
                leave_value(0x01, pins, num_pins, DELAY);
            }
        }
    }
}

int main() {
    // stdio_init_all();
    uint button_pin = EVENT_PIN;
    uint led_pins[] = {ONES_PIN, TWOS_PIN, FOURS_PIN, EIGHTS_PIN,
        SIXTEENS_PIN, THIRTYTWOS_PIN, SIXTYFOURS_PIN,
        ONETWENTYEIGHTS_PIN};
    // uint pins[] = {16, 17, 19, 20, 21, 22, 23, 24};
    // note: I would probably do a macro for the next line also
    // but I wanted to illustrate the common sizeof() trick
    uint num_pins = NUM_PINS;
    for (int i = 0; i < num_pins; i++) {
        gpio_init(led_pins[i]);
        gpio_set_dir(led_pins[i], GPIO_OUT);
    }


    // printf("Hello GPIO IRQ\n");
    gpio_set_irq_enabled_with_callback(
        button_pin,
        GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL,
        true,
        &gpio_callback
    );

    // Wait forever
    while (1);

    return 0;
}


static const char *gpio_irq_str[] = {
        "LEVEL_LOW",  // 0x1
        "LEVEL_HIGH", // 0x2
        "EDGE_FALL",  // 0x4
        "EDGE_RISE"   // 0x8
};

void gpio_event_string(char *buf, uint32_t events) {
    for (uint i = 0; i < 4; i++) {
        uint mask = (1 << i);
        if (events & mask) {
            // Copy this event string into the user string
            const char *event_str = gpio_irq_str[i];
            while (*event_str != '\0') {
                *buf++ = *event_str++;
            }
            events &= ~mask;

            // If more events add ", "
            if (events) {
                *buf++ = ',';
                *buf++ = ' ';
            }
        }
    }
    *buf++ = '\0';
}
