#include "demo.h"
DemoManager::DemoManager()
{
}
DemoManager::DemoManager(Configuration *config, CRGB *leds)
{
  this->config = config;
  this->animations = Animations(this->config, leds);
}

void DemoManager::Run()
{
  //todo: select from several demo animations based on config
  this->animations.Fire();
}