#include "DFS.h"
#include "BFS.h"

void DFS(const std::vector<size_t> &init, const std::vector<size_t> &goal)
{
    if (!isSolvable(init))
    {
        std::cout << "\033[0;31m"; //red
        std::cout << "*************************\n";
        std::cout << "This puzzle is not solvable\n";
        std::cout << "*************************\n";
        std::cout << "\033[0;37m"; //gray
    }
    else if (init == goal) //when the initial puzzle is the goal puzzle!
    {
        std::cout << "\033[0;32m"; //green
        std::cout << "*************************\n";
        std::cout << "******PUZZLE SOLVED******\nNumber of steps: 0 || your initial puzzle is the goal puzzle\n";
        std::cout << "*************************\n";
        std::cout << "\033[0;37m"; //gray
    }
    else
    {
        std::stack<std::vector<size_t>> stack{};    //we use a stack to check each Depth of the graph in order
        std::vector<std::vector<size_t>> dfs{init}; //we use a vector to store the states that we have traversed, and we use it to prevent traversing one state twice
        stack.push(dfs.back());
        size_t steps{};
        Process_DFS(dfs, stack, steps);
    }
}

void Process_DFS(std::vector<std::vector<size_t>> &dfs, std::stack<std::vector<size_t>> &stack, size_t &steps)
{
    bool in_bfs{false};
    size_t i{}; // position of the empty block(here we use zero instead of empty, but when we print the puzzle, we print " " instead of "0")
}
