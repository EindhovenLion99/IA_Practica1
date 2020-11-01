#include "Tablero.h"

Tablero::Tablero(int fila, int columna) {
  M = fila;
  N = columna;
  Tab = new Coche_Autonomo*[M];
  for (int i = 0; i < M; i++) {
    Tab[i] = new Coche_Autonomo[N];
  }
  for (int i = 0; i <  M; i++) {
    for (int j = 0; j < N; j++) {
      Tab[i][j] = Coche_Autonomo(0, i, j);
    }
  }
}

Tablero::~Tablero() {

}

void Tablero::setCoche(int x, int y) {
  Tab[x][y].setActivo(1);
}

void Tablero::setObstaculo(int x, int y) {
  Tab[x][y].setObs(1);
}

void Tablero::WriteTablero() {
  for (int i = 0; i < M; i++) {
    cout << "|";
    for (int j = 0; j < N; j++) {
      Tab[i][j].WriteCoche(cout);
    }
    cout << "|";
  }
  cout << endl;
}