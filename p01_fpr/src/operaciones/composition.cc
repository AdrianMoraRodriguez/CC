

#include "composition.h"

int Composition::operar(int x, int y) const {
  return left_function_->operar(right_function_->operar(x, y));
}

int Composition::operar(std::vector<int> x, int y, int length) const {
  return left_function_->operar(right_function_->operar(x, y, length));
}

int Composition::operar(int x) const {
  return left_function_->operar(right_function_->operar(x));
}

int Composition::operar(int x, int y, FRP* function) const {
  return left_function_->operar(right_function_->operar(x, y, function));
}

std::vector<int> Composition::operar(std::vector<int> x, std::vector<int> y) const {
  std::cout << "Error" << std::endl;
  exit(1);
}