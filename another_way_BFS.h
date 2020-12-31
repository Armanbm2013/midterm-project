#ifndef awbfs_h
#define awbfs_h

#include <iostream>
#include <vector>
#include <queue>

void Fast_BFS(std::vector<int> &init, const std::vector<int> &goal, const int &depth_limit = -1);
bool is_goal_1(const std::vector<int> &state, const std::vector<int> &goal);
bool is_goal_2(const std::vector<int> &state, const std::vector<int> &goal);
bool is_goal_3(const std::vector<int> &state, const std::vector<int> &goal);
bool is_goal_4(const std::vector<int> &state, const std::vector<int> &goal);

#endif
