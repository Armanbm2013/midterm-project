#include "apmidproject.h"
#include "time.h"
#include "BFS.h"
#include "DFS.h"
#include "another_way_BFS.h"

bool in_vec(const std::vector<size_t> &v, size_t a)
{
    for (auto &num : v)
        if (num == a)
            return true;
    return false;
}

void hello_game()
{
    std::cout << "\033[0;32m"; //green
    std::cout << "\n\n************************************************************\n"
              << "****************Wlecome to the 8-pullze game****************\n"
              << "************************************************************\n\n";
    std::cout << "\033[0;37m"; //gray
}

std::vector<size_t> own_8_puzzle_vs_random()
{
    std::cout << "\033[0;34m"; //blue
    std::cout << "\nDo you want to solve your own 8-puzzle or want to see how a random puzzle is solved?\n\n"
              << "1.your own 8-puzzle\n2.a random 8-puzzle\n\nInput the number you choose: ";
    std::cout << "\033[0;37m"; //gray

    size_t choice{};
    std::cin >> choice;

    while (choice != 1 && choice != 2)
    {
        std::cout << "\033[0;31m"; //red
        std::cout << "Invalid choice, try again: ";
        std::cout << "\033[0;37m"; //gray
        std::cin >> choice;
    }

    std::vector<size_t> first_state;

    if (choice == 1)
    {
        size_t a{}, b{}, c{};
        std::cout << "\033[0;34m"; //blue
        std::cout << "\nEnter your first row of the puzzle in order, the numbers should range from zero to 8(input empty space by 0): ";
        std::cout << "\033[0;37m"; //gray
        std::cin >> a >> b >> c;
        while (a > 8 || b > 8 || c > 8 || a == b || a == c || b == c)
        {
            std::cout << "\033[0;31m"; //red
            std::cout << "Invalid input, try again: ";
            std::cout << "\033[0;37m"; //gray
            std::cin >> a >> b >> c;
        }
        first_state.push_back(a);
        first_state.push_back(b);
        first_state.push_back(c);

        std::cout << "\033[0;34m"; //blue
        std::cout << "\nEnter your second row of the puzzle in order, the numbers should range from zero to 8(input empty space by 0): ";
        std::cout << "\033[0;37m"; //gray
        std::cin >> a >> b >> c;
        while (a > 8 || b > 8 || c > 8 || a == b || a == c || b == c || in_vec(first_state, a) || in_vec(first_state, b) || in_vec(first_state, c))
        {
            std::cout << "\033[0;31m"; //red
            std::cout << "Invalid input, try again: ";
            std::cout << "\033[0;37m"; //gray
            std::cin >> a >> b >> c;
        }
        first_state.push_back(a);
        first_state.push_back(b);
        first_state.push_back(c);

        std::cout << "\033[0;34m"; //blue
        std::cout << "\nEnter your third row of the puzzle in order, the numbers should range from zero to 8(input empty space by 0): ";
        std::cout << "\033[0;37m"; //gray
        std::cin >> a >> b >> c;
        while (a > 8 || b > 8 || c > 8 || a == b || a == c || b == c || in_vec(first_state, a) || in_vec(first_state, b) || in_vec(first_state, c))
        {
            std::cout << "\033[0;31m"; //red
            std::cout << "Invalid input, try again: ";
            std::cout << "\033[0;37m"; //gray
            std::cin >> a >> b >> c;
        }
        first_state.push_back(a);
        first_state.push_back(b);
        first_state.push_back(c);
    }
    else if (choice == 2)
    {
        size_t temp{};
        srand(time(0));
        while (first_state.size() != 9)
        {
            temp = rand() % 9;
            while (in_vec(first_state, temp))
                temp = rand() % 9;
            first_state.push_back(temp);
        }
    }

    std::cout << "\033[0;32m"; //green
    std::cout << "\nFirst State:\n";

    std::cout << "\033[0;31m"; //red
    for (size_t i{}; i < 9; i++)
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
    std::cout << "\033[0;37m"; //gray

    return first_state;
}

