#include "animation.h"

// COOLING: How much does the air cool as it rises?
// Less cooling = taller flames.  More cooling = shorter flames.
// Default 55, suggested range 20-100 
#define COOLING  55

// SPARKING: What chance (out of 255) is there that a new spark will be lit?
// Higher chance = more roaring fire.  Lower chance = more flickery fire.
// Default 120, suggested range 50-200.
#define SPARKING 120
#define REVERSE false

CRGBPalette16 palette;

Animations::Animations(){}

Animations::Animations(Configuration *config, CRGB *leds){
  this->config = config;
  this->leds = leds;
  this->heat = (byte*)malloc(sizeof(byte)*this->config->strip_length);
}

void Animations::Fire()
{
  static const int pixels = this->config->strip_length;

  // Step 1.  Cool down every cell a little
    for( int i = 0; i < pixels; i++) {
      heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / pixels) + 2));
    }
  
    // Step 2.  Heat from each cell drifts 'up' and diffuses a little
    for( int k= pixels - 1; k >= 2; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }
    
    // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
    if( random8() < SPARKING ) {
      int y = random8(7);
      heat[y] = qadd8( heat[y], random8(160,255) );
    }

    // Step 4.  Map from heat cells to LED colors
    for( int j = 0; j < pixels; j++) {
      // Scale the heat value from 0-255 down to 0-240
      // for best results with color palettes.
      byte colorindex = scale8( heat[j], 240);
      CRGB color = ColorFromPalette( palette, colorindex);
      int pixelnumber;
      if( REVERSE ) {
        pixelnumber = (pixels-1) - j;
      } else {
        pixelnumber = j;
      }
      leds[pixelnumber] = color;
    }
}