#include "DFS.h"

void DFS(std::vector<int> &init, const std::vector<int> &goal, const int &depth_limit)
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
        std::stack<std::vector<int>> stack{};    //we use a stack to check each Depth of the graph in order
        std::vector<std::vector<int>> dfs{init}; //we use a vector to store the states that we have traversed, and we use it to prevent traversing one state twice
        stack.push(init);

        bool in_dfs{false};
        int i{}; // position of the empty block in each state(here we use zero instead of empty, but when we print the puzzle, we print " " instead of "0")

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
                size_t num1{traverse_state(dfs, stack, temp, state1, goal, depth_limit, in_dfs)};
                if (num1 == 0)
                    break;
                else if (num1 == 1)
                    continue;

                std::vector<int> state2 = std::vector<int>{temp[3], temp[1], temp[2], temp[0], temp[4], temp[5], temp[6], temp[7], temp[8], temp[9] + 1};
                size_t num2{traverse_state(dfs, stack, temp, state2, goal, depth_limit, in_dfs)};
                if (num2 == 0)
                    break;
                else if (num2 == 1)
                    continue;
            }

            else if (i == 1)
            {
                std::vector<int> state1 = std::vector<int>{temp[1], temp[0], temp[2], temp[3], temp[4], temp[5], temp[6], temp[7], temp[8], temp[9] + 1};
                size_t num1{traverse_state(dfs, stack, temp, state1, goal, depth_limit, in_dfs)};
                if (num1 == 0)
                    break;
                else if (num1 == 1)
                    continue;

                std::vector<int> state2 = std::vector<int>{temp[0], temp[2], temp[1], temp[3], temp[4], temp[5], temp[6], temp[7], temp[8], temp[9] + 1};
                size_t num2{traverse_state(dfs, stack, temp, state2, goal, depth_limit, in_dfs)};
                if (num2 == 0)
                    break;
                else if (num2 == 1)
                    continue;

                std::vector<int> state3 = std::vector<int>{temp[0], temp[4], temp[2], temp[3], temp[1], temp[5], temp[6], temp[7], temp[8], temp[9] + 1};
                size_t num3{traverse_state(dfs, stack, temp, state3, goal, depth_limit, in_dfs)};
                if (num3 == 0)
                    break;
                else if (num3 == 1)
                    continue;
            }

            else if (i == 2)
            {
                std::vector<int> state1 = std::vector<int>{temp[0], temp[2], temp[1], temp[3], temp[4], temp[5], temp[6], temp[7], temp[8], temp[9] + 1};
                size_t num1{traverse_state(dfs, stack, temp, state1, goal, depth_limit, in_dfs)};
                if (num1 == 0)
                    break;
                else if (num1 == 1)
                    continue;

                std::vector<int> state2 = std::vector<int>{temp[0], temp[1], temp[5], temp[3], temp[4], temp[2], temp[6], temp[7], temp[8], temp[9] + 1};
                size_t num2{traverse_state(dfs, stack, temp, state2, goal, depth_limit, in_dfs)};
                if (num2 == 0)
                    break;
                else if (num2 == 1)
                    continue;
            }

            else if (i == 3)
            {
                std::vector<int> state1 = std::vector<int>{temp[3], temp[1], temp[2], temp[0], temp[4], temp[5], temp[6], temp[7], temp[8], temp[9] + 1};
                size_t num1{traverse_state(dfs, stack, temp, state1, goal, depth_limit, in_dfs)};
                if (num1 == 0)
                    break;
                else if (num1 == 1)
                    continue;

                std::vector<int> state2 = std::vector<int>{temp[0], temp[1], temp[2], temp[4], temp[3], temp[5], temp[6], temp[7], temp[8], temp[9] + 1};
                size_t num2{traverse_state(dfs, stack, temp, state2, goal, depth_limit, in_dfs)};
                if (num2 == 0)
                    break;
                else if (num2 == 1)
                    continue;

                std::vector<int> state3 = std::vector<int>{temp[0], temp[1], temp[2], temp[6], temp[4], temp[5], temp[3], temp[7], temp[8], temp[9] + 1};
                size_t num3{traverse_state(dfs, stack, temp, state3, goal, depth_limit, in_dfs)};
                if (num3 == 0)
                    break;
                else if (num3 == 1)
                    continue;
            }

            else if (i == 4)
            {
                std::vector<int> state1 = std::vector<int>{temp[0], temp[4], temp[2], temp[3], temp[1], temp[5], temp[6], temp[7], temp[8], temp[9] + 1};
                size_t num1{traverse_state(dfs, stack, temp, state1, goal, depth_limit, in_dfs)};
                if (num1 == 0)
                    break;
                else if (num1 == 1)
                    continue;

                std::vector<int> state2 = std::vector<int>{temp[0], temp[1], temp[2], temp[4], temp[3], temp[5], temp[6], temp[7], temp[8], temp[9] + 1};
                size_t num2{traverse_state(dfs, stack, temp, state2, goal, depth_limit, in_dfs)};
                if (num2 == 0)
                    break;
                else if (num2 == 1)
                    continue;

                std::vector<int> state3 = std::vector<int>{temp[0], temp[1], temp[2], temp[3], temp[5], temp[4], temp[6], temp[7], temp[8], temp[9] + 1};
                size_t num3{traverse_state(dfs, stack, temp, state3, goal, depth_limit, in_dfs)};
                if (num3 == 0)
                    break;
                else if (num3 == 1)
                    continue;

                std::vector<int> state4 = std::vector<int>{temp[0], temp[1], temp[2], temp[3], temp[7], temp[5], temp[6], temp[4], temp[8], temp[9] + 1};
                size_t num4{traverse_state(dfs, stack, temp, state4, goal, depth_limit, in_dfs)};
                if (num4 == 0)
                    break;
                else if (num4 == 1)
                    continue;
            }

            else if (i == 5)
            {
                std::vector<int> state1 = std::vector<int>{temp[0], temp[1], temp[5], temp[3], temp[4], temp[2], temp[6], temp[7], temp[8], temp[9] + 1};
                size_t num1{traverse_state(dfs, stack, temp, state1, goal, depth_limit, in_dfs)};
                if (num1 == 0)
                    break;
                else if (num1 == 1)
                    continue;

                std::vector<int> state2 = std::vector<int>{temp[0], temp[1], temp[2], temp[3], temp[5], temp[4], temp[6], temp[7], temp[8], temp[9] + 1};
                size_t num2{traverse_state(dfs, stack, temp, state2, goal, depth_limit, in_dfs)};
                if (num2 == 0)
                    break;
                else if (num2 == 1)
                    continue;

                std::vector<int> state3 = std::vector<int>{temp[0], temp[1], temp[2], temp[3], temp[4], temp[8], temp[6], temp[7], temp[5], temp[9] + 1};
                size_t num3{traverse_state(dfs, stack, temp, state3, goal, depth_limit, in_dfs)};
                if (num3 == 0)
                    break;
                else if (num3 == 1)
                    continue;
            }

            else if (i == 6)
            {
                std::vector<int> state1 = std::vector<int>{temp[0], temp[1], temp[2], temp[6], temp[4], temp[5], temp[3], temp[7], temp[8], temp[9] + 1};
                size_t num1{traverse_state(dfs, stack, temp, state1, goal, depth_limit, in_dfs)};
                if (num1 == 0)
                    break;
                else if (num1 == 1)
                    continue;

                std::vector<int> state2 = std::vector<int>{temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[7], temp[6], temp[8], temp[9] + 1};
                size_t num2{traverse_state(dfs, stack, temp, state2, goal, depth_limit, in_dfs)};
                if (num2 == 0)
                    break;
                else if (num2 == 1)
                    continue;
            }

            else if (i == 7)
            {
                std::vector<int> state1 = std::vector<int>{temp[0], temp[1], temp[2], temp[3], temp[7], temp[5], temp[6], temp[4], temp[8], temp[9] + 1};
                size_t num1{traverse_state(dfs, stack, temp, state1, goal, depth_limit, in_dfs)};
                if (num1 == 0)
                    break;
                else if (num1 == 1)
                    continue;

                std::vector<int> state2 = std::vector<int>{temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[7], temp[6], temp[8], temp[9] + 1};
                size_t num2{traverse_state(dfs, stack, temp, state2, goal, depth_limit, in_dfs)};
                if (num2 == 0)
                    break;
                else if (num2 == 1)
                    continue;

                std::vector<int> state3 = std::vector<int>{temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[6], temp[8], temp[7], temp[9] + 1};
                size_t num3{traverse_state(dfs, stack, temp, state3, goal, depth_limit, in_dfs)};
                if (num3 == 0)
                    break;
                else if (num3 == 1)
                    continue;
            }

            else if (i == 8)
            {
                std::vector<int> state1 = std::vector<int>{temp[0], temp[1], temp[2], temp[3], temp[4], temp[8], temp[6], temp[7], temp[5], temp[9] + 1};
                size_t num1{traverse_state(dfs, stack, temp, state1, goal, depth_limit, in_dfs)};
                if (num1 == 0)
                    break;
                else if (num1 == 1)
                    continue;

                std::vector<int> state2 = std::vector<int>{temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[6], temp[8], temp[7], temp[9] + 1};
                size_t num2{traverse_state(dfs, stack, temp, state2, goal, depth_limit, in_dfs)};
                if (num2 == 0)
                    break;
                else if (num2 == 1)
                    continue;
            }

            if (stack.empty())
            {
                std::cout << "\u001b[31;1mNo answers find till depth " << depth_limit << "\u001b[0m\n";
                break;
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

void solved_DFS(std::stack<std::vector<int>> &stack, const std::vector<int> &goal)
{
    std::vector<std::vector<int>> moves{};
    while (!stack.empty())
    {
        moves.push_back(stack.top());
        stack.pop();
    }
    size_t steps{moves.size() - 1};

    std::cout << "\u001b[32;1m"; //Bright Green
    std::cout << "\n*************************\n";
    std::cout << "******\u001b[36;1mPUZZLE SOLVED\u001b[32;1m******\nNumber of steps: " << steps;
    std::cout << "\n*************************\n\u001b[0m";

    for (size_t i{0}; i < steps; i++)
        print_puzzle(i, moves[steps - i]);

    std::cout << "\u001b[32;1m\n\nGoal State:\nStep " << steps << ":\n";
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

size_t traverse_state(std::vector<std::vector<int>> &dfs, std::stack<std::vector<int>> &stack, const std::vector<int> &temp, const std::vector<int> &state, const std::vector<int> &goal, const int &depth_limit, bool &in_dfs)
{
    for (size_t i{}; i < dfs.size(); i++)
        if (dfs[i][0] == state[0])
            if (dfs[i][1] == state[1])
                if (dfs[i][2] == state[2])
                    if (dfs[i][3] == state[3])
                        if (dfs[i][4] == state[4])
                            if (dfs[i][5] == state[5])
                                if (dfs[i][6] == state[6])
                                    if (dfs[i][7] == state[7])
                                        if (dfs[i][8] == state[8])
                                        {
                                            if (depth_limit != -1)
                                            {
                                                if (dfs[i][9] > state[9])
                                                    dfs.erase(dfs.begin() + i);
                                                else
                                                    in_dfs = true;
                                            }
                                            else
                                                in_dfs = true;
                                            break;
                                        }

    if (!in_dfs)
    {
        stack.push(temp);
        dfs.push_back(state);
        stack.push(state);
        if (is_goal(state, goal))
        {
            solved_DFS(stack, goal);
            return 0; //causes the while loop in the DFS function to break
        }
        return 1; //causes the while loop in the DFS function to continue
    }
    in_dfs = false;
    return 2; // does nothing
}