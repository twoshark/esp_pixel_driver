#ifndef WIFIMANAGER_ADAPTER_H
#define WIFIMANAGER_ADAPTER_H

#include "config.h"
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager/tree/development
#include <Arduino.h>

class IPAddressParameter : public WiFiManagerParameter
{
public:
  IPAddressParameter(const char *id, const char *placeholder, IPAddress address)
      : WiFiManagerParameter("")
  {
    init(id, placeholder, address.toString().c_str(), 16, "", WFM_LABEL_BEFORE);
  }

  bool getValue(IPAddress &ip)
  {
    return ip.fromString(WiFiManagerParameter::getValue());
  }
};

class IntParameter : public WiFiManagerParameter
{
public:
  IntParameter(const char *id, const char *placeholder, long value, const uint8_t length = 10)
      : WiFiManagerParameter("")
  {
    init(id, placeholder, String(value).c_str(), length, "", WFM_LABEL_BEFORE);
  }

  long getValue()
  {
    return String(WiFiManagerParameter::getValue()).toInt();
  }
};

class BoolParameter : public WiFiManagerParameter
{
public:
  BoolParameter(const char *id, const char *placeholder, bool value)
      : WiFiManagerParameter("")
  {
    init(id, placeholder, String(value).c_str(), 16, "", WFM_LABEL_BEFORE);
  }

  bool getValue()
  {
    String value = String(WiFiManagerParameter::getValue());
    return value == "true" || value =="t" || value.toInt() == 1;
  }
};

class WifiManagerAdapter
{
public:
  void setup(Configuration *config);
};

#endif
