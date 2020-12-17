#include "puzzle8.h"

puzzle8::puzzle8(std::vector<int> &state)
{
    std::cout << "puzzle8 constructor" << std::endl;
    for (size_t i{}; i < 9; i++)
    {
        nodes[i]->val = state[i];
    }
    nodes[0]->up = nullptr;
    nodes[0]->down = nodes[3];
    nodes[0]->left = nullptr;
    nodes[0]->right = nodes[1];
    nodes[1]->up = nullptr;
    nodes[1]->down = nodes[4];
    nodes[1]->left = nodes[0];
    nodes[1]->right = nodes[2];
    nodes[2]->up = nullptr;
    nodes[2]->down = nodes[5];
    nodes[2]->left = nodes[1];
    nodes[2]->right = nullptr;
    nodes[3]->up = nodes[0];
    nodes[3]->down = nodes[6];
    nodes[3]->left = nullptr;
    nodes[3]->right = nodes[4];
    nodes[4]->up = nodes[1];
    nodes[4]->down = nodes[7];
    nodes[4]->left = nodes[3];
    nodes[4]->right = nodes[5];
    nodes[5]->up = nodes[2];
    nodes[5]->down = nodes[8];
    nodes[5]->left = nodes[4];
    nodes[5]->right = nullptr;
    nodes[6]->up = nodes[3];
    nodes[6]->down = nullptr;
    nodes[6]->left = nullptr;
    nodes[6]->right = nodes[7];
    nodes[7]->up = nodes[4];
    nodes[7]->down = nullptr;
    nodes[7]->left = nodes[6];
    nodes[7]->right = nodes[8];
    nodes[8]->up = nodes[5];
    nodes[8]->down = nullptr;
    nodes[8]->left = nodes[7];
    nodes[8]->right = nullptr;
}