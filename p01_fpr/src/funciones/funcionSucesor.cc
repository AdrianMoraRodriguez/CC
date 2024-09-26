/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Complejidad Computacional (CC)
 * Curso: 4º
 * Práctica 1: Implementación de Funciones Primitivas Recursivas
 * @file funcionSucesor.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la clase FuncionSucesor
 * 
 */

#include "funcionSucesor.h"

/**
 * @brief Operación de la función primitiva recursiva sucesor
 * @param x 
 * @param y 
 * @return int 
 */
int FuncionSucesor::operar(int x, int y) const {
  std::cout << "Sucesor no posible con dos argumentos" << std::endl;
  exit(1);
}

int FuncionSucesor::operar(int x) const {
  return x + 1;
}

int FuncionSucesor::operar(std::vector<int> x, int y, int length) const {
  std::cout << "Sucesor no posible con vector" << std::endl;
  exit(1);
}