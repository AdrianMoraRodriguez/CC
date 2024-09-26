
#include "funcionHElevar.h"
#include "funcionMultiplicar.h"
#include "funcionProyeccion.h"
#include "funcionSucesor.h"
#include "funcionZero.h"
#include "../operaciones/composition.h"
#include "../operaciones/combination.h"

int FunctionHElevar::operar(int x, int y) const {
  std::cout << "No se puede realizar la operación" << std::endl;
  exit(1);
}

int FunctionHElevar::operar(std::vector<int> x, int y, int length) const {
  std::cout << "No se puede realizar la operación" << std::endl;
  exit(1);
}

int FunctionHElevar::operar(int x) const {
  std::cout << "No se puede realizar la operación" << std::endl;
  exit(1);
}

int FunctionHElevar::operar(int x, int y, FRP* function) const {
  incrementarContador();
  std::vector<int> vector;
  vector.push_back(x);
  vector.push_back(y);
  vector.push_back(function->operar(x, y));
  FRP* function1 = new FuncionProyeccion();
  int result1 = function1->operar(vector, 2, 3);
  int result2 = function1->operar(vector, 0, 3);
  Operation* operation = new Combination();
  std::vector<int> vector1 = operation->operar(std::vector<int>{result1}, std::vector<int>{result2});
  FRP* function2 = new FunctionMultiplicar();
  return function2->operar(function1->operar(vector1, 0, 2), function1->operar(vector1, 1, 2));
}