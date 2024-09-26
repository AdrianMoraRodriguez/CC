/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Complejidad Computacional (CC)
 * Curso: 4º
 * Práctica 1: Implementación de Funciones Primitivas Recursivas
 * @file fpr.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Clase abstracta FRP
 * 
 */

#include <iostream>
#include <vector>

#pragma once

class FRP {
  public:
    virtual int operar(int x, int y = 0) const = 0;
    virtual int operar(std::vector<int> x, int y = 0, int length) const = 0;
    virtual int operar(int x) const = 0;
    virtual int operar(int x, int y, FRP* function) const = 0;
    static void resetContador() { contador = 0; }
  private:
    static int contador;
  protected:
    static void incrementarContador() { contador++; }
};

int Operacion::contador = 0;