#ifndef BFS_h
#define BFS_h

#include <iostream>
#include <vector>
#include <queue>
#include "Node.h"

void BFS(std::vector<int> &initial, const std::vector<int> &goal, const int &depth_limit = -1);
void solved_Fast_BFS(Node &goal_node, const std::vector<int> &goal);
size_t traverse_BFS_goal1(std::vector<int> &state, std::vector<Node> &bfs1, std::queue<Node> &queue1, const Node &temp1, bool &in_bfs1, const std::vector<int> &goal, const int &goal_zero, Node &init);
size_t traverse_BFS_goal2(std::vector<int> &state, std::vector<Node> &bfs2, std::queue<Node> &queue2, const Node &temp1, bool &in_bfs2, const std::vector<int> &goal, const int &goal_zero, Node &init);
size_t traverse_BFS_goal3(std::vector<int> &state, std::vector<Node> &bfs2, std::queue<Node> &queue2, const Node &temp1, bool &in_bfs2, const std::vector<int> &goal, const int &goal_zero, Node &init);

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
