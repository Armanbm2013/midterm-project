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

//following code is copied from "https://www.geeksforgeeks.org/check-instance-8-puzzle-solvable/"
// A utility function to count inversions in given vector 'arr'
int getInvCount(const std::vector<size_t> &arr)
{
    int inv_count = 0;
    for (int i = 0; i < 9 - 1; i++)
        for (int j = i + 1; j < 9; j++)
            // Value 0 is used for empty space
            if (arr[j] && arr[i] && arr[i] > arr[j])
                inv_count++;
    return inv_count;
}

// This function returns true if given 8 puzzle is solvable.
bool isSolvable(const std::vector<size_t> &arr)
{
    // Count inversions in given 8 puzzle
    int invCount = getInvCount(arr);

    // return true if inversion count is even.
    return (invCount % 2 == 0);
}