#ifndef node_h
#define node_h

#include <iostream>
#include <vector>

class Node
{
public:
    Node(Node *u, Node *d, Node *l, Node *r);

    int val{};
    Node *up{nullptr};
    Node *down{nullptr};
    Node *left{nullptr};
    Node *right{nullptr};
};

#endif
