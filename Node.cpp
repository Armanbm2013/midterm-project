#include "Node.h"
#include <utility>

Node::Node(std::vector<int> &state)
{
    this->state = std::move(state);
    parents.push_back(this->state);
}

Node::Node(const Node &parent, std::vector<int> &state)
{
    parents = parent.parents;
    this->state = std::move(state);
    parents.push_back(this->state);
}

int Node::operator[](const int &n)
{
    return state[n];
}