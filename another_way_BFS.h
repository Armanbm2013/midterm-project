#ifndef awbfs_h
#define awbfs_h

#include <iostream>
#include <vector>
#include <queue>
#include "Node.h"

void Fast_BFS(std::vector<int> &i, const std::vector<int> &goal, const int &depth_limit = -1);
void solved_Fast_BFS(Node &goal_node, const std::vector<int> &goal);

bool is_goal_4578_1(const std::vector<int> &state, const std::vector<int> &goal);
bool is_goal_4578_2(const std::vector<int> &state, const std::vector<int> &goal);
bool is_goal_4578_3(const std::vector<int> &state, const std::vector<int> &goal);
bool is_goal_4578_4(const std::vector<int> &state, const std::vector<int> &goal);

bool is_goal_013_1(const std::vector<int> &state, const std::vector<int> &goal);
bool is_goal_013_2(const std::vector<int> &state, const std::vector<int> &goal);
bool is_goal_013_3(const std::vector<int> &state, const std::vector<int> &goal);
bool is_goal_013_4(const std::vector<int> &state, const std::vector<int> &goal);

bool is_goal_2_1(const std::vector<int> &state, const std::vector<int> &goal);
bool is_goal_2_2(const std::vector<int> &state, const std::vector<int> &goal);
bool is_goal_2_3(const std::vector<int> &state, const std::vector<int> &goal);
bool is_goal_2_4(const std::vector<int> &state, const std::vector<int> &goal);

bool is_goal_6_1(const std::vector<int> &state, const std::vector<int> &goal);
bool is_goal_6_2(const std::vector<int> &state, const std::vector<int> &goal);
bool is_goal_6_3(const std::vector<int> &state, const std::vector<int> &goal);
bool is_goal_6_4(const std::vector<int> &state, const std::vector<int> &goal);

#endif
