#include "BFS.h"

void BFS(std::vector<size_t> &init, const std::vector<size_t> &goal)
{
    if (init == goal)
    {
        std::cout << "*************************\n";
        std::cout << "******PUZZLE SOLVED******\nNumber of steps: 0 || your initial puzzle is the goal puzzle" << std::endl;
        std::cout << "*************************" << std::endl;
    }
    else
    {
        std::queue<std::vector<size_t>> queue{};
        std::vector<std::vector<size_t>> bfs{init};
        queue.push(bfs.back());
        size_t depth{};
        while (true)
        {
            size_t i{};
            for (size_t j{}; j < 9; j++)
                if (queue.front()[i] == 0)
                    i = j;
            if (i == 0)
            {
            }
            else if (i == 1)
            {
            }
            else if (i == 2)
            {
            }
            else if (i == 3)
            {
            }
            else if (i == 4)
            {
            }
            else if (i == 5)
            {
            }
            else if (i == 6)
            {
            }
            else if (i == 7)
            {
            }
            else if (i == 8)
            {
            }
        }
    }
}