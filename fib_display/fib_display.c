/*
 * fib_display for Raspberry Pi Pico
 *
 * @version     1.0.0
 * @author      <YOU>
 * @copyright   2023
 * @licence     MIT
 *
 */
#include "pico/stdlib.h"
#include "fib_display.h"
#define DELAY 125
#ifndef LED_PIN
#define LED_PIN 15
#endif
#ifndef BOARD_LED
#define BOARD_LED 25
#endif

void print_value(int value, uint pins[], uint num_pins) {
    // Only puts the value on the pins
    // doesn't leave it
    for (int i = 0; i < num_pins; i++) {
        uint ith_bit = value & (1 << i);
        gpio_put(pins[i], ith_bit);
    }
}

void leave_value(int value, uint pins[], uint num_pins, uint delay) {
    // Puts the value on the pins, then waits for delay ms.
    print_value(value, pins, num_pins);
    sleep_ms(delay);
}

void flash_value(int value, uint pins[], uint num_pins, uint delay) {
    // Puts the value on the pins, then waits for delay ms.
    // Then turns the pins off, then waits for delay ms.
    print_value(value, pins, num_pins);
    sleep_ms(delay);
    print_value(0, pins, num_pins);
    sleep_ms(delay);
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

int main() {
    // Use for debugging
    // stdio_init_all();

    // Set up the pins
    uint pins[] = {16, 17, 18, 19, 20, 21, 22, 26};
    // uint pins[] = {16, 17, 19, 20, 21, 22, 23, 24};
    uint num_pins = sizeof(pins) / sizeof(pins[0]);
    for (int i = 0; i < num_pins; i++) {
        gpio_init(pins[i]);
        gpio_set_dir(pins[i], GPIO_OUT);
    }

    // Display the fib sequence
    uint i = 0;
    while (true) {
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
            i = 0;
        }
    }


    return 0;
}
