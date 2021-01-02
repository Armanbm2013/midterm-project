#ifndef DFS_h
#define DFS_h

#include <iostream>
#include <vector>
#include <stack>

void DFS(std::vector<int> &init, const std::vector<int> &goal, const int &depth_limit = -1);
void solved_DFS(std::stack<std::vector<int>> &stack, const std::vector<int> &goal);

bool is_goal(const std::vector<int> &state, const std::vector<int> &goal);
void print_puzzle(int steps, const std::vector<int> &state);
int getInvCount(const std::vector<int> &arr);
bool isSolvable(const std::vector<int> &arr, const std::vector<int> &goal);

#endif
