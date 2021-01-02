#include "Node.h"

Node::Node(std::vector<int> &state)
{
    this->state = move(state);
    parents.push_back(this->state);
}

Node::Node(const Node &parent, std::vector<int> &state)
{
    parents = parent.parents;
    this->state = move(state);
    parents.push_back(this->state);
}