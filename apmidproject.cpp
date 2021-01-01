#include "apmidproject.h"
#include "time.h"
#include "BFS.h"
#include "DFS.h"
#include "another_way_BFS.h"

bool in_vec(const std::vector<int> &v, int a)
{
    for (auto &num : v)
        if (num == a)
            return true;
    return false;
}

void hello_game()
{
    std::cout << "\u001b[32;1m"; //green
    std::cout << "\n\n************************************************************\n"
              << "****************Wlecome to the 8-pullze game****************\n"
              << "************************************************************\n\n";
    std::cout << "\u001b[0m"; //reset
}

std::vector<int> own_8_puzzle_vs_random()
{
    std::cout << "\033[0;34m"; //blue
    std::cout << "\nDo you want to solve your own 8-puzzle or want to see how a random puzzle is solved?\n\n"
              << "1.your own 8-puzzle\n2.a random 8-puzzle\n\nInput the number you choose: ";
    std::cout << "\u001b[0m"; //reset

    int choice{};
    std::cin >> choice;

    while (choice != 1 && choice != 2)
    {
        std::cout << "\033[0;31m"; //red
        std::cout << "Invalid choice, try again: ";
        std::cout << "\u001b[0m"; //reset
        std::cin >> choice;
    }

    std::vector<int> first_state;

    if (choice == 1)
    {
        int a{}, b{}, c{};
        std::cout << "\033[0;34m"; //blue
        std::cout << "\nEnter your first row of the puzzle in order, the numbers should range from zero to 8(input empty space by 0): ";
        std::cout << "\u001b[0m"; //reset
        std::cin >> a >> b >> c;
        while (a > 8 || b > 8 || c > 8 || a == b || a == c || b == c)
        {
            std::cout << "\033[0;31m"; //red
            std::cout << "Invalid input, try again: ";
            std::cout << "\u001b[0m"; //reset
            std::cin >> a >> b >> c;
        }
        first_state.push_back(a);
        first_state.push_back(b);
        first_state.push_back(c);

        std::cout << "\033[0;34m"; //blue
        std::cout << "\nEnter your second row of the puzzle in order, the numbers should range from zero to 8(input empty space by 0): ";
        std::cout << "\u001b[0m"; //reset
        std::cin >> a >> b >> c;
        while (a > 8 || b > 8 || c > 8 || a == b || a == c || b == c || in_vec(first_state, a) || in_vec(first_state, b) || in_vec(first_state, c))
        {
            std::cout << "\033[0;31m"; //red
            std::cout << "Invalid input, try again: ";
            std::cout << "\u001b[0m"; //reset
            std::cin >> a >> b >> c;
        }
        first_state.push_back(a);
        first_state.push_back(b);
        first_state.push_back(c);

        std::cout << "\033[0;34m"; //blue
        std::cout << "\nEnter your third row of the puzzle in order, the numbers should range from zero to 8(input empty space by 0): ";
        std::cout << "\u001b[0m"; //reset
        std::cin >> a >> b >> c;
        while (a > 8 || b > 8 || c > 8 || a == b || a == c || b == c || in_vec(first_state, a) || in_vec(first_state, b) || in_vec(first_state, c))
        {
            std::cout << "\033[0;31m"; //red
            std::cout << "Invalid input, try again: ";
            std::cout << "\u001b[0m"; //reset
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

    std::cout << "\u001b[32;1m"; //green
    std::cout << "\nFirst State:\n";

    std::cout << "\033[0;31m"; //red
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
    std::cout << "\u001b[0m"; //reset

    return first_state;
}

std::vector<int> input_goal_vs_default_goal()
{
    std::cout << "\033[0;34m"; //blue
    std::cout << "\nwould you like to enter your goal state or do you want to use the default?\n\n"
              << "1.your custom goal state\n2.default goal\n\nInput the number you choose: ";
    std::cout << "\u001b[0m"; //reset

    int choice{};
    std::cin >> choice;

    while (choice != 1 && choice != 2)
    {
        std::cout << "\033[0;31m"; //red
        std::cout << "Invalid input, try again: ";
        std::cout << "\u001b[0m"; //reset
        std::cin >> choice;
    }

    std::vector<int> goal;

    if (choice == 1) //custom goal
    {
        int a{}, b{}, c{};
        std::cout << "\033[0;34m"; //blue
        std::cout << "\nEnter your first row of the goal state in order, the numbers should range from zero to 8(input empty space by 0): ";
        std::cout << "\u001b[0m"; //reset
        std::cin >> a >> b >> c;
        while (a > 8 || b > 8 || c > 8 || a == b || a == c || b == c)
        {
            std::cout << "\033[0;31m"; //red
            std::cout << "Invalid input, try again: ";
            std::cout << "\u001b[0m"; //reset
            std::cin >> a >> b >> c;
        }
        goal.push_back(a);
        goal.push_back(b);
        goal.push_back(c);

        std::cout << "\033[0;34m"; //blue
        std::cout << "\nEnter your second row of the goal state in order, the numbers should range from zero to 8(input empty space by 0): ";
        std::cout << "\u001b[0m"; //reset
        std::cin >> a >> b >> c;
        while (a > 8 || b > 8 || c > 8 || a == b || a == c || b == c || in_vec(goal, a) || in_vec(goal, b) || in_vec(goal, c))
        {
            std::cout << "\033[0;31m"; //red
            std::cout << "Invalid input, try again: ";
            std::cout << "\u001b[0m"; //reset
            std::cin >> a >> b >> c;
        }
        goal.push_back(a);
        goal.push_back(b);
        goal.push_back(c);

        std::cout << "\033[0;34m"; //blue
        std::cout << "\nEnter your third row of the goal state in order, the numbers should range from zero to 8(input empty space by 0): ";
        std::cout << "\u001b[0m"; //reset
        std::cin >> a >> b >> c;
        while (a > 8 || b > 8 || c > 8 || a == b || a == c || b == c || in_vec(goal, a) || in_vec(goal, b) || in_vec(goal, c))
        {
            std::cout << "\033[0;31m"; //red
            std::cout << "Invalid input, try again: ";
            std::cout << "\u001b[0m"; //reset
            std::cin >> a >> b >> c;
        }
        goal.push_back(a);
        goal.push_back(b);
        goal.push_back(c);
    }
    else //default goal
        goal = {1, 2, 3, 4, 5, 6, 7, 8, 0};

    std::cout << "\u001b[32;1m"; //green
    std::cout << "\nGoal State:\n";

    std::cout << "\033[0;31m"; //red
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
    std::cout << "\u001b[0m"; //reset
    return goal;
}

void choose_algorithm(std::vector<int> &init, const std::vector<int> &goal)
{
    int choice{};
    std::cout << "\033[0;34m"; //blue
    std::cout << "\nWhich algorithm do you want to solve your puzzle with?\n\n";
    std::cout << "1.BFS\n2.Fast BFS\n3.DFS\n\nInput the number you choose: ";
    std::cout << "\u001b[0m"; //reset
    std::cin >> choice;
    while (choice != 1 && choice != 2 && choice != 3)
    {
        std::cout << "\033[0;31m"; //red
        std::cout << "Invalid choice, try again: ";
        std::cout << "\u001b[0m"; //reset
        std::cin >> choice;
    }

    int depth_limit{};
    int depth_choice{};
    std::cout << "\\nDo you want to set a depth limit?\n\n"
              << "1.Yes\n2.No\n";
    std::cin >> depth_choice;

    while (depth_choice != 1 && depth_choice != 2)
    {
        std::cout << "\033[0;31m"; //red
        std::cout << "Invalid choice, try again: ";
        std::cout << "\u001b[0m"; //reset
        std::cin >> depth_choice;
    }
    if (depth_choice == 1)
    {
        std::cout << "\n\nEnter Depth limit: ";
        std::cin >> depth_limit;
        if (choice == 1)
            BFS(init, goal, depth_limit);
        else if (choice == 2)
            Fast_BFS(init, goal, depth_limit);
        else
            DFS(init, goal, depth_limit);
    }
    else
    {
        if (choice == 1)
            BFS(init, goal);
        else if (choice == 2)
            Fast_BFS(init, goal);
        else
            DFS(init, goal);
    }
}

bool continue_game()
{
    std::cout << "\033[0;32m"; //green
    std::cout << "\n\n\n************************************************************\n"
              << "Do you Want to play again?\n";
    std::cout << "1.Yes\n2.No\n\nInput the number you choose: ";
    std::cout << "\u001b[0m"; //reset
    int choice{};
    std::cin >> choice;
    while (choice != 1 && choice != 2)
    {
        std::cout << "\033[0;31m"; //red
        std::cout << "Invalid choice, try again: ";
        std::cout << "\u001b[0m"; //reset
        std::cin >> choice;
    }
    if (choice == 1)
        return true;
    return false;
}
