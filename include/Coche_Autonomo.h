#pragma once

#include <iostream>

using namespace std;

class Tablero;
class Coche_Autonomo {
 private:
  int posX;
  int PosY;
 public:
  Coche_Autonomo();
  Coche_Autonomo(int x, int y);
  ~Coche_Autonomo();

  ostream& WriteCoche(ostream& os) const;
};