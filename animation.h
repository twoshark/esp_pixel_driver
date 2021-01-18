#ifndef ANIMATION_H
#define ANIMATION_H

#include "config.h"
#include <FastLED.h>

class Animations
{
public:
  Animations();
  Animations(Configuration *config, CRGB *leds);
  void Fire();

private:
  Configuration *config;
  CRGB *leds;
  byte *heat;
};

#endif