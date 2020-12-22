#ifndef BFS_h
#define BFS_h

#include <iostream>
#include <vector>
#include <queue>

void BFS(const std::vector<size_t> &init, const std::vector<size_t> &goal);
bool is_goal(const std::vector<size_t> &state, const std::vector<size_t> &goal);
void solved(size_t steps, const std::vector<size_t> &goal);
void print_puzzle(size_t steps, const std::vector<size_t> &state);
int getInvCount(const std::vector<size_t> &arr);
bool isSolvable(const std::vector<size_t> &arr);
#endif
