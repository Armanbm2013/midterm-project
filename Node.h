#ifndef node_h
#define node_h

#include <iostream>
#include <vector>

class Node
{
public:
    Node(int i);

    int val{};
    Node *up{nullptr};
    Node *down{nullptr};
    Node *left{nullptr};
    Node *right{nullptr};
};

#endif
