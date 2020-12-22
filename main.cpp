#include "BFS.h"
#include "another_way_BFS.h"

int main()
{
    std::vector<size_t> goal{1, 2, 3, 4, 5, 6, 7, 8, 0};
    std::vector<size_t> a{1, 2, 3, 4, 8, 0, 7, 6, 5};
    std::vector<size_t> b{1, 2, 3, 6, 0, 4, 8, 5, 7};
    std::vector<size_t> c{1, 5, 7, 6, 8, 4, 3, 0, 2};
    std::vector<size_t> non_solvable{8, 1, 2, 0, 4, 3, 7, 6, 5};
    another_algorithm_BFS(b, goal);
    return 0;
}
