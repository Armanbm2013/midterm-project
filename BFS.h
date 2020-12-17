#ifndef BFS_h
#define BFS_h

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

void BFS(std::vector<int> &init, const std::vector<int> &goal)
{
    std::queue<std::vector<int>> queue{};
    std::vector<std::vector<int>> bfs{init};
    queue.push(bfs.back());
    size_t depth{};
    while (true)
    {
        if (bfs.back() == goal)
        {
            std::cout << "*************************\n";
            std::cout << "******PUZZLE SOLVED******\nNumber of steps: " << bfs.size() - 1 << std::endl;
            std::cout << "*************************" << std::endl;
            break;
        }
        else
        {
            for (size_t i{}; i < 9; i++)
                if (queue.front()[i] == 0)
                {
                }
        }
    }
}

#endif
