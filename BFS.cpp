#include "BFS.h"

void BFS(std::vector<int> &init, const std::vector<int> &goal, const int &depth_limit)
{
    if (!isSolvable(init, goal))
    {
        std::cout << "\u001b[31;1m"; //Bright Red
        std::cout << "\n*************************\n";
        std::cout << "This puzzle is not solvable\n";
        std::cout << "*************************\n";
        std::cout << "\u001b[0m"; //reset color and style
    }

    else if (init == goal) //when the initial puzzle is the goal puzzle!
    {
        std::cout << "\u001b[32;1m"; //Bright Green
        std::cout << "\n*************************\n";
        std::cout << "******\u001b[36;1mPUZZLE SOLVED\u001b[32;1m******\nNumber of steps: 0 || your initial puzzle is the goal puzzle\n";
        std::cout << "*************************\n";
        std::cout << "\u001b[0m"; //reset color and style
    }

    else
    {
        init.push_back(0);                       //This is the depth level of the Node
        std::queue<std::vector<int>> queue{};    //we use a queue to check each level of the graph in order
        std::vector<std::vector<int>> bfs{init}; //we use a vector to store the states that we have traversed, and we use it to prevent traversing one state twice
        queue.push(init);

        int steps{};
        bool in_bfs{false};
        int i{}; // position of the empty block in each state(here we use zero instead of empty, but when we print the puzzle, we print " " instead of "0")

        print_puzzle(steps, init);

        while (true)
        {
            std::vector<int> temp = queue.front();
            queue.pop();

            if (depth_limit != -1) //if depth limit was given by the user
                if (temp[9] >= depth_limit)
                {
                    std::cout << "\u001b[31;1mNo answers find till depth " << depth_limit << "\u001b[0m\n";
                    break;
                }

            for (int j{}; j < 9; j++)
                if (temp[j] == 0)
                {
                    i = j;
                    break;
                }

            if (i == 0)
            {
                std::vector<int> state1 = std::vector<int>{temp[1], temp[0], temp[2], temp[3], temp[4], temp[5], temp[6], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : bfs)
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
                                                        in_bfs = true;
                                                        break;
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

                std::vector<int> state2 = std::vector<int>{temp[3], temp[1], temp[2], temp[0], temp[4], temp[5], temp[6], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : bfs)
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
                                                        in_bfs = true;
                                                        break;
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
                std::vector<int> state1 = std::vector<int>{temp[1], temp[0], temp[2], temp[3], temp[4], temp[5], temp[6], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : bfs)
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
                                                        in_bfs = true;
                                                        break;
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

                std::vector<int> state2 = std::vector<int>{temp[0], temp[2], temp[1], temp[3], temp[4], temp[5], temp[6], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : bfs)
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
                                                        in_bfs = true;
                                                        break;
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

                std::vector<int> state3 = std::vector<int>{temp[0], temp[4], temp[2], temp[3], temp[1], temp[5], temp[6], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : bfs)
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
                                                        in_bfs = true;
                                                        break;
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
                std::vector<int> state1 = std::vector<int>{temp[0], temp[2], temp[1], temp[3], temp[4], temp[5], temp[6], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : bfs)
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
                                                        in_bfs = true;
                                                        break;
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

                std::vector<int> state2 = std::vector<int>{temp[0], temp[1], temp[5], temp[3], temp[4], temp[2], temp[6], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : bfs)
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
                                                        in_bfs = true;
                                                        break;
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
                std::vector<int> state1 = std::vector<int>{temp[3], temp[1], temp[2], temp[0], temp[4], temp[5], temp[6], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : bfs)
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
                                                        in_bfs = true;
                                                        break;
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

                std::vector<int> state2 = std::vector<int>{temp[0], temp[1], temp[2], temp[4], temp[3], temp[5], temp[6], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : bfs)
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
                                                        in_bfs = true;
                                                        break;
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

                std::vector<int> state3 = std::vector<int>{temp[0], temp[1], temp[2], temp[6], temp[4], temp[5], temp[3], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : bfs)
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
                                                        in_bfs = true;
                                                        break;
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
                std::vector<int> state1 = std::vector<int>{temp[0], temp[4], temp[2], temp[3], temp[1], temp[5], temp[6], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : bfs)
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
                                                        in_bfs = true;
                                                        break;
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

                std::vector<int> state2 = std::vector<int>{temp[0], temp[1], temp[2], temp[4], temp[3], temp[5], temp[6], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : bfs)
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
                                                        in_bfs = true;
                                                        break;
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

                std::vector<int> state3 = std::vector<int>{temp[0], temp[1], temp[2], temp[3], temp[5], temp[4], temp[6], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : bfs)
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
                                                        in_bfs = true;
                                                        break;
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

                std::vector<int> state4 = std::vector<int>{temp[0], temp[1], temp[2], temp[3], temp[7], temp[5], temp[6], temp[4], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : bfs)
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
                                                        in_bfs = true;
                                                        break;
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
                std::vector<int> state1 = std::vector<int>{temp[0], temp[1], temp[5], temp[3], temp[4], temp[2], temp[6], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : bfs)
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
                                                        in_bfs = true;
                                                        break;
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

                std::vector<int> state2 = std::vector<int>{temp[0], temp[1], temp[2], temp[3], temp[5], temp[4], temp[6], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : bfs)
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
                                                        in_bfs = true;
                                                        break;
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

                std::vector<int> state3 = std::vector<int>{temp[0], temp[1], temp[2], temp[3], temp[4], temp[8], temp[6], temp[7], temp[5], temp[9] + 1};
                for (std::vector<int> &puzzle : bfs)
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
                                                        in_bfs = true;
                                                        break;
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
                std::vector<int> state1 = std::vector<int>{temp[0], temp[1], temp[2], temp[6], temp[4], temp[5], temp[3], temp[7], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : bfs)
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
                                                        in_bfs = true;
                                                        break;
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

                std::vector<int> state2 = std::vector<int>{temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[7], temp[6], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : bfs)
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
                                                        in_bfs = true;
                                                        break;
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
                std::vector<int> state1 = std::vector<int>{temp[0], temp[1], temp[2], temp[3], temp[7], temp[5], temp[6], temp[4], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : bfs)
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
                                                        in_bfs = true;
                                                        break;
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

                std::vector<int> state2 = std::vector<int>{temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[7], temp[6], temp[8], temp[9] + 1};
                for (std::vector<int> &puzzle : bfs)
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
                                                        in_bfs = true;
                                                        break;
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

                std::vector<int> state3 = std::vector<int>{temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[6], temp[8], temp[7], temp[9] + 1};
                for (std::vector<int> &puzzle : bfs)
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
                                                        in_bfs = true;
                                                        break;
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
                std::vector<int> state1 = std::vector<int>{temp[0], temp[1], temp[2], temp[3], temp[4], temp[8], temp[6], temp[7], temp[5], temp[9] + 1};
                for (std::vector<int> &puzzle : bfs)
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
                                                        in_bfs = true;
                                                        break;
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

                std::vector<int> state2 = std::vector<int>{temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[6], temp[8], temp[7], temp[9] + 1};
                for (std::vector<int> &puzzle : bfs)
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
                                                        in_bfs = true;
                                                        break;
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
    }
}

bool is_goal(const std::vector<int> &state, const std::vector<int> &goal)
{
    if (goal[0] == state[0])
        if (goal[1] == state[1])
            if (goal[2] == state[2])
                if (goal[3] == state[3])
                    if (goal[4] == state[4])
                        if (goal[5] == state[5])
                            if (goal[6] == state[6])
                                if (goal[7] == state[7])
                                    if (goal[8] == state[8])
                                        return true;
    return false;
}

void solved(int steps, const std::vector<int> &goal)
{
    std::cout << "\u001b[32;1m"; //Bright Green
    std::cout << "\n*************************\n";
    std::cout << "******\u001b[36;1mPUZZLE SOLVED\u001b[32;1m******\nNumber of steps: " << steps;
    std::cout << "\n*************************\n";
    std::cout << "\nStep " << steps << ":\n";
    for (int i{}; i < 9; i++)
    {
        if (goal[i] == 0)
            std::cout << " ";
        else
            std::cout << goal[i];
        if (i % 3 == 2)
            std::cout << "\n";
        else
            std::cout << " ";
    }
    std::cout << "\n*************************\n";
    std::cout << "\u001b[0m"; //reset color and style
}

void print_puzzle(int steps, const std::vector<int> &state)
{
    std::cout << "\u001b[31;1m"; //Bright Red
    std::cout << "\nStep " << steps << ":\n";
    std::cout << "\u001b[34;1m"; //Bright Blue
    for (int i{}; i < 9; i++)
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
    std::cout << "\u001b[0m"; //reset color and style
}

//following code is copied from "https://www.geeksforgeeks.org/check-instance-8-puzzle-solvable/" ***with a little modification***
// A utility function to count inversions in given vector 'arr'
int getInvCount(const std::vector<int> &arr)
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
bool isSolvable(const std::vector<int> &arr, const std::vector<int> &goal)
{
    // Count inversions in given 8 puzzle
    int invCount = getInvCount(arr);

    // Count inversions in given 8 puzzle
    int invCount_goal = getInvCount(goal);

    // return true if inversion count is even.
    return (invCount % 2 == invCount_goal % 2);
}
