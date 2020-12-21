#include "BFS.h"

void BFS(const std::vector<size_t> &init, const std::vector<size_t> &goal)
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

                    std::vector<size_t> state2 = std::vector<size_t>{temp[0], temp[2], temp[1], temp[3], temp[4], temp[5], temp[6], temp[7], temp[8]};
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

                    std::vector<size_t> state3 = std::vector<size_t>{temp[0], temp[4], temp[2], temp[3], temp[1], temp[5], temp[6], temp[7], temp[8]};
                    for (std::vector<size_t> &puzzle : bfs)
                    {
                        if (puzzle == state3)
                        {
                            in_bfs = true;
                            break;
                        }
                    }

                    if (!in_bfs)
                    {
                        steps++;
                        bfs.push_back(state3);
                        queue.push(state3);
                        if (is_goal(state3, goal))
                        {
                            solved(steps, goal);
                            break;
                        }
                        print_puzzle(steps, state3);
                    }
                    in_bfs = false;
                }
                else if (i == 2)
                {
                    std::vector<size_t> state1 = std::vector<size_t>{temp[0], temp[2], temp[1], temp[3], temp[4], temp[5], temp[6], temp[7], temp[8]};
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

                    std::vector<size_t> state2 = std::vector<size_t>{temp[0], temp[1], temp[5], temp[3], temp[4], temp[2], temp[6], temp[7], temp[8]};
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
                else if (i == 3)
                {
                    std::vector<size_t> state1 = std::vector<size_t>{temp[3], temp[1], temp[2], temp[0], temp[4], temp[5], temp[6], temp[7], temp[8]};
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

                    std::vector<size_t> state2 = std::vector<size_t>{temp[0], temp[1], temp[2], temp[4], temp[3], temp[5], temp[6], temp[7], temp[8]};
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

                    std::vector<size_t> state3 = std::vector<size_t>{temp[0], temp[1], temp[2], temp[6], temp[4], temp[5], temp[3], temp[7], temp[8]};
                    for (std::vector<size_t> &puzzle : bfs)
                    {
                        if (puzzle == state3)
                        {
                            in_bfs = true;
                            break;
                        }
                    }

                    if (!in_bfs)
                    {
                        steps++;
                        bfs.push_back(state3);
                        queue.push(state3);
                        if (is_goal(state3, goal))
                        {
                            solved(steps, goal);
                            break;
                        }
                        print_puzzle(steps, state3);
                    }
                    in_bfs = false;
                }
                else if (i == 4)
                {
                    std::vector<size_t> state1 = std::vector<size_t>{temp[0], temp[4], temp[2], temp[3], temp[1], temp[5], temp[6], temp[7], temp[8]};
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

                    std::vector<size_t> state2 = std::vector<size_t>{temp[0], temp[1], temp[2], temp[4], temp[3], temp[5], temp[6], temp[7], temp[8]};
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

                    std::vector<size_t> state3 = std::vector<size_t>{temp[0], temp[1], temp[2], temp[3], temp[5], temp[4], temp[6], temp[7], temp[8]};
                    for (std::vector<size_t> &puzzle : bfs)
                    {
                        if (puzzle == state3)
                        {
                            in_bfs = true;
                            break;
                        }
                    }

                    if (!in_bfs)
                    {
                        steps++;
                        bfs.push_back(state3);
                        queue.push(state3);
                        if (is_goal(state3, goal))
                        {
                            solved(steps, goal);
                            break;
                        }
                        print_puzzle(steps, state3);
                    }
                    in_bfs = false;

                    std::vector<size_t> state4 = std::vector<size_t>{temp[0], temp[1], temp[2], temp[3], temp[7], temp[5], temp[6], temp[4], temp[8]};
                    for (std::vector<size_t> &puzzle : bfs)
                    {
                        if (puzzle == state4)
                        {
                            in_bfs = true;
                            break;
                        }
                    }

                    if (!in_bfs)
                    {
                        steps++;
                        bfs.push_back(state4);
                        queue.push(state4);
                        if (is_goal(state4, goal))
                        {
                            solved(steps, goal);
                            break;
                        }
                        print_puzzle(steps, state4);
                    }
                    in_bfs = false;
                }
                else if (i == 5)
                {
                    std::vector<size_t> state1 = std::vector<size_t>{temp[0], temp[1], temp[5], temp[3], temp[4], temp[2], temp[6], temp[7], temp[8]};
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

                    std::vector<size_t> state2 = std::vector<size_t>{temp[0], temp[1], temp[2], temp[3], temp[5], temp[4], temp[6], temp[7], temp[8]};
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

                    std::vector<size_t> state3 = std::vector<size_t>{temp[0], temp[1], temp[2], temp[3], temp[4], temp[8], temp[6], temp[7], temp[5]};
                    for (std::vector<size_t> &puzzle : bfs)
                    {
                        if (puzzle == state3)
                        {
                            in_bfs = true;
                            break;
                        }
                    }

                    if (!in_bfs)
                    {
                        steps++;
                        bfs.push_back(state3);
                        queue.push(state3);
                        if (is_goal(state3, goal))
                        {
                            solved(steps, goal);
                            break;
                        }
                        print_puzzle(steps, state3);
                    }
                    in_bfs = false;
                }
                else if (i == 6)
                {
                    std::vector<size_t> state1 = std::vector<size_t>{temp[0], temp[1], temp[2], temp[6], temp[4], temp[5], temp[3], temp[7], temp[8]};
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

                    std::vector<size_t> state2 = std::vector<size_t>{temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[7], temp[6], temp[8]};
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
                else if (i == 7)
                {
                    std::vector<size_t> state1 = std::vector<size_t>{temp[0], temp[1], temp[2], temp[3], temp[7], temp[5], temp[6], temp[4], temp[8]};
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

                    std::vector<size_t> state2 = std::vector<size_t>{temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[7], temp[6], temp[8]};
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

                    std::vector<size_t> state3 = std::vector<size_t>{temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[6], temp[8], temp[7]};
                    for (std::vector<size_t> &puzzle : bfs)
                    {
                        if (puzzle == state3)
                        {
                            in_bfs = true;
                            break;
                        }
                    }

                    if (!in_bfs)
                    {
                        steps++;
                        bfs.push_back(state3);
                        queue.push(state3);
                        if (is_goal(state3, goal))
                        {
                            solved(steps, goal);
                            break;
                        }
                        print_puzzle(steps, state3);
                    }
                    in_bfs = false;
                }
                else if (i == 8)
                {
                    std::vector<size_t> state1 = std::vector<size_t>{temp[0], temp[1], temp[2], temp[3], temp[4], temp[8], temp[6], temp[7], temp[5]};
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

                    std::vector<size_t> state2 = std::vector<size_t>{temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[6], temp[8], temp[7]};
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
            }
            else
                break;
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
    std::cout << "******PUZZLE SOLVED******\nNumber of steps: " << steps;
    std::cout << "\n*************************\n";
    print_puzzle(steps, goal);
    std::cout << "\n*************************\n";
}

void print_puzzle(size_t steps, const std::vector<size_t> &state)
{
    std::cout << std::endl;
    std::cout << "Step " << steps << ":\n";
    for (size_t i{}; i < 9; i++)
    {
        if (state[i] == 0)
            std::cout << " ";
        else
            std::cout << state[i];
        if (i % 3 == 2)
            std::cout << "\n";
        else
            std::cout << " ";
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