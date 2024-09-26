

#include "funcionSuma.h"
#include "funcionHSuma.h"
#include "funcionProyeccion.h"
#include "funcionSucesor.h"
#include "funcionZero.h"
#include "../operaciones/composition.h"

int FunctionSuma::operar(int x, int y) const {
  incrementarContador();
  if (y == 0) {
    FRP* function = new FuncionProyeccion();
    return function->operar(std::vector<int>{x}, 0, 1);
  }
  else {
    FRP* function = new FunctionHSuma();
    FRP* function1 = new FunctionSuma();
    return function->operar(x, y-1, function1);
  }
}

int FunctionSuma::operar(std::vector<int> x, int y, int length) const {
  std::cout << "No se puede realizar la operación" << std::endl;
  exit(1);
}

int FunctionSuma::operar(int x) const {
  std::cout << "No se puede realizar la operación" << std::endl;
  exit(1);
}

int FunctionSuma::operar(int x, int y, FRP* function) const {
  std::cout << "No se puede realizar la operación" << std::endl;
  exit(1);
}