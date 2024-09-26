/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Complejidad Computacional (CC)
 * Curso: 4º
 * Práctica 1: Implementación de Funciones Primitivas Recursivas
 * @file funcionZero.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la clase FuncionZero
 * 
 */

#include "funcionZero.h"

/**
 * @brief Operación de la función primitiva recursiva zero
 * @param x 
 * @param y 
 * @return int 
 */
int FuncionZero::operar(int x, int y) const {
  std::cout << "Zero no posible con dos argumentos" << std::endl;
  exit(1);
}

int FuncionZero::operar(int x) const {
  incrementarContador();
  return 0;
}

int FuncionZero::operar(std::vector<int> x, int y, int length) const {
  std::cout << "Zero no posible con vector" << std::endl;
  exit(1);
}

int FuncionZero::operar(int x, int y, FRP* function) const {
  std::cout << "Zero no posible con función" << std::endl;
  exit(1);
}