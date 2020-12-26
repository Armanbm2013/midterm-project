#ifndef DFS_h
#define DFS_h

#include <iostream>
#include <vector>
#include <stack>

void Process_DFS(const std::vector<size_t> &init, const std::vector<size_t> &goal, std::vector<std::vector<size_t>> &dfs, std::stack<std::vector<size_t>> &stack);
void DFS(const std::vector<size_t> &init, const std::vector<size_t> &goal);

#endif
