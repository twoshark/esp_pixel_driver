#include "config.h"
#include "memory.h"
#include <EEPROM.h>

Memory::Memory()
{
  EEPROM.begin(512);
}

Configuration Memory::Load()
{
  Configuration c;
  EEPROM.get(0, c);
  return c;
}

void Memory::Save(Configuration config)
{
  EEPROM.put(0, config);
  if (EEPROM.commit())
  {
    Serial.println("Settings saved");
  }
  else
  {
    Serial.println("EEPROM error");
  }
}
