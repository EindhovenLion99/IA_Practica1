const int CONST_P_OBSTACULOS = 30;
const int CAP_MAX_COCHE = 6;

#include <vector>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cmath>

#include "Celda.h"
#include "F_heuristica.h"

using namespace std;

// Tablero: Matriz de celdas, Implementada en la línea de comandos. Desde ella se gestionan las celdas y sus propiedades.
// Sirve de entorno de simulación del algoritmo A* de busqueda de caminos minimos que implementamos 
class Tablero {

private:
    vector<vector<Celda>> rejilla_;    // Matriz de celdas
    int porcentajeObstaculos_;      // Porcentaje que define la cantidad de celdas que contendrán obstáculos.
    int x_, y_;     // Tamaño del mapa (anchura y altura).
    F_heuristica* heuristica_;      //  Puntero clase padre, realiza el calculo h. True = manhattan      False = euclidea 

    /**
     * addObstaculos: Añade obstáculos en las celdas del mapa.
     *  mod: Booleano que permite alternar la entrada de obstáculos en el mapa:
     *  mod true: Se añaden los obstáculos desde un archivo que los contiene.
     *  mod false: Los obstáculos se generan aleatoriamente.
     */
    void addObstaculos(bool mod);

    void resetCamino();
    void setVecinosAt(int i, int j);
    void setVecinos();
    bool is_in_set(const Celda&, const std::vector<Celda>&);
    void reconstruir_camino(vector<Celda> &v, Celda actual, Celda I);
    vector<Celda> Astar(unsigned int x_coche, unsigned int y_coche, unsigned int x_final, unsigned int y_final);

public:

    static int contador;

    Tablero(int x, int y, bool h, int pObst = CONST_P_OBSTACULOS);
    ~Tablero();

    void caminoMinimo(unsigned int x_coche, unsigned int y_coche, unsigned int x_final, unsigned int y_final, int& pasajeros);
    void visualizar();

    void cambiarHeuristica(bool);

};


