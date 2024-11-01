#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#include "turingMachine.h"
#include "utils.h"


void turingMachine::makeAlphabet(std::vector<std::string> alphabet) {
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


void turingMachine::makeTapeAlphabet(std::vector<std::string> tape_alphabet) {
  for (int i = 0; i < tape_alphabet.size(); i++) {
    if (tape_alphabet[i].size() != 1) {
      throw std::invalid_argument("tape alphabet must contain single characters");
    }
    tapeAlphabet_.push_back(tape_alphabet[i][0]);
  }
}

void turingMachine::makeStates(std::vector<std::string> states_names) {
  for (int i = 0; i < states_names.size(); i++) {
    if (states_names[i].find("#") != std::string::npos) {
      throw std::invalid_argument("State name cannot contain the character #");
    }
    states_.push_back(Node(states_names[i]));
  }
}

void turingMachine::makeFinalStates(std::vector<std::string> final_states) {
  for (int i = 0; i < final_states.size(); i++) {
    try {
      findNode(final_states[i]).setFinal(true);
    } catch (std::invalid_argument& e) {
      throw std::invalid_argument("Final state " + final_states[i] + " not found");
    }
  }
}

void turingMachine::makeMachine(std::string filename) {
  std::vector<std::string> important_lines = getImportantLines(filename);
  makeStates(split(important_lines[0], ' '));
  makeAlphabet(split(important_lines[1], ' '));
  makeTapeAlphabet(split(important_lines[2], ' '));
  std::string start_state = important_lines[3];
  char blank_symbol = important_lines[4][0];
  tapeAlphabet_.push_back(blank_symbol);
  if (std::find(alphabet_.begin(), alphabet_.end(), blank_symbol) != alphabet_.end()) {
    throw std::invalid_argument("Blank symbol " + std::string(1,blank_symbol) + " cannot be in the alphabet");
  }
  makeFinalStates(split(important_lines[5], ' '));
  int tapes = important_lines[6][0] - '0';
  for (int i = 7; i < important_lines.size(); i++) {
    std::vector<std::string> transition = split(important_lines[i], ' ');
    Node& node = findNode(transition[0]);
    int position = 1;
    std::vector<char> symbols;
    for (int j = 0; j < tapes; j++) {
      char symbol = transition[position][0];
      if (std::find(tapeAlphabet_.begin(), tapeAlphabet_.end(), symbol) == tapeAlphabet_.end() && std::find(alphabet_.begin(), alphabet_.end(), symbol) == alphabet_.end()) {
        throw std::invalid_argument("Transition symbol " + std::string(1,symbol) +  " not in tape alphabet");
      }
      symbols.push_back(symbol);
      position++;
    }
    std::string next_node_name = transition[position++];
    findNode(next_node_name);
    std::vector<char> symbols_to_write;
    std::vector<char> movements;
    for (int j = 0; j < tapes; j++) {
      char symbol = transition[position][0];
      if (std::find(tapeAlphabet_.begin(), tapeAlphabet_.end(), symbol) == tapeAlphabet_.end() && std::find(alphabet_.begin(), alphabet_.end(), symbol) == alphabet_.end()) {
        throw std::invalid_argument("Transition symbol " + std::string(1,symbol) +  " not in tape alphabet");
      }
      symbols_to_write.push_back(symbol);
      position++;
      char movement = transition[position][0];
      if (movement != 'L' && movement != 'R' && movement != 'S') {
        throw std::invalid_argument("Movement must be L, R or S");
      }
      movements.push_back(movement);
      position++;
    }
    node.addTransition(Transition(symbols, next_node_name, symbols_to_write, movements));
  }
  for (int i = 0; i < tapes; i++) {
    tapes_.push_back(Tape(blank_symbol));
    std::cout << "Tape " << i << ": " << tapes_[i] << std::endl;
  }
  startState_ = findNode(start_state);
  blank_symbol_ = blank_symbol;
}


void turingMachine::analize(std::string input) {
  for (int i = 0; i < input.size(); i++) {
    if (std::find(alphabet_.begin(), alphabet_.end(), input[i]) == alphabet_.end()) {
      throw std::invalid_argument("Input contains symbols not in the alphabet");
    }
  }
}

void turingMachine::initializeTapes(std::string input, int tapes) {
  tapes_[0].Initialize(input);
  for (int i = 1; i < tapes; i++) {
    tapes_[i].Initialize("");
  }
}

std::vector<char> turingMachine::readTapes() {
  std::vector<char> result;
  for (Tape tape : tapes_) {
    result.push_back(tape.Read());
  }
  return result;
}

void turingMachine::printTapes() {
  std::cout << "Tapes:\n";
  for (Tape tape : tapes_) {
    std::cout << tape << "\n";
  }
  std::cout << std::endl;
}

bool turingMachine::evaluate(std::string input, bool trace) {
  analize(input);
  initializeTapes(input, tapes_.size());
  Node current_node = startState_;
  std::vector<Transition> transitions;
  transitions = current_node.getTransitions(readTapes());
  while (transitions.size() != 0) {
    Transition transition = transitions[0];
      for (int i = 0; i < tapes_.size(); i++) {
        tapes_[i].WriteAndMove(transition.getSymbolsToWrite()[i], transition.getMovements()[i]);
      }
      current_node = findNode(transition.getNextNodeName());
      if (trace) {
        std::cout << "Current node: " << current_node.getName() << std::endl;
        std::cout << "Current input: " << input << std::endl;
        std::cout << "Current tapes: ";
        for (Tape tape : tapes_) {
          std::cout << tape << " ";
        }
        std::cout << std::endl;
        std::cout << "------------------------" << std::endl;
      }
    transitions = current_node.getTransitions(readTapes());
  }
  printTapes();
  return current_node.isFinal();
}

// bool turingMachine::evaluatePrivate(std::string input, Node current_node, int i, bool trace) {
//   std::vector<Transition> transitions;
//   if (stack_.empty()) {
//     return (current_node.isFinal() && i > input.size() - 1);
//   } else {
//     transitions = current_node.getTransitions(input[i], stack_.top());
//   }
//   if (trace) {
//     std::cout << "Current node: " << current_node.getName() << std::endl;
//     if (input.substr(i) == "") {
//       std::cout << "Current input: ." << std::endl;
//     } else {
//       std::cout << "Current input: " << input.substr(i) << std::endl;
//     }
//     std::cout << "Current stack: ";
//     stack_.printStack();
//     std::cout << "------------------------" << std::endl;
//   } 
//   for (Transition transition : transitions) {
//     Stack stack_copy = stack_;
//     if (transition.getStackSymbolConsumed() == '.') {
//       throw std::invalid_argument("Transition must consume a stack symbol");
//     }
//     stack_.pop();
//     if (transition.getStackSymbolProduced() != ".") {
//       pushStack(transition.getStackSymbolProduced());
//     }
//     if (transition.getSymbol() == '.') {
//       if (evaluatePrivate(input, findNode(transition.getNextNodeName()), i, trace)) {
//         return true;
//       }
//     } else {
//       if (evaluatePrivate(input, findNode(transition.getNextNodeName()), i + 1, trace)) {
//         return true;
//       }
//     }
//     stack_ = stack_copy;
//   }
//   return (current_node.isFinal() && i > input.size() - 1);
// }