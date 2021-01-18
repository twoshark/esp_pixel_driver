# Esp Pixel Driver

Artnet LED Pixel Driver for the ESP8266 & ESP32 Microcontrollers.

<!-- markdownlint-disable MD001 -->

### Pixel Mapped Artnet Stream

<!-- markdownlint-enable MD001 -->

The pixel mapped artnet subscriber expects 3 channels of color data per pixel to be applied directly to particular leds.

| <-- Pixel Start Channel \
| `Red` | `Green` | `Blue` |

### Strip Length & DMX Universes

In order to prevent phasing between pixels in different universes, the driver will not update the strand until _all_ expected universes are received. The number of expected universes maybe calculated with the following formula:

``` cpp
  expectedUniverses = pixels / 170 + ((pixels % 170) ? 1 : 0);
```

## Configuration

This pixel driver allows for configuration via webform & via macros in `config.h`

### Output Pin

Output pins for FastLED must be constant at compile time. `#define` the following in `config.h`:

| Parameter  | Variable   | Type | Notes           |
| ---------- | ---------- | ---- | --------------- |
| Output Pin | OUTPUT_PIN | int  | ESP GPIO Number |

### Startup Form

This pixel driver uses an ESP32 compatible branch of [WiFi Manager](https://github.com/tzapu/WiFiManager/tree/development). On device start, the ESP will broadcast a wifi network & serve a webpage at `192.168.4.1`. Network details and configuration for the pixel driver may be entered in that form.

### Static

Configuration values may be preconfigured by setting any of the following values in `config.h` before uploading to your microcontroller.

| Parameter                 | Variable                  | Type   | Notes                             |
| ------------------------- | ------------------------- | ------ | --------------------------------- |
| Disable WifiManager Setup | DISABLE_WIFIMANAGER_SETUP | --     | `#define` to activate             |
| Serial Log Level          | DEBUG_LOGS                | bool   | Activating may impact performance |
| Enable LED Output         | OUTPUT_LEDS               | bool   |                                   |
| LED Strip Length          | STRIP_LENGTH              | int    |                                   |
| Start Universe            | START_UNIVERSE            | int    |                                   |
| Start Channel             | CHANNEL_OFFSET            | int    |                                   |
| Wifi Network SSID         | WIFI_SSID                 | char[] |                                   |
| Wifi Password             | PASSWORD                  | char[] |                                   |
