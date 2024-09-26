

#include "fpr.h"

class FunctionSuma: public FRP {
  public:
    FunctionSuma() {}
    int operar(int x, int y) const override;
    int operar(std::vector<int> x, int y, int length) const override;
    int operar(int x) const override;
    int operar(int x, int y, FRP* function) const override;
};