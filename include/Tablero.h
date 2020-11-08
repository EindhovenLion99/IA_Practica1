#pragma once
#include "Celda.h"

class Tablero {
 private:
  int M, N;
  Celda **Tab;
  
 public:
  Tablero(int fila, int columna); 
  ~Tablero();

  void setCoche(int x, int y); // Da vida al coche
  void setObstaculo(int x, int y);
  void setDestino(int x, int y);

  bool isCar(int x, int y);
  bool isObs(int x, int y);

  Celda **getTablero() const; // Pasa por referencia el tablero  

  void WriteTablero(); // Escribe el tablero
  void ActualizarTab(); // Actualiza el tablero
};