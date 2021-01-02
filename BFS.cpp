#include "BFS.h"
#include "DFS.h"

#include <utility>

void BFS(std::vector<int> &initial, const std::vector<int> &goal, const int &depth_limit)
{
    if (!isSolvable(initial, goal))
    {
        std::cout << "\u001b[31;1m"; //Bright Red
        std::cout << "\n*************************\n";
        std::cout << "This puzzle is not solvable\n";
        std::cout << "*************************\n";
        std::cout << "\u001b[0m"; //reset color and style
    }

    else if (initial == goal) //when the initial puzzle is the goal puzzle!
    {
        std::cout << "\u001b[32;1m"; //Bright Green
        std::cout << "\n*************************\n";
        std::cout << "******\u001b[36;1mPUZZLE SOLVED\u001b[32;1m******\nNumber of steps: 0 || your initial puzzle is the goal puzzle\n";
        std::cout << "*************************\n";
        std::cout << "\u001b[0m"; //reset color and style
    }

    else
    {
        initial.push_back(0); //This is the depth level of the Node
        Node init{initial};

        bool goal_finded{false};   //We use it to end the while loop
        bool depth_reached{false}; //We use it to stop function when we traversed all Node till ours depth limit
        int i{};                   //position of the empty block in each state(here we use zero instead of empty, but when we print the puzzle, we print " " instead of "0")

        int goal_zero{}; //position of the empty block in the goal state
        for (int i{}; i < 9; i++)
            if (goal[i] == 0)
            {
                goal_zero = i;
                break;
            }

        while (!goal_finded && !depth_reached)
        {

            bool condition_1{false};
            bool condition_2{false};
            bool condition_3{false};
            if (goal_zero == 4 || goal_zero == 5 || goal_zero == 7 || goal_zero == 8)
            {
                condition_1 = is_goal_4578_1(init.state, goal);
                condition_2 = is_goal_4578_2(init.state, goal);
                condition_3 = is_goal_4578_3(init.state, goal);
            }
            else if (goal_zero == 0 || goal_zero == 1 || goal_zero == 3)
            {
                condition_1 = is_goal_013_1(init.state, goal);
                condition_2 = is_goal_013_2(init.state, goal);
                condition_3 = is_goal_013_3(init.state, goal);
            }
            else if (goal_zero == 2)
            {
                condition_1 = is_goal_2_1(init.state, goal);
                condition_2 = is_goal_2_2(init.state, goal);
                condition_3 = is_goal_2_3(init.state, goal);
            }
            else
            {
                condition_1 = is_goal_6_1(init.state, goal);
                condition_2 = is_goal_6_2(init.state, goal);
                condition_3 = is_goal_6_3(init.state, goal);
            }

            if (condition_1)
            {
                if (condition_2)
                {
                    if (condition_3)
                    {
                        if (is_goal(init.state, goal))
                        {
                            solved_Fast_BFS(init, goal);
                            goal_finded = true;
                            break;
                        }
                        else
                        {
                            /********************************************************************************************************************************************************************************
                             **************************************************************************Step 4 of solving the puzzle**************************************************************************
                             ********************************************************************************************************************************************************************************/

                            std::queue<Node> queue4{};    //a queue to find a node "a" that is_goal_4578_4(a,goal) or is_goal_013_4(a,goal) or is_goal_2_4(a,goal) or is_goal_6_4(a,goal) is true
                            std::vector<Node> bfs4{init}; //a vector to store all of traveresed states until finding the node "a" that is_goal_4578_4(a,goal) or is_goal_013_4(a,goal) or is_goal_2_4(a,goal) or is_goal_6_4(a,goal) is true
                            queue4.push(bfs4.back());

                            bool in_bfs4{false};

                            while (true)
                            {
                                Node temp1 = queue4.front();
                                queue4.pop();

                                if (depth_limit != -1) //if depth limit was given by the user
                                    if (temp1[9] >= depth_limit)
                                    {
                                        depth_reached = true;
                                        std::cout << "\u001b[31;1mNo answers find till depth " << depth_limit << "\u001b[0m\n";
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
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state1)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state1};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_4578_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;

                                        std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state2)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state2};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_4578_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;
                                    }

                                    else if (i == 5)
                                    {
                                        std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[8], temp1[6], temp1[7], temp1[5], temp1[9] + 1};
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state1)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state1};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_4578_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;

                                        std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state2)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state2};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_4578_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;
                                    }

                                    else if (i == 7)
                                    {
                                        std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8], temp1[9] + 1};
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state1)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state1};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_4578_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;

                                        std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[8], temp1[7], temp1[9] + 1};
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state2)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state2};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_4578_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;
                                    }

                                    else if (i == 8)
                                    {
                                        std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[8], temp1[6], temp1[7], temp1[5], temp1[9] + 1};
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state1)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state1};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_4578_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;

                                        std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[8], temp1[7], temp1[9] + 1};
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state2)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state2};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_4578_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;
                                    }
                                }

                                else if (goal_zero == 0 || goal_zero == 1 || goal_zero == 3)
                                {
                                    if (i == 0)
                                    {
                                        std::vector<int> state1 = std::vector<int>{temp1[1], temp1[0], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state1)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state1};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_013_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;

                                        std::vector<int> state2 = std::vector<int>{temp1[3], temp1[1], temp1[2], temp1[0], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state2)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state2};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_013_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;
                                    }

                                    else if (i == 1)
                                    {
                                        std::vector<int> state1 = std::vector<int>{temp1[1], temp1[0], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state1)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state1};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_013_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;

                                        std::vector<int> state2 = std::vector<int>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state2)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state2};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_013_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;
                                    }

                                    else if (i == 3)
                                    {
                                        std::vector<int> state1 = std::vector<int>{temp1[3], temp1[1], temp1[2], temp1[0], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state1)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state1};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_013_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;

                                        std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state2)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state2};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_013_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;
                                    }

                                    else if (i == 4)
                                    {
                                        std::vector<int> state1 = std::vector<int>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state1)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state1};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_013_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;

                                        std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state2)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state2};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_013_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;
                                    }
                                }

                                else if (goal_zero == 2)
                                {
                                    if (i == 1)
                                    {
                                        std::vector<int> state1 = std::vector<int>{temp1[0], temp1[2], temp1[1], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state1)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state1};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_2_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;

                                        std::vector<int> state2 = std::vector<int>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state2)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state2};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_2_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;
                                    }

                                    else if (i == 2)
                                    {
                                        std::vector<int> state1 = std::vector<int>{temp1[0], temp1[2], temp1[1], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state1)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state1};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_2_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;

                                        std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[5], temp1[3], temp1[4], temp1[2], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state2)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state2};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_2_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;
                                    }

                                    else if (i == 4)
                                    {
                                        std::vector<int> state1 = std::vector<int>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state1)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state1};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_2_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;

                                        std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state2)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state2};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_2_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;
                                    }

                                    else if (i == 5)
                                    {
                                        std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[5], temp1[3], temp1[4], temp1[2], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state1)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state1};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_2_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;

                                        std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state2)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state2};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_2_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;
                                    }
                                }

                                else //goal_zero = 6
                                {
                                    if (i == 3)
                                    {
                                        std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state1)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state1};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_6_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;

                                        std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[6], temp1[4], temp1[5], temp1[3], temp1[7], temp1[8], temp1[9] + 1};
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state2)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state2};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_6_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;
                                    }

                                    else if (i == 4)
                                    {
                                        std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state1)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state1};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_6_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;

                                        std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8], temp1[9] + 1};
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state2)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state2};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_6_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;
                                    }

                                    else if (i == 6)
                                    {
                                        std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[6], temp1[4], temp1[5], temp1[3], temp1[7], temp1[8], temp1[9] + 1};
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state1)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state1};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_6_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;

                                        std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[7], temp1[6], temp1[8], temp1[9] + 1};
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state2)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state2};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_6_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;
                                    }

                                    else if (i == 7)
                                    {
                                        std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8], temp1[9] + 1};
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state1)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state1};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_6_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;

                                        std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[7], temp1[6], temp1[8], temp1[9] + 1};
                                        for (auto &node : bfs4)
                                        {
                                            if (node.state == state2)
                                            {
                                                in_bfs4 = true;
                                                break;
                                            }
                                        }

                                        if (!in_bfs4)
                                        {
                                            Node node{temp1, state2};
                                            bfs4.push_back(node);
                                            queue4.push(node);
                                            if (is_goal_6_4(node.state, goal))
                                            {
                                                solved_Fast_BFS(node, goal);
                                                goal_finded = true;
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;
                                    }
                                }
                            }
                        }
                    }

                    else
                    {
                        /********************************************************************************************************************************************************************************
                         **************************************************************************Step 3 of solving the puzzle**************************************************************************
                         ********************************************************************************************************************************************************************************/

                        std::queue<Node> queue3{};    //a queue to find a node "a" that is_goal_4578_3(a,goal) or is_goal_013_3(a,goal) or is_goal_2_3(a,goal) or is_goal_6_3(a,goal) is true
                        std::vector<Node> bfs3{init}; //a vector to store all of traveresed states until finding the node "a" that is_goal_4578_3(a,goal) or is_goal_013_3(a,goal) or is_goal_2_3(a,goal) or is_goal_6_3(a,goal) is true
                        queue3.push(bfs3.back());

                        bool in_bfs3{false};

                        while (true)
                        {
                            Node temp1 = queue3.front();
                            queue3.pop();

                            if (depth_limit != -1) //if depth limit was given by the user
                                if (temp1[9] >= depth_limit)
                                {
                                    depth_reached = true;
                                    std::cout << "\u001b[31;1mNo answers find till depth " << depth_limit << "\u001b[0m\n";
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
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state1)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state1};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_4578_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[6], temp1[4], temp1[5], temp1[3], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state2)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state2};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_4578_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }

                                else if (i == 4)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state1)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state1};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_4578_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state2)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state2};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_4578_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state3 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state3)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state3};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_4578_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }

                                else if (i == 5)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[8], temp1[6], temp1[7], temp1[5], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state1)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state1};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_4578_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state2)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state2};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_4578_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }

                                else if (i == 6)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[6], temp1[4], temp1[5], temp1[3], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state1)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state1};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_4578_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[7], temp1[6], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state2)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state2};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_4578_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }

                                else if (i == 7)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state1)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state1};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_4578_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[7], temp1[6], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state2)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state2};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_4578_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state3 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[8], temp1[7], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state3)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state3};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_4578_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }

                                else if (i == 8)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[8], temp1[6], temp1[7], temp1[5], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state1)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state1};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_4578_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[8], temp1[7], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state2)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state2};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_4578_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }
                            }

                            else if (goal_zero == 0 || goal_zero == 1 || goal_zero == 3)
                            {
                                if (i == 0)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[1], temp1[0], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state1)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state1};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_013_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[3], temp1[1], temp1[2], temp1[0], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state2)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state2};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_013_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }

                                else if (i == 1)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[1], temp1[0], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state1)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state1};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_013_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state2)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state2};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_013_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }

                                else if (i == 3)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[3], temp1[1], temp1[2], temp1[0], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state1)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state1};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_013_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state2)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state2};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_013_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state3 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[6], temp1[4], temp1[5], temp1[3], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state3)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state3};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_013_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }

                                else if (i == 4)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state1)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state1};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_013_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state2)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state2};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_013_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state3 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state3)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state3};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_013_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }

                                else if (i == 6)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[6], temp1[4], temp1[5], temp1[3], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state1)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state1};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_013_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[7], temp1[6], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state2)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state2};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_013_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }

                                else if (i == 7)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state1)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state1};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_013_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[7], temp1[6], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state2)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state2};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_013_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }
                            }

                            else if (goal_zero == 2)
                            {
                                if (i == 0)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[1], temp1[0], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state1)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state1};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_2_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[3], temp1[1], temp1[2], temp1[0], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state2)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state2};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_2_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }

                                else if (i == 1)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[1], temp1[0], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state1)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state1};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_2_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state2)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state2};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_2_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state3 = std::vector<int>{temp1[0], temp1[2], temp1[1], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state3)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state3};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_2_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }

                                else if (i == 2)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[0], temp1[2], temp1[1], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state1)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state1};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_2_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[5], temp1[3], temp1[4], temp1[2], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state2)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state2};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_2_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }

                                else if (i == 3)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[3], temp1[1], temp1[2], temp1[0], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state1)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state1};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_2_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state2)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state2};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_2_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }

                                else if (i == 4)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state1)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state1};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_2_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state2)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state2};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_2_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state3 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state3)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state3};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_2_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }

                                else if (i == 5)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[5], temp1[3], temp1[4], temp1[2], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state1)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state1};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_2_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state2)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state2};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_2_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }
                            }

                            else //goal_zero = 6
                            {
                                if (i == 0)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[1], temp1[0], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state1)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state1};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_6_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[3], temp1[1], temp1[2], temp1[0], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state2)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state2};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_6_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }

                                else if (i == 1)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[1], temp1[0], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state1)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state1};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_6_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state2)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state2};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_6_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }

                                else if (i == 3)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[3], temp1[1], temp1[2], temp1[0], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state1)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state1};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_6_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state2)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state2};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_6_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state3 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[6], temp1[4], temp1[5], temp1[3], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state3)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state3};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_6_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }

                                else if (i == 4)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state1)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state1};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_6_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state2)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state2};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_6_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state3 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state3)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state3};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_6_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }

                                else if (i == 6)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[6], temp1[4], temp1[5], temp1[3], temp1[7], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state1)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state1};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_6_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[7], temp1[6], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state2)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state2};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_6_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }

                                else if (i == 7)
                                {
                                    std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state1)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state1};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_6_3(node.state, goal))
                                        {
                                            init = std::move(node);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[7], temp1[6], temp1[8], temp1[9] + 1};
                                    for (auto &node : bfs3)
                                    {
                                        if (node.state == state2)
                                        {
                                            in_bfs3 = true;
                                            break;
                                        }
                                    }

                                    if (!in_bfs3)
                                    {
                                        Node node{temp1, state2};
                                        bfs3.push_back(node);
                                        queue3.push(node);
                                        if (is_goal_6_3(node.state, goal))
                                        {
                                            init = std::move(node);
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
                    /********************************************************************************************************************************************************************************
                     **************************************************************************Step 2 of solving the puzzle**************************************************************************
                     ********************************************************************************************************************************************************************************/

                    std::queue<Node> queue2{};    //a queue to find a node "a" that is_goal_4578_2(a,goal) or is_goal_013_2(a,goal) or is_goal_2_2(a,goal) or is_goal_6_2(a,goal) is true
                    std::vector<Node> bfs2{init}; //a vector to store all of traveresed states until finding the node "a" that is_goal_4578_2(a,goal) or is_goal_013_2(a,goal) or is_goal_2_2(a,goal) or is_goal_6_2(a,goal) is true
                    queue2.push(bfs2.back());

                    bool in_bfs2{false};
                    while (true)
                    {
                        Node temp1 = queue2.front();
                        queue2.pop();
                        if (depth_limit != -1) //if depth limit was given by the user
                            if (temp1[9] >= depth_limit)
                            {
                                depth_reached = true;
                                std::cout << "\u001b[31;1mNo answers find till depth " << depth_limit << "\u001b[0m\n";
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
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_4578_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_4578_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 2)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[2], temp1[1], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_4578_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[5], temp1[3], temp1[4], temp1[2], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_4578_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 3)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_4578_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[6], temp1[4], temp1[5], temp1[3], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_4578_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 4)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_4578_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_4578_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state3 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state3)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state3};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_4578_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state4 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state4)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state4};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_4578_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 5)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[5], temp1[3], temp1[4], temp1[2], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_4578_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_4578_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state3 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[8], temp1[6], temp1[7], temp1[5], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state3)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state3};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_4578_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 6)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[6], temp1[4], temp1[5], temp1[3], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_4578_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[7], temp1[6], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_4578_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 7)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_4578_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[7], temp1[6], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_4578_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state3 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[8], temp1[7], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state3)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state3};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_4578_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 8)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[8], temp1[6], temp1[7], temp1[5], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_4578_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[8], temp1[7], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_4578_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }
                        }

                        else if (goal_zero == 0 || goal_zero == 1 || goal_zero == 3)
                        {
                            if (i == 0)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[1], temp1[0], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_013_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[3], temp1[1], temp1[2], temp1[0], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_013_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }
                            else if (i == 1)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[2], temp1[1], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_013_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_013_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state3 = std::vector<int>{temp1[1], temp1[0], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state3)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state3};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_013_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 2)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[2], temp1[1], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_013_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[5], temp1[3], temp1[4], temp1[2], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_013_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 3)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_013_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[6], temp1[4], temp1[5], temp1[3], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_013_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state3 = std::vector<int>{temp1[3], temp1[1], temp1[2], temp1[0], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state3)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state3};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_013_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 4)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_013_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_013_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state3 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state3)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state3};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_013_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state4 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state4)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state4};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_013_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 5)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[5], temp1[3], temp1[4], temp1[2], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_013_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_013_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 6)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[6], temp1[4], temp1[5], temp1[3], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_013_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[7], temp1[6], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_013_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 7)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_013_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[7], temp1[6], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_013_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }
                        }

                        else if (goal_zero == 2)
                        {
                            if (i == 0)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[1], temp1[0], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_2_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[3], temp1[1], temp1[2], temp1[0], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_2_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }
                            else if (i == 1)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[2], temp1[1], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_2_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_2_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state3 = std::vector<int>{temp1[1], temp1[0], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state3)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state3};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_2_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 2)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[2], temp1[1], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_2_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[5], temp1[3], temp1[4], temp1[2], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_2_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 3)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_2_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[3], temp1[1], temp1[2], temp1[0], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_2_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 4)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_2_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_2_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state3 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state3)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state3};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_2_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state4 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state4)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state4};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_2_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 5)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[5], temp1[3], temp1[4], temp1[2], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_2_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_2_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state3 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[8], temp1[6], temp1[7], temp1[5], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state3)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state3};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_2_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 7)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_2_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[8], temp1[7], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_2_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 8)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[8], temp1[6], temp1[7], temp1[5], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_2_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[8], temp1[7], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_2_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }
                        }

                        else //goal_zero = 6
                        {
                            if (i == 0)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[1], temp1[0], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_6_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[3], temp1[1], temp1[2], temp1[0], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_6_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }
                            else if (i == 1)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[1], temp1[0], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_6_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_6_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 3)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_6_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[3], temp1[1], temp1[2], temp1[0], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_6_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state3 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[6], temp1[4], temp1[5], temp1[3], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state3)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state3};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_6_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 4)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_6_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_6_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state3 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state3)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state3};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_6_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state4 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state4)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state4};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_6_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 5)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[8], temp1[6], temp1[7], temp1[5], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_6_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_6_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 6)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[6], temp1[4], temp1[5], temp1[3], temp1[7], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_6_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[7], temp1[6], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_6_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 7)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_6_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[8], temp1[7], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_6_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state3 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[7], temp1[6], temp1[8], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state3)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state3};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_6_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }

                            else if (i == 8)
                            {
                                std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[8], temp1[6], temp1[7], temp1[5], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state1)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state1};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_6_2(node.state, goal))
                                    {
                                        init = std::move(node);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[8], temp1[7], temp1[9] + 1};
                                for (auto &node : bfs2)
                                {
                                    if (node.state == state2)
                                    {
                                        in_bfs2 = true;
                                        break;
                                    }
                                }

                                if (!in_bfs2)
                                {
                                    Node node{temp1, state2};
                                    bfs2.push_back(node);
                                    queue2.push(node);
                                    if (is_goal_6_2(node.state, goal))
                                    {
                                        init = std::move(node);
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
                /********************************************************************************************************************************************************************************
                 **************************************************************************Step 1 of solving the puzzle**************************************************************************
                 ********************************************************************************************************************************************************************************/

                std::queue<Node> queue1{};    //a queue to find a node "a" that is_goal_4578_1(a,goal) or is_goal_013_1(a,goal) or is_goal_2_1(a,goal) or is_goal_6_1(a,goal) is true
                std::vector<Node> bfs1{init}; //a vector to store all of traveresed states until finding the node "a" that is_goal_4578_1(a,goal) or is_goal_013_1(a,goal) or is_goal_2_1(a,goal) or is_goal_6_1(a,goal) is true
                queue1.push(bfs1.back());

                bool in_bfs1{false};

                while (true)
                {
                    Node temp1 = queue1.front();
                    queue1.pop();

                    if (depth_limit != -1) //if depth limit was given by the user
                        if (temp1[9] >= depth_limit)
                        {
                            depth_reached = true;
                            std::cout << "\u001b[31;1mNo answers find till depth " << depth_limit << "\u001b[0m\n";
                            break;
                        }

                    for (int j{}; j < 9; j++)
                        if (temp1[j] == 0)
                        {
                            i = j;
                            break;
                        }

                    if (i == 0)
                    {
                        std::vector<int> state1 = std::vector<int>{temp1[1], temp1[0], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                        for (auto &node : bfs1)
                        {
                            if (node.state == state1)
                            {
                                in_bfs1 = true;
                                break;
                            }
                        }

                        if (!in_bfs1)
                        {
                            Node node{temp1, state1};
                            bfs1.push_back(node);
                            queue1.push(node);
                            if (goal_zero == 4 || goal_zero == 5 || goal_zero == 7 || goal_zero == 8)
                            {
                                if (is_goal_4578_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 0 || goal_zero == 1 || goal_zero == 3)
                            {
                                if (is_goal_013_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 2)
                            {
                                if (is_goal_2_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else //goal_zero = 6
                            {
                                if (is_goal_6_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                        }
                        in_bfs1 = false;

                        std::vector<int> state2 = std::vector<int>{temp1[3], temp1[1], temp1[2], temp1[0], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                        for (auto &node : bfs1)
                        {
                            if (node.state == state2)
                            {
                                in_bfs1 = true;
                                break;
                            }
                        }

                        if (!in_bfs1)
                        {
                            Node node{temp1, state2};
                            bfs1.push_back(node);
                            queue1.push(node);
                            if (goal_zero == 4 || goal_zero == 5 || goal_zero == 7 || goal_zero == 8)
                            {
                                if (is_goal_4578_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 0 || goal_zero == 1 || goal_zero == 3)
                            {
                                if (is_goal_013_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 2)
                            {
                                if (is_goal_2_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else //goal_zero = 6
                            {
                                if (is_goal_6_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                        }
                        in_bfs1 = false;
                    }

                    else if (i == 1)
                    {
                        std::vector<int> state1 = std::vector<int>{temp1[1], temp1[0], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                        for (auto &node : bfs1)
                        {
                            if (node.state == state1)
                            {
                                in_bfs1 = true;
                                break;
                            }
                        }

                        if (!in_bfs1)
                        {
                            Node node{temp1, state1};
                            bfs1.push_back(node);
                            queue1.push(node);
                            if (goal_zero == 4 || goal_zero == 5 || goal_zero == 7 || goal_zero == 8)
                            {
                                if (is_goal_4578_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 0 || goal_zero == 1 || goal_zero == 3)
                            {
                                if (is_goal_013_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 2)
                            {
                                if (is_goal_2_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else //goal_zero = 6
                            {
                                if (is_goal_6_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                        }
                        in_bfs1 = false;

                        std::vector<int> state2 = std::vector<int>{temp1[0], temp1[2], temp1[1], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                        for (auto &node : bfs1)
                        {
                            if (node.state == state2)
                            {
                                in_bfs1 = true;
                                break;
                            }
                        }

                        if (!in_bfs1)
                        {
                            Node node{temp1, state2};
                            bfs1.push_back(node);
                            queue1.push(node);
                            if (goal_zero == 4 || goal_zero == 5 || goal_zero == 7 || goal_zero == 8)
                            {
                                if (is_goal_4578_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 0 || goal_zero == 1 || goal_zero == 3)
                            {
                                if (is_goal_013_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 2)
                            {
                                if (is_goal_2_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else //goal_zero = 6
                            {
                                if (is_goal_6_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                        }
                        in_bfs1 = false;

                        std::vector<int> state3 = std::vector<int>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                        for (auto &node : bfs1)
                        {
                            if (node.state == state3)
                            {
                                in_bfs1 = true;
                                break;
                            }
                        }

                        if (!in_bfs1)
                        {
                            Node node{temp1, state3};
                            bfs1.push_back(node);
                            queue1.push(node);
                            if (goal_zero == 4 || goal_zero == 5 || goal_zero == 7 || goal_zero == 8)
                            {
                                if (is_goal_4578_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 0 || goal_zero == 1 || goal_zero == 3)
                            {
                                if (is_goal_013_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 2)
                            {
                                if (is_goal_2_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else //goal_zero = 6
                            {
                                if (is_goal_6_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                        }
                        in_bfs1 = false;
                    }

                    else if (i == 2)
                    {
                        std::vector<int> state1 = std::vector<int>{temp1[0], temp1[2], temp1[1], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                        for (auto &node : bfs1)
                        {
                            if (node.state == state1)
                            {
                                in_bfs1 = true;
                                break;
                            }
                        }

                        if (!in_bfs1)
                        {
                            Node node{temp1, state1};
                            bfs1.push_back(node);
                            queue1.push(node);
                            if (goal_zero == 4 || goal_zero == 5 || goal_zero == 7 || goal_zero == 8)
                            {
                                if (is_goal_4578_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 0 || goal_zero == 1 || goal_zero == 3)
                            {
                                if (is_goal_013_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 2)
                            {
                                if (is_goal_2_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else //goal_zero = 6
                            {
                                if (is_goal_6_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                        }
                        in_bfs1 = false;

                        std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[5], temp1[3], temp1[4], temp1[2], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                        for (auto &node : bfs1)
                        {
                            if (node.state == state2)
                            {
                                in_bfs1 = true;
                                break;
                            }
                        }

                        if (!in_bfs1)
                        {
                            Node node{temp1, state2};
                            bfs1.push_back(node);
                            queue1.push(node);
                            if (goal_zero == 4 || goal_zero == 5 || goal_zero == 7 || goal_zero == 8)
                            {
                                if (is_goal_4578_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 0 || goal_zero == 1 || goal_zero == 3)
                            {
                                if (is_goal_013_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 2)
                            {
                                if (is_goal_2_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else //goal_zero = 6
                            {
                                if (is_goal_6_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                        }
                        in_bfs1 = false;
                    }

                    else if (i == 3)
                    {
                        std::vector<int> state1 = std::vector<int>{temp1[3], temp1[1], temp1[2], temp1[0], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                        for (auto &node : bfs1)
                        {
                            if (node.state == state1)
                            {
                                in_bfs1 = true;
                                break;
                            }
                        }

                        if (!in_bfs1)
                        {
                            Node node{temp1, state1};
                            bfs1.push_back(node);
                            queue1.push(node);
                            if (goal_zero == 4 || goal_zero == 5 || goal_zero == 7 || goal_zero == 8)
                            {
                                if (is_goal_4578_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 0 || goal_zero == 1 || goal_zero == 3)
                            {
                                if (is_goal_013_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 2)
                            {
                                if (is_goal_2_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else //goal_zero = 6
                            {
                                if (is_goal_6_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                        }
                        in_bfs1 = false;

                        std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                        for (auto &node : bfs1)
                        {
                            if (node.state == state2)
                            {
                                in_bfs1 = true;
                                break;
                            }
                        }

                        if (!in_bfs1)
                        {
                            Node node{temp1, state2};
                            bfs1.push_back(node);
                            queue1.push(node);
                            if (goal_zero == 4 || goal_zero == 5 || goal_zero == 7 || goal_zero == 8)
                            {
                                if (is_goal_4578_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 0 || goal_zero == 1 || goal_zero == 3)
                            {
                                if (is_goal_013_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 2)
                            {
                                if (is_goal_2_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else //goal_zero = 6
                            {
                                if (is_goal_6_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                        }
                        in_bfs1 = false;

                        std::vector<int> state3 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[6], temp1[4], temp1[5], temp1[3], temp1[7], temp1[8], temp1[9] + 1};
                        for (auto &node : bfs1)
                        {
                            if (node.state == state3)
                            {
                                in_bfs1 = true;
                                break;
                            }
                        }

                        if (!in_bfs1)
                        {
                            Node node{temp1, state3};
                            bfs1.push_back(node);
                            queue1.push(node);
                            if (goal_zero == 4 || goal_zero == 5 || goal_zero == 7 || goal_zero == 8)
                            {
                                if (is_goal_4578_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 0 || goal_zero == 1 || goal_zero == 3)
                            {
                                if (is_goal_013_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 2)
                            {
                                if (is_goal_2_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else //goal_zero = 6
                            {
                                if (is_goal_6_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                        }
                        in_bfs1 = false;
                    }

                    else if (i == 4)
                    {
                        std::vector<int> state1 = std::vector<int>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                        for (auto &node : bfs1)
                        {
                            if (node.state == state1)
                            {
                                in_bfs1 = true;
                                break;
                            }
                        }

                        if (!in_bfs1)
                        {
                            Node node{temp1, state1};
                            bfs1.push_back(node);
                            queue1.push(node);
                            if (goal_zero == 4 || goal_zero == 5 || goal_zero == 7 || goal_zero == 8)
                            {
                                if (is_goal_4578_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 0 || goal_zero == 1 || goal_zero == 3)
                            {
                                if (is_goal_013_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 2)
                            {
                                if (is_goal_2_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else //goal_zero = 6
                            {
                                if (is_goal_6_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                        }
                        in_bfs1 = false;

                        std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                        for (auto &node : bfs1)
                        {
                            if (node.state == state2)
                            {
                                in_bfs1 = true;
                                break;
                            }
                        }

                        if (!in_bfs1)
                        {
                            Node node{temp1, state2};
                            bfs1.push_back(node);
                            queue1.push(node);
                            if (goal_zero == 4 || goal_zero == 5 || goal_zero == 7 || goal_zero == 8)
                            {
                                if (is_goal_4578_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 0 || goal_zero == 1 || goal_zero == 3)
                            {
                                if (is_goal_013_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 2)
                            {
                                if (is_goal_2_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else //goal_zero = 6
                            {
                                if (is_goal_6_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                        }
                        in_bfs1 = false;

                        std::vector<int> state3 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                        for (auto &node : bfs1)
                        {
                            if (node.state == state3)
                            {
                                in_bfs1 = true;
                                break;
                            }
                        }

                        if (!in_bfs1)
                        {
                            Node node{temp1, state3};
                            bfs1.push_back(node);
                            queue1.push(node);
                            if (goal_zero == 4 || goal_zero == 5 || goal_zero == 7 || goal_zero == 8)
                            {
                                if (is_goal_4578_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 0 || goal_zero == 1 || goal_zero == 3)
                            {
                                if (is_goal_013_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 2)
                            {
                                if (is_goal_2_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else //goal_zero = 6
                            {
                                if (is_goal_6_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                        }
                        in_bfs1 = false;

                        std::vector<int> state4 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8], temp1[9] + 1};
                        for (auto &node : bfs1)
                        {
                            if (node.state == state4)
                            {
                                in_bfs1 = true;
                                break;
                            }
                        }

                        if (!in_bfs1)
                        {
                            Node node{temp1, state4};
                            bfs1.push_back(node);
                            queue1.push(node);
                            if (goal_zero == 4 || goal_zero == 5 || goal_zero == 7 || goal_zero == 8)
                            {
                                if (is_goal_4578_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 0 || goal_zero == 1 || goal_zero == 3)
                            {
                                if (is_goal_013_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 2)
                            {
                                if (is_goal_2_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else //goal_zero = 6
                            {
                                if (is_goal_6_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                        }
                        in_bfs1 = false;
                    }

                    else if (i == 5)
                    {
                        std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[5], temp1[3], temp1[4], temp1[2], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                        for (auto &node : bfs1)
                        {
                            if (node.state == state1)
                            {
                                in_bfs1 = true;
                                break;
                            }
                        }

                        if (!in_bfs1)
                        {
                            Node node{temp1, state1};
                            bfs1.push_back(node);
                            queue1.push(node);
                            if (goal_zero == 4 || goal_zero == 5 || goal_zero == 7 || goal_zero == 8)
                            {
                                if (is_goal_4578_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 0 || goal_zero == 1 || goal_zero == 3)
                            {
                                if (is_goal_013_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 2)
                            {
                                if (is_goal_2_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else //goal_zero = 6
                            {
                                if (is_goal_6_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                        }
                        in_bfs1 = false;

                        std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8], temp1[9] + 1};
                        for (auto &node : bfs1)
                        {
                            if (node.state == state2)
                            {
                                in_bfs1 = true;
                                break;
                            }
                        }

                        if (!in_bfs1)
                        {
                            Node node{temp1, state2};
                            bfs1.push_back(node);
                            queue1.push(node);
                            if (goal_zero == 4 || goal_zero == 5 || goal_zero == 7 || goal_zero == 8)
                            {
                                if (is_goal_4578_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 0 || goal_zero == 1 || goal_zero == 3)
                            {
                                if (is_goal_013_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 2)
                            {
                                if (is_goal_2_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else //goal_zero = 6
                            {
                                if (is_goal_6_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                        }
                        in_bfs1 = false;

                        std::vector<int> state3 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[8], temp1[6], temp1[7], temp1[5], temp1[9] + 1};
                        for (auto &node : bfs1)
                        {
                            if (node.state == state3)
                            {
                                in_bfs1 = true;
                                break;
                            }
                        }

                        if (!in_bfs1)
                        {
                            Node node{temp1, state3};
                            bfs1.push_back(node);
                            queue1.push(node);
                            if (goal_zero == 4 || goal_zero == 5 || goal_zero == 7 || goal_zero == 8)
                            {
                                if (is_goal_4578_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 0 || goal_zero == 1 || goal_zero == 3)
                            {
                                if (is_goal_013_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 2)
                            {
                                if (is_goal_2_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else //goal_zero = 6
                            {
                                if (is_goal_6_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                        }
                        in_bfs1 = false;
                    }

                    else if (i == 6)
                    {
                        std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[6], temp1[4], temp1[5], temp1[3], temp1[7], temp1[8], temp1[9] + 1};
                        for (auto &node : bfs1)
                        {
                            if (node.state == state1)
                            {
                                in_bfs1 = true;
                                break;
                            }
                        }

                        if (!in_bfs1)
                        {
                            Node node{temp1, state1};
                            bfs1.push_back(node);
                            queue1.push(node);
                            if (goal_zero == 4 || goal_zero == 5 || goal_zero == 7 || goal_zero == 8)
                            {
                                if (is_goal_4578_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 0 || goal_zero == 1 || goal_zero == 3)
                            {
                                if (is_goal_013_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 2)
                            {
                                if (is_goal_2_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else //goal_zero = 6
                            {
                                if (is_goal_6_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                        }
                        in_bfs1 = false;

                        std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[7], temp1[6], temp1[8], temp1[9] + 1};
                        for (auto &node : bfs1)
                        {
                            if (node.state == state2)
                            {
                                in_bfs1 = true;
                                break;
                            }
                        }

                        if (!in_bfs1)
                        {
                            Node node{temp1, state2};
                            bfs1.push_back(node);
                            queue1.push(node);
                            if (goal_zero == 4 || goal_zero == 5 || goal_zero == 7 || goal_zero == 8)
                            {
                                if (is_goal_4578_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 0 || goal_zero == 1 || goal_zero == 3)
                            {
                                if (is_goal_013_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 2)
                            {
                                if (is_goal_2_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else //goal_zero = 6
                            {
                                if (is_goal_6_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                        }
                        in_bfs1 = false;
                    }

                    else if (i == 7)
                    {
                        std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8], temp1[9] + 1};
                        for (auto &node : bfs1)
                        {
                            if (node.state == state1)
                            {
                                in_bfs1 = true;
                                break;
                            }
                        }

                        if (!in_bfs1)
                        {
                            Node node{temp1, state1};
                            bfs1.push_back(node);
                            queue1.push(node);
                            if (goal_zero == 4 || goal_zero == 5 || goal_zero == 7 || goal_zero == 8)
                            {
                                if (is_goal_4578_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 0 || goal_zero == 1 || goal_zero == 3)
                            {
                                if (is_goal_013_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 2)
                            {
                                if (is_goal_2_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else //goal_zero = 6
                            {
                                if (is_goal_6_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                        }
                        in_bfs1 = false;

                        std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[7], temp1[6], temp1[8], temp1[9] + 1};
                        for (auto &node : bfs1)
                        {
                            if (node.state == state2)
                            {
                                in_bfs1 = true;
                                break;
                            }
                        }

                        if (!in_bfs1)
                        {
                            Node node{temp1, state2};
                            bfs1.push_back(node);
                            queue1.push(node);
                            if (goal_zero == 4 || goal_zero == 5 || goal_zero == 7 || goal_zero == 8)
                            {
                                if (is_goal_4578_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 0 || goal_zero == 1 || goal_zero == 3)
                            {
                                if (is_goal_013_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 2)
                            {
                                if (is_goal_2_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else //goal_zero = 6
                            {
                                if (is_goal_6_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                        }
                        in_bfs1 = false;

                        std::vector<int> state3 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[8], temp1[7], temp1[9] + 1};
                        for (auto &node : bfs1)
                        {
                            if (node.state == state3)
                            {
                                in_bfs1 = true;
                                break;
                            }
                        }

                        if (!in_bfs1)
                        {
                            Node node{temp1, state3};
                            bfs1.push_back(node);
                            queue1.push(node);
                            if (goal_zero == 4 || goal_zero == 5 || goal_zero == 7 || goal_zero == 8)
                            {
                                if (is_goal_4578_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 0 || goal_zero == 1 || goal_zero == 3)
                            {
                                if (is_goal_013_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 2)
                            {
                                if (is_goal_2_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else //goal_zero = 6
                            {
                                if (is_goal_6_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                        }
                        in_bfs1 = false;
                    }

                    else if (i == 8)
                    {
                        std::vector<int> state1 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[8], temp1[6], temp1[7], temp1[5], temp1[9] + 1};
                        for (auto &node : bfs1)
                        {
                            if (node.state == state1)
                            {
                                in_bfs1 = true;
                                break;
                            }
                        }

                        if (!in_bfs1)
                        {
                            Node node{temp1, state1};
                            bfs1.push_back(node);
                            queue1.push(node);
                            if (goal_zero == 4 || goal_zero == 5 || goal_zero == 7 || goal_zero == 8)
                            {
                                if (is_goal_4578_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 0 || goal_zero == 1 || goal_zero == 3)
                            {
                                if (is_goal_013_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 2)
                            {
                                if (is_goal_2_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else //goal_zero = 6
                            {
                                if (is_goal_6_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                        }
                        in_bfs1 = false;

                        std::vector<int> state2 = std::vector<int>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[8], temp1[7], temp1[9] + 1};
                        for (auto &node : bfs1)
                        {
                            if (node.state == state2)
                            {
                                in_bfs1 = true;
                                break;
                            }
                        }

                        if (!in_bfs1)
                        {
                            Node node{temp1, state2};
                            bfs1.push_back(node);
                            queue1.push(node);
                            if (goal_zero == 4 || goal_zero == 5 || goal_zero == 7 || goal_zero == 8)
                            {
                                if (is_goal_4578_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 0 || goal_zero == 1 || goal_zero == 3)
                            {
                                if (is_goal_013_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else if (goal_zero == 2)
                            {
                                if (is_goal_2_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                            else //goal_zero = 6
                            {
                                if (is_goal_6_1(node.state, goal))
                                {
                                    init = std::move(node);
                                    break;
                                }
                            }
                        }
                        in_bfs1 = false;
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

void solved_Fast_BFS(Node &goal_node, const std::vector<int> &goal)
{
    size_t steps{goal_node.parents.size()};
    std::cout << "\u001b[32;1m"; //Bright Green
    std::cout << "\n*************************\n";
    std::cout << "******\u001b[36;1mPUZZLE SOLVED\u001b[32;1m******\nNumber of steps: " << steps;
    std::cout << "\n*************************\n\u001b[0m";

    for (size_t i{0}; i < steps - 1; i++)
        print_puzzle(i, goal_node.parents[i]);

    std::cout << "\u001b[32;1m\n\nGoal State:\nStep " << steps - 1 << ":\n";
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