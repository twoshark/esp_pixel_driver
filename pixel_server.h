#ifndef PIXEL_SERVER_H
#define PIXEL_SERVER_H
#ifdef ESP8266
#include <esp8266wifi.h>
#include <ESP8266WebServer.h>
#include <DNSServer.h>
#elif defined(ESP32)
#include <WiFi.h>
#include <WebServer.h>
#endif

#include "config.h"

class PixelServer
{
public:
  Configuration *config;
  void Listen();
  void begin();
};

#endif
