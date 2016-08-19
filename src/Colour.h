#ifndef COLOUR_H
#define COLOUR_H

#include <string>
#include <cstdint>

class Colour
{
public:
    std::uint8_t red, green, blue;
    std::string findName();
};

#endif
