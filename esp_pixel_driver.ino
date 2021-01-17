#include "config.h"
#include <Arduino.h>
#include <ArtnetWifi.h>
#include <FastLED.h>
#include <Esp.h>

#ifdef ESP8266
#include <esp8266wifi.h>
#elif defined(ESP32)
#include <WiFi.h>
#endif

//LEDs
CRGB leds[STRIP_LENGTH];

//Calculated Constants
const int channels = STRIP_LENGTH * 3;
const int maxUniverses = channels / 512 + ((channels % 512) ? 1 : 0);

//DMX Handler Globals
ArtnetWifi artnet;
bool universesReceived[maxUniverses];
bool sendFrame = 1;
int previousDataLength = 0;

//Network Config
const IPAddress ip(192, 168, 1, 200);
const IPAddress gateway(192, 168, 1, 1);
const IPAddress subnet(255, 255, 255, 0);

void setup()
{
  //LED Init
  FastLED.addLeds<WS2812, OUTPUT_PIN, RGB>(leds, STRIP_LENGTH);

  //Serial Start
  Serial.begin(115200);
  delay(500);

  //Status - Connecting to Wifi
  status(0);
  setup_wifi();
  artnet.begin();
  delay(500);

  //Status - Waiting for Artnet
  status(1);
  artnet.setArtDmxCallback(onDmxFrame);
  delay(500);
}

void loop()
{
  artnet.read();
  delay(5);
}

void setup_wifi()
{
  WiFi.begin(WIFI_SSID, PASSWORD);
  #ifdef ESP32
  WiFi.setSleep(false);
  #endif
  WiFi.config(ip, gateway, subnet);
  int loop_limit = 30;
  int count = 0;
  while (WiFi.status() != WL_CONNECTED && count < loop_limit)
  {
    Serial.println("-~~<*}(~){*>~~-\n");
    delay(500);
    count++;
  }
  if (count == loop_limit)
  {
    ESP.restart();
  }
  Serial.println("WiFi connected, IP = ");
  Serial.println(WiFi.localIP());
  delay(500);
}

void onDmxFrame(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t *data)
{
  sendFrame = 1;

  // Mark received Universe
  if ((universe - START_UNIVERSE) < maxUniverses)
  {
    universesReceived[universe - START_UNIVERSE] = 1;
  }

  for (int i = 0; i < maxUniverses; i++)
  {
    if (universesReceived[i] == 0)
    {
      // if we're missing an expected universe, do not playback 
      sendFrame = 0;
      break;
    }
  }

  // read universe and put into the right part of the display buffer
  for (int i = 0; i < length / 3; i++)
  {
    int led = i + (universe - START_UNIVERSE) * (previousDataLength / 3);
    if (led < STRIP_LENGTH && OUTPUT_MODE == OUTPUT_MODE_LED)
    {
      leds[led] = CRGB(data[i * 3], data[i * 3 + 1], data[i * 3 + 2]);
      debug_led_output(i, data[i * 3], data[i * 3 + 1], data[i * 3 + 2]);
    }
  }
  previousDataLength = length;

  if (sendFrame)
  {
    FastLED.show();
    // Reset universeReceived to 0
    memset(universesReceived, 0, maxUniverses);
  }
}

void status(uint8_t state)
{
  for (int i = 0; i < STRIP_LENGTH; i++)
  {
    uint8_t g = 0;
    uint8_t r = 0;
    uint8_t b = 0;

    // States
    // 0 - Connecting to Wifi
    // 1 - Waiting For ArtNet
    switch (state)
    {
    case 0:
      r = 255;
      b = 255;
      break;
    case 1:
      g = 255;
    default:
      break;
    }

    if (OUTPUT_MODE == OUTPUT_MODE_LED)
    {
      leds[i] = CRGB(r, g, b);
    }
    debug_led_output(i, r, g, b);
  }
  if (OUTPUT_MODE == OUTPUT_MODE_LED)
  {
    delay(500);
    FastLED.show();
  }
}

void debug_led_output(int i, uint8_t r, uint8_t g, uint8_t b)
{
  if (LOG_LEVEL == LOG_LEVEL_DEBUG)
  {
    char buf[16]; //formatting buffer
    sprintf(buf, "Pixel ID: %u", i);
    Serial.println(buf);

    sprintf(buf, "~~Green: %u", g);
    Serial.println(buf);

    sprintf(buf, "~~Red: %u", r);
    Serial.println(buf);

    sprintf(buf, "~~Blue: %u", b);
    Serial.println(buf);
  }
}
