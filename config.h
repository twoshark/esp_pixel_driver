#ifndef CONFIG_H
#define CONFIG_H

#include "util.h"

#define UNIVERSE_PIXEL_MAPPING 1 //DMX Universe to listen in
#define OFFSET_PIXEL_MAPPING 0 //DMX Start Channel

#define UNIVERSE_FIXTURE 2 //DMX Universe to listen in
#define OFFSET_FIXTURE 0 //DMX Start Channel

#define STRIP_LENGTH 30
#define FIXTURE_COUNT 3

#define OUTPUT_MODE OUTPUT_MODE_LED

//Must define:
/*
#define WIFI_SSID "hfsjdkf"
#define PASSWORD "sdjfhdskjfn"
*/
#include "secret.h"

#endif
