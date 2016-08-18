#ifndef ORGAN_H
#define ORGAN_H

#include <vector>
#include "Entity.h"

class Resource
{
    double quantity;
};

class Organ : Entity
{
   public:
       std::vector<Resource> inputs;
       std::vector<Resource> outputs;
};

#endif
