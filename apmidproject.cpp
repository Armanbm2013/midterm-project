#include "apmidproject.h"
#include "time.h"

bool in_vec(const std::vector<size_t> &v, size_t a)
{
    for (auto &num : v)
        if (num == a)
            return true;
    return false;
}

void hello_game(){
    std::cout << "******Wlecome to the 8-pullze game******\n\n************************************************************\n\n"}

std::vector<size_t> own_8_puzzle_vs_random()
{
    std::cout << "Do you want to solve your own 8-puzzle or want to see how a random puzzle is solved?\n\n"
              << "1.your own 8-puzzle\n2.a random 8-puzzle\n";

    size_t choice{};
    std::cin >> choice;

    while (choice != 1 && choice != 2)
    {
        std::cout << "Invalid input, try again: ";
        std::cin >> choice;
    }

    std::vector<size_t> first_state;

    if (choice == 1)
    {
        size_t a{}, b{}, c{};
        std::cout << "Enter your first row of the puzzle in order, the numbers should range from zero to 8(input empty space by 0): ";
        std::cin >> a >> b >> c;
        bool first_condition{a > 8 || b > 8 || c > 8 || a == b || a == c || b == c};
        while (first_condition)
        {
            std::cout << "Invalid input, try again: ";
            std::cin >> a >> b >> c;
        }
        first_state.push_back(a);
        first_state.push_back(b);
        first_state.push_back(c);

        std::cout << "Enter your second row of the puzzle in order, the numbers should range from zero to 8(input empty space by 0): ";
        std::cin >> a >> b >> c;
        first_condition = a > 8 || b > 8 || c > 8 || a == b || a == c || b == c;
        while (first_condition || in_vec(first_state, a) || in_vec(first_state, b) || in_vec(first_state, c))
        {
            std::cout << "Invalid input, try again: ";
            std::cin >> a >> b >> c;
        }
        first_state.push_back(a);
        first_state.push_back(b);
        first_state.push_back(c);

        std::cout << "Enter your third row of the puzzle in order, the numbers should range from zero to 8(input empty space by 0): ";
        std::cin >> a >> b >> c;
        first_condition = a > 8 || b > 8 || c > 8 || a == b || a == c || b == c;
        while (first_condition || in_vec(first_state, a) || in_vec(first_state, b) || in_vec(first_state, c))
        {
            std::cout << "Invalid input, try again: ";
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

    return first_state;
}