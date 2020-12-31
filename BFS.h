#ifndef BFS_h
#define BFS_h

#include <iostream>
#include <vector>
#include <queue>

void BFS(std::vector<int> &init, const std::vector<int> &goal, const int &depth_limit = -1);
bool is_goal(const std::vector<int> &state, const std::vector<int> &goal);
void solved(int steps, const std::vector<int> &goal);
void print_puzzle(int steps, const std::vector<int> &state);
int getInvCount(const std::vector<int> &arr);
bool isSolvable(const std::vector<int> &arr, const std::vector<int> &goal);
#endif
