#pragma once
#include "Coche_Autonomo.h"

class Tablero {
 private:
  int M, N;
  Coche_Autonomo **Tab;
  
 public:
  Tablero(int fila, int columna); 
  ~Tablero();

  void setCoche(int x, int y); // Da vida al coche
  void setObstaculo(int x, int y); 
  Coche_Autonomo **getTablero() const; // Pasa por referencia el tablero  

  void WriteTablero(); // Escribe el tablero
  void ActualizarTab(); // Actualiza el tablero
};