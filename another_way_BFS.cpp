#include "BFS.h"
#include "another_way_BFS.h"

void Fast_BFS(std::vector<int> &init, const std::vector<int> &goal, const int &depth_limit)
{
    if (!isSolvable(init, goal))
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
        init.push_back(0);                    //This is the depth level of the Node
        std::queue<std::vector<int>> queue{}; //This stores vectors like "v" that at least one of this functions returns true: is_goal_4578_1(v,goal), is_goal_4578_2(v,goal), is_goal_4578_3(v,goal), is_goal_4578_4(v,goal)
        queue.push(init);

        bool goal_finded{false};   //We use it to end the while loop
        bool depth_reached{false}; //We use it to stop function when we traversed all Node till ours depth limit
        int steps{};
        int i{}; //position of the empty block in each state(here we use zero instead of empty, but when we print the puzzle, we print " " instead of "0")

        int goal_zero{}; //position of the empty block in the goal state
        for (int i{}; i < 9; i++)
            if (goal[i] == 0)
            {
                goal_zero = i;
                break;
            }

        print_puzzle(steps, init);

        while (!goal_finded)
        {
            if (depth_reached)
                break;

            std::vector<int> temp = queue.front();
            queue.pop();

            bool condition_1{false};
            bool condition_2{false};
            bool condition_3{false};
            if (goal_zero == 4 || goal_zero == 5 || goal_zero == 7 || goal_zero == 8)
            {
                condition_1 = is_goal_4578_1(temp, goal);
                condition_2 = is_goal_4578_2(temp, goal);
                condition_3 = is_goal_4578_3(temp, goal);
            }
            else if (goal_zero == 0 || goal_zero == 1 || goal_zero == 3)
            {
                condition_1 = is_goal_013_1(temp, goal);
                condition_2 = is_goal_013_2(temp, goal);
                condition_3 = is_goal_013_3(temp, goal);
            }
            else if (goal_zero == 2)
            {
                condition_1 = is_goal_2_1(temp, goal);
                condition_2 = is_goal_2_2(temp, goal);
                condition_3 = is_goal_2_3(temp, goal);
            }
            else
            {
                condition_1 = is_goal_6_1(temp, goal);
                condition_2 = is_goal_6_2(temp, goal);
                condition_3 = is_goal_6_3(temp, goal);
            }

            if (condition_1)
            {
                if (condition_2)
                {
                    if (condition_3)
                    {
                        std::queue<std::vector<int>> queue4{};    //a queue for to find a node a that is_goal_4578_4(a,goal) is true
                        std::vector<std::vector<int>> bfs4{temp}; //a vector to store all of traveresed states until finding the node a that is_goal_4578_4(a,goal) is true
                        queue4.push(bfs4.back());

                        bool in_bfs4{false};

                        while (true)
                        {
                            std::vector<int> temp1 = queue4.front();
                            queue4.pop();

                            if (depth_limit != -1) //if depth limit was given by the user
                                if (temp1[9] >= depth_limit)
                                {
                                    depth_reached = true;
                                    std::cout << "No answers find till depth " << depth_limit << "\n";
                                    break;
                                }

                            for (int j{}; j < 9; j++)
                                if (temp1[j] == 0)
                                {
                                    i = j;
                                    break;
                                }

                            if (goal_zero == 4 || goal_zero == 5 || goal_zero == 7 || goal_zero == 8)
                            {
                                if (i == 4)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs4)
                                    {
                                        if (puzzle == state1)
                                        {
                                            in_bfs4 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs4)
                                    {
                                        steps++;
                                        bfs4.push_back(state1);
                                        queue4.push(state1);
                                        if (is_goal_4578_4(state1, goal))
                                        {
                                            solved(steps, goal);
                                            goal_finded = true;
                                            break;
                                        }
                                        print_puzzle(steps, state1);
                                    }
                                    in_bfs4 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs4)
                                    {
                                        if (puzzle == state2)
                                        {
                                            in_bfs4 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs4)
                                    {
                                        steps++;
                                        bfs4.push_back(state2);
                                        queue4.push(state2);
                                        if (is_goal_4578_4(state2, goal))
                                        {
                                            solved(steps, goal);
                                            goal_finded = true;
                                            break;
                                        }
                                        print_puzzle(steps, state2);
                                    }
                                    in_bfs4 = false;
                                }

                                else if (i == 5)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[8], temp1[6], temp1[7], temp1[5], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs4)
                                    {
                                        if (puzzle == state1)
                                        {
                                            in_bfs4 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs4)
                                    {
                                        steps++;
                                        bfs4.push_back(state1);
                                        queue4.push(state1);
                                        if (is_goal_4578_4(state1, goal))
                                        {
                                            solved(steps, goal);
                                            goal_finded = true;
                                            break;
                                        }
                                        print_puzzle(steps, state1);
                                    }
                                    in_bfs4 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs4)
                                    {
                                        if (puzzle == state2)
                                        {
                                            in_bfs4 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs4)
                                    {
                                        steps++;
                                        bfs4.push_back(state2);
                                        queue4.push(state2);
                                        if (is_goal_4578_4(state2, goal))
                                        {
                                            solved(steps, goal);
                                            goal_finded = true;
                                            break;
                                        }
                                        print_puzzle(steps, state2);
                                    }
                                    in_bfs4 = false;
                                }

                                else if (i == 7)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs4)
                                    {
                                        if (puzzle == state1)
                                        {
                                            in_bfs4 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs4)
                                    {
                                        steps++;
                                        bfs4.push_back(state1);
                                        queue4.push(state1);
                                        if (is_goal_4578_4(state1, goal))
                                        {
                                            solved(steps, goal);
                                            goal_finded = true;
                                            break;
                                        }
                                        print_puzzle(steps, state1);
                                    }
                                    in_bfs4 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[8], temp1[7], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs4)
                                    {
                                        if (puzzle == state2)
                                        {
                                            in_bfs4 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs4)
                                    {
                                        steps++;
                                        bfs4.push_back(state2);
                                        queue4.push(state2);
                                        if (is_goal_4578_4(state2, goal))
                                        {
                                            solved(steps, goal);
                                            goal_finded = true;
                                            break;
                                        }
                                        print_puzzle(steps, state2);
                                    }
                                    in_bfs4 = false;
                                }

                                else if (i == 8)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[8], temp1[6], temp1[7], temp1[5], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs4)
                                    {
                                        if (puzzle == state1)
                                        {
                                            in_bfs4 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs4)
                                    {
                                        steps++;
                                        bfs4.push_back(state1);
                                        queue4.push(state1);
                                        if (is_goal_4578_4(state1, goal))
                                        {
                                            solved(steps, goal);
                                            goal_finded = true;
                                            break;
                                        }
                                        print_puzzle(steps, state1);
                                    }
                                    in_bfs4 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[8], temp1[7], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs4)
                                    {
                                        if (puzzle == state2)
                                        {
                                            in_bfs4 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs4)
                                    {
                                        steps++;
                                        bfs4.push_back(state2);
                                        queue4.push(state2);
                                        if (is_goal_4578_4(state2, goal))
                                        {
                                            solved(steps, goal);
                                            goal_finded = true;
                                            break;
                                        }
                                        print_puzzle(steps, state2);
                                    }
                                    in_bfs4 = false;
                                }
                            }

                            else if (goal_zero == 0 || goal_zero == 1 || goal_zero == 3)
                            {
                                if (i == 0)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[1], temp1[0], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs4)
                                    {
                                        if (puzzle == state1)
                                        {
                                            in_bfs4 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs4)
                                    {
                                        steps++;
                                        bfs4.push_back(state1);
                                        queue4.push(state1);
                                        if (is_goal_013_4(state1, goal))
                                        {
                                            solved(steps, goal);
                                            goal_finded = true;
                                            break;
                                        }
                                        print_puzzle(steps, state1);
                                    }
                                    in_bfs4 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[3], temp1[1], temp1[2], temp1[0], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs4)
                                    {
                                        if (puzzle == state2)
                                        {
                                            in_bfs4 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs4)
                                    {
                                        steps++;
                                        bfs4.push_back(state2);
                                        queue4.push(state2);
                                        if (is_goal_013_4(state2, goal))
                                        {
                                            solved(steps, goal);
                                            goal_finded = true;
                                            break;
                                        }
                                        print_puzzle(steps, state2);
                                    }
                                    in_bfs4 = false;
                                }

                                else if (i == 1)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[1], temp1[0], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs4)
                                    {
                                        if (puzzle == state1)
                                        {
                                            in_bfs4 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs4)
                                    {
                                        steps++;
                                        bfs4.push_back(state1);
                                        queue4.push(state1);
                                        if (is_goal_013_4(state1, goal))
                                        {
                                            solved(steps, goal);
                                            goal_finded = true;
                                            break;
                                        }
                                        print_puzzle(steps, state1);
                                    }
                                    in_bfs4 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs4)
                                    {
                                        if (puzzle == state2)
                                        {
                                            in_bfs4 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs4)
                                    {
                                        steps++;
                                        bfs4.push_back(state2);
                                        queue4.push(state2);
                                        if (is_goal_013_4(state2, goal))
                                        {
                                            solved(steps, goal);
                                            goal_finded = true;
                                            break;
                                        }
                                        print_puzzle(steps, state2);
                                    }
                                    in_bfs4 = false;
                                }

                                else if (i == 3)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[3], temp1[1], temp1[2], temp1[0], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs4)
                                    {
                                        if (puzzle == state1)
                                        {
                                            in_bfs4 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs4)
                                    {
                                        steps++;
                                        bfs4.push_back(state1);
                                        queue4.push(state1);
                                        if (is_goal_013_4(state1, goal))
                                        {
                                            solved(steps, goal);
                                            goal_finded = true;
                                            break;
                                        }
                                        print_puzzle(steps, state1);
                                    }
                                    in_bfs4 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs4)
                                    {
                                        if (puzzle == state2)
                                        {
                                            in_bfs4 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs4)
                                    {
                                        steps++;
                                        bfs4.push_back(state2);
                                        queue4.push(state2);
                                        if (is_goal_013_4(state2, goal))
                                        {
                                            solved(steps, goal);
                                            goal_finded = true;
                                            break;
                                        }
                                        print_puzzle(steps, state2);
                                    }
                                    in_bfs4 = false;
                                }

                                else if (i == 4)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs4)
                                    {
                                        if (puzzle == state1)
                                        {
                                            in_bfs4 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs4)
                                    {
                                        steps++;
                                        bfs4.push_back(state1);
                                        queue4.push(state1);
                                        if (is_goal_013_4(state1, goal))
                                        {
                                            solved(steps, goal);
                                            goal_finded = true;
                                            break;
                                        }
                                        print_puzzle(steps, state1);
                                    }
                                    in_bfs4 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs4)
                                    {
                                        if (puzzle == state2)
                                        {
                                            in_bfs4 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs4)
                                    {
                                        steps++;
                                        bfs4.push_back(state2);
                                        queue4.push(state2);
                                        if (is_goal_013_4(state2, goal))
                                        {
                                            solved(steps, goal);
                                            goal_finded = true;
                                            break;
                                        }
                                        print_puzzle(steps, state2);
                                    }
                                    in_bfs4 = false;
                                }
                            }

                            else if (goal_zero == 2)
                            {
                                if (i == 1)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[0], temp1[2], temp1[1], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs4)
                                    {
                                        if (puzzle == state1)
                                        {
                                            in_bfs4 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs4)
                                    {
                                        steps++;
                                        bfs4.push_back(state1);
                                        queue4.push(state1);
                                        if (is_goal_2_1(state1, goal))
                                        {
                                            solved(steps, goal);
                                            goal_finded = true;
                                            break;
                                        }
                                        print_puzzle(steps, state1);
                                    }
                                    in_bfs4 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs4)
                                    {
                                        if (puzzle == state2)
                                        {
                                            in_bfs4 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs4)
                                    {
                                        steps++;
                                        bfs4.push_back(state2);
                                        queue4.push(state2);
                                        if (is_goal_2_1(state2, goal))
                                        {
                                            solved(steps, goal);
                                            goal_finded = true;
                                            break;
                                        }
                                        print_puzzle(steps, state2);
                                    }
                                    in_bfs4 = false;
                                }

                                else if (i == 2)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[0], temp1[2], temp1[1], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs4)
                                    {
                                        if (puzzle == state1)
                                        {
                                            in_bfs4 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs4)
                                    {
                                        steps++;
                                        bfs4.push_back(state1);
                                        queue4.push(state1);
                                        if (is_goal_2_1(state1, goal))
                                        {
                                            solved(steps, goal);
                                            goal_finded = true;
                                            break;
                                        }
                                        print_puzzle(steps, state1);
                                    }
                                    in_bfs4 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[5], temp1[3], temp1[4], temp1[2], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs4)
                                    {
                                        if (puzzle == state2)
                                        {
                                            in_bfs4 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs4)
                                    {
                                        steps++;
                                        bfs4.push_back(state2);
                                        queue4.push(state2);
                                        if (is_goal_2_1(state2, goal))
                                        {
                                            solved(steps, goal);
                                            goal_finded = true;
                                            break;
                                        }
                                        print_puzzle(steps, state2);
                                    }
                                    in_bfs4 = false;
                                }

                                else if (i == 4)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs4)
                                    {
                                        if (puzzle == state1)
                                        {
                                            in_bfs4 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs4)
                                    {
                                        steps++;
                                        bfs4.push_back(state1);
                                        queue4.push(state1);
                                        if (is_goal_2_1(state1, goal))
                                        {
                                            solved(steps, goal);
                                            goal_finded = true;
                                            break;
                                        }
                                        print_puzzle(steps, state1);
                                    }
                                    in_bfs4 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs4)
                                    {
                                        if (puzzle == state2)
                                        {
                                            in_bfs4 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs4)
                                    {
                                        steps++;
                                        bfs4.push_back(state2);
                                        queue4.push(state2);
                                        if (is_goal_2_1(state2, goal))
                                        {
                                            solved(steps, goal);
                                            goal_finded = true;
                                            break;
                                        }
                                        print_puzzle(steps, state2);
                                    }
                                    in_bfs4 = false;
                                }

                                else if (i == 5)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[5], temp1[3], temp1[4], temp1[2], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs4)
                                    {
                                        if (puzzle == state1)
                                        {
                                            in_bfs4 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs4)
                                    {
                                        steps++;
                                        bfs4.push_back(state1);
                                        queue4.push(state1);
                                        if (is_goal_2_1(state1, goal))
                                        {
                                            solved(steps, goal);
                                            goal_finded = true;
                                            break;
                                        }
                                        print_puzzle(steps, state1);
                                    }
                                    in_bfs4 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs4)
                                    {
                                        if (puzzle == state2)
                                        {
                                            in_bfs4 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs4)
                                    {
                                        steps++;
                                        bfs4.push_back(state2);
                                        queue4.push(state2);
                                        if (is_goal_2_1(state2, goal))
                                        {
                                            solved(steps, goal);
                                            goal_finded = true;
                                            break;
                                        }
                                        print_puzzle(steps, state2);
                                    }
                                    in_bfs4 = false;
                                }
                            }

                            else
                            {
                            }
                        }
                    }

                    else
                    {
                        std::queue<std::vector<int>> queue3{};    //a queue for to find a node a that is_goal_4578_3(a,goal) is true
                        std::vector<std::vector<int>> bfs3{temp}; //a vector to store all of traveresed states until finding the node a that is_goal_4578_3(a,goal) is true
                        queue3.push(bfs3.back());

                        bool in_bfs3{false};

                        while (true)
                        {
                            std::vector<int> temp1 = queue3.front();
                            queue3.pop();

                            if (depth_limit != -1) //if depth limit was given by the user
                                if (temp1[9] >= depth_limit)
                                {
                                    depth_reached = true;
                                    std::cout << "No answers find till depth " << depth_limit << "\n";
                                    break;
                                }

                            for (int j{}; j < 9; j++)
                                if (temp1[j] == 0)
                                {
                                    i = j;
                                    break;
                                }

                            if (goal_zero == 4 || goal_zero == 5 || goal_zero == 7 || goal_zero == 8)
                            {
                                if (i == 3)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs3)
                                    {
                                        if (puzzle == state1)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        steps++;
                                        bfs3.push_back(state1);
                                        queue3.push(state1);
                                        print_puzzle(steps, state1);
                                        if (is_goal_4578_3(state1, goal))
                                        {
                                            queue.push(state1);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[6], temp1[4], temp1[5], temp1[3], temp1[7], temp1[8], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs3)
                                    {
                                        if (puzzle == state2)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        steps++;
                                        bfs3.push_back(state2);
                                        queue3.push(state2);
                                        print_puzzle(steps, state2);
                                        if (is_goal_4578_3(state2, goal))
                                        {
                                            queue.push(state2);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }

                                else if (i == 4)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs3)
                                    {
                                        if (puzzle == state1)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        steps++;
                                        bfs3.push_back(state1);
                                        queue3.push(state1);
                                        print_puzzle(steps, state1);
                                        if (is_goal_4578_3(state1, goal))
                                        {
                                            queue.push(state1);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs3)
                                    {
                                        if (puzzle == state2)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        steps++;
                                        bfs3.push_back(state2);
                                        queue3.push(state2);
                                        print_puzzle(steps, state2);
                                        if (is_goal_4578_3(state2, goal))
                                        {
                                            queue.push(state2);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state3 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs3)
                                    {
                                        if (puzzle == state3)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        steps++;
                                        bfs3.push_back(state3);
                                        queue3.push(state3);
                                        print_puzzle(steps, state3);
                                        if (is_goal_4578_3(state3, goal))
                                        {
                                            queue.push(state3);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }

                                else if (i == 5)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[8], temp1[6], temp1[7], temp1[5], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs3)
                                    {
                                        if (puzzle == state1)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        steps++;
                                        bfs3.push_back(state1);
                                        queue3.push(state1);
                                        print_puzzle(steps, state1);
                                        if (is_goal_4578_3(state1, goal))
                                        {
                                            queue.push(state1);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs3)
                                    {
                                        if (puzzle == state2)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        steps++;
                                        bfs3.push_back(state2);
                                        queue3.push(state2);
                                        print_puzzle(steps, state2);
                                        if (is_goal_4578_3(state2, goal))
                                        {
                                            queue.push(state2);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }

                                else if (i == 6)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[6], temp1[4], temp1[5], temp1[3], temp1[7], temp1[8], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs3)
                                    {
                                        if (puzzle == state1)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        steps++;
                                        bfs3.push_back(state1);
                                        queue3.push(state1);
                                        print_puzzle(steps, state1);
                                        if (is_goal_4578_3(state1, goal))
                                        {
                                            queue.push(state1);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[7], temp1[6], temp1[8], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs3)
                                    {
                                        if (puzzle == state2)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        steps++;
                                        bfs3.push_back(state2);
                                        queue3.push(state2);
                                        print_puzzle(steps, state2);
                                        if (is_goal_4578_3(state2, goal))
                                        {
                                            queue.push(state2);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }

                                else if (i == 7)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs3)
                                    {
                                        if (puzzle == state1)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        steps++;
                                        bfs3.push_back(state1);
                                        queue3.push(state1);
                                        print_puzzle(steps, state1);
                                        if (is_goal_4578_3(state1, goal))
                                        {
                                            queue.push(state1);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[7], temp1[6], temp1[8], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs3)
                                    {
                                        if (puzzle == state2)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        steps++;
                                        bfs3.push_back(state2);
                                        queue3.push(state2);
                                        print_puzzle(steps, state2);
                                        if (is_goal_4578_3(state2, goal))
                                        {
                                            queue.push(state2);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state3 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[8], temp1[7], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs3)
                                    {
                                        if (puzzle == state3)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        steps++;
                                        bfs3.push_back(state3);
                                        queue3.push(state3);
                                        print_puzzle(steps, state3);
                                        if (is_goal_4578_3(state3, goal))
                                        {
                                            queue.push(state3);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }

                                else if (i == 8)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[8], temp1[6], temp1[7], temp1[5], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs3)
                                    {
                                        if (puzzle == state1)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        steps++;
                                        bfs3.push_back(state1);
                                        queue3.push(state1);
                                        print_puzzle(steps, state1);
                                        if (is_goal_4578_3(state1, goal))
                                        {
                                            queue.push(state1);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[8], temp1[7], temp1[9] + 1};
                                    for (std::vector<int> &puzzle : bfs3)
                                    {
                                        if (puzzle == state2)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        steps++;
                                        bfs3.push_back(state2);
                                        queue3.push(state2);
                                        print_puzzle(steps, state2);
                                        if (is_goal_4578_3(state2, goal))
                                        {
                                            queue.push(state2);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }
                            }
                        }
                    }
                }

                else
                {
                    std::queue<std::vector<int>> queue2{};    //a queue for to find a node a that is_goal_4578_2(a,goal) is true
                    std::vector<std::vector<int>> bfs2{temp}; //a vector to store all of traveresed states until finding the node a that is_goal_4578_2(a,goal) is true
                    queue2.push(bfs2.back());

                    bool in_bfs2{false};

                    while (true)
                    {
                        std::vector<int> temp1 = queue2.front();
                        queue2.pop();

                        if (depth_limit != -1) //if depth limit was given by the user
                            if (temp1[9] >= depth_limit)
                            {
                                depth_reached = true;
                                std::cout << "No answers find till depth " << depth_limit << "\n";
                                break;
                            }

                        for (int j{}; j < 9; j++)
                            if (temp1[j] == 0)
                            {
                                i = j;
                                break;
                            }

                        if (goal_zero == 4 || goal_zero == 5 || goal_zero == 7 || goal_zero == 8)
                        {
                            if (i == 1)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[2], temp1[1], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (std::vector<int> &puzzle : bfs2)
                                {
                                    if (puzzle == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    steps++;
                                    bfs2.push_back(state1);
                                    queue2.push(state1);
                                    print_puzzle(steps, state1);
                                    if (is_goal_4578_2(state1, goal))
                                    {
                                        queue.push(state1);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (std::vector<int> &puzzle : bfs2)
                                {
                                    if (puzzle == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    steps++;
                                    bfs2.push_back(state2);
                                    queue2.push(state2);
                                    print_puzzle(steps, state2);
                                    if (is_goal_4578_2(state2, goal))
                                    {
                                        queue.push(state2);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 2)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[2], temp1[1], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (std::vector<int> &puzzle : bfs2)
                                {
                                    if (puzzle == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    steps++;
                                    bfs2.push_back(state1);
                                    queue2.push(state1);
                                    print_puzzle(steps, state1);
                                    if (is_goal_4578_2(state1, goal))
                                    {
                                        queue.push(state1);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[5], temp1[3], temp1[4], temp1[2], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (std::vector<int> &puzzle : bfs2)
                                {
                                    if (puzzle == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    steps++;
                                    bfs2.push_back(state2);
                                    queue2.push(state2);
                                    print_puzzle(steps, state2);
                                    if (is_goal_4578_2(state2, goal))
                                    {
                                        queue.push(state2);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 3)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (std::vector<int> &puzzle : bfs2)
                                {
                                    if (puzzle == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    steps++;
                                    bfs2.push_back(state1);
                                    queue2.push(state1);
                                    print_puzzle(steps, state1);
                                    if (is_goal_4578_2(state1, goal))
                                    {
                                        queue.push(state1);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[6], temp1[4], temp1[5], temp1[3], temp1[7], temp1[8], temp1[9] + 1};
                                for (std::vector<int> &puzzle : bfs2)
                                {
                                    if (puzzle == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    steps++;
                                    bfs2.push_back(state2);
                                    queue2.push(state2);
                                    print_puzzle(steps, state2);
                                    if (is_goal_4578_2(state2, goal))
                                    {
                                        queue.push(state2);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 4)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (std::vector<int> &puzzle : bfs2)
                                {
                                    if (puzzle == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    steps++;
                                    bfs2.push_back(state1);
                                    queue2.push(state1);
                                    print_puzzle(steps, state1);
                                    if (is_goal_4578_2(state1, goal))
                                    {
                                        queue.push(state1);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (std::vector<int> &puzzle : bfs2)
                                {
                                    if (puzzle == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    steps++;
                                    bfs2.push_back(state2);
                                    queue2.push(state2);
                                    print_puzzle(steps, state2);
                                    if (is_goal_4578_2(state2, goal))
                                    {
                                        queue.push(state2);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state3 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (std::vector<int> &puzzle : bfs2)
                                {
                                    if (puzzle == state3)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    steps++;
                                    bfs2.push_back(state3);
                                    queue2.push(state3);
                                    print_puzzle(steps, state3);
                                    if (is_goal_4578_2(state3, goal))
                                    {
                                        queue.push(state3);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state4 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8], temp1[9] + 1};
                                for (std::vector<int> &puzzle : bfs2)
                                {
                                    if (puzzle == state4)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    steps++;
                                    bfs2.push_back(state4);
                                    queue2.push(state4);
                                    print_puzzle(steps, state4);
                                    if (is_goal_4578_2(state4, goal))
                                    {
                                        queue.push(state4);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 5)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[5], temp1[3], temp1[4], temp1[2], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (std::vector<int> &puzzle : bfs2)
                                {
                                    if (puzzle == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    steps++;
                                    bfs2.push_back(state1);
                                    queue2.push(state1);
                                    print_puzzle(steps, state1);
                                    if (is_goal_4578_2(state1, goal))
                                    {
                                        queue.push(state1);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (std::vector<int> &puzzle : bfs2)
                                {
                                    if (puzzle == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    steps++;
                                    bfs2.push_back(state2);
                                    queue2.push(state2);
                                    print_puzzle(steps, state2);
                                    if (is_goal_4578_2(state2, goal))
                                    {
                                        queue.push(state2);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state3 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[8], temp1[6], temp1[7], temp1[5], temp1[9] + 1};
                                for (std::vector<int> &puzzle : bfs2)
                                {
                                    if (puzzle == state3)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    steps++;
                                    bfs2.push_back(state3);
                                    queue2.push(state3);
                                    print_puzzle(steps, state3);
                                    if (is_goal_4578_2(state3, goal))
                                    {
                                        queue.push(state3);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 6)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[6], temp1[4], temp1[5], temp1[3], temp1[7], temp1[8], temp1[9] + 1};
                                for (std::vector<int> &puzzle : bfs2)
                                {
                                    if (puzzle == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    steps++;
                                    bfs2.push_back(state1);
                                    queue2.push(state1);
                                    print_puzzle(steps, state1);
                                    if (is_goal_4578_2(state1, goal))
                                    {
                                        queue.push(state1);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[7], temp1[6], temp1[8], temp1[9] + 1};
                                for (std::vector<int> &puzzle : bfs2)
                                {
                                    if (puzzle == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    steps++;
                                    bfs2.push_back(state2);
                                    queue2.push(state2);
                                    print_puzzle(steps, state2);
                                    if (is_goal_4578_2(state2, goal))
                                    {
                                        queue.push(state2);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 7)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8], temp1[9] + 1};
                                for (std::vector<int> &puzzle : bfs2)
                                {
                                    if (puzzle == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    steps++;
                                    bfs2.push_back(state1);
                                    queue2.push(state1);
                                    print_puzzle(steps, state1);
                                    if (is_goal_4578_2(state1, goal))
                                    {
                                        queue.push(state1);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[7], temp1[6], temp1[8], temp1[9] + 1};
                                for (std::vector<int> &puzzle : bfs2)
                                {
                                    if (puzzle == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    steps++;
                                    bfs2.push_back(state2);
                                    queue2.push(state2);
                                    print_puzzle(steps, state2);
                                    if (is_goal_4578_2(state2, goal))
                                    {
                                        queue.push(state2);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state3 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[8], temp1[7], temp1[9] + 1};
                                for (std::vector<int> &puzzle : bfs2)
                                {
                                    if (puzzle == state3)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    steps++;
                                    bfs2.push_back(state3);
                                    queue2.push(state3);
                                    print_puzzle(steps, state3);
                                    if (is_goal_4578_2(state3, goal))
                                    {
                                        queue.push(state3);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 8)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[8], temp1[6], temp1[7], temp1[5], temp1[9] + 1};
                                for (std::vector<int> &puzzle : bfs2)
                                {
                                    if (puzzle == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    steps++;
                                    bfs2.push_back(state1);
                                    queue2.push(state1);
                                    print_puzzle(steps, state1);
                                    if (is_goal_4578_2(state1, goal))
                                    {
                                        queue.push(state1);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[8], temp1[7], temp1[9] + 1};
                                for (std::vector<int> &puzzle : bfs2)
                                {
                                    if (puzzle == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    steps++;
                                    bfs2.push_back(state2);
                                    queue2.push(state2);
                                    print_puzzle(steps, state2);
                                    if (is_goal_4578_2(state2, goal))
                                    {
                                        queue.push(state2);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }
                        }
                    }
                }
            }

            else
            {
                std::queue<std::vector<int>> queue1{};    //a queue for to find a node a that is_goal_4578_1(a,goal) is true
                std::vector<std::vector<int>> bfs1{temp}; //a vector to store all of traveresed states until finding the node a that is_goal_4578_1(a,goal) is true
                queue1.push(bfs1.back());

                bool in_bfs1{false};

                while (true)
                {
                    std::vector<int> temp1 = queue1.front();
                    queue1.pop();

                    if (depth_limit != -1) //if depth limit was given by the user
                        if (temp1[9] >= depth_limit)
                        {
                            depth_reached = true;
                            std::cout << "No answers find till depth " << depth_limit << "\n";
                            break;
                        }

                    for (int j{}; j < 9; j++)
                        if (temp1[j] == 0)
                        {
                            i = j;
                            break;
                        }

                    if (goal_zero == 4 || goal_zero == 5 || goal_zero == 7 || goal_zero == 8)
                    {

                        if (i == 0)
                        {
                            std::vector<int> state1 = std::vector<int>{temp1[1], temp1[0], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                            for (std::vector<int> &puzzle : bfs1)
                            {
                                if (puzzle == state1)
                                {
                                    in_bfs1 = true;
                                    break;
                                }
                            }

                            if (!in_bfs1)
                            {
                                steps++;
                                bfs1.push_back(state1);
                                queue1.push(state1);
                                print_puzzle(steps, state1);
                                if (is_goal_4578_1(state1, goal))
                                {
                                    queue.push(state1);
                                    break;
                                }
                            }
                            in_bfs1 = false;

                            std::vector<int> state2 = std::vector<int>{temp1[3], temp1[1], temp1[2], temp1[0], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                            for (std::vector<int> &puzzle : bfs1)
                            {
                                if (puzzle == state2)
                                {
                                    in_bfs1 = true;
                                    break;
                                }
                            }

                            if (!in_bfs1)
                            {
                                steps++;
                                bfs1.push_back(state2);
                                queue1.push(state2);
                                print_puzzle(steps, state2);
                                if (is_goal_4578_1(state2, goal))
                                {
                                    queue.push(state2);
                                    break;
                                }
                            }
                            in_bfs1 = false;
                        }

                        else if (i == 1)
                        {
                            std::vector<int> state1 = std::vector<int>{temp1[1], temp1[0], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                            for (std::vector<int> &puzzle : bfs1)
                            {
                                if (puzzle == state1)
                                {
                                    in_bfs1 = true;
                                    break;
                                }
                            }

                            if (!in_bfs1)
                            {
                                steps++;
                                bfs1.push_back(state1);
                                queue1.push(state1);
                                print_puzzle(steps, state1);
                                if (is_goal_4578_1(state1, goal))
                                {
                                    queue.push(state1);
                                    break;
                                }
                            }
                            in_bfs1 = false;

                            std::vector<int> state2 = std::vector<int>{temp1[0], temp1[2], temp1[1], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                            for (std::vector<int> &puzzle : bfs1)
                            {
                                if (puzzle == state2)
                                {
                                    in_bfs1 = true;
                                    break;
                                }
                            }

                            if (!in_bfs1)
                            {
                                steps++;
                                bfs1.push_back(state2);
                                queue1.push(state2);
                                print_puzzle(steps, state2);
                                if (is_goal_4578_1(state2, goal))
                                {
                                    queue.push(state2);
                                    break;
                                }
                            }
                            in_bfs1 = false;

                            std::vector<int> state3 = std::vector<int>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                            for (std::vector<int> &puzzle : bfs1)
                            {
                                if (puzzle == state3)
                                {
                                    in_bfs1 = true;
                                    break;
                                }
                            }

                            if (!in_bfs1)
                            {
                                steps++;
                                bfs1.push_back(state3);
                                queue1.push(state3);
                                print_puzzle(steps, state3);
                                if (is_goal_4578_1(state3, goal))
                                {
                                    queue.push(state3);
                                    break;
                                }
                            }
                            in_bfs1 = false;
                        }

                        else if (i == 2)
                        {
                            std::vector<int> state1 = std::vector<int>{temp1[0], temp1[2], temp1[1], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                            for (std::vector<int> &puzzle : bfs1)
                            {
                                if (puzzle == state1)
                                {
                                    in_bfs1 = true;
                                    break;
                                }
                            }

                            if (!in_bfs1)
                            {
                                steps++;
                                bfs1.push_back(state1);
                                queue1.push(state1);
                                print_puzzle(steps, state1);
                                if (is_goal_4578_1(state1, goal))
                                {
                                    queue.push(state1);
                                    break;
                                }
                            }
                            in_bfs1 = false;

                            std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[5], temp1[3], temp1[4], temp1[2], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                            for (std::vector<int> &puzzle : bfs1)
                            {
                                if (puzzle == state2)
                                {
                                    in_bfs1 = true;
                                    break;
                                }
                            }

                            if (!in_bfs1)
                            {
                                steps++;
                                bfs1.push_back(state2);
                                queue1.push(state2);
                                print_puzzle(steps, state2);
                                if (is_goal_4578_1(state2, goal))
                                {
                                    queue.push(state2);
                                    break;
                                }
                            }
                            in_bfs1 = false;
                        }

                        else if (i == 3)
                        {
                            std::vector<int> state1 = std::vector<int>{temp1[3], temp1[1], temp1[2], temp1[0], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                            for (std::vector<int> &puzzle : bfs1)
                            {
                                if (puzzle == state1)
                                {
                                    in_bfs1 = true;
                                    break;
                                }
                            }

                            if (!in_bfs1)
                            {
                                steps++;
                                bfs1.push_back(state1);
                                queue1.push(state1);
                                print_puzzle(steps, state1);
                                if (is_goal_4578_1(state1, goal))
                                {
                                    queue.push(state1);
                                    break;
                                }
                            }
                            in_bfs1 = false;

                            std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                            for (std::vector<int> &puzzle : bfs1)
                            {
                                if (puzzle == state2)
                                {
                                    in_bfs1 = true;
                                    break;
                                }
                            }

                            if (!in_bfs1)
                            {
                                steps++;
                                bfs1.push_back(state2);
                                queue1.push(state2);
                                print_puzzle(steps, state2);
                                if (is_goal_4578_1(state2, goal))
                                {
                                    queue.push(state2);
                                    break;
                                }
                            }
                            in_bfs1 = false;

                            std::vector<int> state3 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[6], temp1[4], temp1[5], temp1[3], temp1[7], temp1[8], temp1[9] + 1};
                            for (std::vector<int> &puzzle : bfs1)
                            {
                                if (puzzle == state3)
                                {
                                    in_bfs1 = true;
                                    break;
                                }
                            }

                            if (!in_bfs1)
                            {
                                steps++;
                                bfs1.push_back(state3);
                                queue1.push(state3);
                                print_puzzle(steps, state3);
                                if (is_goal_4578_1(state3, goal))
                                {
                                    queue.push(state3);
                                    break;
                                }
                            }
                            in_bfs1 = false;
                        }

                        else if (i == 4)
                        {
                            std::vector<int> state1 = std::vector<int>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                            for (std::vector<int> &puzzle : bfs1)
                            {
                                if (puzzle == state1)
                                {
                                    in_bfs1 = true;
                                    break;
                                }
                            }

                            if (!in_bfs1)
                            {
                                steps++;
                                bfs1.push_back(state1);
                                queue1.push(state1);
                                print_puzzle(steps, state1);
                                if (is_goal_4578_1(state1, goal))
                                {
                                    queue.push(state1);
                                    break;
                                }
                            }
                            in_bfs1 = false;

                            std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                            for (std::vector<int> &puzzle : bfs1)
                            {
                                if (puzzle == state2)
                                {
                                    in_bfs1 = true;
                                    break;
                                }
                            }

                            if (!in_bfs1)
                            {
                                steps++;
                                bfs1.push_back(state2);
                                queue1.push(state2);
                                print_puzzle(steps, state2);
                                if (is_goal_4578_1(state2, goal))
                                {
                                    queue.push(state2);
                                    break;
                                }
                            }
                            in_bfs1 = false;

                            std::vector<int> state3 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                            for (std::vector<int> &puzzle : bfs1)
                            {
                                if (puzzle == state3)
                                {
                                    in_bfs1 = true;
                                    break;
                                }
                            }

                            if (!in_bfs1)
                            {
                                steps++;
                                bfs1.push_back(state3);
                                queue1.push(state3);
                                print_puzzle(steps, state3);
                                if (is_goal_4578_1(state3, goal))
                                {
                                    queue.push(state3);
                                    break;
                                }
                            }
                            in_bfs1 = false;

                            std::vector<int> state4 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8], temp1[9] + 1};
                            for (std::vector<int> &puzzle : bfs1)
                            {
                                if (puzzle == state4)
                                {
                                    in_bfs1 = true;
                                    break;
                                }
                            }

                            if (!in_bfs1)
                            {
                                steps++;
                                bfs1.push_back(state4);
                                queue1.push(state4);
                                print_puzzle(steps, state4);
                                if (is_goal_4578_1(state4, goal))
                                {
                                    queue.push(state4);
                                    break;
                                }
                            }
                            in_bfs1 = false;
                        }

                        else if (i == 5)
                        {
                            std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[5], temp1[3], temp1[4], temp1[2], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                            for (std::vector<int> &puzzle : bfs1)
                            {
                                if (puzzle == state1)
                                {
                                    in_bfs1 = true;
                                    break;
                                }
                            }

                            if (!in_bfs1)
                            {
                                steps++;
                                bfs1.push_back(state1);
                                queue1.push(state1);
                                print_puzzle(steps, state1);
                                if (is_goal_4578_1(state1, goal))
                                {
                                    queue.push(state1);
                                    break;
                                }
                            }
                            in_bfs1 = false;

                            std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                            for (std::vector<int> &puzzle : bfs1)
                            {
                                if (puzzle == state2)
                                {
                                    in_bfs1 = true;
                                    break;
                                }
                            }

                            if (!in_bfs1)
                            {
                                steps++;
                                bfs1.push_back(state2);
                                queue1.push(state2);
                                print_puzzle(steps, state2);
                                if (is_goal_4578_1(state2, goal))
                                {
                                    queue.push(state2);
                                    break;
                                }
                            }
                            in_bfs1 = false;

                            std::vector<int> state3 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[8], temp1[6], temp1[7], temp1[5], temp1[9] + 1};
                            for (std::vector<int> &puzzle : bfs1)
                            {
                                if (puzzle == state3)
                                {
                                    in_bfs1 = true;
                                    break;
                                }
                            }

                            if (!in_bfs1)
                            {
                                steps++;
                                bfs1.push_back(state3);
                                queue1.push(state3);
                                print_puzzle(steps, state3);
                                if (is_goal_4578_1(state3, goal))
                                {
                                    queue.push(state3);
                                    break;
                                }
                            }
                            in_bfs1 = false;
                        }

                        else if (i == 6)
                        {
                            std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[6], temp1[4], temp1[5], temp1[3], temp1[7], temp1[8], temp1[9] + 1};
                            for (std::vector<int> &puzzle : bfs1)
                            {
                                if (puzzle == state1)
                                {
                                    in_bfs1 = true;
                                    break;
                                }
                            }

                            if (!in_bfs1)
                            {
                                steps++;
                                bfs1.push_back(state1);
                                queue1.push(state1);
                                print_puzzle(steps, state1);
                                if (is_goal_4578_1(state1, goal))
                                {
                                    queue.push(state1);
                                    break;
                                }
                            }
                            in_bfs1 = false;

                            std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[7], temp1[6], temp1[8], temp1[9] + 1};
                            for (std::vector<int> &puzzle : bfs1)
                            {
                                if (puzzle == state2)
                                {
                                    in_bfs1 = true;
                                    break;
                                }
                            }

                            if (!in_bfs1)
                            {
                                steps++;
                                bfs1.push_back(state2);
                                queue1.push(state2);
                                print_puzzle(steps, state2);
                                if (is_goal_4578_1(state2, goal))
                                {
                                    queue.push(state2);
                                    break;
                                }
                            }
                            in_bfs1 = false;
                        }

                        else if (i == 7)
                        {
                            std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8], temp1[9] + 1};
                            for (std::vector<int> &puzzle : bfs1)
                            {
                                if (puzzle == state1)
                                {
                                    in_bfs1 = true;
                                    break;
                                }
                            }

                            if (!in_bfs1)
                            {
                                steps++;
                                bfs1.push_back(state1);
                                queue1.push(state1);
                                print_puzzle(steps, state1);
                                if (is_goal_4578_1(state1, goal))
                                {
                                    queue.push(state1);
                                    break;
                                }
                            }
                            in_bfs1 = false;

                            std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[7], temp1[6], temp1[8], temp1[9] + 1};
                            for (std::vector<int> &puzzle : bfs1)
                            {
                                if (puzzle == state2)
                                {
                                    in_bfs1 = true;
                                    break;
                                }
                            }

                            if (!in_bfs1)
                            {
                                steps++;
                                bfs1.push_back(state2);
                                queue1.push(state2);
                                print_puzzle(steps, state2);
                                if (is_goal_4578_1(state2, goal))
                                {
                                    queue.push(state2);
                                    break;
                                }
                            }
                            in_bfs1 = false;

                            std::vector<int> state3 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[8], temp1[7], temp1[9] + 1};
                            for (std::vector<int> &puzzle : bfs1)
                            {
                                if (puzzle == state3)
                                {
                                    in_bfs1 = true;
                                    break;
                                }
                            }

                            if (!in_bfs1)
                            {
                                steps++;
                                bfs1.push_back(state3);
                                queue1.push(state3);
                                print_puzzle(steps, state3);
                                if (is_goal_4578_1(state3, goal))
                                {
                                    queue.push(state3);
                                    break;
                                }
                            }
                            in_bfs1 = false;
                        }

                        else if (i == 8)
                        {
                            std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[8], temp1[6], temp1[7], temp1[5], temp1[9] + 1};
                            for (std::vector<int> &puzzle : bfs1)
                            {
                                if (puzzle == state1)
                                {
                                    in_bfs1 = true;
                                    break;
                                }
                            }

                            if (!in_bfs1)
                            {
                                steps++;
                                bfs1.push_back(state1);
                                queue1.push(state1);
                                print_puzzle(steps, state1);
                                if (is_goal_4578_1(state1, goal))
                                {
                                    queue.push(state1);
                                    break;
                                }
                            }
                            in_bfs1 = false;

                            std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[8], temp1[7], temp1[9] + 1};
                            for (std::vector<int> &puzzle : bfs1)
                            {
                                if (puzzle == state2)
                                {
                                    in_bfs1 = true;
                                    break;
                                }
                            }

                            if (!in_bfs1)
                            {
                                steps++;
                                bfs1.push_back(state2);
                                queue1.push(state2);
                                print_puzzle(steps, state2);
                                if (is_goal_4578_1(state2, goal))
                                {
                                    queue.push(state2);
                                    break;
                                }
                            }
                            in_bfs1 = false;
                        }
                    }
                }
            }
        }
    }
}

//for goal states that their empty pisition is in goal[4] or goal[5] or goal[7] or goal[8]
bool is_goal_4578_1(const std::vector<int> &state, const std::vector<int> &goal)
{
    return state[0] == goal[0];
}

bool is_goal_4578_2(const std::vector<int> &state, const std::vector<int> &goal)
{
    return (state[1] == goal[1] && state[2] == goal[2]);
}

bool is_goal_4578_3(const std::vector<int> &state, const std::vector<int> &goal)
{
    return (state[3] == goal[3] && state[6] == goal[6]);
}

bool is_goal_4578_4(const std::vector<int> &state, const std::vector<int> &goal)
{
    return (state[4] == goal[4] && state[5] == goal[5] && state[7] == goal[7] && state[8] == goal[8]);
}

//for goal states that their empty pisition is in goal[0] or goal[1] or goal[3]
bool is_goal_013_1(const std::vector<int> &state, const std::vector<int> &goal)
{
    return state[8] == goal[8];
}

bool is_goal_013_2(const std::vector<int> &state, const std::vector<int> &goal)
{
    return (state[5] == goal[5] && state[2] == goal[2]);
}

bool is_goal_013_3(const std::vector<int> &state, const std::vector<int> &goal)
{
    return (state[7] == goal[7] && state[6] == goal[6]);
}

bool is_goal_013_4(const std::vector<int> &state, const std::vector<int> &goal)
{
    return (state[0] == goal[0] && state[1] == goal[1] && state[3] == goal[3] && state[4] == goal[4]);
}

//for goal states that their empty pisition is in goal[2]
bool is_goal_2_1(const std::vector<int> &state, const std::vector<int> &goal)
{
    return state[6] == goal[6];
}

bool is_goal_2_2(const std::vector<int> &state, const std::vector<int> &goal)
{
    return (state[7] == goal[7] && state[8] == goal[8]);
}

bool is_goal_2_3(const std::vector<int> &state, const std::vector<int> &goal)
{
    return (state[3] == goal[3] && state[0] == goal[0]);
}

bool is_goal_2_4(const std::vector<int> &state, const std::vector<int> &goal)
{
    return (state[1] == goal[1] && state[2] == goal[2] && state[4] == goal[4] && state[5] == goal[5]);
}

//for goal states that their empty pisition is in goal[6]
bool is_goal_6_1(const std::vector<int> &state, const std::vector<int> &goal)
{
    return state[2] == goal[2];
}

bool is_goal_6_2(const std::vector<int> &state, const std::vector<int> &goal)
{
    return (state[5] == goal[5] && state[8] == goal[8]);
}

bool is_goal_6_3(const std::vector<int> &state, const std::vector<int> &goal)
{
    return (state[0] == goal[0] && state[1] == goal[1]);
}

bool is_goal_6_4(const std::vector<int> &state, const std::vector<int> &goal)
{
    return (state[3] == goal[3] && state[4] == goal[4] && state[6] == goal[6] && state[7] == goal[7]);
}
