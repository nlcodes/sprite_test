#ifndef BITMAP_H
#define BITMAP_H

#include <stdint.h>

static const uint8_t smiley_binary[64] = {
  0,0,1,1,1,1,0,0, 
  0,1,0,0,0,0,1,0, 
  1,0,1,0,0,1,0,1, 
  1,0,0,0,0,0,0,1, 
  1,0,1,0,0,1,0,1, 
  1,0,0,1,1,0,0,1, 
  0,1,0,0,0,0,1,0, 
  0,0,1,1,1,1,0,0 
};

static const uint8_t sprite_bmp_16px[32] = {
  0x00, 0x00, 
  0x60, 0xf0, 
  0xd8, 0xfc, 
  0xfc, 0xbc, 
  0xbc, 0xfc, 
  0xfc, 0xd8, 
  0xf0, 0x60, 
  0x00, 0x00, 
  0x00, 0x00, 
  0x00, 0x00, 
  0x00, 0x00, 
  0x00, 0x3f, 
  0x3f, 0x30, 
  0x00, 0x00, 
  0x00, 0x00, 
  0x00, 0x00
};

static const uint8_t sprite_bmp_12px[24]  = {
  0x18, 0x3c, 
  0x36, 0x3f, 
  0x3f, 0xef, 
  0xef, 0x3f, 
  0x3f, 0x36, 
  0x3c, 0x18, 
  0x00, 0x00, 
  0x00, 0x00, 
  0x00, 0x0f, 
  0x0f, 0x0c, 
  0x00, 0x00, 
  0x00, 0x00
};

#endif
