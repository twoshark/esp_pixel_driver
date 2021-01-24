#ifndef CONFIG_H
#define CONFIG_H

#include "enums.h"
#include <Arduino.h>

#define OUTPUT_PIN 17
#define MAX_STRIP_LENGTH 500

class Configuration
{
public:
  char *name;
  char *description;
  uint32_t ip;
  uint32_t gateway;
  uint32_t subnet;
  int strip_length;
  int start_universe;
  int channel_offset;
  bool debug_logs;
  bool output_leds;
  void applyOverrides();
};

/*

//override with static values
#define DISABLE_WIFIMANAGER_SETUP

#define DEBUG_LOGS false 
#define OUTPUT_LEDS true

#define NAME "Pixel Driver Deluxe"
#define DESCRIPTION "ESP Pixel Driver"
#define STRIP_LENGTH 250

// Pixel Mapped Output Configuration
#define START_UNIVERSE 1 //DMX Universe to listen in
#define CHANNEL_OFFSET 0 //DMX Start Channel


//#define WIFI_SSID "hfsjdkf"
//#define PASSWORD "sdjfhdskjfn"

*/

#endif
