#ifndef apmidproject_h
#define apmidproject_h

#include <iostream>
#include <vector>

bool in_vec(const std::vector<int> &v, int a);
void hello_game();
std::vector<int> own_8_puzzle_vs_random();
std::vector<int> input_goal_vs_default_goal();
void choose_algorithm(std::vector<int> &init, const std::vector<int> &goal);
bool continue_game();

#endif
