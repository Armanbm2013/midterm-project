#include <chrono>
#include "BFS.h"
#include "another_way_BFS.h"
#include "apmidproject.h"
#include "DFS.h"

int main()
{
    auto start = std::chrono::high_resolution_clock::now(); //r

    hello_game(); //welcome message

    std::vector<size_t> first_state{own_8_puzzle_vs_random()};

    std::vector<size_t> goal{input_goal_vs_default_goal()};

    choose_algorithm(first_state, goal);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
    std::cout << "******Time Taken To Solve The Puzzle: " << duration.count() << " Seconds******" << std::endl;

    // std::vector<size_t> goal{1, 2, 3, 4, 5, 6, 7, 8, 0};
    // std::vector<size_t> test1{1, 2, 3, 4, 6, 8, 0, 7, 5};
    // std::vector<size_t> test2{2, 3, 0, 1, 5, 6, 4, 7, 8};
    // std::vector<size_t> test3{1, 2, 3, 4, 6, 8, 7, 5, 0};
    // std::vector<size_t> test4{1, 2, 3, 0, 5, 6, 4, 7, 8};
    // std::vector<size_t> test5{8, 6, 3, 0, 4, 2, 5, 1, 2};
    return 0;
}
