#include "config.h"

void Configuration::applyOverrides(){
  #ifdef STATIC_CONFIG_OVERRIDES
    #ifdef NAME
    config.name = NAME;
    #endif
    #ifdef DESCRIPTION
    config.descripton = DESCRIPTION;
    #endif
    #ifdef DEBUG_LOGS
    config.debug_logs = DEBUG_LOGS;
    #endif
    #ifdef OUTPUT_LEDS
    config.output_leds = OUTPUT_LEDS;
    #endif
    #ifdef OUTPUT_PIN
    config.output_pin = OUTPUT_PIN;
    #endif
    #ifdef STRIP_LENGTH
    config.name = STRIP_LENGTH;
    #endif
    #ifdef START_UNIVERSE
    config.name = START_UNIVERSE;
    #endif
    #ifdef CHANNEL_OFFSET
    config.name = CHANNEL_OFFSET;
    #endif
  #endif
}