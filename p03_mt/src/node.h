#include <iostream>
#include <vector>
#include <string>

#include "transition.h"

#pragma once

class Node {
 public:
  Node() {}
  Node(std::string name) {
    name_ = name;
  } 
  Node(std::string name, bool isFinal) {
    isFinal_ = isFinal;
    name_ = name;
  }
  Node(std::string name, std::vector<Transition> transitions) {
    transitions_ = transitions;
  }
  Node(std::string name, std::vector<Transition> transitions, bool isFinal) {
    transitions_ = transitions;
    isFinal_ = isFinal;
  }
  void addTransition(Transition transition) {
    transitions_.push_back(transition);
  }

  void setFinal(bool isFinal) {
    isFinal_ = isFinal;
  }

  std::string getName() {
    return name_;
  }

  std::vector<Transition> getTransitions() {
    return transitions_;
  }

  bool isFinal() {
    return isFinal_;
  }

  std::vector<Transition> getTransitions(std::vector<char> symbols) {
    std::vector<Transition> result;
    for (Transition transition : transitions_) {
      if (transition.getSymbols() == symbols) {
        result.push_back(transition);
      }
    }
    return result;
  }

  //Sobrecarga de operador para imprimir el nodo
  friend std::ostream& operator<<(std::ostream& os, const Node& node) {
    os << "Node: " << node.name_ << std::endl;
    os << "Transitions: " << std::endl;
    for (Transition transition : node.transitions_) {
      os << transition;
      os << "----------------" << std::endl;
    }
    return os;
  }
 private:
  std::vector<Transition> transitions_;
  bool isFinal_ = false;
  std::string name_;
};