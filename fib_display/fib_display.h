/*
 * fib_display for Raspberry Pi Pico
 *
 * @version     1.0.0
 * @author      <YOU>
 * @copyright   2023
 * @licence     MIT
 *
 */
#define _FIB_DISPLAY_MAIN_HEADER_
#ifndef _FIB_DISPLAY_MAIN_HEADER_
#define _FIB_DISPLAY_MAIN_HEADER_

/*
 * C HEADERS
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 * PICO HEADERS
 */
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/gpio.h"
#include "hardware/i2c.h"
#include "hardware/spi.h"
#include "hardware/adc.h"
#include "hardware/uart.h"

#endif // _FIB_DISPLAY_MAIN_HEADER_

void print_value(int value, uint pins[], uint num_pins);

void leave_value(int value, uint pins[], uint num_pins, uint delay);

void flash_value(int value, uint pins[], uint num_pins, uint delay);
