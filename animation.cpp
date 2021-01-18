#include "animation.h"

Animation::Animation(){}

Animation::Animation(Configuration *config, CRGB *leds){
  this->config = config;
  this->leds = leds;
}