std::vector<size_t> input_goal_vs_default_goal()
{
    std::cout << "\033[0;34m"; //blue
    std::cout << "\nwould you like to enter your goal state or do you want to use the default?\n\n"
              << "1.your custom goal state\n2.default goal\n\nInput the number you choose: ";
    std::cout << "\033[0;37m"; //gray

    size_t choice{};
    std::cin >> choice;

    while (choice != 1 && choice != 2)
    {
        std::cout << "\033[0;31m"; //red
        std::cout << "Invalid input, try again: ";
        std::cout << "\033[0;37m"; //gray
        std::cin >> choice;
    }

    std::vector<size_t> goal;

    if (choice == 1) //custom goal
    {
        size_t a{}, b{}, c{};
        std::cout << "\033[0;34m"; //blue
        std::cout << "\nEnter your first row of the goal state in order, the numbers should range from zero to 8(input empty space by 0): ";
        std::cout << "\033[0;37m"; //gray
        std::cin >> a >> b >> c;
        while (a > 8 || b > 8 || c > 8 || a == b || a == c || b == c)
        {
            std::cout << "\033[0;31m"; //red
            std::cout << "Invalid input, try again: ";
            std::cout << "\033[0;37m"; //gray
            std::cin >> a >> b >> c;
        }
        goal.push_back(a);
        goal.push_back(b);
        goal.push_back(c);

        std::cout << "\033[0;34m"; //blue
        std::cout << "\nEnter your second row of the goal state in order, the numbers should range from zero to 8(input empty space by 0): ";
        std::cout << "\033[0;37m"; //gray
        std::cin >> a >> b >> c;
        while (a > 8 || b > 8 || c > 8 || a == b || a == c || b == c || in_vec(goal, a) || in_vec(goal, b) || in_vec(goal, c))
        {
            std::cout << "\033[0;31m"; //red
            std::cout << "Invalid input, try again: ";
            std::cout << "\033[0;37m"; //gray
            std::cin >> a >> b >> c;
        }
        goal.push_back(a);
        goal.push_back(b);
        goal.push_back(c);

        std::cout << "\033[0;34m"; //blue
        std::cout << "\nEnter your third row of the goal state in order, the numbers should range from zero to 8(input empty space by 0): ";
        std::cout << "\033[0;37m"; //gray
        std::cin >> a >> b >> c;
        while (a > 8 || b > 8 || c > 8 || a == b || a == c || b == c || in_vec(goal, a) || in_vec(goal, b) || in_vec(goal, c))
        {
            std::cout << "\033[0;31m"; //red
            std::cout << "Invalid input, try again: ";
            std::cout << "\033[0;37m"; //gray
            std::cin >> a >> b >> c;
        }
        goal.push_back(a);
        goal.push_back(b);
        goal.push_back(c);
    }
    else //default goal
        goal = {1, 2, 3, 4, 5, 6, 7, 8, 0};

    std::cout << "\033[0;32m"; //green
    std::cout << "\nGoal State:\n";

    std::cout << "\033[0;31m"; //red
    for (size_t i{}; i < 9; i++)
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
    std::cout << "\033[0;37m"; //gray
    return goal;
}

void choose_algorithm(std::vector<size_t> &init, const std::vector<size_t> &goal)
{
    size_t choice{};
    std::cout << "\033[0;34m"; //blue
    std::cout << "\nWhich algorithm do you want to solve your puzzle with?\n\n";
    std::cout << "1.BFS\n2.Fast BFS\n3.DFS\n\nInput the number you choose: ";
    std::cout << "\033[0;37m"; //gray
    std::cin >> choice;
    while (choice != 1 && choice != 2 && choice != 3)
    {
        std::cout << "\033[0;31m"; //red
        std::cout << "Invalid choice, try again: ";
        std::cout << "\033[0;37m"; //gray
        std::cin >> choice;
    }
    if (choice == 1)
    {
        BFS(init, goal);
    }
    else if (choice == 2)
    {
        another_algorithm_BFS(init, goal);
    }
    else
    {
        DFS(init, goal);
    }
}

bool continue_game()
{
    std::cout << "\033[0;32m"; //green
    std::cout << "\n\n\n************************************************************\n"
              << "Do you Want to play again?\n";
    std::cout << "1.Yes\n2.No\n\nInput the number you choose: ";
    std::cout << "\033[0;37m"; //gray
    size_t choice{};
    std::cin >> choice;
    while (choice != 1 && choice != 2)
    {
        std::cout << "\033[0;31m"; //red
        std::cout << "Invalid choice, try again: ";
        std::cout << "\033[0;37m"; //gray
        std::cin >> choice;
    }
    if (choice == 1)
        return true;
    return false;
}