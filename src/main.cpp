#include "../include/Tablero.h"

int main(int argc, char *argv[]) {

    int pasajeros = 1;
    cout << endl << "PRACTICA 1: Busqueda" << endl << endl;
    cout << "Modo de Visualización: Consola" << endl;

    // ************* Filas y Columnas

    cout << "Introduce el numero de filas: "; 
    int filas;
    cin >> filas;

    cout << "Introduce el numero de columnas: ";
    int columnas;
    cin >> columnas;

    // ************+ Posicion del coche
    
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
    } else {
      cout << endl << "Modo Manual" << endl;
      cout << "Introduzca posicion del coche x: ";
      cin >> x_coche;
      cout << "Introduzca posicion del coche y: ";
      cin >> y_coche;
    }

    // *********** Porcentaje de obstaculos

    int obs, pea;
    cout << "¿Porcentaje de obstaculos?" << endl;
    cin >> obs; 
	  cout << endl;

    srand(static_cast<unsigned int>(time(nullptr)));

    // ************ Crear el tablero

    Tablero Tablero_(filas, columnas, false, obs);
    Tablero_.visualizar();

    // *********** Posicion final
    
    cout << endl << "Posicion del final: Manual (0) o aleatorio (1)?: ";
    cin >> opc;

    int x, y;
    int x_final = x_coche;
    int y_final = y_coche;
    int aux = 0;

    if (opc > 1 || opc < 0) {
      cout << "Introduzca una opcion valida (0/1)" << endl;
      exit(0);
    } else if (opc) {
      cout << "Modo aleatorio..." << endl;
      x_final = rand() % filas;
      x = x_final;
      y_final = rand() % columnas;
      y = y_final;
    } else {
      cout << endl << "Modo Manual" << endl;
      cout << "Introduzca posicion del final x: ";
      cin >> x_final;
      x = x_final;
      cout << "Introduzca posicion del final y: ";
      cin >> y_final;
      y = y_final;
    }

    // *********** Camino minimo con Euclidea
    
    cout << endl << "\n\nCamino minimo con Funcion Heuristica: Distancia Euclidea \n\n";
    Tablero_.caminoMinimo(x_coche, y_coche, x_final, y_final, pasajeros);
    cout << "Pasajeros recogidos: " << pasajeros << endl;
    cout << "Nodos generados: " << Tablero_.contador << endl;

    Tablero_.cambiarHeuristica(true);
    pasajeros = 1;
    Tablero_.contador = 0;

    // *********** Camino minimo con Manhattan

    cout << endl << "\n\nCamino minimo con Funcion Heuristica: Distancia Manhattan \n\n";
    Tablero_.caminoMinimo(x_coche, y_coche, x_final, y_final, pasajeros);
    cout << "Pasajeros recogidos: " << pasajeros << endl;
    cout << "Nodos generados: " << Tablero_.contador << endl;
    return 0;
}#include "../include/Tablero.h"

int main(int argc, char *argv[]) {

    cout << endl << "PRACTICA 1: Busqueda" << endl << endl;
    cout << "Modo de Visualización: Consola" << endl;

    // ************* Filas y Columnas

    cout << "Introduce el numero de filas: "; 
    int filas;
    cin >> filas;

    cout << "Introduce el numero de columnas: ";
    int columnas;
    cin >> columnas;

    // ************+ Posicion del coche
    
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
    } else {
      cout << endl << "Modo Manual" << endl;
      cout << "Introduzca posicion del coche x: ";
      cin >> x_coche;
      cout << "Introduzca posicion del coche y: ";
      cin >> y_coche;
    }

    // *********** Porcentaje de obstaculos

    int obs, pea;
    cout << "¿Porcentaje de obstaculos?" << endl;
    cin >> obs; 
	  cout << endl;

    srand(static_cast<unsigned int>(time(nullptr)));

    // ************ Crear el tablero

    Tablero Tablero_(filas, columnas, false, obs);
    Tablero_.visualizar();

    // *********** Posicion final
    
    cout << endl << "Posicion del final: Manual (0) o aleatorio (1)?: ";
    cin >> opc;

    int x, y;
    int x_final = x_coche;
    int y_final = y_coche;
    int aux = 0;

    if (opc > 1 || opc < 0) {
      cout << "Introduzca una opcion valida (0/1)" << endl;
      exit(0);
    } else if (opc) {
      cout << "Modo aleatorio..." << endl;
      x_final = rand() % filas;
      x = x_final;
      y_final = rand() % columnas;
      y = y_final;
    } else {
      cout << endl << "Modo Manual" << endl;
      cout << "Introduzca posicion del final x: ";
      cin >> x_final;
      x = x_final;
      cout << "Introduzca posicion del final y: ";
      cin >> y_final;
      y = y_final;
    }

    // *********** Camino minimo con Euclidea
    
    cout << endl << "\n\nCamino minimo con Funcion Heuristica: Distancia Euclidea \n\n";
    Tablero_.caminoMinimo(x_coche, y_coche, x_final, y_final);
    cout << "Nodos generados: " << Tablero_.contador << endl;

    Tablero_.cambiarHeuristica(true);
    Tablero_.contador = 0;

    // *********** Camino minimo con Manhattan

    cout << endl << "\n\nCamino minimo con Funcion Heuristica: Distancia Manhattan \n\n";
    Tablero_.caminoMinimo(x_coche, y_coche, x_final, y_final);
    cout << "Nodos generados: " << Tablero_.contador << endl;
    return 0;
}

