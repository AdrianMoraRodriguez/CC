#include "operation.h"


class Combination: public Operation {
  public:
    Combination(FRP* left_function, FRP* right_function): Operation(left_function, right_function) {}
    Combination() {}
    int operar(int x, int y) const override;
    int operar(std::vector<int> x, int y, int length) const override;
    int operar(int x) const override;
    int operar(int x, int y, FRP* function) const override;
    std::vector<int> operar(std::vector<int> x, std::vector<int> y) const override;
};