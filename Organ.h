#ifndef ORGAN_H
#define ORGAN_H

#include <vector>

class Resource
{
    double quantity;
};

class Organ
{
   public:
       std::vector<Resource> inputs;
       std::vector<Resource> outputs;
};

#endif