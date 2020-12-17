#ifndef BFS_h
#define BFS_h

#include <queue>
#include <stack>

#include "puzzle8.h"

void BFS(puzzle8 &init, const std::vector<int> &goal)
{
    std::queue<puzzle8> queue{};
    std::vector<puzzle8> bfs{init};
    queue.push(bfs.back());
    size_t depth{};
    while (true)
    {
        if (bfs.back().state == goal)
        {
            std::cout << "*************************\n";
            std::cout << "******PUZZLE SOLVED******\nNumber of steps: " << bfs.size() - 1 << std::endl;
            std::cout << "*************************" << std::endl;
            break;
        }
        else
        {
            for (size_t i{}; i < 9; i++)
                if (queue.front().state[i] == 0)
                {
                }
        }
    }
}

#endif
