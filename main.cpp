#include <chrono>
#include "BFS.h"
#include "another_way_BFS.h"

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<size_t> goal{1, 2, 3, 4, 5, 6, 7, 8, 0};
    std::vector<size_t> a{1, 2, 3, 4, 8, 0, 7, 6, 5};
    std::vector<size_t> b{1, 2, 3, 6, 0, 4, 8, 5, 7};
    std::vector<size_t> c{1, 5, 7, 6, 8, 4, 3, 0, 2};
    std::vector<size_t> d{3, 5, 6, 8, 1, 4, 0, 7, 2};
    std::vector<size_t> e{7, 4, 2, 1, 3, 8, 0, 5, 6};
    std::vector<size_t> f{7, 8, 0, 5, 6, 1, 4, 2, 3};
    std::vector<size_t> non_solvable{8, 1, 2, 0, 4, 3, 7, 6, 5};
    BFS(b, goal);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
    std::cout << "******Time Taken To Solve The Puzzle: " << duration.count() << " Seconds******" << std::endl;
    return 0;
}
