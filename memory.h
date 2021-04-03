  
#ifndef MEMORY_H
#define MEMORY_H

#include "config.h"

class Memory
{
  public:
    Memory();
    /**
     * Save
     * @param  {Configuration} config : 
     */
    void Save(Configuration config);
    /**
     * Load
     * @return {Configuration}  : 
     */
    Configuration Load();
};

#endif
