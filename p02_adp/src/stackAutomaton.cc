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
    if (states_names[i].find("#") != std::string::npos) {
      throw std::invalid_argument("State name cannot contain the character #");
    }
    states_.push_back(Node(states_names[i]));
  }
}

void StackAutomaton::makeFinalStates(std::vector<std::string> final_states) {
  for (int i = 0; i < final_states.size(); i++) {
    try {
      findNode(final_states[i]).setFinal(true);
    } catch (std::invalid_argument& e) {
      throw std::invalid_argument("Final state " + final_states[i] + " not found");
    }
  }
}

void StackAutomaton::makeAutomaton(std::string filename) {
  std::vector<std::string> important_lines = getImportantLines(filename);
  makeStates(split(important_lines[0], ' '));
  makeAlphabet(split(important_lines[1], ' '));
  makeStackAlphabet(split(important_lines[2], ' '));
  std::string start_state = important_lines[3];
  char starting_stack_symbol = important_lines[4][0];
  if (std::find(stackAlphabet_.begin(), stackAlphabet_.end(), starting_stack_symbol) == stackAlphabet_.end()) {
    throw std::invalid_argument("Starting stack symbol not in stack alphabet");
  }
  makeFinalStates(split(important_lines[5], ' '));
  for (int i = 6; i < important_lines.size(); i++) {
    std::vector<std::string> transition = split(important_lines[i], ' ');
    Node& node = findNode(transition[0]);

    char symbol = transition[1][0];
    if (std::find(alphabet_.begin(), alphabet_.end(), symbol) == alphabet_.end() && symbol != '.') {
      throw std::invalid_argument("Transition symbol " + std::string(1,symbol) +  " not in alphabet");
    }

    char stack_symbol_consumed = transition[2][0];
    if (std::find(stackAlphabet_.begin(), stackAlphabet_.end(), stack_symbol_consumed) == stackAlphabet_.end()) {
      throw std::invalid_argument("Stack symbol consumed " + std::string(1,stack_symbol_consumed) + " not in stack alphabet");
    }

    std::string next_node_name = transition[3];
    if (std::find_if(states_.begin(), states_.end(), [&next_node_name](Node node) { return node.getName() == next_node_name; }) == states_.end()) {
      throw std::invalid_argument("Next node " + next_node_name + " not found");
    }

    std::string stack_symbol_produced = transition[4];
    for (int i = 0; i < stack_symbol_produced.size(); i++) {
      if (std::find(stackAlphabet_.begin(), stackAlphabet_.end(), stack_symbol_produced[i]) == stackAlphabet_.end() && stack_symbol_produced[i] != '.') {
        throw std::invalid_argument("Stack symbol produced " + std::string(1,stack_symbol_produced[i]) + " not in stack alphabet");
      }
    }
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

void StackAutomaton::analize(std::string input) {
  for (int i = 0; i < input.size(); i++) {
    if (std::find(alphabet_.begin(), alphabet_.end(), input[i]) == alphabet_.end()) {
      throw std::invalid_argument("Input contains symbols not in the alphabet");
    }
  }
}

bool StackAutomaton::evaluate(std::string input) {
  try {
    analize(input);
    initializeStack();
    return evaluatePrivate(input, startState_, 0);
  } catch (std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
    return false;
  }
}

bool StackAutomaton::evaluatePrivate(std::string input, Node current_node, int i) {
  std::vector<Transition> transitions = current_node.getTransitions(input[i], stack_.top());
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
  return (current_node.isFinal() && i > input.size() - 1);
}