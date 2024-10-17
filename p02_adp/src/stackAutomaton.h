#include <iostream>
#include <vector>
#include <string>
#include <stack>

#include "node.h"
#include "transition.h"
#include "stack.h"

#pragma once

class StackAutomaton {
 public:
  StackAutomaton() {}
  void makeAutomaton(std::string filename);
  bool evaluate(std::string input, bool trace);
  void printAutomaton() {
    for (Node node : states_) {
      std::cout << node << std::endl;
    }
  }
 private:
 void initializeStack() {
  while (!stack_.empty()) {
    stack_.pop();
  }
  stack_.push(startingStackSymbol_);
 }
  Node& findNode(std::string name) {
    for (Node& node : states_) {
      if (node.getName() == name) {
        return node;
      }
    }
    throw std::invalid_argument("Node " + name + " not found");
  }
  void makeAlphabet(std::vector<std::string> alphabet);
  void makeStackAlphabet(std::vector<std::string> stack_alphabet);
  void makeStates(std::vector<std::string> states_names);
  void makeFinalStates(std::vector<std::string> final_states);
  void pushStack(std::string stack_symbols);
  void analize(std::string input);
  bool evaluatePrivate(std::string input, Node current_node, int i, bool trace);
  Stack stack_;
  char startingStackSymbol_;
  std::vector<Node> states_;
  Node startState_;
  Node actualState_;
  std::vector<char> alphabet_;
  std::vector<char> stackAlphabet_;
};

