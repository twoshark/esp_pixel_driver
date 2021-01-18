#include "config.h"

void Configuration::applyOverrides()
{
#ifdef NAME
  this->name = NAME;
#endif
#ifdef DESCRIPTION
  this->descripton = DESCRIPTION;
#endif
#ifdef DEBUG_LOGS
  this->debug_logs = DEBUG_LOGS;
#endif
#ifdef OUTPUT_LEDS
  this->output_leds = OUTPUT_LEDS;
#endif
#ifdef STRIP_LENGTH
  this->strip_length = STRIP_LENGTH;
#endif
#ifdef START_UNIVERSE
  this->start_address = START_UNIVERSE;
#endif
#ifdef CHANNEL_OFFSET
  this->channel_offset = CHANNEL_OFFSET;
#endif
}
