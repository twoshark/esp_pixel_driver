#ifndef PIXEL_SERVER_H
#define PIXEL_SERVER_H
#ifdef ESP8266
#include <esp8266wifi.h>
#include <ESP8266WebServer.h>
#elif defined(ESP32)
#include <WiFi.h>
#include <WebServer.h>
#endif

#include <DNSServer.h>
#include "config.h"

class PixelServer
{
public:
  /**
   * Listen - check for and serve clients
   */
  void Listen(Configuration config);
  void begin();
};

#endif