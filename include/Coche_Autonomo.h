#pragma once

#include <iostream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

using namespace std;

class Tablero;
class Coche_Autonomo {
 private:
  bool activo_;
  bool obstaculo_;
  int posX;
  int posY;
  int vacinas;

 public:
  Coche_Autonomo();
  Coche_Autonomo(int activo, int x, int y);
  ~Coche_Autonomo();

  void setActivo(int valor);
  void setObs(int valor);

  bool isActivo();
  bool isObs();

  int contarVecinas(const Tablero& Tab);

  ostream& WriteCoche(ostream& os) const;
};