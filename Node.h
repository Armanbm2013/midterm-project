#ifndef Node_H
#define Node_H

#include <iostream>
#include <vector>

class Node
{
public:
    Node(std::vector<int> &state);
    Node(const Node &parent, std::vector<int> &state);

    std::vector<int> state{};
    std::vector<std::vector<int>> parents{};
};

#endif