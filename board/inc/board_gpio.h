#pragma once

#include <stdint.h>
#include <stdbool.h>

bool board_read_btn(void);

void board_set_led(bool value);
void board_toggle_led(void);
void board_led_on(void);
void board_led_off(void);
