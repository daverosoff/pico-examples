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

void print_value(int value, uint pins[], uint num_pins) {

    // for (int i = 0; i < num_pins; i++) {
    //     gpio_put(pins[i], value & 1);
    //     value >>= 1;
    // }

    for (int i = 0; i < num_pins; i++) {
        gpio_put(pins[i], (value >> i) & 1);
    }
}

void leave_value(int value, uint pins[], uint num_pins, uint delay) {
    print_value(value, pins, num_pins);
    sleep_ms(delay);
}

void flash_value(int value, uint pins[], uint num_pins, uint delay) {
    print_value(value, pins, num_pins);
    sleep_ms(delay);
    print_value(0, pins, num_pins);
    sleep_ms(delay);
}

uint fib(uint n) {
    // iterative
    uint a = 0;
    uint b = 1;
    for (int i = 0; i < n; i++) {
        uint temp = a;
        a = b;
        b = temp + b;
    }
    return a;
}

int main() {
    // Use for debugging
    // stdio_init_all();

    // Set up the pins
    // uint pins[] = {16, 17, 18, 19, 20, 21, 22, 26};
    uint pins[] = {16, 17, 19, 20, 21, 22, 23, 24};
    uint num_pins = 8; // sizeof(pins) / sizeof(pins[0]);
    for (int i = 0; i < num_pins; i++) {
        gpio_init(pins[i]);
        gpio_set_dir(pins[i], GPIO_OUT);
    }

    // Bea's program

    while(true) {
        for (int count = 0; count < 3; count++) {
            leave_value(0x01, pins, num_pins, 50);
            leave_value(0x03, pins, num_pins, 50);
            leave_value(0x06, pins, num_pins, 50);
            leave_value(0x0C, pins, num_pins, 50);
            leave_value(0x18, pins, num_pins, 50);
            leave_value(0x30, pins, num_pins, 50);
            leave_value(0x60, pins, num_pins, 50);
            leave_value(0xC0, pins, num_pins, 50);
            leave_value(0x80, pins, num_pins, 100);
            leave_value(0xC0, pins, num_pins, 50);
            leave_value(0x60, pins, num_pins, 50);
            leave_value(0x30, pins, num_pins, 50);
            leave_value(0x18, pins, num_pins, 50);
            leave_value(0x0C, pins, num_pins, 50);
            leave_value(0x06, pins, num_pins, 50);
            leave_value(0x03, pins, num_pins, 50);
            leave_value(0x01, pins, num_pins, 50);
        }
        leave_value(0x00, pins, num_pins, 250);
        for (int count = 0; count < 3; count++) {
            leave_value(0xA0, pins, num_pins, 150);
            leave_value(0x50, pins, num_pins, 150);
            leave_value(0x28, pins, num_pins, 150);
            leave_value(0x14, pins, num_pins, 150);
            leave_value(0x0A, pins, num_pins, 150);
            leave_value(0x05, pins, num_pins, 150);
            leave_value(0x0A, pins, num_pins, 150);
            leave_value(0x14, pins, num_pins, 150);
            leave_value(0x28, pins, num_pins, 150);
            leave_value(0x50, pins, num_pins, 150);
        }
        leave_value(0x00, pins, num_pins, 250);
    }

    // Display the fib sequence
    // uint i = 0;
    // while (true) {
        // uint f = fib(i++);
        // if (f < 0x100) {
            // flash_value(f, pins, num_pins, 250);
        // }
        // else {
            // for (int count = 0; count < 3; count++) {
                // leave_value(0x01, pins, num_pins, 40);
                // leave_value(0x03, pins, num_pins, 40);
                // leave_value(0x06, pins, num_pins, 40);
                // leave_value(0x0C, pins, num_pins, 40);
                // leave_value(0x18, pins, num_pins, 40);
                // leave_value(0x30, pins, num_pins, 40);
                // leave_value(0x60, pins, num_pins, 40);
                // leave_value(0xC0, pins, num_pins, 40);
                // leave_value(0x80, pins, num_pins, 40);
                // leave_value(0xC0, pins, num_pins, 40);
                // leave_value(0x60, pins, num_pins, 40);
                // leave_value(0x30, pins, num_pins, 40);
                // leave_value(0x18, pins, num_pins, 40);
                // leave_value(0x0C, pins, num_pins, 40);
                // leave_value(0x06, pins, num_pins, 40);
                // leave_value(0x03, pins, num_pins, 40);
                // leave_value(0x01, pins, num_pins, 40);
            // }
            // i = 0;
        // }
    // }


    return 0;
}
