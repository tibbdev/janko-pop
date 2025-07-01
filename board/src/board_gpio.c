#include "board_gpio.h"

#include "main.h"

bool board_read_btn(void)
{
    if(BTN_GPIO_Port->IDR & BTN_Pin)
        return true;

    return false;
}

void board_set_led(bool value)
{
    if(value)
    {
        LED_GPIO_Port->ODR |= LED_Pin;
        return;
    }
    
    LED_GPIO_Port->ODR &= ~LED_Pin;
}

void board_toggle_led(void)
{
    if(LED_GPIO_Port->ODR & LED_Pin)
    {
        LED_GPIO_Port->ODR &= ~LED_Pin;
        return;
    }

    LED_GPIO_Port->ODR |= LED_Pin;
}

void board_led_on(void)
{
    LED_GPIO_Port->ODR |= LED_Pin;
}

void board_led_off(void)
{
    LED_GPIO_Port->ODR &= ~LED_Pin;
}
