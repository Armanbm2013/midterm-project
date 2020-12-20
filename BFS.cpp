#include "BFS.h"

void BFS(std::vector<size_t> &init, const std::vector<size_t> &goal)
{
    if (init == goal) //when the initial puzzle is the goal puzzle!
    {
        std::cout << "*************************\n";
        std::cout << "******PUZZLE SOLVED******\nNumber of steps: 0 || your initial puzzle is the goal puzzle" << std::endl;
        std::cout << "*************************" << std::endl;
    }
    else
    {
        std::queue<std::vector<size_t>> queue{};    //we use a queue to check each level of the graph in order
        std::vector<std::vector<size_t>> bfs{init}; //we use a vector to store the states that we have traversed, and we use it to prevent traversing one state twice
        queue.push(bfs.back());
        size_t depth{};
        size_t steps{};
        bool in_bfs{false};
        size_t i{}; // position of the empty block(here we use zero instead of empty, but when we print the puzzle, we print " " instead of "0")
        while (true)
        {
            std::vector<size_t> temp = queue.front();
            queue.pop();
            for (size_t j{}; j < 9; j++)
                if (temp[j] == 0)
                    i = j;
            if (i == 0)
            {
                std::vector<size_t> state1 = std::vector<size_t>{temp[1], temp[0], temp[2], temp[3], temp[4], temp[5], temp[6], temp[7], temp[8]};
                for (std::vector<size_t> &puzzle : bfs)
                {
                    if (puzzle == state1)
                    {
                        in_bfs = true;
                        break;
                    }
                }

                if (!in_bfs)
                {
                    steps++;
                    bfs.push_back(state1);
                    queue.push(state1);
                    if (is_goal(state1, goal))
                    {
                        solved(steps, goal);
                        break;
                    }
                    print_puzzle(steps, state1);
                }
                in_bfs = false;

                std::vector<size_t> state2 = std::vector<size_t>{temp[3], temp[1], temp[2], temp[0], temp[4], temp[5], temp[6], temp[7], temp[8]};
                for (std::vector<size_t> &puzzle : bfs)
                {
                    if (puzzle == state2)
                    {
                        in_bfs = true;
                        break;
                    }
                }

                if (!in_bfs)
                {
                    steps++;
                    bfs.push_back(state2);
                    queue.push(state2);
                    if (is_goal(state2, goal))
                    {
                        solved(steps, goal);
                        break;
                    }
                    print_puzzle(steps, state2);
                }
                in_bfs = false;
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

bool is_goal(const std::vector<size_t> &state, const std::vector<size_t> &goal)
{
    return state == goal;
}

void solved(size_t steps, const std::vector<size_t> &goal)
{
    std::cout << "*************************\n";
    std::cout << "******PUZZLE SOLVED******\nNumber of steps: " << steps << std::endl;
    std::cout << "*************************" << std::endl;
    print_puzzle(steps, goal);
    std::cout << "\n*************************" << std::endl;
}

void print_puzzle(size_t steps, const std::vector<size_t> &state)
{
    std::cout << std::endl;
    std::cout << "Step " << steps << ":" << std::endl;
    for (size_t i{}; i < 9; i++)
    {
        std::cout << state[i];
        if (i % 3 == 2)
            std::cout << std::endl;
        else
            std::cout << " ";
    }
}