#include "funcionMultiplicar.h"
#include "funcionHMultiplicar.h"
#include "funcionProyeccion.h"
#include "funcionSucesor.h"
#include "funcionZero.h"
#include "../operaciones/composition.h"

int FunctionMultiplicar::operar(int x, int y) const {
  if (y == 0) {
    FRP* function = new FuncionZero();
    FRP* function1 = new FuncionProyeccion();
    Composition operationComposition(function, function1);
    return operationComposition.operar(std::vector<int>{x, y}, 0, 1);
  }
  else {
    FRP* function = new FunctionHMultiplicar();
    FRP* function1 = new FunctionMultiplicar();
    return function->operar(x, y-1, function1);
  }
}

int FunctionMultiplicar::operar(std::vector<int> x, int y, int length) const {
  std::cout << "No se puede realizar la operación" << std::endl;
  exit(1);
}

int FunctionMultiplicar::operar(int x) const {
  std::cout << "No se puede realizar la operación" << std::endl;
  exit(1);
}

int FunctionMultiplicar::operar(int x, int y, FRP* function) const {
  std::cout << "No se puede realizar la operación" << std::endl;
  exit(1);
}