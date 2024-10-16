#include <iostream>
#include <vector>

#pragma once

class Transition {
 public:
  Transition() {}
  Transition(char symbol,std::string nextNodeName, char stackSymbol) {
    this->symbol_ = symbol;
    this->nextNodeName_ = nextNodeName;
    this->stackSymbol_ = stackSymbol;
  }
  Transition(char symbol,std::string nextNodeName) {
    this->symbol_ = symbol;
    this->nextNodeName_ = nextNodeName;
    this->stackSymbol_ = '.';
  }
 private:
  char symbol_;
  std::string nextNodeName_;
  char stackSymbol_;
};