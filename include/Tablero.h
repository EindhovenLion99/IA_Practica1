#pragma once

#include <vector>
#include <sstream>
#include "Celda.h"
#include "F_heuristica.h"

class Tablero {
  private:
    
    int M, N;
    Celda **Tab;
    F_heuristica* heuristica_;

   
    void addPeatones();

   

    void resetCamino();
    void setVecinosAt(int i, int j);
    void setVecinos();
    bool is_in_set(const Celda&, const std::vector<Celda>&);
    void reconstruir_camino(vector<Celda> &v, Celda actual, Celda I);
    vector<Celda> Astar(unsigned int xInicio, unsigned int yInicio, unsigned int xFinal, unsigned int yFinal);
  
  public:
    Tablero(int fila, int columna); 
    ~Tablero();

    void setCoche(int x, int y); // Da vida al coche
    void setObstaculo(int x, int y);
    void setDestino(int x, int y);

    bool isCar(int x, int y);
    bool isObs(int x, int y);

    static int contador;

    Celda **getTablero() const; // Pasa por referencia el tablero  

    void caminoMinimo(unsigned int xInicio, unsigned int yInicio, unsigned int xFinal, unsigned int yFinal, int& pasajeros);
    void cambiarHeuristica(bool);

    void WriteTablero(); // Escribe el tablero
    void ActualizarTab(); // Actualiza el tablero


};