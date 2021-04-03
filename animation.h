#ifndef ANIMATION_H
#define ANIMATION_H

#include "config.h"
#include <FastLED.h>

class Animation
{
public:
  Animation();
  Animation(Configuration *config, CRGB *leds);
  void Fire();

private:
  Configuration *config;
  CRGB *leds;
  byte *heat;
};

#endif