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
#define BOARD_LED PICO_DEFAULT_LED_PIN

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

void blinks(uint n, uint led_pins[], uint num_pins) {
    for (int i = 0; i < num_pins; i++) {
        gpio_put(led_pins[i], 1);
    }
    gpio_put(BOARD_LED, 1);
    sleep_ms(250);
    for (int i = 0; i < num_pins; i++) {
        gpio_put(led_pins[i], 0);
        gpio_put(BOARD_LED, 0);
        sleep_ms(250);
    }
    sleep_ms(500);
}
