#ifndef DFS_h
#define DFS_h

#include <iostream>
#include <vector>
#include <stack>

bool Process_DFS(std::vector<std::vector<size_t>> &dfs, std::stack<std::vector<size_t>> &stack, size_t &steps);
void DFS(const std::vector<size_t> &init, const std::vector<size_t> &goal);

#endif
