/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Complejidad Computacional (CC)
 * Curso: 4º
 * Práctica 1: Implementación de Funciones Primitivas Recursivas
 * @file funcionProyeccion.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Definición de la clase FuncionProyeccion
 * 
 */

#include "funcionProyeccion.h"

/**
 * @brief Operación de la función primitiva recursiva proyección
 * @param x 
 * @param y 
 * @return int 
 */
int FuncionProyeccion::operar(int x, int y) const {
  std::cout << "Proyección no posible con entero en primer argumento" << std::endl;
  exit(1);
}

int FuncionProyeccion::operar(int x) const {
  std::cout << "Proyección no posible con un solo argumento" << std::endl;
  exit(1);
}

int FuncionProyeccion::operar(std::vector<int> x, int y, , int length) const {
  if (y >= length) {
    std::cout << "Proyección no posible con y mayor que la longitud del vector" << std::endl;
    exit(1);
  }
  return x[y];
}