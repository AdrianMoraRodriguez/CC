#include <iostream>

#include "stackAutomaton.h"

int main() {
  StackAutomaton automaton;
  std::string filendir = "data/";
  std::string filename;
  std::cout << "Debbug? (y/n): ";
  char debbug;
  std::cin >> debbug;
  if (debbug == 'y') {
    filendir = "/workspaces/CC/p02_adp/data/";
  }
  std::cout << "Enter the name of the file: ";
  std::cin >> filename;
  filendir += filename;
  automaton.makeAutomaton(filendir);
  std::string input;
  automaton.printAutomaton();
  while (true) {
    std::cout << "Enter the input string (exit to quit): ";
    std::cin >> input;
    if (input == "exit") {
      break;
    }
    if (automaton.evaluate(input)) {
    std::cout << "The string is accepted" << std::endl;
    } else {
      std::cout << "The string is not accepted" << std::endl;
    }
  }
}