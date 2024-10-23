#include <stack>
#include <iostream>

#pragma once

class Stack {
 public:
  Stack() {}
  Stack(Stack& stack) {stack_ = stack.getStack();}
  Stack(std::stack<char> stack) {stack_ = stack;}
  void push(char symbol) {
    stack_.push(symbol);
  }
  char pop() {
    if (stack_.empty()) {
      return '.';
    }
    char symbol = stack_.top();
    stack_.pop();
    return symbol;
  }
  char top() {
    return stack_.top();
  }
  bool empty() {
    return stack_.empty();
  }
  std::stack<char> getStack() {
    return stack_;
  }
  void printStack() {
    std::stack<char> stack_copy = stack_;
    while (!stack_copy.empty()) {
      std::cout << stack_copy.top();
      stack_copy.pop();
    }
    std::cout << std::endl;
  }
  private:
    std::stack<char> stack_;
};