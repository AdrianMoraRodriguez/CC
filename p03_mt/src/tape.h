
#include <iostream>
#include <vector>

class Tape {
 public:
  Tape() {}
  Tape(char blank_symbol) : blank_symbol_(blank_symbol) {
    tape_.push_back(blank_symbol);
    head_ = 0;
  }
  void Initialize(std::string input) {
    tape_.clear();
    if (input.size() == 0) {
      tape_.push_back(blank_symbol_);
    } else {
      for (int i = 0; i < input.size(); i++) {
        tape_.push_back(input[i]);
      }
    }
    head_ = 0;
  }
  char Read() {
    return tape_[head_];
  }
  void WriteAndMove(char symbol, char movement) {
    Write(symbol);
    MoveHead(movement);
  }

  // Sobrecarga de operador para imprimir la cinta
  friend std::ostream& operator<<(std::ostream& os, const Tape& tape) {
    for (int i = 0; i < tape.tape_.size(); i++) {
      if (i == tape.head_) {
        os << "\033[4m" << tape.tape_[i] << "\033[0m";
      } else {
        os << tape.tape_[i];
      }
    }
    return os;
  }

 private:
  void Write(char symbol) {
    tape_[head_] = symbol;
  }
  void MoveHead(char movement) {
    if (movement == 'L') {
      head_--;
      if (head_ < 0) {
        tape_.insert(tape_.begin(), blank_symbol_);
        head_ = 0;
      }
    } else if (movement == 'R') {
      head_++;
      if (head_ >= tape_.size()) {
        tape_.push_back(blank_symbol_);
      }
    }
  }
  std::vector<char> tape_;
  int head_;
  char blank_symbol_;
};