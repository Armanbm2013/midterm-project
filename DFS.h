#ifndef DFS_h
#define DFS_h

#include <iostream>
#include <vector>
#include <stack>

void DFS(std::vector<int> &init, const std::vector<int> &goal, const int &depth_limit = -1);
void solved_DFS(std::stack<std::vector<int>> &stack, const std::vector<int> &goal);

#endif
