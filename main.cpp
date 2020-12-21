#include "BFS.h"

int main()
{
    std::vector<size_t> goal{1, 2, 3, 4, 5, 6, 7, 8, 0};
    std::vector<size_t> a{4, 3, 8, 0, 5, 6, 1, 2, 7};
    std::vector<size_t> b{0, 7, 5, 4, 2, 1, 8, 6, 3};
    std::vector<size_t> c{3, 2, 0, 7, 5, 6, 4, 1, 8};
    std::vector<size_t> d{0, 1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<size_t> non_solvable{8, 1, 2, 0, 4, 3, 7, 6, 5};
    BFS(goal, goal);
    return 0;
}
