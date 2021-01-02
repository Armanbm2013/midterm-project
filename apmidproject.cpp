#include "apmidproject.h"
#include "time.h"
#include "DFS.h"
#include "BFS.h"

bool in_vec(const std::vector<int> &v, int a)
{
    for (auto &num : v)
        if (num == a)
            return true;
    return false;
}

void hello_game()
{
    std::cout << "\u001b[32;1m\n\n************************************************************\n"
              << "****************Wlecome to the 8-pullze game****************\n"
              << "************************************************************\n\n";
    std::cout << "\u001b[0m"; //reset color and style
}

std::vector<int> own_8_puzzle_vs_random()
{
    std::cout << "\u001b[35;1m\nDo you want to solve your own 8-puzzle or want to see how a random puzzle is solved?\n\n"
              << "\u001b[31;1m1 \u001b[33;1mYour own 8-puzzle\n\u001b[31;1m2 \u001b[33;1mA random 8-puzzle\n\n\u001b[35;1mInput the number you choose: ";
    std::cout << "\u001b[0m"; //reset color and style

    int choice{};
    std::cin >> choice;

    while (choice != 1 && choice != 2)
    {
        std::cout << "\u001b[31;1m"; //Bright Red
        std::cout << "Invalid choice, try again: ";
        std::cout << "\u001b[0m"; //reset color and style
        std::cin >> choice;
    }

    std::vector<int> first_state;

    if (choice == 1)
    {
        int a{}, b{}, c{};
        std::cout << "\u001b[33;1m\nEnter your first row of the puzzle in order, the numbers should range from zero to 8(input empty space by 0): ";
        std::cout << "\u001b[0m"; //reset color and style
        std::cin >> a >> b >> c;
        while (a > 8 || b > 8 || c > 8 || a == b || a == c || b == c)
        {
            std::cout << "\u001b[31;1m"; //Bright Red
            std::cout << "Invalid input, try again: ";
            std::cout << "\u001b[0m"; //reset color and style
            std::cin >> a >> b >> c;
        }
        first_state.push_back(a);
        first_state.push_back(b);
        first_state.push_back(c);

        std::cout << "\u001b[33;1m\nEnter your second row of the puzzle in order, the numbers should range from zero to 8(input empty space by 0): ";
        std::cout << "\u001b[0m"; //reset color and style
        std::cin >> a >> b >> c;
        while (a > 8 || b > 8 || c > 8 || a == b || a == c || b == c || in_vec(first_state, a) || in_vec(first_state, b) || in_vec(first_state, c))
        {
            std::cout << "\u001b[31;1m"; //Bright Red
            std::cout << "Invalid input, try again: ";
            std::cout << "\u001b[0m"; //reset color and style
            std::cin >> a >> b >> c;
        }
        first_state.push_back(a);
        first_state.push_back(b);
        first_state.push_back(c);

        std::cout << "\u001b[33;1m\nEnter your third row of the puzzle in order, the numbers should range from zero to 8(input empty space by 0): ";
        std::cout << "\u001b[0m"; //reset color and style
        std::cin >> a >> b >> c;
        while (a > 8 || b > 8 || c > 8 || a == b || a == c || b == c || in_vec(first_state, a) || in_vec(first_state, b) || in_vec(first_state, c))
        {
            std::cout << "\u001b[31;1m"; //Bright Red
            std::cout << "Invalid input, try again: ";
            std::cout << "\u001b[0m"; //reset color and style
            std::cin >> a >> b >> c;
        }
        first_state.push_back(a);
        first_state.push_back(b);
        first_state.push_back(c);
    }
    else if (choice == 2)
    {
        int temp{};
        srand(time(0));
        while (first_state.size() != 9)
        {
            temp = rand() % 9;
            while (in_vec(first_state, temp))
                temp = rand() % 9;
            first_state.push_back(temp);
        }
    }

    std::cout << "\u001b[32;1m"; //Bright Green
    std::cout << "\n\nFirst State:\n";

    std::cout << "\u001b[31;1m"; //Bright Red
    for (int i{}; i < 9; i++)
    {
        if (first_state[i] == 0)
            std::cout << " ";
        else
            std::cout << first_state[i];
        if (i % 3 == 2)
            std::cout << "\n";
        else
            std::cout << " ";
    }
    std::cout << "\u001b[0m"; //reset color and style

    return first_state;
}

