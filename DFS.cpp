#include "DFS.h"
#include "BFS.h"

void DFS(std::vector<int> &init, const std::vector<int> &goal, const int &depth_limit)
{
    if (!isSolvable(init, goal))
    {
        std::cout << "\u001b[31;1m"; //Bright Red
        std::cout << "*************************\n";
        std::cout << "This puzzle is not solvable\n";
        std::cout << "*************************\n";
        std::cout << "\u001b[0m"; //reset color and style
    }

    else if (init == goal) //when the initial puzzle is the goal puzzle!
    {
        std::cout << "\u001b[32;1m"; //Bright Green
        std::cout << "*************************\n";
        std::cout << "******PUZZLE SOLVED******\nNumber of steps: 0 || your initial puzzle is the goal puzzle\n";
        std::cout << "*************************\n";
        std::cout << "\u001b[0m"; //reset color and style
    }

    else
    {
        init.push_back(0);                       //This is the depth level of the Node
        std::stack<std::vector<int>> stack{};    //we use a stack to check each Depth of the graph in order
        std::vector<std::vector<int>> dfs{init}; //we use a vector to store the states that we have traversed, and we use it to prevent traversing one state twice
        stack.push(init);

        int steps{};
        bool in_dfs{false};
        int i{}; // position of the empty block in each state(here we use zero instead of empty, but when we print the puzzle, we print " " instead of "0")

        print_puzzle(steps, init);

        while (true)
        {
            std::vector<int> temp = stack.top();
            stack.pop();

            if (depth_limit != -1) //if depth limit was given by the user
                if (temp[9] >= depth_limit)
                    continue;

            for (int j{}; j < 9; j++)
                if (temp[j] == 0)
                {
                    i = j;
                    break;
                }

            if (i == 0)
            {
                std::vector<int> state1 = std::vector<int>{temp[1], temp[0], temp[2], temp[3], temp[4], temp[5], temp[6], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : dfs)
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
                    stack.push(temp);
                    steps++;
                    dfs.push_back(state1);
                    stack.push(state1);
                    if (is_goal(state1, goal))
                    {
                        solved(steps, goal);
                        break;
                    }
                    print_puzzle(steps, state1);
                    continue;
                }
                in_dfs = false;

                std::vector<int> state2 = std::vector<int>{temp[3], temp[1], temp[2], temp[0], temp[4], temp[5], temp[6], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : dfs)
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
                    stack.push(temp);
                    steps++;
                    dfs.push_back(state2);
                    stack.push(state2);
                    if (is_goal(state2, goal))
                    {
                        solved(steps, goal);
                        break;
                    }
                    print_puzzle(steps, state2);
                    continue;
                }
                in_dfs = false;
            }

            else if (i == 1)
            {
                std::vector<int> state1 = std::vector<int>{temp[1], temp[0], temp[2], temp[3], temp[4], temp[5], temp[6], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : dfs)
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
                    stack.push(temp);
                    steps++;
                    dfs.push_back(state1);
                    stack.push(state1);
                    if (is_goal(state1, goal))
                    {
                        solved(steps, goal);
                        break;
                    }
                    print_puzzle(steps, state1);
                    continue;
                }
                in_dfs = false;

                std::vector<int> state2 = std::vector<int>{temp[0], temp[2], temp[1], temp[3], temp[4], temp[5], temp[6], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : dfs)
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
                    stack.push(temp);
                    steps++;
                    dfs.push_back(state2);
                    stack.push(state2);
                    if (is_goal(state2, goal))
                    {
                        solved(steps, goal);
                        break;
                    }
                    print_puzzle(steps, state2);
                    continue;
                }
                in_dfs = false;

                std::vector<int> state3 = std::vector<int>{temp[0], temp[4], temp[2], temp[3], temp[1], temp[5], temp[6], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : dfs)
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
                    stack.push(temp);
                    steps++;
                    dfs.push_back(state3);
                    stack.push(state3);
                    if (is_goal(state3, goal))
                    {
                        solved(steps, goal);
                        break;
                    }
                    print_puzzle(steps, state3);
                    continue;
                }
                in_dfs = false;
            }

            else if (i == 2)
            {
                std::vector<int> state1 = std::vector<int>{temp[0], temp[2], temp[1], temp[3], temp[4], temp[5], temp[6], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : dfs)
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
                    stack.push(temp);
                    steps++;
                    dfs.push_back(state1);
                    stack.push(state1);
                    if (is_goal(state1, goal))
                    {
                        solved(steps, goal);
                        break;
                    }
                    print_puzzle(steps, state1);
                    continue;
                }
                in_dfs = false;

                std::vector<int> state2 = std::vector<int>{temp[0], temp[1], temp[5], temp[3], temp[4], temp[2], temp[6], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : dfs)
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
                    stack.push(temp);
                    steps++;
                    dfs.push_back(state2);
                    stack.push(state2);
                    if (is_goal(state2, goal))
                    {
                        solved(steps, goal);
                        break;
                    }
                    print_puzzle(steps, state2);
                    continue;
                }
                in_dfs = false;
            }

            else if (i == 3)
            {
                std::vector<int> state1 = std::vector<int>{temp[3], temp[1], temp[2], temp[0], temp[4], temp[5], temp[6], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : dfs)
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
                    stack.push(temp);
                    steps++;
                    dfs.push_back(state1);
                    stack.push(state1);
                    if (is_goal(state1, goal))
                    {
                        solved(steps, goal);
                        break;
                    }
                    print_puzzle(steps, state1);
                    continue;
                }
                in_dfs = false;

                std::vector<int> state2 = std::vector<int>{temp[0], temp[1], temp[2], temp[4], temp[3], temp[5], temp[6], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : dfs)
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
                    stack.push(temp);
                    steps++;
                    dfs.push_back(state2);
                    stack.push(state2);
                    if (is_goal(state2, goal))
                    {
                        solved(steps, goal);
                        break;
                    }
                    print_puzzle(steps, state2);
                    continue;
                }
                in_dfs = false;

                std::vector<int> state3 = std::vector<int>{temp[0], temp[1], temp[2], temp[6], temp[4], temp[5], temp[3], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : dfs)
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
                    stack.push(temp);
                    steps++;
                    dfs.push_back(state3);
                    stack.push(state3);
                    if (is_goal(state3, goal))
                    {
                        solved(steps, goal);
                        break;
                    }
                    print_puzzle(steps, state3);
                    continue;
                }
                in_dfs = false;
            }

            else if (i == 4)
            {
                std::vector<int> state1 = std::vector<int>{temp[0], temp[4], temp[2], temp[3], temp[1], temp[5], temp[6], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : dfs)
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
                    stack.push(temp);
                    steps++;
                    dfs.push_back(state1);
                    stack.push(state1);
                    if (is_goal(state1, goal))
                    {
                        solved(steps, goal);
                        break;
                    }
                    print_puzzle(steps, state1);
                    continue;
                }
                in_dfs = false;

                std::vector<int> state2 = std::vector<int>{temp[0], temp[1], temp[2], temp[4], temp[3], temp[5], temp[6], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : dfs)
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
                    stack.push(temp);
                    steps++;
                    dfs.push_back(state2);
                    stack.push(state2);
                    if (is_goal(state2, goal))
                    {
                        solved(steps, goal);
                        break;
                    }
                    print_puzzle(steps, state2);
                    continue;
                }
                in_dfs = false;

                std::vector<int> state3 = std::vector<int>{temp[0], temp[1], temp[2], temp[3], temp[5], temp[4], temp[6], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : dfs)
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
                    stack.push(temp);
                    steps++;
                    dfs.push_back(state3);
                    stack.push(state3);
                    if (is_goal(state3, goal))
                    {
                        solved(steps, goal);
                        break;
                    }
                    print_puzzle(steps, state3);
                    continue;
                }
                in_dfs = false;

                std::vector<int> state4 = std::vector<int>{temp[0], temp[1], temp[2], temp[3], temp[7], temp[5], temp[6], temp[4], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : dfs)
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
                    stack.push(temp);
                    steps++;
                    dfs.push_back(state4);
                    stack.push(state4);
                    if (is_goal(state4, goal))
                    {
                        solved(steps, goal);
                        break;
                    }
                    print_puzzle(steps, state4);
                    continue;
                }
                in_dfs = false;
            }

            else if (i == 5)
            {
                std::vector<int> state1 = std::vector<int>{temp[0], temp[1], temp[5], temp[3], temp[4], temp[2], temp[6], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : dfs)
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
                    stack.push(temp);
                    steps++;
                    dfs.push_back(state1);
                    stack.push(state1);
                    if (is_goal(state1, goal))
                    {
                        solved(steps, goal);
                        break;
                    }
                    print_puzzle(steps, state1);
                    continue;
                }
                in_dfs = false;

                std::vector<int> state2 = std::vector<int>{temp[0], temp[1], temp[2], temp[3], temp[5], temp[4], temp[6], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : dfs)
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
                    stack.push(temp);
                    steps++;
                    dfs.push_back(state2);
                    stack.push(state2);
                    if (is_goal(state2, goal))
                    {
                        solved(steps, goal);
                        break;
                    }
                    print_puzzle(steps, state2);
                    continue;
                }
                in_dfs = false;

                std::vector<int> state3 = std::vector<int>{temp[0], temp[1], temp[2], temp[3], temp[4], temp[8], temp[6], temp[7], temp[5], temp[9] + 1};
                for (std::vector<int> &puzzle : dfs)
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
                    stack.push(temp);
                    steps++;
                    dfs.push_back(state3);
                    stack.push(state3);
                    if (is_goal(state3, goal))
                    {
                        solved(steps, goal);
                        break;
                    }
                    print_puzzle(steps, state3);
                    continue;
                }
                in_dfs = false;
            }

            else if (i == 6)
            {
                std::vector<int> state1 = std::vector<int>{temp[0], temp[1], temp[2], temp[6], temp[4], temp[5], temp[3], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : dfs)
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
                    stack.push(temp);
                    steps++;
                    dfs.push_back(state1);
                    stack.push(state1);
                    if (is_goal(state1, goal))
                    {
                        solved(steps, goal);
                        break;
                    }
                    print_puzzle(steps, state1);
                    continue;
                }
                in_dfs = false;

                std::vector<int> state2 = std::vector<int>{temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[7], temp[6], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : dfs)
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
                    stack.push(temp);
                    steps++;
                    dfs.push_back(state2);
                    stack.push(state2);
                    if (is_goal(state2, goal))
                    {
                        solved(steps, goal);
                        break;
                    }
                    print_puzzle(steps, state2);
                    continue;
                }
                in_dfs = false;
            }

            else if (i == 7)
            {
                std::vector<int> state1 = std::vector<int>{temp[0], temp[1], temp[2], temp[3], temp[7], temp[5], temp[6], temp[4], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : dfs)
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
                    stack.push(temp);
                    steps++;
                    dfs.push_back(state1);
                    stack.push(state1);
                    if (is_goal(state1, goal))
                    {
                        solved(steps, goal);
                        break;
                    }
                    print_puzzle(steps, state1);
                    continue;
                }
                in_dfs = false;

                std::vector<int> state2 = std::vector<int>{temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[7], temp[6], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : dfs)
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
                    stack.push(temp);
                    steps++;
                    dfs.push_back(state2);
                    stack.push(state2);
                    if (is_goal(state2, goal))
                    {
                        solved(steps, goal);
                        break;
                    }
                    print_puzzle(steps, state2);
                    continue;
                }
                in_dfs = false;

                std::vector<int> state3 = std::vector<int>{temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[6], temp[8], temp[7], temp[9] + 1};
                for (std::vector<int> &puzzle : dfs)
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
                    stack.push(temp);
                    steps++;
                    dfs.push_back(state3);
                    stack.push(state3);
                    if (is_goal(state3, goal))
                    {
                        solved(steps, goal);
                        break;
                    }
                    print_puzzle(steps, state3);
                    continue;
                }
                in_dfs = false;
            }

            else if (i == 8)
            {
                std::vector<int> state1 = std::vector<int>{temp[0], temp[1], temp[2], temp[3], temp[4], temp[8], temp[6], temp[7], temp[5], temp[9] + 1};
                for (std::vector<int> &puzzle : dfs)
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
                    stack.push(temp);
                    steps++;
                    dfs.push_back(state1);
                    stack.push(state1);
                    if (is_goal(state1, goal))
                    {
                        solved(steps, goal);
                        break;
                    }
                    print_puzzle(steps, state1);
                    continue;
                }
                in_dfs = false;

                std::vector<int> state2 = std::vector<int>{temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[6], temp[8], temp[7], temp[9] + 1};
                for (std::vector<int> &puzzle : dfs)
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
                    stack.push(temp);
                    steps++;
                    dfs.push_back(state2);
                    stack.push(state2);
                    if (is_goal(state2, goal))
                    {
                        solved(steps, goal);
                        break;
                    }
                    print_puzzle(steps, state2);
                    continue;
                }
                in_dfs = false;
            }
            if (stack.empty())
            {
                std::cout << "\u001b[31;1mNo answers find till depth " << depth_limit << "\u001b[0m\n";
                break;
            }
        }
    }
}
