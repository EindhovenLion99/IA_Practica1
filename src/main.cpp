#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Celda.h"
#include "Tablero.h"

using namespace std;



int main() {
  srand(time(NULL));
  cout << endl << "PRACTICA 1: Busqueda" << endl << endl;

  cout << "Introduce el numero de filas: ";
  int filas;
  cin >> filas;

  cout << "Introduce el numero de columnas: ";
  int columnas;
  cin >> columnas;

  Tablero T(filas, columnas);

  int opc;
  cout << endl << "Posicion del coche: Manual (0) o aleatorio (1)?: ";
  cin >> opc;

  int x_coche, y_coche;

  if (opc > 1 || opc < 0) {
    cout << "Introduzca una opcion valida (0/1)" << endl;
    exit(0);
  } else if (opc) {
    cout << "Modo aleatorio..." << endl;
    x_coche = rand() % filas;
    y_coche = rand() % columnas;
    T.setCoche(x_coche, y_coche);
  } else {
    cout << endl << "Modo Manual" << endl;
    cout << "Introduzca posicion del coche x: ";
    cin >> x_coche;
    cout << "Introduzca posicion del coche y: ";
    cin >> y_coche;
    T.setCoche(x_coche, y_coche);
  }

  int Obstaculos;
  cout << endl << "Introduce el numero de obstaculos: ";
  cin >> Obstaculos;

  cout << endl << "Manual (0) o aleatorio (1)?: ";
  cin >> opc;

  int x, y;

  if (opc > 1 || opc < 0) {
    cout << "Introduzca una opcion valida (0/1)" << endl;
    exit(0);
  } else if (opc) {
    cout << "Modo aleatorio..." << endl;
    for (int i = 0; i < Obstaculos; ++i) {
      x = rand() % filas;
      y = rand() % columnas;
      if(T.isCar(x, y)){
        --i;
      } else {
        T.setObstaculo(x, y);
      }
    }
  } else {
    cout << endl << "Modo Manual" << endl;
    for (int i = 0; i < Obstaculos; ++i) {
      cout << "Coordenada x: ";
      cin >> x;
      cout << "Coordenada y: ";
      cin >> y;
      if (T.isCar(x, y)) {
        cout << "En esa coordenada se ubica el coche, repita..." << endl;
        --i;
      } else {
        T.setObstaculo(x, y);
      } 
    }
  }

  cout << endl << "Posicion del final: Manual (0) o aleatorio (1)?: ";
  cin >> opc;

  int x_final = x_coche;
  int y_final = y_coche;
  int aux = 0;

  if (opc > 1 || opc < 0) {
    cout << "Introduzca una opcion valida (0/1)" << endl;
    exit(0);
  } else if (opc) {
    cout << "Modo aleatorio..." << endl;
    while (T.isCar(x_final, y_final) || T.isObs(x, y)) {
      x_final = rand() % filas;
      x = x_final;
      y_final = rand() % columnas;
      y = y_final;
    }
    T.setDestino(x_final, y_final);
  } else {
    cout << endl << "Modo Manual" << endl;
    while (T.isCar(x_final, y_final) || T.isObs(x, y)) {
      if (aux > 0) 
        cout << "En esa celda se encuentra un coche o un obstaculo, repita..." << endl;
      cout << "Introduzca posicion del final x: ";
      cin >> x_final;
      x = x_final;
      cout << "Introduzca posicion del final y: ";
      cin >> y_final;
      y = y_final;
      ++aux;
    }
    T.setDestino(x_final, y_final);
  }
  T.WriteTablero();
}