std::vector<int> input_goal_vs_default_goal()
{
    std::cout << "\u001b[35;1m\nwould you like to enter your goal state or do you want to use the default?\n\n"
              << "\u001b[31;1m1 \u001b[33;1mYour custom goal state\n\u001b[31;1m2 \u001b[33;1mDefault goal\n\n\u001b[35;1mInput the number you choose: ";
    std::cout << "\u001b[0m"; //reset color and style

    int choice{};
    std::cin >> choice;

    while (choice != 1 && choice != 2)
    {
        std::cout << "\u001b[31;1m"; //Bright Red
        std::cout << "Invalid input, try again: ";
        std::cout << "\u001b[0m"; //reset color and style
        std::cin >> choice;
    }

    std::vector<int> goal;

    if (choice == 1) //custom goal
    {
        int a{}, b{}, c{};
        std::cout << "\u001b[33;1m\nEnter your first row of the goal state in order, the numbers should range from zero to 8(input empty space by 0): ";
        std::cout << "\u001b[0m"; //reset color and style
        std::cin >> a >> b >> c;
        while (a > 8 || b > 8 || c > 8 || a == b || a == c || b == c)
        {
            std::cout << "\u001b[31;1m"; //Bright Red
            std::cout << "Invalid input, try again: ";
            std::cout << "\u001b[0m"; //reset color and style
            std::cin >> a >> b >> c;
        }
        goal.push_back(a);
        goal.push_back(b);
        goal.push_back(c);

        std::cout << "\u001b[33;1m\nEnter your second row of the goal state in order, the numbers should range from zero to 8(input empty space by 0): ";
        std::cout << "\u001b[0m"; //reset color and style
        std::cin >> a >> b >> c;
        while (a > 8 || b > 8 || c > 8 || a == b || a == c || b == c || in_vec(goal, a) || in_vec(goal, b) || in_vec(goal, c))
        {
            std::cout << "\u001b[31;1m"; //Bright Red
            std::cout << "Invalid input, try again: ";
            std::cout << "\u001b[0m"; //reset color and style
            std::cin >> a >> b >> c;
        }
        goal.push_back(a);
        goal.push_back(b);
        goal.push_back(c);

        std::cout << "\u001b[33;1m\nEnter your third row of the goal state in order, the numbers should range from zero to 8(input empty space by 0): ";
        std::cout << "\u001b[0m"; //reset color and style
        std::cin >> a >> b >> c;
        while (a > 8 || b > 8 || c > 8 || a == b || a == c || b == c || in_vec(goal, a) || in_vec(goal, b) || in_vec(goal, c))
        {
            std::cout << "\u001b[31;1m"; //Bright Red
            std::cout << "Invalid input, try again: ";
            std::cout << "\u001b[0m"; //reset color and style
            std::cin >> a >> b >> c;
        }
        goal.push_back(a);
        goal.push_back(b);
        goal.push_back(c);
    }
    else //default goal
        goal = {1, 2, 3, 4, 5, 6, 7, 8, 0};

    std::cout << "\u001b[32;1m"; //Bright Green
    std::cout << "\n\nGoal State:\n";

    std::cout << "\u001b[31;1m"; //Bright Red
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
    std::cout << "\u001b[0m"; //reset color and style
    return goal;
}

void choose_algorithm(std::vector<int> &init, const std::vector<int> &goal)
{
    int choice{};
    std::cout << "\u001b[35;1m\nWhich algorithm do you want to solve your puzzle with?\n\n";
    std::cout << "\u001b[31;1m1 \u001b[33;1mBFS\n\u001b[31;1m2 \u001b[33;1mDFS\n\n\u001b[35;1mInput the number you choose: ";
    std::cout << "\u001b[0m"; //reset color and style
    std::cin >> choice;
    while (choice != 1 && choice != 2)
    {
        std::cout << "\u001b[31;1m"; //Bright Red
        std::cout << "Invalid choice, try again: ";
        std::cout << "\u001b[0m"; //reset color and style
        std::cin >> choice;
    }

    int depth_limit{};
    int depth_choice{};
    std::cout << "\u001b[35;1m\nDo you want to set a depth limit?\n\n"
              << "\u001b[31;1m1 \u001b[33;1mYes\n\u001b[31;1m2 \u001b[33;1mNo\n\n\u001b[35;1mInput the number you choose: ";
    std::cout << "\u001b[0m"; //reset color and style
    std::cin >> depth_choice;

    while (depth_choice != 1 && depth_choice != 2)
    {
        std::cout << "\u001b[31;1m"; //Bright Red
        std::cout << "Invalid choice, try again: ";
        std::cout << "\u001b[0m"; //reset color and style
        std::cin >> depth_choice;
    }
    if (depth_choice == 1)
    {
        std::cout << "\u001b[33;1m\nEnter Depth limit: \u001b[0m";
        std::cin >> depth_limit;
        if (choice == 1)
            BFS(init, goal, depth_limit);

        else
            DFS(init, goal, depth_limit);
    }
    else
    {
        if (choice == 1)
            BFS(init, goal);
        else if (choice == 2)
            DFS(init, goal);
    }
}

bool continue_game()
{
    std::cout << "\u001b[36;1m\n\n\n************************************************************\n"
              << "\u001b[35;1mDo you Want to play again?\n";
    std::cout << "\u001b[32;1m1.Yes\n\u001b[31;1m2.No\n\n\u001b[32;1mInput the number you choose: ";
    std::cout << "\u001b[0m"; //reset color and style
    int choice{};
    std::cin >> choice;
    while (choice != 1 && choice != 2)
    {
        std::cout << "\u001b[31;1m"; //Bright Red
        std::cout << "Invalid choice, try again: ";
        std::cout << "\u001b[0m"; //reset color and style
        std::cin >> choice;
    }
    if (choice == 1)
        return true;
    return false;
}
