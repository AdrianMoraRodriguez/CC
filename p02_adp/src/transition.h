#include <iostream>
#include <vector>

#pragma once

class Transition {
 public:
  Transition() {}
  Transition(char symbol,std::string nextNodeName, char stackSymbol, std::string stackSymbolProduced) {
    this->symbol_ = symbol;
    this->nextNodeName_ = nextNodeName;
    this->stackSymbolConsumed_ = stackSymbol;
    this->stackSymbolProduced_ = stackSymbolProduced;
  }
  Transition(char symbol,std::string nextNodeName) {
    this->symbol_ = symbol;
    this->nextNodeName_ = nextNodeName;
    this->stackSymbolConsumed_ = '.';
    this->stackSymbolProduced_ = ".";
  }
  Transition(char symbol,std::string nextNodeName, char stackSymbol) {
    this->symbol_ = symbol;
    this->nextNodeName_ = nextNodeName;
    this->stackSymbolConsumed_ = stackSymbol;
    this->stackSymbolProduced_ = ".";
  }
  Transition(char symbol,std::string nextNodeName, std::string stackSymbolProduced) {
    this->symbol_ = symbol;
    this->nextNodeName_ = nextNodeName;
    this->stackSymbolConsumed_ = '.';
    this->stackSymbolProduced_ = stackSymbolProduced;
  }
  // Sobrecarga de operador para imprimir la transición
  friend std::ostream& operator<<(std::ostream& os, const Transition& transition) {
    os << "Symbol: " << transition.symbol_ << std::endl;
    os << "Next node: " << transition.nextNodeName_ << std::endl;
    os << "Stack symbol consumed: " << transition.stackSymbolConsumed_ << std::endl;
    os << "Stack symbol produced: " << transition.stackSymbolProduced_ << std::endl;
    return os;
  }
  char getSymbol() {
    return symbol_;
  }
  std::string getNextNodeName() {
    return nextNodeName_;
  }
  char getStackSymbolConsumed() {
    return stackSymbolConsumed_;
  }
  std::string getStackSymbolProduced() {
    return stackSymbolProduced_;
  }
 private:
  char symbol_;
  std::string nextNodeName_;
  char stackSymbolConsumed_;
  std::string stackSymbolProduced_;
};