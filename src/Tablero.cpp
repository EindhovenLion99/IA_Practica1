#include "Tablero.h"

Tablero::Tablero(int fila, int columna) {
  M = fila;
  N = columna;
  Tab = new Celda*[M];
  for (int i = 0; i < M; i++) {
    Tab[i] = new Celda[N];
  }
  for (int i = 0; i <  M; i++) {
    for (int j = 0; j < N; j++) {
      Tab[i][j] = Celda(0, i, j);
    }
  }
}

Tablero::~Tablero() {

}

void Tablero::setCoche(int x, int y) {
  Tab[x][y].setActivo(1);
}

void Tablero::setDestino(int x, int y) {
  Tab[x][y].setFinal(1);
}

void Tablero::setObstaculo(int x, int y) {
  Tab[x][y].setObs(1);
}

bool Tablero::isCar(int x, int y) {
  if(Tab[x][y].isActivo())
    return true;
  return false;
}

bool Tablero::isObs(int x, int y) {
  if(Tab[x][y].isObs())
    return true;
  return false;
}

void Tablero::WriteTablero() {
  cout << endl;
  for (int i = 0; i < M; i++) {
    cout << "|";
    for (int j = 0; j < N; j++) {
      Tab[i][j].WriteCelda(cout);
    }
    cout << "|" << endl;
  }
  cout << endl;
}