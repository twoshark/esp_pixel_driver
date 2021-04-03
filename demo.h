#ifndef DEMO_H
#define DEMO_H
#include "config.h"
#include <FastLED.h>
#include "animation.h"

class DemoManager
{
public:
  DemoManager();
  DemoManager(Configuration *config, CRGB *leds);
  void Run();

private:
  Configuration *config;
  Animation animations;
};

#endif