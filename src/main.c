#include "gd32vf103.h"
#include "gd32vf103v_eval.h"
#include <stdio.h>

/* RED LED DEFINITIONS */
#define RED_LED_PIN GPIO_PIN_13
#define RED_LED_PORT GPIOC
#define RED_LED_CLOCK RCU_GPIOC

/* GREEN LED DEFINITIONS */
#define GREEN_LED_PIN GPIO_PIN_1
#define GREEN_LED_PORT GPIOA
#define GREEN_LED_CLOCK RCU_GPIOA

/* BLUEE LED DEFINITIONS */
#define BLUE_LED_PIN GPIO_PIN_2
#define BLUE_LED_PORT GPIOA
#define BLUE_LED_CLOCK RCU_GPIOA

int main(void)
{
    /* enable the led clock(s) */
    rcu_periph_clock_enable(RED_LED_CLOCK);
    rcu_periph_clock_enable(GREEN_LED_CLOCK);

    /* configure led GPIO port(s) */
    gpio_init(RED_LED_PORT, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, RED_LED_PIN);
    gpio_init(GREEN_LED_PORT, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GREEN_LED_PIN);
    gpio_init(BLUE_LED_PORT, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, BLUE_LED_PIN);

    gpio_bit_write(RED_LED_PORT, RED_LED_PIN, FALSE);
    gpio_bit_write(GREEN_LED_PORT, GREEN_LED_PIN, FALSE);
    gpio_bit_write(BLUE_LED_PORT, BLUE_LED_PIN, FALSE);

    while (1)
    {
        gpio_bit_write(RED_LED_PORT, RED_LED_PIN, TRUE);
        delay_1ms(300);
        gpio_bit_write(GREEN_LED_PORT, GREEN_LED_PIN, TRUE);
        delay_1ms(300);
        gpio_bit_write(BLUE_LED_PORT, BLUE_LED_PIN, TRUE);
        delay_1ms(1000);

        gpio_bit_write(RED_LED_PORT, RED_LED_PIN, FALSE);
        delay_1ms(300);
        gpio_bit_write(GREEN_LED_PORT, GREEN_LED_PIN, FALSE);
        delay_1ms(300);
        gpio_bit_write(BLUE_LED_PORT, BLUE_LED_PIN, FALSE);
        delay_1ms(1000);
    }
}