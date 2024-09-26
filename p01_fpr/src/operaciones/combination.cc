#include "combination.h"

int Combination::operar(int x, int y) const {
  std::cout << "Error" << std::endl;
  exit(1);
}

int Combination::operar(std::vector<int> x, int y, int length) const {
  std::cout << "Error" << std::endl;
  exit(1);
}

int Combination::operar(int x) const {
  std::cout << "Error" << std::endl;
  exit(1);
}

int Combination::operar(int x, int y, FRP* function) const {
  std::cout << "Error" << std::endl;
  exit(1);
}

std::vector<int> Combination::operar(std::vector<int> x, std::vector<int> y) const {
  std::vector<int> result;
  for (int i = 0; i < x.size(); i++) {
    result.push_back(x[i]);
  }
  for (int i = 0; i < y.size(); i++) {
    result.push_back(y[i]);
  }
  return result;
}