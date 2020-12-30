#include "BFS.h"
#include "another_way_BFS.h"
#include "apmidproject.h"
#include "DFS.h"

int main()
{
    hello_game(); //welcome message
    do
    {
        std::vector<size_t> first_state{own_8_puzzle_vs_random()}; //determinig first state
        std::vector<size_t> goal{input_goal_vs_default_goal()};    //determining goal state
        choose_algorithm(first_state, goal);
    } while (continue_game());

    //default goal: std::vector<size_t> goal{1, 2, 3, 4, 5, 6, 7, 8, 0};
    //tests:
    // std::vector<size_t> test1{1, 2, 3, 4, 6, 8, 0, 7, 5};
    // std::vector<size_t> test2{2, 3, 0, 1, 5, 6, 4, 7, 8};
    // std::vector<size_t> test3{1, 2, 3, 4, 6, 8, 7, 5, 0};
    // std::vector<size_t> test4{1, 2, 3, 0, 5, 6, 4, 7, 8};
    return 0;
}
