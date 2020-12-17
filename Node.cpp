#include "Node.h"

Node::Node(Node *u, Node *d, Node *l, Node *r) : up{u}, down{d}, left{l}, right{r}
{
    std::cout << "Node constructor" << std::endl;
}