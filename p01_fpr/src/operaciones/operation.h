

#pragma once

#include <vector>

#include "../funciones/fpr.h"

class Operation {
  public:
    Operation(FRP* left_function, FRP* right_function) {
      left_function_ = left_function;
      right_function_ = right_function;
    }
    Operation() {}
    virtual int operar(int x, int y) const = 0;
    virtual int operar(std::vector<int> x, int y, int length) const = 0;
    virtual int operar(int x) const = 0;
    virtual int operar(int x, int y, FRP* function) const = 0;
    virtual std::vector<int> operar(std::vector<int> x, std::vector<int> y) const = 0;
  protected:
    FRP* left_function_;
    FRP* right_function_;
};