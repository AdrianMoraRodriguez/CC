#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#include "stackAutomaton.h"
#include "utils.h"

void StackAutomaton::makeAutomaton(std::string filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::invalid_argument("File not found");
  }
  std::string line;
  std::vector<std::string> important_lines;
  while (std::getline(file, line)) {
    if (line[0] == '#') {
      continue;
    }
    important_lines.push_back(line);
  }
  std::vector<std::string> states_names = split(important_lines[0], ' ');
  std::vector<std::string> alphabet = split(important_lines[1], ' ');
  std::vector<std::string> stack_alphabet = split(important_lines[2], ' ');
  std::string start_state = important_lines[3];
  char starting_stack_symbol = important_lines[4][0];
  std::vector<std::string> final_states = split(important_lines[5], ' ');
  
}