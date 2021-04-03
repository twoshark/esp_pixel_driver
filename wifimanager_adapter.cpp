
#include "wifimanager_adapter.h"

void WifiManagerAdapter::setup(Configuration *config)
{
    WiFiManager wm;

    IPAddress ip(config->ip);
    IPAddressParameter param_ip("ip", "Ip", ip);
    IPAddress gateway(config->gateway);
    IPAddressParameter param_gateway("gateway", "Gateway", gateway);
    IPAddress subnet(config->subnet);
    IPAddressParameter param_subnet("subnet", "Subnet", subnet);
    Serial.println("After IPS");

    IntParameter param_strip_length("Strip Length", "Strip Length", config->strip_length);
    
    IntParameter param_start_universe("Start Universe", "Start Universe", config->start_universe);
    
    IntParameter param_channel_offset("DMX Channel Offset", "DMX Channel Offset", config->channel_offset);
    
    BoolParameter param_debug_logs("Enable Debug Log Output", "Enable Debug Log Output", config->debug_logs);
    
    BoolParameter param_output_leds("Enable LED Output", "Enable LED Output", config->output_leds);
    
    wm.addParameter(&param_ip);
    wm.addParameter(&param_gateway);
    wm.addParameter(&param_subnet);

    wm.addParameter(&param_strip_length);
    wm.addParameter(&param_start_universe);
    wm.addParameter(&param_channel_offset);
    wm.addParameter(&param_debug_logs);
    wm.addParameter(&param_output_leds);

    //SSID & password parameters already included
    wm.startConfigPortal();

    if (param_ip.getValue(ip))
    {
        config->ip = ip;

        Serial.print("IP param: ");
        Serial.println(ip);
    }
    else
    {
        Serial.println("Invalid or Missing IP.");
    }

    if (param_gateway.getValue(gateway))
    {
        config->gateway = gateway;

        Serial.print("Gateway param: ");
        Serial.println(gateway);
    }
    else
    {
        Serial.println("Invalid or Missing Gateway.");
    }

    if (param_subnet.getValue(subnet))
    {
        config->subnet = subnet;

        Serial.print("Subnet param: ");
        Serial.println(subnet);
    }
    else
    {
        Serial.println("Invalid or Missing Subnet.");
    }

    if (param_strip_length.getValue() && (param_strip_length.getValue() > MAX_STRIP_LENGTH))
    {
        config->strip_length = param_strip_length.getValue();

        Serial.println("Strip Length: ");
        Serial.println(config->strip_length);
    }
    else
    {

        Serial.println("Strip Length: ");
        Serial.println("Invalid or Missing.");
    }

    if (param_start_universe.getValue() && param_start_universe.getValue() >= 0)
    {
        config->start_universe = param_start_universe.getValue();

        Serial.println("Start Universe: ");
        Serial.println(config->start_universe);
    }
    else
    {

        Serial.println("Start Universe: ");
        Serial.println("Invalid or Missing.");
    }

    if (param_channel_offset.getValue() && param_channel_offset.getValue() >= 0 && param_channel_offset.getValue() < 512)
    {
        config->channel_offset = param_channel_offset.getValue();

        Serial.println("Channel Offset: ");
        Serial.println(config->channel_offset);
    }
    else
    {
        Serial.println("Channel Offset: ");
        Serial.println("Invalid or Missing.");
    }

    config->output_leds = param_output_leds.getValue();
    if (config->output_leds)
    {
        Serial.println("LED Output: ACTIVE ");
    }
    else
    {
        Serial.println("LED Output: OFF ");
    }
    
    config->debug_logs = param_debug_logs.getValue();
    if (config->debug_logs)
    {
        Serial.println("Debug Output: ACTIVE ");
    }
    else
    {
        Serial.println("Debug Output: OFF ");
    }
}
