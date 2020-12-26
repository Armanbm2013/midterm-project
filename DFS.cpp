#include "DFS.h"
#include "BFS.h"

void DFS(const std::vector<size_t> &init, const std::vector<size_t> &goal)
{
    if (!isSolvable(init))
    {
        std::cout << "\033[0;31m"; //red
        std::cout << "*************************\n";
        std::cout << "This puzzle is not solvable\n";
        std::cout << "*************************\n";
        std::cout << "\033[0;37m"; //gray
    }
    else if (init == goal) //when the initial puzzle is the goal puzzle!
    {
        std::cout << "\033[0;32m"; //green
        std::cout << "*************************\n";
        std::cout << "******PUZZLE SOLVED******\nNumber of steps: 0 || your initial puzzle is the goal puzzle\n";
        std::cout << "*************************\n";
        std::cout << "\033[0;37m"; //gray
    }
    else
    {
        std::stack<std::vector<size_t>> stack{};    //we use a stack to check each Depth of the graph in order
        std::vector<std::vector<size_t>> dfs{init}; //we use a vector to store the states that we have traversed, and we use it to prevent traversing one state twice
        stack.push(dfs.back());
        size_t steps{};
        Process_DFS(goal, dfs, stack, steps);
    }
}

bool Process_DFS(const std::vector<size_t> &goal, std::vector<std::vector<size_t>> &dfs, std::stack<std::vector<size_t>> &stack, size_t &steps)
{
    bool in_dfs{false};
    size_t i{}; // position of the empty block(here we use zero instead of empty, but when we print the puzzle, we print " " instead of "0")
    std::vector<size_t> temp = stack.top();
    stack.pop();
    for (size_t j{}; j < 9; j++)
        if (temp[j] == 0)
        {
            i = j;
            break;
        }

    if (i == 0)
    {
        std::vector<size_t> state1 = std::vector<size_t>{temp[1], temp[0], temp[2], temp[3], temp[4], temp[5], temp[6], temp[7], temp[8]};
        for (std::vector<size_t> &puzzle : dfs)
            if (puzzle[0] == state1[0])
                if (puzzle[1] == state1[1])
                    if (puzzle[2] == state1[2])
                        if (puzzle[3] == state1[3])
                            if (puzzle[4] == state1[4])
                                if (puzzle[5] == state1[5])
                                    if (puzzle[6] == state1[6])
                                        if (puzzle[7] == state1[7])
                                            if (puzzle[8] == state1[8])
                                            {
                                                in_dfs = true;
                                                break;
                                            }

        if (!in_dfs)
        {
            steps++;
            dfs.push_back(state1);
            stack.push(state1);
            if (is_goal(state1, goal))
            {
                solved(steps, goal);
                return true;
            }
            print_puzzle(steps, state1);
            if (Process_DFS(goal, dfs, stack, steps))
                return true;
        }
        in_dfs = false;

        std::vector<size_t> state2 = std::vector<size_t>{temp[3], temp[1], temp[2], temp[0], temp[4], temp[5], temp[6], temp[7], temp[8]};
        for (std::vector<size_t> &puzzle : dfs)
            if (puzzle[0] == state2[0])
                if (puzzle[1] == state2[1])
                    if (puzzle[2] == state2[2])
                        if (puzzle[3] == state2[3])
                            if (puzzle[4] == state2[4])
                                if (puzzle[5] == state2[5])
                                    if (puzzle[6] == state2[6])
                                        if (puzzle[7] == state2[7])
                                            if (puzzle[8] == state2[8])
                                            {
                                                in_dfs = true;
                                                break;
                                            }

        if (!in_dfs)
        {
            steps++;
            dfs.push_back(state2);
            stack.push(state2);
            if (is_goal(state2, goal))
            {
                solved(steps, goal);
                return true;
            }
            print_puzzle(steps, state2);
            if (Process_DFS(goal, dfs, stack, steps))
                return true;
        }
        in_dfs = false;
    }

    else if (i == 1)
    {
        std::vector<size_t> state1 = std::vector<size_t>{temp[1], temp[0], temp[2], temp[3], temp[4], temp[5], temp[6], temp[7], temp[8]};
        for (std::vector<size_t> &puzzle : dfs)
            if (puzzle[0] == state1[0])
                if (puzzle[1] == state1[1])
                    if (puzzle[2] == state1[2])
                        if (puzzle[3] == state1[3])
                            if (puzzle[4] == state1[4])
                                if (puzzle[5] == state1[5])
                                    if (puzzle[6] == state1[6])
                                        if (puzzle[7] == state1[7])
                                            if (puzzle[8] == state1[8])
                                            {
                                                in_dfs = true;
                                                break;
                                            }

        if (!in_dfs)
        {
            steps++;
            dfs.push_back(state1);
            stack.push(state1);
            if (is_goal(state1, goal))
            {
                solved(steps, goal);
                return true;
            }
            print_puzzle(steps, state1);
            if (Process_DFS(goal, dfs, stack, steps))
                return true;
        }
        in_dfs = false;

        std::vector<size_t> state2 = std::vector<size_t>{temp[0], temp[2], temp[1], temp[3], temp[4], temp[5], temp[6], temp[7], temp[8]};
        for (std::vector<size_t> &puzzle : dfs)
            if (puzzle[0] == state2[0])
                if (puzzle[1] == state2[1])
                    if (puzzle[2] == state2[2])
                        if (puzzle[3] == state2[3])
                            if (puzzle[4] == state2[4])
                                if (puzzle[5] == state2[5])
                                    if (puzzle[6] == state2[6])
                                        if (puzzle[7] == state2[7])
                                            if (puzzle[8] == state2[8])
                                            {
                                                in_dfs = true;
                                                break;
                                            }

        if (!in_dfs)
        {
            steps++;
            dfs.push_back(state2);
            stack.push(state2);
            if (is_goal(state2, goal))
            {
                solved(steps, goal);
                return true;
            }
            print_puzzle(steps, state2);
            if (Process_DFS(goal, dfs, stack, steps))
                return true;
        }
        in_dfs = false;

        std::vector<size_t> state3 = std::vector<size_t>{temp[0], temp[4], temp[2], temp[3], temp[1], temp[5], temp[6], temp[7], temp[8]};
        for (std::vector<size_t> &puzzle : dfs)
            if (puzzle[0] == state3[0])
                if (puzzle[1] == state3[1])
                    if (puzzle[2] == state3[2])
                        if (puzzle[3] == state3[3])
                            if (puzzle[4] == state3[4])
                                if (puzzle[5] == state3[5])
                                    if (puzzle[6] == state3[6])
                                        if (puzzle[7] == state3[7])
                                            if (puzzle[8] == state3[8])
                                            {
                                                in_dfs = true;
                                                break;
                                            }

        if (!in_dfs)
        {
            steps++;
            dfs.push_back(state3);
            stack.push(state3);
            if (is_goal(state3, goal))
            {
                solved(steps, goal);
                return true;
            }
            print_puzzle(steps, state3);
            if (Process_DFS(goal, dfs, stack, steps))
                return true;
        }
        in_dfs = false;
    }
    else if (i == 2)
    {
        std::vector<size_t> state1 = std::vector<size_t>{temp[0], temp[2], temp[1], temp[3], temp[4], temp[5], temp[6], temp[7], temp[8]};
        for (std::vector<size_t> &puzzle : dfs)
            if (puzzle[0] == state1[0])
                if (puzzle[1] == state1[1])
                    if (puzzle[2] == state1[2])
                        if (puzzle[3] == state1[3])
                            if (puzzle[4] == state1[4])
                                if (puzzle[5] == state1[5])
                                    if (puzzle[6] == state1[6])
                                        if (puzzle[7] == state1[7])
                                            if (puzzle[8] == state1[8])
                                            {
                                                in_dfs = true;
                                                break;
                                            }

        if (!in_dfs)
        {
            steps++;
            dfs.push_back(state1);
            stack.push(state1);
            if (is_goal(state1, goal))
            {
                solved(steps, goal);
                return true;
            }
            print_puzzle(steps, state1);
            if (Process_DFS(goal, dfs, stack, steps))
                return true;
        }
        in_dfs = false;

        std::vector<size_t> state2 = std::vector<size_t>{temp[0], temp[1], temp[5], temp[3], temp[4], temp[2], temp[6], temp[7], temp[8]};
        for (std::vector<size_t> &puzzle : dfs)
            if (puzzle[0] == state2[0])
                if (puzzle[1] == state2[1])
                    if (puzzle[2] == state2[2])
                        if (puzzle[3] == state2[3])
                            if (puzzle[4] == state2[4])
                                if (puzzle[5] == state2[5])
                                    if (puzzle[6] == state2[6])
                                        if (puzzle[7] == state2[7])
                                            if (puzzle[8] == state2[8])
                                            {
                                                in_dfs = true;
                                                break;
                                            }

        if (!in_dfs)
        {
            steps++;
            dfs.push_back(state2);
            stack.push(state2);
            if (is_goal(state2, goal))
            {
                solved(steps, goal);
                return true;
            }
            print_puzzle(steps, state2);
            if (Process_DFS(goal, dfs, stack, steps))
                return true;
        }
        in_dfs = false;
    }
    else if (i == 3)
    {
        std::vector<size_t> state1 = std::vector<size_t>{temp[3], temp[1], temp[2], temp[0], temp[4], temp[5], temp[6], temp[7], temp[8]};
        for (std::vector<size_t> &puzzle : dfs)
            if (puzzle[0] == state1[0])
                if (puzzle[1] == state1[1])
                    if (puzzle[2] == state1[2])
                        if (puzzle[3] == state1[3])
                            if (puzzle[4] == state1[4])
                                if (puzzle[5] == state1[5])
                                    if (puzzle[6] == state1[6])
                                        if (puzzle[7] == state1[7])
                                            if (puzzle[8] == state1[8])
                                            {
                                                in_dfs = true;
                                                break;
                                            }

        if (!in_dfs)
        {
            steps++;
            dfs.push_back(state1);
            stack.push(state1);
            if (is_goal(state1, goal))
            {
                solved(steps, goal);
                return true;
            }
            print_puzzle(steps, state1);
            if (Process_DFS(goal, dfs, stack, steps))
                return true;
        }
        in_dfs = false;

        std::vector<size_t> state2 = std::vector<size_t>{temp[0], temp[1], temp[2], temp[4], temp[3], temp[5], temp[6], temp[7], temp[8]};
        for (std::vector<size_t> &puzzle : dfs)
            if (puzzle[0] == state2[0])
                if (puzzle[1] == state2[1])
                    if (puzzle[2] == state2[2])
                        if (puzzle[3] == state2[3])
                            if (puzzle[4] == state2[4])
                                if (puzzle[5] == state2[5])
                                    if (puzzle[6] == state2[6])
                                        if (puzzle[7] == state2[7])
                                            if (puzzle[8] == state2[8])
                                            {
                                                in_dfs = true;
                                                break;
                                            }

        if (!in_dfs)
        {
            steps++;
            dfs.push_back(state2);
            stack.push(state2);
            if (is_goal(state2, goal))
            {
                solved(steps, goal);
                return true;
            }
            print_puzzle(steps, state2);
            if (Process_DFS(goal, dfs, stack, steps))
                return true;
        }
        in_dfs = false;

        std::vector<size_t> state3 = std::vector<size_t>{temp[0], temp[1], temp[2], temp[6], temp[4], temp[5], temp[3], temp[7], temp[8]};
        for (std::vector<size_t> &puzzle : dfs)
            if (puzzle[0] == state3[0])
                if (puzzle[1] == state3[1])
                    if (puzzle[2] == state3[2])
                        if (puzzle[3] == state3[3])
                            if (puzzle[4] == state3[4])
                                if (puzzle[5] == state3[5])
                                    if (puzzle[6] == state3[6])
                                        if (puzzle[7] == state3[7])
                                            if (puzzle[8] == state3[8])
                                            {
                                                in_dfs = true;
                                                break;
                                            }

        if (!in_dfs)
        {
            steps++;
            dfs.push_back(state3);
            stack.push(state3);
            if (is_goal(state3, goal))
            {
                solved(steps, goal);
                return true;
            }
            print_puzzle(steps, state3);
            if (Process_DFS(goal, dfs, stack, steps))
                return true;
        }
        in_dfs = false;
    }
    else if (i == 4)
    {
        std::vector<size_t> state1 = std::vector<size_t>{temp[0], temp[4], temp[2], temp[3], temp[1], temp[5], temp[6], temp[7], temp[8]};
        for (std::vector<size_t> &puzzle : dfs)
            if (puzzle[0] == state1[0])
                if (puzzle[1] == state1[1])
                    if (puzzle[2] == state1[2])
                        if (puzzle[3] == state1[3])
                            if (puzzle[4] == state1[4])
                                if (puzzle[5] == state1[5])
                                    if (puzzle[6] == state1[6])
                                        if (puzzle[7] == state1[7])
                                            if (puzzle[8] == state1[8])
                                            {
                                                in_dfs = true;
                                                break;
                                            }

        if (!in_dfs)
        {
            steps++;
            dfs.push_back(state1);
            stack.push(state1);
            if (is_goal(state1, goal))
            {
                solved(steps, goal);
                return true;
            }
            print_puzzle(steps, state1);
            if (Process_DFS(goal, dfs, stack, steps))
                return true;
        }
        in_dfs = false;

        std::vector<size_t> state2 = std::vector<size_t>{temp[0], temp[1], temp[2], temp[4], temp[3], temp[5], temp[6], temp[7], temp[8]};
        for (std::vector<size_t> &puzzle : dfs)
            if (puzzle[0] == state2[0])
                if (puzzle[1] == state2[1])
                    if (puzzle[2] == state2[2])
                        if (puzzle[3] == state2[3])
                            if (puzzle[4] == state2[4])
                                if (puzzle[5] == state2[5])
                                    if (puzzle[6] == state2[6])
                                        if (puzzle[7] == state2[7])
                                            if (puzzle[8] == state2[8])
                                            {
                                                in_dfs = true;
                                                break;
                                            }

        if (!in_dfs)
        {
            steps++;
            dfs.push_back(state2);
            stack.push(state2);
            if (is_goal(state2, goal))
            {
                solved(steps, goal);
                return true;
            }
            print_puzzle(steps, state2);
            if (Process_DFS(goal, dfs, stack, steps))
                return true;
        }
        in_dfs = false;

        std::vector<size_t> state3 = std::vector<size_t>{temp[0], temp[1], temp[2], temp[3], temp[5], temp[4], temp[6], temp[7], temp[8]};
        for (std::vector<size_t> &puzzle : dfs)
            if (puzzle[0] == state3[0])
                if (puzzle[1] == state3[1])
                    if (puzzle[2] == state3[2])
                        if (puzzle[3] == state3[3])
                            if (puzzle[4] == state3[4])
                                if (puzzle[5] == state3[5])
                                    if (puzzle[6] == state3[6])
                                        if (puzzle[7] == state3[7])
                                            if (puzzle[8] == state3[8])
                                            {
                                                in_dfs = true;
                                                break;
                                            }

        if (!in_dfs)
        {
            steps++;
            dfs.push_back(state3);
            stack.push(state3);
            if (is_goal(state3, goal))
            {
                solved(steps, goal);
                return true;
            }
            print_puzzle(steps, state3);
            if (Process_DFS(goal, dfs, stack, steps))
                return true;
        }
        in_dfs = false;

        std::vector<size_t> state4 = std::vector<size_t>{temp[0], temp[1], temp[2], temp[3], temp[7], temp[5], temp[6], temp[4], temp[8]};
        for (std::vector<size_t> &puzzle : dfs)
            if (puzzle[0] == state4[0])
                if (puzzle[1] == state4[1])
                    if (puzzle[2] == state4[2])
                        if (puzzle[3] == state4[3])
                            if (puzzle[4] == state4[4])
                                if (puzzle[5] == state4[5])
                                    if (puzzle[6] == state4[6])
                                        if (puzzle[7] == state4[7])
                                            if (puzzle[8] == state4[8])
                                            {
                                                in_dfs = true;
                                                break;
                                            }

        if (!in_dfs)
        {
            steps++;
            dfs.push_back(state4);
            stack.push(state4);
            if (is_goal(state4, goal))
            {
                solved(steps, goal);
                return true;
            }
            print_puzzle(steps, state4);
            if (Process_DFS(goal, dfs, stack, steps))
                return true;
        }
        in_dfs = false;
    }
    else if (i == 5)
    {
        std::vector<size_t> state1 = std::vector<size_t>{temp[0], temp[1], temp[5], temp[3], temp[4], temp[2], temp[6], temp[7], temp[8]};
        for (std::vector<size_t> &puzzle : dfs)
            if (puzzle[0] == state1[0])
                if (puzzle[1] == state1[1])
                    if (puzzle[2] == state1[2])
                        if (puzzle[3] == state1[3])
                            if (puzzle[4] == state1[4])
                                if (puzzle[5] == state1[5])
                                    if (puzzle[6] == state1[6])
                                        if (puzzle[7] == state1[7])
                                            if (puzzle[8] == state1[8])
                                            {
                                                in_dfs = true;
                                                break;
                                            }

        if (!in_dfs)
        {
            steps++;
            dfs.push_back(state1);
            stack.push(state1);
            if (is_goal(state1, goal))
            {
                solved(steps, goal);
                return true;
            }
            print_puzzle(steps, state1);
            if (Process_DFS(goal, dfs, stack, steps))
                return true;
        }
        in_dfs = false;

        std::vector<size_t> state2 = std::vector<size_t>{temp[0], temp[1], temp[2], temp[3], temp[5], temp[4], temp[6], temp[7], temp[8]};
        for (std::vector<size_t> &puzzle : dfs)
            if (puzzle[0] == state2[0])
                if (puzzle[1] == state2[1])
                    if (puzzle[2] == state2[2])
                        if (puzzle[3] == state2[3])
                            if (puzzle[4] == state2[4])
                                if (puzzle[5] == state2[5])
                                    if (puzzle[6] == state2[6])
                                        if (puzzle[7] == state2[7])
                                            if (puzzle[8] == state2[8])
                                            {
                                                in_dfs = true;
                                                break;
                                            }

        if (!in_dfs)
        {
            steps++;
            dfs.push_back(state2);
            stack.push(state2);
            if (is_goal(state2, goal))
            {
                solved(steps, goal);
                return true;
            }
            print_puzzle(steps, state2);
            if (Process_DFS(goal, dfs, stack, steps))
                return true;
        }
        in_dfs = false;

        std::vector<size_t> state3 = std::vector<size_t>{temp[0], temp[1], temp[2], temp[3], temp[4], temp[8], temp[6], temp[7], temp[5]};
        for (std::vector<size_t> &puzzle : dfs)
            if (puzzle[0] == state3[0])
                if (puzzle[1] == state3[1])
                    if (puzzle[2] == state3[2])
                        if (puzzle[3] == state3[3])
                            if (puzzle[4] == state3[4])
                                if (puzzle[5] == state3[5])
                                    if (puzzle[6] == state3[6])
                                        if (puzzle[7] == state3[7])
                                            if (puzzle[8] == state3[8])
                                            {
                                                in_dfs = true;
                                                break;
                                            }

        if (!in_dfs)
        {
            steps++;
            dfs.push_back(state3);
            stack.push(state3);
            if (is_goal(state3, goal))
            {
                solved(steps, goal);
                return true;
            }
            print_puzzle(steps, state3);
            if (Process_DFS(goal, dfs, stack, steps))
                return true;
        }
        in_dfs = false;
    }
    else if (i == 6)
    {
        std::vector<size_t> state1 = std::vector<size_t>{temp[0], temp[1], temp[2], temp[6], temp[4], temp[5], temp[3], temp[7], temp[8]};
        for (std::vector<size_t> &puzzle : dfs)
            if (puzzle[0] == state1[0])
                if (puzzle[1] == state1[1])
                    if (puzzle[2] == state1[2])
                        if (puzzle[3] == state1[3])
                            if (puzzle[4] == state1[4])
                                if (puzzle[5] == state1[5])
                                    if (puzzle[6] == state1[6])
                                        if (puzzle[7] == state1[7])
                                            if (puzzle[8] == state1[8])
                                            {
                                                in_dfs = true;
                                                break;
                                            }

        if (!in_dfs)
        {
            steps++;
            dfs.push_back(state1);
            stack.push(state1);
            if (is_goal(state1, goal))
            {
                solved(steps, goal);
                return true;
            }
            print_puzzle(steps, state1);
            if (Process_DFS(goal, dfs, stack, steps))
                return true;
        }
        in_dfs = false;

        std::vector<size_t> state2 = std::vector<size_t>{temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[7], temp[6], temp[8]};
        for (std::vector<size_t> &puzzle : dfs)
            if (puzzle[0] == state2[0])
                if (puzzle[1] == state2[1])
                    if (puzzle[2] == state2[2])
                        if (puzzle[3] == state2[3])
                            if (puzzle[4] == state2[4])
                                if (puzzle[5] == state2[5])
                                    if (puzzle[6] == state2[6])
                                        if (puzzle[7] == state2[7])
                                            if (puzzle[8] == state2[8])
                                            {
                                                in_dfs = true;
                                                break;
                                            }

        if (!in_dfs)
        {
            steps++;
            dfs.push_back(state2);
            stack.push(state2);
            if (is_goal(state2, goal))
            {
                solved(steps, goal);
                return true;
            }
            print_puzzle(steps, state2);
            if (Process_DFS(goal, dfs, stack, steps))
                return true;
        }
        in_dfs = false;
    }
    else if (i == 7)
    {
        std::vector<size_t> state1 = std::vector<size_t>{temp[0], temp[1], temp[2], temp[3], temp[7], temp[5], temp[6], temp[4], temp[8]};
        for (std::vector<size_t> &puzzle : dfs)
            if (puzzle[0] == state1[0])
                if (puzzle[1] == state1[1])
                    if (puzzle[2] == state1[2])
                        if (puzzle[3] == state1[3])
                            if (puzzle[4] == state1[4])
                                if (puzzle[5] == state1[5])
                                    if (puzzle[6] == state1[6])
                                        if (puzzle[7] == state1[7])
                                            if (puzzle[8] == state1[8])
                                            {
                                                in_dfs = true;
                                                break;
                                            }

        if (!in_dfs)
        {
            steps++;
            dfs.push_back(state1);
            stack.push(state1);
            if (is_goal(state1, goal))
            {
                solved(steps, goal);
                return true;
            }
            print_puzzle(steps, state1);
            if (Process_DFS(goal, dfs, stack, steps))
                return true;
        }
        in_dfs = false;

        std::vector<size_t> state2 = std::vector<size_t>{temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[7], temp[6], temp[8]};
        for (std::vector<size_t> &puzzle : dfs)
            if (puzzle[0] == state2[0])
                if (puzzle[1] == state2[1])
                    if (puzzle[2] == state2[2])
                        if (puzzle[3] == state2[3])
                            if (puzzle[4] == state2[4])
                                if (puzzle[5] == state2[5])
                                    if (puzzle[6] == state2[6])
                                        if (puzzle[7] == state2[7])
                                            if (puzzle[8] == state2[8])
                                            {
                                                in_dfs = true;
                                                break;
                                            }

        if (!in_dfs)
        {
            steps++;
            dfs.push_back(state2);
            stack.push(state2);
            if (is_goal(state2, goal))
            {
                solved(steps, goal);
                return true;
            }
            print_puzzle(steps, state2);
            if (Process_DFS(goal, dfs, stack, steps))
                return true;
        }
        in_dfs = false;

        std::vector<size_t> state3 = std::vector<size_t>{temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[6], temp[8], temp[7]};
        for (std::vector<size_t> &puzzle : dfs)
            if (puzzle[0] == state3[0])
                if (puzzle[1] == state3[1])
                    if (puzzle[2] == state3[2])
                        if (puzzle[3] == state3[3])
                            if (puzzle[4] == state3[4])
                                if (puzzle[5] == state3[5])
                                    if (puzzle[6] == state3[6])
                                        if (puzzle[7] == state3[7])
                                            if (puzzle[8] == state3[8])
                                            {
                                                in_dfs = true;
                                                break;
                                            }

        if (!in_dfs)
        {
            steps++;
            dfs.push_back(state3);
            stack.push(state3);
            if (is_goal(state3, goal))
            {
                solved(steps, goal);
                return true;
            }
            print_puzzle(steps, state3);
            if (Process_DFS(goal, dfs, stack, steps))
                return true;
        }
        in_dfs = false;
    }
    else if (i == 8)
    {
        std::vector<size_t> state1 = std::vector<size_t>{temp[0], temp[1], temp[2], temp[3], temp[4], temp[8], temp[6], temp[7], temp[5]};
        for (std::vector<size_t> &puzzle : dfs)
            if (puzzle[0] == state1[0])
                if (puzzle[1] == state1[1])
                    if (puzzle[2] == state1[2])
                        if (puzzle[3] == state1[3])
                            if (puzzle[4] == state1[4])
                                if (puzzle[5] == state1[5])
                                    if (puzzle[6] == state1[6])
                                        if (puzzle[7] == state1[7])
                                            if (puzzle[8] == state1[8])
                                            {
                                                in_dfs = true;
                                                break;
                                            }

        if (!in_dfs)
        {
            steps++;
            dfs.push_back(state1);
            stack.push(state1);
            if (is_goal(state1, goal))
            {
                solved(steps, goal);
                return true;
            }
            print_puzzle(steps, state1);
            if (Process_DFS(goal, dfs, stack, steps))
                return true;
        }
        in_dfs = false;

        std::vector<size_t> state2 = std::vector<size_t>{temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[6], temp[8], temp[7]};
        for (std::vector<size_t> &puzzle : dfs)
            if (puzzle[0] == state2[0])
                if (puzzle[1] == state2[1])
                    if (puzzle[2] == state2[2])
                        if (puzzle[3] == state2[3])
                            if (puzzle[4] == state2[4])
                                if (puzzle[5] == state2[5])
                                    if (puzzle[6] == state2[6])
                                        if (puzzle[7] == state2[7])
                                            if (puzzle[8] == state2[8])
                                            {
                                                in_dfs = true;
                                                break;
                                            }

        if (!in_dfs)
        {
            steps++;
            dfs.push_back(state2);
            stack.push(state2);
            if (is_goal(state2, goal))
            {
                solved(steps, goal);
                return true;
            }
            print_puzzle(steps, state2);
            if (Process_DFS(goal, dfs, stack, steps))
                return true;
        }
        in_dfs = false;
    }
    return false;
}
