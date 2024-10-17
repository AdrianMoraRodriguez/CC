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
  std::string file;
  file = filendir + filename;
  automaton.makeAutomaton(file);
  std::string input;
  std::cout << "Automatan previsualization: " << std::endl;
  automaton.printAutomaton();
  std::cout << "Type 'exit' to exit, type 'change' to change the automaton used" << std::endl;
  while (true) {
    std::cout << "Enter the input or option: ";
    std::cin >> input;
    if (input == "exit") {
      break;
    }
    if (input == "change") {
      std::cout << "Enter the name of the file: ";
      std::cin >> filename;
      std::string file;
      file = filendir + filename;
      automaton.makeAutomaton(file);
      std::cout << "Automaton changed, new automatan previsualization: " << std::endl;
      automaton.printAutomaton();
      continue;
    }
    if (automaton.evaluate(input)) {
    std::cout << "The string is accepted" << std::endl;
    } else {
      std::cout << "The string is not accepted" << std::endl;
    }
  }
  system("clear");
}