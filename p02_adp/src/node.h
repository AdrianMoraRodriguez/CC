#include <iostream>
#include <vector>
#include <string>

#include "transition.h"

#pragma once

class Node {
 public:
  Node(std::string name) {} 
  Node(std::string name, bool isFinal) {
    isFinal_ = isFinal;
    this->name_ = name;
  }
  Node(std::string name, std::vector<Transition> transitions) {
    this->transitions_ = transitions;
  }
  Node(std::string name, std::vector<Transition> transitions, bool isFinal) {
    this->transitions_ = transitions;
    this->isFinal_ = isFinal;
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
 private:
  std::vector<Transition> transitions_;
  bool isFinal_ = false;
  std::string name_;
};