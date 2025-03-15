#include "stm32_hal/hal/hal.h"
#include "bitmap.h"
#include <string.h>

#define NUM_OF_BUTTONS 16
volatile uint8_t matrix_buttons[NUM_OF_BUTTONS] = {0};

int main() {
  volatile uint8_t running = 1;

  volatile uint16_t x_counter = 64;
  volatile uint16_t y_counter = 56;
  volatile uint8_t jumping = 0;

  /* Init timer interrupts for other peripheral
   * init and for use as delays in program
   */
  hal_timer_interrupt_init(1000000);
  
  hal_display_init();

  hal_gpio_init();

  /* Copy bitmap from header */
  uint8_t sprite_bmp_copy[64];
  memcpy(sprite_bmp_copy, smiley_binary, 64);

  /* Main program loop */
  while(running) {
    hal_read_write_buttons(matrix_buttons);

    if(matrix_buttons[2]) {
      hal_clear_binary_data(sprite_bmp_copy, 8, 8, x_counter, y_counter);
      x_counter += 8;

      if(x_counter >= 120) {
        x_counter = 120; 
      }
    } else if(matrix_buttons[3]) {
      hal_clear_binary_data(sprite_bmp_copy, 8, 8, x_counter, y_counter);
      x_counter -= 8; 
      
      if(x_counter <= 8) {
        x_counter = 8; 
      }
    }

    if(matrix_buttons[1] && !jumping) {
      hal_clear_binary_data(sprite_bmp_copy, 8, 8, x_counter, y_counter);
      y_counter -= 16; 
      jumping = 1;
    } 

    hal_draw_binary_data(sprite_bmp_copy, 8, 8, x_counter, y_counter);

    /* Draw display buffer to oled */
    hal_buffer_write();

    while(y_counter < 56 && jumping) {

      hal_clear_binary_data(sprite_bmp_copy, 8, 8, x_counter, y_counter);
      y_counter += 8;

      hal_draw_binary_data(sprite_bmp_copy, 8, 8, x_counter, y_counter);

      hal_timer_interrupt_change_delay(1000000);
      hal_timer_interrupt_reset();
      while(!hal_timer_interrupt_check());

      hal_buffer_write();

      if(y_counter >= 56) {
        jumping = 0;
      }
    }
  }

  return 0;
}
