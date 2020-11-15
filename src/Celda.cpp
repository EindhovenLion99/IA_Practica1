#include "../include/Celda.h"

Celda::Celda():valor_(0), g_(INT_MAX), f_(INT_MAX), x_(0), y_(0) {
    padre_ = std::make_pair(0, 0);  //default
}

Celda::Celda(int x, int y, int valor, int g, int f):
valor_(valor), g_(g), f_(f), x_(x), y_(y) {
    if(x < 0 || y < 0) 

    if(valor_ < 0 || valor_ > 3){
        valor_ = 0;                 //default
    }
    padre_ = std::make_pair(0,0);   //default
}

Celda::~Celda() {}

int Celda::getValor(){ return valor_; }

void Celda::setValor(int valor){ valor_ = valor; }

int Celda::getX() const { return x_; }

int Celda::getY() const { return y_; }

int Celda::getf_() { return f_; }

void Celda::setf_(int f) { f_ = f; }

int Celda::getg_() { return g_; }

void Celda::setg_(int g) { g_ = g; }

pair<int,int> Celda::getPadre() {
    return padre_;
}

pair<int,int> Celda::getPadre() const {
    return padre_;
}

void Celda::setPadre(const Celda& c) {
    padre_ = std::make_pair(c.getX(), c.getY());
}

unsigned int Celda::sizeVecinos() { return vecinos_.size(); }

pair<int, int> Celda::getVecino(int i) {
    return vecinos_[static_cast<unsigned int>(i)];
}

void Celda::resetVecinos() {
    vecinos_.clear();
}

void Celda::visualizar() {
    switch (valor_){
        case 0: {
            cout << " . ";
            break;
        }
        case 1: {
            cout << RED << " O " << RESET;
            break;
        }
        case 2: {
            cout << YELLOW << " C " << RESET;
            break;
        }
        case 3: {
            cout << GREEN << " X " << RESET;
        break;
        }
        default: {
            
        }
    }
}

void Celda::addVecino(const Celda& c) {
    vecinos_.push_back(std::make_pair(c.getX(), c.getY()));
}
