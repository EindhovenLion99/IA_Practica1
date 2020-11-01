#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Coche_Autonomo.h"
#include "Tablero.h"

using namespace std;



int main() {
  cout << endl << "PRACTICA 1: Busqueda" << endl << endl;
  cout << "Introduce el numero de filas: ";
  int filas;
  cin >> filas;

  cout << "Introduce el numero de columnas: ";
  int columnas;
  cin >> columnas;

  Tablero T(filas, columnas);

  int x_coche, y_coche;
  cout << "Introduzca posicion del coche x: ";
  cin >> x_coche;
  cout << "Introduzca posicion del coche y: ";
  cin >> y_coche;

  T.setCoche(x_coche, y_coche);

  int Obstaculos;
  cout << "Introduce el numero de obstaculos: ";
  cin >> Obstaculos;

  cout << endl;

  int opc;
  cout << "Manual (0) o aleatorio (1)?: ";
  cin >> opc;

  if (opc > 1 || opc < 0) {
    cout << "Introduzca una opcion valida (0/1)" << endl;
    exit(0);
  } else if (opc) {
    cout << "Modo aleatorio..." << endl;
    for (int i = 0; i < Obstaculos; ++i) {
      srand (time(NULL));
      int x = rand() % filas;
      int y = rand() % columnas;
      T.setObstaculo(x, y);
    }
  } else {
    int x, y;
    cout << "Modo Manual" << endl;
    for (int i = 0; i < Obstaculos; ++i) {
      cout << "Coordenada x: ";
      cin >> x;
      cout << "Coordenada y: ";
      cin >> y;
      T.setObstaculo(x, y);
    }
  }

  cout << "Llega" << endl;
  T.WriteTablero();

}