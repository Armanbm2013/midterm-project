#ifndef apmidproject_h
#define apmidproject_h

#include <iostream>
#include <vector>

bool in_vec(const std::vector<size_t> &v, size_t a);
void hello_game();
std::vector<size_t> own_8_puzzle_vs_random();
std::vector<size_t> input_goal_vs_default_goal();
void choose_algorithm(std::vector<size_t> &init, const std::vector<size_t> &goal);

#endif
