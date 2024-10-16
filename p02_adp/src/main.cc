#include <iostream>

#include "stackAutomaton.h"

int main() {
  StackAutomaton automaton;
  std::string filendir = "data/";
  std::string filename;
  std::cout << "Enter the name of the file: ";
  std::cin >> filename;
  filendir += filename;
  automaton.makeAutomaton(filendir);
}