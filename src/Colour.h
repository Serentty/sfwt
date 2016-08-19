#ifndef COLOUR_H
#define COLOUR_H

#include <string>
#include <stdint.h>

class Colour
{
public:
    uint8_t red, green, blue;
    std::string findName();
};

#endif
