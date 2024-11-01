#include <iostream>
#include <vector>
#include <string>
#include <stack>

#include "node.h"
#include "transition.h"
#include "tape.h"

#pragma once

class turingMachine {
 public:
  turingMachine() {}
  void makeMachine(std::string filename);
  bool evaluate(std::string input, bool trace);
  void printMachine() {
    for (Node node : states_) {
      std::cout << node << std::endl;
    }
  }
 private:
  Node& findNode(std::string name) {
    for (Node& node : states_) {
      if (node.getName() == name) {
        return node;
      }
    }
    throw std::invalid_argument("Node " + name + " not found");
  }
  void makeAlphabet(std::vector<std::string> alphabet);
  void makeTapeAlphabet(std::vector<std::string> tape_alphabet);
  void makeStates(std::vector<std::string> states_names);
  void makeFinalStates(std::vector<std::string> final_states);
  void analize(std::string input);
  void initializeTapes(std::string input, int tapes);
  void printTapes();
  std::vector<char> readTapes();

  char blank_symbol_;
  std::vector<Node> states_;
  Node startState_;
  Node actualState_;
  std::vector<Tape> tapes_;
  std::vector<char> alphabet_;
  std::vector<char> tapeAlphabet_;
};

