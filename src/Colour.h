#ifndef COLOUR_H
#define COLOUR_H

#include <string>
#include <cstdint>

class Colour
{
public:
    uint8_t red, green, blue;
    string findName();
};

#endif
