
#include "funcionHSuma.h"
#include "funcionProyeccion.h"
#include "funcionSucesor.h"
#include "funcionZero.h"
#include "../operaciones/composition.h"

int FunctionHSuma::operar(int x, int y) const {
  std::cout << "No se puede realizar la operación" << std::endl;
  exit(1);
}

int FunctionHSuma::operar(std::vector<int> x, int y, int length) const {
  std::cout << "No se puede realizar la operación" << std::endl;
  exit(1);
}

int FunctionHSuma::operar(int x) const {
  std::cout << "No se puede realizar la operación" << std::endl;
  exit(1);
}

int FunctionHSuma::operar(int x, int y, FRP* function) const {
  incrementarContador();
  std::vector<int> vector;
  vector.push_back(x);
  vector.push_back(y);
  vector.push_back(function->operar(x, y));
  FRP* function1 = new FuncionProyeccion();
  FRP* function2 = new FuncionSucesor();
  Composition composition1(function2, function1);
  int result = composition1.operar(vector, 2, 3);
  return result;
}