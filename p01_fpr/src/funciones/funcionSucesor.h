/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Complejidad Computacional (CC)
 * Curso: 4º
 * Práctica 1: Implementación de Funciones Primitivas Recursivas
 * @file funcionSucesor.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Clase FuncionSucesor
 * 
 */

#include "fpr.h"

#pragma once

class FuncionSucesor : public FRP {
  public:
    int operar(int x, int y = 0) const override;
    int operar(std::vector<int> x, int y = 0, int length) const override;
    int operar(int x) const override;
    int operar(int x, int y, FRP* function) const override;
};