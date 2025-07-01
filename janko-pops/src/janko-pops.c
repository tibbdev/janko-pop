#include "janko-pops.h"
#include "board_gpio.h"

const uint32_t FLASH_RATES[] =
{
    50, 100, 250, 500, 1000
};

int16_t janko_pops_init(void)
{
    board_led_off();
    return 0;
}

int16_t janko_pops_tick(uint32_t now)
{
    static uint32_t last_toggled = 0;
    static uint8_t  flash_rate_idx = 2;
    static bool     btn_pressed_old = true;

    bool btn_pressed = board_read_btn();

    if(btn_pressed && (btn_pressed != btn_pressed_old))
    {
        flash_rate_idx++;
        flash_rate_idx %= (sizeof(FLASH_RATES) / sizeof(FLASH_RATES[0]));
    }
    
    btn_pressed_old = btn_pressed;

    if(FLASH_RATES[flash_rate_idx] < (now - last_toggled))
    {
        board_toggle_led();
        last_toggled = now;
    }

    return 0;
}
