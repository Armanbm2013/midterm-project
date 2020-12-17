#ifndef puzzle8_h
#define puzzle8_h

#include <iostream>
#include <vector>

#include "Node.h"

class puzzle8
{
public:
    puzzle8(std::vector<int> &state);

    std::vector<Node *> nodes{9, nullptr};
};

#endif