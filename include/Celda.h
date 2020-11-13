#pragma once

#include <iostream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

using namespace std;

class Tablero;
class Celda {
 private:
  bool coche_activo_;
  bool obstaculo_;
  bool end_point_;

  int posX;
  int posY;
  int vecinas;

 public:
  Celda();
  Celda(int activo, int x, int y);
  ~Celda();

  void setActivo(int valor);
  void setObs(int valor);
  void setFinal(int valor);

  bool isActivo();
  bool isObs();
  bool isEnd();

  int getX();
  int getY();

  int contarVecinas(const Tablero& Tab);

  ostream& WriteCelda(ostream& os) const;
};