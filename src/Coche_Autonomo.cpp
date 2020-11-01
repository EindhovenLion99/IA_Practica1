#include "Coche_Autonomo.h"

Coche_Autonomo::Coche_Autonomo() {}

Coche_Autonomo::Coche_Autonomo(int activo, int x, int y) {
  activo_ = activo;
  posX = x;
  posY = y;
}

Coche_Autonomo::~Coche_Autonomo() {

}

void Coche_Autonomo::setActivo(int valor) {
  activo_ = valor;
}

void Coche_Autonomo::setObs(int valor) {
  obstaculo_ = valor;
}

bool Coche_Autonomo::isActivo() {
  return activo_;
}

bool Coche_Autonomo::isObs() {
  return obstaculo_;
}


ostream& Coche_Autonomo::WriteCoche(ostream& os) const {
  if (activo_) {
    os << GREEN << " C " << RESET;
  } else if (obstaculo_) {
    os << RED << " O " << RESET;
  } else { 
    os << "  ";
  }
}