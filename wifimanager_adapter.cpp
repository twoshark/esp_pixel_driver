
#include "wifimanager_adapter.h"

void WifiManagerAdapter::setup(Configuration *config)
{
    WiFiManager wm;

    config->name[23] = '\0'; //overflow defense
    config->description[47] = '\0'; //overflow defense

    WiFiManagerParameter param_name("Pixel Driver Name", "Pixel Driver Name", config->name, 24);
    WiFiManagerParameter param_description("Description", "Description", config->description, 48);
    IPAddress ip(config->ip);
    IPAddressParameter param_ip("ip", "Ip", ip);
    IPAddress gateway(config->gateway);
    IPAddressParameter param_gateway("gateway", "Gateway", gateway);
    IPAddress subnet(config->subnet);
    IPAddressParameter param_subnet("subnet", "Subnet", subnet);

    IntParameter param_strip_length("Strip Length", "Strip Length", config->strip_length);
    IntParameter param_start_universe("Start Universe", "Start Universe", config->start_universe);
    IntParameter param_channel_offset("DMX Channel Offset", "DMX Channel Offset", config->channel_offset);
    BoolParameter param_debug_logs("Enable Debug Log Output", "Enable Debug Log Output", config->debug_logs);
    BoolParameter param_output_leds("Enable LED Output", "Enable LED Output", config->output_leds);

    
    wm.addParameter(&param_name);
    wm.addParameter(&param_description);
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

    strncpy(config->name, param_name.getValue(), 24);
    config->name[23] = '\0';
    strncpy(config->description, param_description.getValue(), 48);
    config->name[47] = '\0';

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

    config->strip_length = param_strip_length.getValue();
    config->start_universe = param_start_universe.getValue();
    config->channel_offset = param_channel_offset.getValue();
    config->debug_logs = param_debug_logs.getValue();
    config->output_leds = param_output_leds.getValue();
}
