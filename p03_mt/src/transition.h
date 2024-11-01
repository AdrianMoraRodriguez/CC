#include <iostream>
#include <vector>

#pragma once

class Transition {
 public:
  Transition() {}
  Transition(std::vector<char> symbols,std::string nextNodeName, std::vector<char> symbolsToWrite, std::vector<char> movements) {
    this->symbols_ = symbols;
    this->nextNodeName_ = nextNodeName;
    this->symbolsToWrite_ = symbolsToWrite;
    this->movements_ = movements;
  }
  // Sobrecarga de operador para imprimir la transición
  friend std::ostream& operator<<(std::ostream& os, const Transition& transition) {
    os << "Symbol of each tape: ";
    for (char symbol : transition.symbols_) {
      os << symbol << " ";
    }
    os << std::endl;
    os << "Next node: " << transition.nextNodeName_ << std::endl;
    os << "Symbol to write in each tape: ";
    for (char symbol : transition.symbolsToWrite_) {
      os << symbol << " ";
    }
    os << std::endl;
    os << "Movement for each tape: ";
    for (char symbol : transition.movements_) {
      os << symbol << " ";
    }
    os << std::endl;
    return os;
  }
  std::vector<char> getSymbols() {
    return symbols_;
  }
  std::string getNextNodeName() {
    return nextNodeName_;
  }
  std::vector<char> getSymbolsToWrite() {
    return symbolsToWrite_;
  }
  std::vector<char> getMovements() {
    return movements_;
  }
 private:
  std::vector<char> symbols_;
  std::string nextNodeName_;
  std::vector<char> symbolsToWrite_;
  std::vector<char> movements_;
};