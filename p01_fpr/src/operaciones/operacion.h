/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Complejidad Computacional (CC)
 * Curso: 4º
 * Práctica 1: Implementación de Funciones Primitivas Recursivas
 * @file operacion.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Clase abstracta Operacion
 * 
 */

#include "../funciones/fpr.h"

#pragma once

class Operacion {
  public:
    virtual int operar(FRP* base, FRP* recursion) const = 0;
};