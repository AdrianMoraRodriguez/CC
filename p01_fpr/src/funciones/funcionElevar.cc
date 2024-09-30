#include "funcionElevar.h"
#include "funcionHElevar.h"
#include "funcionProyeccion.h"
#include "funcionSucesor.h"
#include "funcionZero.h"
#include "../operaciones/composition.h"

int FunctionElevar::operar(int x, int y) const {
  if (y == 0) {
    FRP* function = new FuncionZero();
    FRP* function1 = new FuncionProyeccion();
    FRP* function2 = new FuncionSucesor();
    Composition operationComposition(function, function1);
    return function2->operar(operationComposition.operar(std::vector<int>{x, y}, 0, 1));
  }
  else {
    FRP* function = new FunctionHElevar();
    FRP* function1 = new FunctionElevar();
    return function->operar(x, y-1, function1);
  }
}

int FunctionElevar::operar(std::vector<int> x, int y, int length) const {
  std::cout << "No se puede realizar la operación" << std::endl;
  exit(1);
}

int FunctionElevar::operar(int x) const {
  std::cout << "No se puede realizar la operación" << std::endl;
  exit(1);
}

int FunctionElevar::operar(int x, int y, FRP* function) const {
  std::cout << "No se puede realizar la operación" << std::endl;
  exit(1);
}