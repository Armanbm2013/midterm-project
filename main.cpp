#include <chrono>
#include "BFS.h"
#include "another_way_BFS.h"
#include "apmidproject.h"
#include "DFS.h"

int main()
{
    // auto start = std::chrono::high_resolution_clock::now();

    // hello_game();
    // std::vector<size_t> first_state{own_8_puzzle_vs_random()};
    // std::vector<size_t> goal{input_goal_vs_default_goal()};

    // size_t choice{};
    // std::cout << "\nWhich algorithm do you want to solve your puzzle with?:\n\n";
    // std::cout << "1.BFS\n2.Fast BFS\n3.DFS\nInput the number of algorithm you choose: ";
    // std::cin >> choice;
    // while (choice != 1 && choice != 2 && choice != 3)
    // {
    //     std::cout << "Invalid input, try again: ";
    //     std::cin >> choice;
    // }

    // auto stop = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
    // std::cout << "******Time Taken To Solve The Puzzle: " << duration.count() << " Seconds******" << std::endl;
    std::vector<size_t> goal{1, 2, 3, 4, 5, 6, 7, 8, 0};
    std::vector<size_t> test1{1, 2, 3, 4, 6, 8, 0, 7, 5};
    DFS(test1, goal);
    return 0;
}
