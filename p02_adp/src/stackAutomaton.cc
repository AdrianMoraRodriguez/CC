#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#include "stackAutomaton.h"
#include "utils.h"


void StackAutomaton::makeAlphabet(std::vector<std::string> alphabet) {
  for (int i = 0; i < alphabet.size(); i++) {
    if (alphabet[i].size() != 1) {
      throw std::invalid_argument("Alphabet must contain single characters");
    }
    if (alphabet[i][0] == '.') {
      throw std::invalid_argument("Alphabet cannot contain the empty string");
    }
    alphabet_.push_back(alphabet[i][0]);
  }
}


void StackAutomaton::makeStackAlphabet(std::vector<std::string> stack_alphabet) {
  for (int i = 0; i < stack_alphabet.size(); i++) {
    if (stack_alphabet[i].size() != 1) {
      throw std::invalid_argument("Stack alphabet must contain single characters");
    }
    if (stack_alphabet[i][0] == '.') {
      throw std::invalid_argument("Stack alphabet cannot contain the empty string");
    }
    stackAlphabet_.push_back(stack_alphabet[i][0]);
  }
}

void StackAutomaton::makeStates(std::vector<std::string> states_names) {
  for (int i = 0; i < states_names.size(); i++) {
    states_.push_back(Node(states_names[i]));
  }
}

void StackAutomaton::makeFinalStates(std::vector<std::string> final_states) {
  for (int i = 0; i < final_states.size(); i++) {
    findNode(final_states[i]).setFinal(true);
  }
}

void StackAutomaton::makeAutomaton(std::string filename) {
  std::vector<std::string> important_lines = getImportantLines(filename);
  makeStates(split(important_lines[0], ' '));
  makeAlphabet(split(important_lines[1], ' '));
  makeStackAlphabet(split(important_lines[2], ' '));
  std::string start_state = important_lines[3];
  char starting_stack_symbol = important_lines[4][0];
  makeFinalStates(split(important_lines[5], ' '));
  for (int i = 6; i < important_lines.size(); i++) {
    std::vector<std::string> transition = split(important_lines[i], ' ');
    Node& node = findNode(transition[0]);
    char symbol = transition[1][0];
    char stack_symbol_consumed = transition[2][0];
    std::string next_node_name = transition[3];
    std::string stack_symbol_produced = transition[4];
    node.addTransition(Transition(symbol, next_node_name, stack_symbol_consumed, stack_symbol_produced));
  }
  startState_ = findNode(start_state);
  startingStackSymbol_ = starting_stack_symbol;
}

void StackAutomaton::pushStack(std::string stack_symbols) {
  for (int i = stack_symbols.size() - 1; i >= 0; i--) {
    stack_.push(stack_symbols[i]);
  }
}

bool StackAutomaton::evaluate(std::string input) {
  initializeStack();
  return evaluatePrivate(input, startState_, 0);
}

bool StackAutomaton::evaluatePrivate(std::string input, Node current_node, int i) {
  std::vector<Transition> transitions = current_node.getTransitions(input[i], stack_.top());
  if (transitions.size() == 0) {
    if (current_node.isFinal() && i > input.size() - 1) {
      return true;
    } else {
      return false;
    }
  }
  for (Transition transition : transitions) {
    std::stack<char> stack_copy = stack_;
    if (transition.getStackSymbolConsumed() == '.') {
      throw std::invalid_argument("Transition must consume a stack symbol");
    }
    stack_.pop();
    if (transition.getStackSymbolProduced() != ".") {
      pushStack(transition.getStackSymbolProduced());
    }
    if (transition.getSymbol() == '.') {
      if (evaluatePrivate(input, findNode(transition.getNextNodeName()), i)) {
        return true;
      }
    } else {
      if (evaluatePrivate(input, findNode(transition.getNextNodeName()), i + 1)) {
        return true;
      }
    }
    stack_ = stack_copy;
  }
  if (current_node.isFinal() && i > input.size() - 1) {
    return true;
  } else {
    return false;
  }
}