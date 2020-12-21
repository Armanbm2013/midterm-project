#include "BFS.h"

void another_algorithm_BFS(const std::vector<size_t> &init, const std::vector<size_t> &goal)
{
    if (init == goal) //when the initial puzzle is the goal puzzle!
    {
        std::cout << "*************************\n";
        std::cout << "******PUZZLE SOLVED******\nNumber of steps: 0 || your initial puzzle is the goal puzzle\n";
        std::cout << "*************************\n";
    }
    else
    {
        std::queue<std::vector<size_t>> queue{};    //we use a queue to check each level of the graph in order
        std::vector<std::vector<size_t>> bfs{init}; //we use a vector to store the states that we have traversed, and we use it to prevent traversing one state twice
        queue.push(bfs.back());
        size_t steps{};
        bool in_bfs{false};
        size_t i{}; // position of the empty block(here we use zero instead of empty, but when we print the puzzle, we print " " instead of "0")
        while (true)
        {
            if (!queue.empty())
            {
                std::vector<size_t> temp = queue.front();
                queue.pop();

                if (is_goal_1(temp, goal))
                {
                }
                else
                {
                    std::queue<std::vector<size_t>> queue1{};    //a queue for to find a node a that is_goal_1(a,goal) is true
                    std::vector<std::vector<size_t>> bfs1{temp}; //a vector to store all of traveresed states until finding the node a that is_goal_1(a,goal) is true
                    queue1.push(bfs1.back());
                    bool in_bfs1{false};
                    while (true)
                    {
                    }
                }
            }
            else
                break;
        }
    }
}

bool is_goal_1(const std::vector<size_t> &state, const std::vector<size_t> &goal)
{
    return state[0] == goal[0];
}

bool is_goal_2(const std::vector<size_t> &state, const std::vector<size_t> &goal)
{
    return state[1] == goal[1] && state[2] == goal[2];
}

bool is_goal_3(const std::vector<size_t> &state, const std::vector<size_t> &goal)
{
    return state[3] == goal[3] && state[6] == goal[6];
}

bool is_goal_4(const std::vector<size_t> &state, const std::vector<size_t> &goal)
{
    return state[4] == goal[4] && state[5] == goal[5] && state[7] == goal[7] && state[8] == goal[8];
}
