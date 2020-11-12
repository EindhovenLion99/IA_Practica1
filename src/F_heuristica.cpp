#include "F_heuristica.h"

F_heuristica::F_heuristica(){}

F_heuristica::~F_heuristica(){}

//-----------------------------------------------------

D_euclidea::D_euclidea(): F_heuristica(){}

int D_euclidea::operator()(Celda& i, Celda& f){
    return static_cast<int>(sqrt(pow((i.getX() - f.getX()), 2) + pow((i.getY() - f.getY()), 2)));
}

//-----------------------------------------------------

D_manhattan::D_manhattan(): F_heuristica(){}

int D_manhattan::operator()(Celda& i, Celda& f){
    return static_cast<int>(fabs(static_cast<double>(i.getX() - f.getX())) + fabs(static_cast<double>(i.getY() - f.getY())));
}