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
  if (Tab[x][y].isActivo())
    return true;
  return false;
}

bool Tablero::isObs(int x, int y) {
  if (Tab[x][y].isObs())
    return true;
  return false;
}

void Tablero::addPeatones() {
  

}

void Tablero::resetCamino() {
   
}


void Tablero::setVecinos() {        //Definitivamente necesitamos que sean enteros normales, asi que... C++11 type-cast
   
}

/* bool Tablero::is_in_set(const Celda& c, const std::vector<Celda>& s) {
  return true;
}

void Tablero::reconstruir_camino(vector<Celda> &v, Celda actual, Celda I) {
   
}

vector<Celda> Tablero::Astar(unsigned int xInicio, unsigned int yInicio, unsigned int xFinal, unsigned int yFinal) {

    
}

void Tablero::caminoMinimo(unsigned int xInicio, unsigned int yInicio, unsigned int xFinal, unsigned int yFinal, int& pasajeros) {

  
}*/

void Tablero::cambiarHeuristica(bool opt) {
    delete heuristica_;
    if(opt) {
        //Manhattan
        // heuristica_ = new D_manhattan();
    }
    else {
        //Euclidea
      // heuristica_ = new D_euclidea();
    }
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