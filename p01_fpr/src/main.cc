#include <iostream>

#include "funciones/funcionSuma.h"
#include "funciones/funcionMultiplicar.h"
#include "funciones/funcionElevar.h"

int main() {
  FunctionSuma suma;
  std::cout << "Introduzca dos números enteros: ";
  int x, y;
  std::cin >> x >> y;
  if (x < 0 || y < 0) {
    std::cout << "Los números deben ser enteros positivos" << std::endl;
    return 1;
  }
  std::cout << "El resultado de elevar " << x << " a la " << y << " es: " << FunctionElevar().operar(x, y) << std::endl;
  std::cout << "Se han realizado " << FRP::getContador() << " llamadas a funciones" << std::endl;
  return 0;
}