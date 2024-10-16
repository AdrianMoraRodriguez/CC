#include <iostream>
#include <vector>
#include <string>
#include <stack>

#include "node.h"
#include "transition.h"

#pragma once

class StackAutomaton {
 public:
  StackAutomaton() {}
  void makeAutomaton(std::string filename);
 private:
  Node& findNode(std::string name) {
    for (Node& node : states_) {
      if (node.getName() == name) {
        return node;
      }
    }
    throw std::invalid_argument("Node not found");
  }
  std::stack<Transition> stack_;
  std::vector<Node> states_;
  std::vector<char> alphabet_;
  std::vector<char> stackAlphabet_;
};

