#include <iostream>


#include "turingMachine.h"

int main() {
  turingMachine machine;
  std::string filendir = "data/";
  std::string filename;
  std::cout << "Enter the name of the file: ";
  std::cin >> filename;
  std::string file;
  file = filendir + filename;
  machine.makeMachine(file);
  std::cout << "Trace mode? (y/n): ";
  char debbug;
  std::cin >> debbug;
  bool trace =  debbug == 'y';
  std::string input;
  std::cout << "Type 'exit' to exit, type 'change' to change the machine used, 'trace' to change mode and 'print' to print machine " << std::endl;
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
      machine.makeMachine(file);
      continue;
    }
    if (input == "trace") {
      trace = !trace;
      std::cout << "Trace mode: " << (trace ? "on" : "off") << std::endl;
      continue;
    }
    if (input == "print") {
      machine.printMachine();
      continue;
    }
    if (machine.evaluate(input,trace)) {
    std::cout << "The string is accepted" << std::endl;
    } else {
      std::cout << "The string is not accepted" << std::endl;
    }
  }
}