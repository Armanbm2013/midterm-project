#include "BFS.h"
#include "another_way_BFS.h"

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
        size_t i{}; // position of the empty block(here we use zero instead of empty, but when we print the puzzle, we print " " instead of "0")
        while (true)
        {
            if (!queue.empty())
            {
                std::vector<size_t> temp = queue.front();
                queue.pop();
                if (is_goal_1(temp, goal))
                {
                    if (is_goal_2(temp, goal))
                    {
                        if (is_goal_3(temp, goal))
                        {
                            if (is_goal_4(temp, goal))
                            {
                                solved(steps, goal);
                                break;
                            }
                            else
                            {
                                std::queue<std::vector<size_t>> queue4{};    //a queue for to find a node a that is_goal_4(a,goal) is true
                                std::vector<std::vector<size_t>> bfs4{temp}; //a vector to store all of traveresed states until finding the node a that is_goal_4(a,goal) is true
                                queue4.push(bfs4.back());
                                bool in_bfs4{false};
                                while (true)
                                {
                                    std::vector<size_t> temp1 = queue4.front();
                                    queue4.pop();
                                    for (size_t j{}; j < 9; j++)
                                        if (temp1[j] == 0)
                                            i = j;
                                    if (i == 4)
                                    {
                                        std::vector<size_t> state1 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8]};
                                        for (std::vector<size_t> &puzzle : bfs4)
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
                                            print_puzzle(steps, state1);
                                            if (is_goal_4(state1, goal))
                                            {
                                                bfs.push_back(state1);
                                                queue.push(state1);
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;

                                        std::vector<size_t> state2 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8]};
                                        for (std::vector<size_t> &puzzle : bfs4)
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
                                            print_puzzle(steps, state2);
                                            if (is_goal_4(state2, goal))
                                            {
                                                bfs.push_back(state2);
                                                queue.push(state2);
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;
                                    }
                                    else if (i == 5)
                                    {
                                        std::vector<size_t> state1 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[8], temp1[6], temp1[7], temp1[5]};
                                        for (std::vector<size_t> &puzzle : bfs4)
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
                                            print_puzzle(steps, state1);
                                            if (is_goal_4(state1, goal))
                                            {
                                                bfs.push_back(state1);
                                                queue.push(state1);
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;

                                        std::vector<size_t> state2 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8]};
                                        for (std::vector<size_t> &puzzle : bfs4)
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
                                            print_puzzle(steps, state2);
                                            if (is_goal_4(state2, goal))
                                            {
                                                bfs.push_back(state2);
                                                queue.push(state2);
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;
                                    }
                                    else if (i == 7)
                                    {
                                        std::vector<size_t> state1 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8]};
                                        for (std::vector<size_t> &puzzle : bfs4)
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
                                            print_puzzle(steps, state1);
                                            if (is_goal_4(state1, goal))
                                            {
                                                bfs.push_back(state1);
                                                queue.push(state1);
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;

                                        std::vector<size_t> state2 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[8], temp1[7]};
                                        for (std::vector<size_t> &puzzle : bfs4)
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
                                            print_puzzle(steps, state2);
                                            if (is_goal_4(state2, goal))
                                            {
                                                bfs.push_back(state2);
                                                queue.push(state2);
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;
                                    }
                                    else if (i == 8)
                                    {
                                        std::vector<size_t> state1 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[8], temp1[6], temp1[7], temp1[5]};
                                        for (std::vector<size_t> &puzzle : bfs4)
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
                                            print_puzzle(steps, state1);
                                            if (is_goal_4(state1, goal))
                                            {
                                                bfs.push_back(state1);
                                                queue.push(state1);
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;

                                        std::vector<size_t> state2 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[8], temp1[7]};
                                        for (std::vector<size_t> &puzzle : bfs4)
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
                                            print_puzzle(steps, state2);
                                            if (is_goal_4(state2, goal))
                                            {
                                                bfs.push_back(state2);
                                                queue.push(state2);
                                                break;
                                            }
                                        }
                                        in_bfs4 = false;
                                    }
                                }
                            }
                        }
                        else
                        {
                            std::queue<std::vector<size_t>> queue3{};    //a queue for to find a node a that is_goal_3(a,goal) is true
                            std::vector<std::vector<size_t>> bfs3{temp}; //a vector to store all of traveresed states until finding the node a that is_goal_3(a,goal) is true
                            queue3.push(bfs3.back());
                            bool in_bfs3{false};
                            while (true)
                            {
                                std::vector<size_t> temp1 = queue3.front();
                                queue3.pop();
                                for (size_t j{}; j < 9; j++)
                                    if (temp1[j] == 0)
                                        i = j;
                                if (i == 3)
                                {
                                    std::vector<size_t> state1 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8]};
                                    for (std::vector<size_t> &puzzle : bfs3)
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
                                        if (is_goal_3(state1, goal))
                                        {
                                            bfs.push_back(state1);
                                            queue.push(state1);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<size_t> state2 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[6], temp1[4], temp1[5], temp1[3], temp1[7], temp1[8]};
                                    for (std::vector<size_t> &puzzle : bfs3)
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
                                        if (is_goal_3(state2, goal))
                                        {
                                            bfs.push_back(state2);
                                            queue.push(state2);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }
                                else if (i == 4)
                                {
                                    std::vector<size_t> state1 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8]};
                                    for (std::vector<size_t> &puzzle : bfs3)
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
                                        if (is_goal_3(state1, goal))
                                        {
                                            bfs.push_back(state1);
                                            queue.push(state1);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<size_t> state2 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8]};
                                    for (std::vector<size_t> &puzzle : bfs3)
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
                                        if (is_goal_3(state2, goal))
                                        {
                                            bfs.push_back(state2);
                                            queue.push(state2);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<size_t> state3 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8]};
                                    for (std::vector<size_t> &puzzle : bfs3)
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
                                        if (is_goal_3(state3, goal))
                                        {
                                            bfs.push_back(state3);
                                            queue.push(state3);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }
                                else if (i == 5)
                                {
                                    std::vector<size_t> state1 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[8], temp1[6], temp1[7], temp1[5]};
                                    for (std::vector<size_t> &puzzle : bfs3)
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
                                        if (is_goal_3(state1, goal))
                                        {
                                            bfs.push_back(state1);
                                            queue.push(state1);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<size_t> state2 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8]};
                                    for (std::vector<size_t> &puzzle : bfs3)
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
                                        if (is_goal_3(state2, goal))
                                        {
                                            bfs.push_back(state2);
                                            queue.push(state2);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }
                                else if (i == 6)
                                {
                                    std::vector<size_t> state1 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[6], temp1[4], temp1[5], temp1[3], temp1[7], temp1[8]};
                                    for (std::vector<size_t> &puzzle : bfs3)
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
                                        if (is_goal_3(state1, goal))
                                        {
                                            bfs.push_back(state1);
                                            queue.push(state1);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<size_t> state2 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[7], temp1[6], temp1[8]};
                                    for (std::vector<size_t> &puzzle : bfs3)
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
                                        if (is_goal_3(state2, goal))
                                        {
                                            bfs.push_back(state2);
                                            queue.push(state2);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }
                                else if (i == 7)
                                {
                                    std::vector<size_t> state1 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8]};
                                    for (std::vector<size_t> &puzzle : bfs3)
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
                                        if (is_goal_3(state1, goal))
                                        {
                                            bfs.push_back(state1);
                                            queue.push(state1);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<size_t> state2 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[7], temp1[6], temp1[8]};
                                    for (std::vector<size_t> &puzzle : bfs3)
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
                                        if (is_goal_3(state2, goal))
                                        {
                                            bfs.push_back(state2);
                                            queue.push(state2);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<size_t> state3 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[8], temp1[7]};
                                    for (std::vector<size_t> &puzzle : bfs3)
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
                                        if (is_goal_3(state3, goal))
                                        {
                                            bfs.push_back(state3);
                                            queue.push(state3);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }
                                else if (i == 8)
                                {
                                    std::vector<size_t> state1 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[8], temp1[6], temp1[7], temp1[5]};
                                    for (std::vector<size_t> &puzzle : bfs3)
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
                                        if (is_goal_3(state1, goal))
                                        {
                                            bfs.push_back(state1);
                                            queue.push(state1);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;

                                    std::vector<size_t> state2 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[8], temp1[7]};
                                    for (std::vector<size_t> &puzzle : bfs3)
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
                                        if (is_goal_3(state2, goal))
                                        {
                                            bfs.push_back(state2);
                                            queue.push(state2);
                                            break;
                                        }
                                    }
                                    in_bfs3 = false;
                                }
                            }
                        }
                    }
                    else
                    {
                        std::queue<std::vector<size_t>> queue2{};    //a queue for to find a node a that is_goal_2(a,goal) is true
                        std::vector<std::vector<size_t>> bfs2{temp}; //a vector to store all of traveresed states until finding the node a that is_goal_2(a,goal) is true
                        queue2.push(bfs2.back());
                        bool in_bfs2{false};
                        while (true)
                        {
                            std::vector<size_t> temp1 = queue2.front();
                            queue2.pop();
                            for (size_t j{}; j < 9; j++)
                                if (temp1[j] == 0)
                                    i = j;
                            if (i == 1)
                            {
                                std::vector<size_t> state1 = std::vector<size_t>{temp1[0], temp1[2], temp1[1], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8]};
                                for (std::vector<size_t> &puzzle : bfs2)
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
                                    if (is_goal_2(state1, goal))
                                    {
                                        bfs.push_back(state1);
                                        queue.push(state1);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<size_t> state2 = std::vector<size_t>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8]};
                                for (std::vector<size_t> &puzzle : bfs2)
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
                                    if (is_goal_2(state2, goal))
                                    {
                                        bfs.push_back(state2);
                                        queue.push(state2);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }
                            else if (i == 2)
                            {
                                std::vector<size_t> state1 = std::vector<size_t>{temp1[0], temp1[2], temp1[1], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8]};
                                for (std::vector<size_t> &puzzle : bfs2)
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
                                    if (is_goal_2(state1, goal))
                                    {
                                        bfs.push_back(state1);
                                        queue.push(state1);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<size_t> state2 = std::vector<size_t>{temp1[0], temp1[1], temp1[5], temp1[3], temp1[4], temp1[2], temp1[6], temp1[7], temp1[8]};
                                for (std::vector<size_t> &puzzle : bfs2)
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
                                    if (is_goal_2(state2, goal))
                                    {
                                        bfs.push_back(state2);
                                        queue.push(state2);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }
                            else if (i == 3)
                            {
                                std::vector<size_t> state1 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8]};
                                for (std::vector<size_t> &puzzle : bfs2)
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
                                    if (is_goal_2(state1, goal))
                                    {
                                        bfs.push_back(state1);
                                        queue.push(state1);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<size_t> state2 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[6], temp1[4], temp1[5], temp1[3], temp1[7], temp1[8]};
                                for (std::vector<size_t> &puzzle : bfs2)
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
                                    if (is_goal_2(state2, goal))
                                    {
                                        bfs.push_back(state2);
                                        queue.push(state2);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }
                            else if (i == 4)
                            {
                                std::vector<size_t> state1 = std::vector<size_t>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8]};
                                for (std::vector<size_t> &puzzle : bfs2)
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
                                    if (is_goal_2(state1, goal))
                                    {
                                        bfs.push_back(state1);
                                        queue.push(state1);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<size_t> state2 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8]};
                                for (std::vector<size_t> &puzzle : bfs2)
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
                                    if (is_goal_2(state2, goal))
                                    {
                                        bfs.push_back(state2);
                                        queue.push(state2);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<size_t> state3 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8]};
                                for (std::vector<size_t> &puzzle : bfs2)
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
                                    if (is_goal_2(state3, goal))
                                    {
                                        bfs.push_back(state3);
                                        queue.push(state3);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<size_t> state4 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8]};
                                for (std::vector<size_t> &puzzle : bfs2)
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
                                    if (is_goal_2(state4, goal))
                                    {
                                        bfs.push_back(state4);
                                        queue.push(state4);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }
                            else if (i == 5)
                            {
                                std::vector<size_t> state1 = std::vector<size_t>{temp1[0], temp1[1], temp1[5], temp1[3], temp1[4], temp1[2], temp1[6], temp1[7], temp1[8]};
                                for (std::vector<size_t> &puzzle : bfs2)
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
                                    if (is_goal_2(state1, goal))
                                    {
                                        bfs.push_back(state1);
                                        queue.push(state1);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<size_t> state2 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8]};
                                for (std::vector<size_t> &puzzle : bfs2)
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
                                    if (is_goal_2(state2, goal))
                                    {
                                        bfs.push_back(state2);
                                        queue.push(state2);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<size_t> state3 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[8], temp1[6], temp1[7], temp1[5]};
                                for (std::vector<size_t> &puzzle : bfs2)
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
                                    if (is_goal_2(state3, goal))
                                    {
                                        bfs.push_back(state3);
                                        queue.push(state3);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }
                            else if (i == 6)
                            {
                                std::vector<size_t> state1 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[6], temp1[4], temp1[5], temp1[3], temp1[7], temp1[8]};
                                for (std::vector<size_t> &puzzle : bfs2)
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
                                    if (is_goal_2(state1, goal))
                                    {
                                        bfs.push_back(state1);
                                        queue.push(state1);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<size_t> state2 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[7], temp1[6], temp1[8]};
                                for (std::vector<size_t> &puzzle : bfs2)
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
                                    if (is_goal_2(state2, goal))
                                    {
                                        bfs.push_back(state2);
                                        queue.push(state2);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }
                            else if (i == 7)
                            {
                                std::vector<size_t> state1 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8]};
                                for (std::vector<size_t> &puzzle : bfs2)
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
                                    if (is_goal_2(state1, goal))
                                    {
                                        bfs.push_back(state1);
                                        queue.push(state1);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<size_t> state2 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[7], temp1[6], temp1[8]};
                                for (std::vector<size_t> &puzzle : bfs2)
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
                                    if (is_goal_2(state2, goal))
                                    {
                                        bfs.push_back(state2);
                                        queue.push(state2);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<size_t> state3 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[8], temp1[7]};
                                for (std::vector<size_t> &puzzle : bfs2)
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
                                    if (is_goal_2(state3, goal))
                                    {
                                        bfs.push_back(state3);
                                        queue.push(state3);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }
                            else if (i == 8)
                            {
                                std::vector<size_t> state1 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[8], temp1[6], temp1[7], temp1[5]};
                                for (std::vector<size_t> &puzzle : bfs2)
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
                                    if (is_goal_2(state1, goal))
                                    {
                                        bfs.push_back(state1);
                                        queue.push(state1);
                                        break;
                                    }
                                }
                                in_bfs2 = false;

                                std::vector<size_t> state2 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[8], temp1[7]};
                                for (std::vector<size_t> &puzzle : bfs2)
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
                                    if (is_goal_2(state2, goal))
                                    {
                                        bfs.push_back(state2);
                                        queue.push(state2);
                                        break;
                                    }
                                }
                                in_bfs2 = false;
                            }
                        }
                    }
                }
                else
                {
                    std::queue<std::vector<size_t>> queue1{};    //a queue for to find a node a that is_goal_1(a,goal) is true
                    std::vector<std::vector<size_t>> bfs1{temp}; //a vector to store all of traveresed states until finding the node a that is_goal_1(a,goal) is true
                    queue1.push(bfs1.back());
                    bool in_bfs1{false};
                    while (true)
                    {
                        std::vector<size_t> temp1 = queue1.front();
                        queue1.pop();
                        for (size_t j{}; j < 9; j++)
                            if (temp1[j] == 0)
                                i = j;
                        if (i == 0)
                        {
                            std::vector<size_t> state1 = std::vector<size_t>{temp1[1], temp1[0], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8]};
                            for (std::vector<size_t> &puzzle : bfs1)
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
                                if (is_goal_1(state1, goal))
                                {
                                    bfs.push_back(state1);
                                    queue.push(state1);
                                    break;
                                }
                            }
                            in_bfs1 = false;

                            std::vector<size_t> state2 = std::vector<size_t>{temp1[3], temp1[1], temp1[2], temp1[0], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8]};
                            for (std::vector<size_t> &puzzle : bfs1)
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
                                if (is_goal_1(state2, goal))
                                {
                                    bfs.push_back(state2);
                                    queue.push(state2);
                                    break;
                                }
                            }
                            in_bfs1 = false;
                        }

                        else if (i == 1)
                        {
                            std::vector<size_t> state1 = std::vector<size_t>{temp1[1], temp1[0], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8]};
                            for (std::vector<size_t> &puzzle : bfs1)
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
                                if (is_goal_1(state1, goal))
                                {
                                    bfs.push_back(state1);
                                    queue.push(state1);
                                    break;
                                }
                            }
                            in_bfs1 = false;

                            std::vector<size_t> state2 = std::vector<size_t>{temp1[0], temp1[2], temp1[1], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8]};
                            for (std::vector<size_t> &puzzle : bfs1)
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
                                if (is_goal_1(state2, goal))
                                {
                                    bfs.push_back(state2);
                                    queue.push(state2);
                                    break;
                                }
                            }
                            in_bfs1 = false;

                            std::vector<size_t> state3 = std::vector<size_t>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8]};
                            for (std::vector<size_t> &puzzle : bfs1)
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
                                if (is_goal_1(state3, goal))
                                {
                                    bfs.push_back(state3);
                                    queue.push(state3);
                                    break;
                                }
                            }
                            in_bfs1 = false;
                        }
                        else if (i == 2)
                        {
                            std::vector<size_t> state1 = std::vector<size_t>{temp1[0], temp1[2], temp1[1], temp1[3], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8]};
                            for (std::vector<size_t> &puzzle : bfs1)
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
                                if (is_goal_1(state1, goal))
                                {
                                    bfs.push_back(state1);
                                    queue.push(state1);
                                    break;
                                }
                            }
                            in_bfs1 = false;

                            std::vector<size_t> state2 = std::vector<size_t>{temp1[0], temp1[1], temp1[5], temp1[3], temp1[4], temp1[2], temp1[6], temp1[7], temp1[8]};
                            for (std::vector<size_t> &puzzle : bfs1)
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
                                if (is_goal_1(state2, goal))
                                {
                                    bfs.push_back(state2);
                                    queue.push(state2);
                                    break;
                                }
                            }
                            in_bfs1 = false;
                        }
                        else if (i == 3)
                        {
                            std::vector<size_t> state1 = std::vector<size_t>{temp1[3], temp1[1], temp1[2], temp1[0], temp1[4], temp1[5], temp1[6], temp1[7], temp1[8]};
                            for (std::vector<size_t> &puzzle : bfs1)
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
                                if (is_goal_1(state1, goal))
                                {
                                    bfs.push_back(state1);
                                    queue.push(state1);
                                    break;
                                }
                            }
                            in_bfs1 = false;

                            std::vector<size_t> state2 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8]};
                            for (std::vector<size_t> &puzzle : bfs1)
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
                                if (is_goal_1(state2, goal))
                                {
                                    bfs.push_back(state2);
                                    queue.push(state2);
                                    break;
                                }
                            }
                            in_bfs1 = false;

                            std::vector<size_t> state3 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[6], temp1[4], temp1[5], temp1[3], temp1[7], temp1[8]};
                            for (std::vector<size_t> &puzzle : bfs1)
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
                                if (is_goal_1(state3, goal))
                                {
                                    bfs.push_back(state3);
                                    queue.push(state3);
                                    break;
                                }
                            }
                            in_bfs1 = false;
                        }
                        else if (i == 4)
                        {
                            std::vector<size_t> state1 = std::vector<size_t>{temp1[0], temp1[4], temp1[2], temp1[3], temp1[1], temp1[5], temp1[6], temp1[7], temp1[8]};
                            for (std::vector<size_t> &puzzle : bfs1)
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
                                if (is_goal_1(state1, goal))
                                {
                                    bfs.push_back(state1);
                                    queue.push(state1);
                                    break;
                                }
                            }
                            in_bfs1 = false;

                            std::vector<size_t> state2 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[4], temp1[3], temp1[5], temp1[6], temp1[7], temp1[8]};
                            for (std::vector<size_t> &puzzle : bfs1)
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
                                if (is_goal_1(state2, goal))
                                {
                                    bfs.push_back(state2);
                                    queue.push(state2);
                                    break;
                                }
                            }
                            in_bfs1 = false;

                            std::vector<size_t> state3 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8]};
                            for (std::vector<size_t> &puzzle : bfs1)
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
                                if (is_goal_1(state3, goal))
                                {
                                    bfs.push_back(state3);
                                    queue.push(state3);
                                    break;
                                }
                            }
                            in_bfs1 = false;

                            std::vector<size_t> state4 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8]};
                            for (std::vector<size_t> &puzzle : bfs1)
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
                                if (is_goal_1(state4, goal))
                                {
                                    bfs.push_back(state4);
                                    queue.push(state4);
                                    break;
                                }
                            }
                            in_bfs1 = false;
                        }
                        else if (i == 5)
                        {
                            std::vector<size_t> state1 = std::vector<size_t>{temp1[0], temp1[1], temp1[5], temp1[3], temp1[4], temp1[2], temp1[6], temp1[7], temp1[8]};
                            for (std::vector<size_t> &puzzle : bfs1)
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
                                if (is_goal_1(state1, goal))
                                {
                                    bfs.push_back(state1);
                                    queue.push(state1);
                                    break;
                                }
                            }
                            in_bfs1 = false;

                            std::vector<size_t> state2 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[5], temp1[4], temp1[6], temp1[7], temp1[8]};
                            for (std::vector<size_t> &puzzle : bfs1)
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
                                if (is_goal_1(state2, goal))
                                {
                                    bfs.push_back(state2);
                                    queue.push(state2);
                                    break;
                                }
                            }
                            in_bfs1 = false;

                            std::vector<size_t> state3 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[8], temp1[6], temp1[7], temp1[5]};
                            for (std::vector<size_t> &puzzle : bfs1)
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
                                if (is_goal_1(state3, goal))
                                {
                                    bfs.push_back(state3);
                                    queue.push(state3);
                                    break;
                                }
                            }
                            in_bfs1 = false;
                        }
                        else if (i == 6)
                        {
                            std::vector<size_t> state1 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[6], temp1[4], temp1[5], temp1[3], temp1[7], temp1[8]};
                            for (std::vector<size_t> &puzzle : bfs1)
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
                                if (is_goal_1(state1, goal))
                                {
                                    bfs.push_back(state1);
                                    queue.push(state1);
                                    break;
                                }
                            }
                            in_bfs1 = false;

                            std::vector<size_t> state2 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[7], temp1[6], temp1[8]};
                            for (std::vector<size_t> &puzzle : bfs1)
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
                                if (is_goal_1(state2, goal))
                                {
                                    bfs.push_back(state2);
                                    queue.push(state2);
                                    break;
                                }
                            }
                            in_bfs1 = false;
                        }
                        else if (i == 7)
                        {
                            std::vector<size_t> state1 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[7], temp1[5], temp1[6], temp1[4], temp1[8]};
                            for (std::vector<size_t> &puzzle : bfs1)
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
                                if (is_goal_1(state1, goal))
                                {
                                    bfs.push_back(state1);
                                    queue.push(state1);
                                    break;
                                }
                            }
                            in_bfs1 = false;

                            std::vector<size_t> state2 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[7], temp1[6], temp1[8]};
                            for (std::vector<size_t> &puzzle : bfs1)
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
                                if (is_goal_1(state2, goal))
                                {
                                    bfs.push_back(state2);
                                    queue.push(state2);
                                    break;
                                }
                            }
                            in_bfs1 = false;

                            std::vector<size_t> state3 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[8], temp1[7]};
                            for (std::vector<size_t> &puzzle : bfs1)
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
                                if (is_goal_1(state3, goal))
                                {
                                    bfs.push_back(state3);
                                    queue.push(state3);
                                    break;
                                }
                            }
                            in_bfs1 = false;
                        }
                        else if (i == 8)
                        {
                            std::vector<size_t> state1 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[8], temp1[6], temp1[7], temp1[5]};
                            for (std::vector<size_t> &puzzle : bfs1)
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
                                if (is_goal_1(state1, goal))
                                {
                                    bfs.push_back(state1);
                                    queue.push(state1);
                                    break;
                                }
                            }
                            in_bfs1 = false;

                            std::vector<size_t> state2 = std::vector<size_t>{temp1[0], temp1[1], temp1[2], temp1[3], temp1[4], temp1[5], temp1[6], temp1[8], temp1[7]};
                            for (std::vector<size_t> &puzzle : bfs1)
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
                                if (is_goal_1(state2, goal))
                                {
                                    bfs.push_back(state2);
                                    queue.push(state2);
                                    break;
                                }
                            }
                            in_bfs1 = false;
                        }
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
    return (state[1] == goal[1] && state[2] == goal[2]);
}

bool is_goal_3(const std::vector<size_t> &state, const std::vector<size_t> &goal)
{
    return (state[3] == goal[3] && state[6] == goal[6]);
}

bool is_goal_4(const std::vector<size_t> &state, const std::vector<size_t> &goal)
{
    return (state[4] == goal[4] && state[5] == goal[5] && state[7] == goal[7] && state[8] == goal[8]);
}