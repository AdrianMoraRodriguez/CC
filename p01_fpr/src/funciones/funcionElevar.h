
#include "fpr.h"

#pragma once

class FunctionElevar : public FRP {
  public:
    FunctionElevar() {}
    int operar(int x, int y) const override;
    int operar(std::vector<int> x, int y, int length) const override;
    int operar(int x) const override;
    int operar(int x, int y, FRP* function) const override;
};