#include "stm32_hal/hal/hal.h"
#include "bitmap.h"
#include <string.h>

#define NUM_OF_BUTTONS 16

volatile uint8_t matrix_buttons[NUM_OF_BUTTONS] = {0};

int main() {
  volatile uint8_t running = 1;

  /* Init timer interrupts for other peripheral
   * init and for use as delays in program
   */
  hal_timer_interrupt_init(1000000);
  
  hal_display_init();

  hal_gpio_init();

  /* Copy bitmap from header */
  uint8_t sprite_bmp_copy[32];
  memcpy(sprite_bmp_copy, sprite_bmp, 32);

  volatile uint16_t counter = 0;

  /* Main program loop */
  while(running) {
    hal_read_write_buttons(matrix_buttons);

    if(matrix_buttons[2] == 1) {
      counter++;

      hal_led_on_off(1);
      hal_timer_interrupt_change_delay(1000000);
      hal_timer_interrupt_reset();
      while(!hal_timer_interrupt_check());
      hal_led_on_off(0);
    } else if(matrix_buttons[3]) {
      counter--; 

      hal_led_on_off(1);
      hal_timer_interrupt_change_delay(1000000);
      hal_timer_interrupt_reset();
      while(!hal_timer_interrupt_check());
      hal_led_on_off(0);
    }
    
    hal_display_write(sprite_bmp_copy, 4, counter, 16, 2);
  }

  return 0;
}
