#include "Celda.h"

Celda::Celda() {}

Celda::Celda(int activo, int x, int y) {
  coche_activo_ = activo;
  posX = x;
  posY = y;
}

Celda::~Celda() {

}

void Celda::setActivo(int valor) {
  coche_activo_ = valor;
}

void Celda::setObs(int valor) {
  obstaculo_ = valor;
}

void Celda::setFinal(int valor) {
  end_point_ = valor;
}

bool Celda::isActivo() {
  return coche_activo_;
}

bool Celda::isObs() {
  return obstaculo_;
}

int Celda::getX() {
  return posX;
}

int Celda::getY() {
  return posY;
}

ostream& Celda::WriteCelda(ostream& os) const {
  if (coche_activo_) {
    os << GREEN << " C " << RESET;
  } else if (obstaculo_) {
    os << RED << " O " << RESET;
  } else if (end_point_) {
    os << YELLOW << " F " << RESET;
  } else { 
    os << " · ";
  }
  return os;
}