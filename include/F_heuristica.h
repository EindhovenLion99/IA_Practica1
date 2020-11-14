#include <cmath>
#include "Celda.h"

class F_heuristica {
public:
    F_heuristica();
    virtual ~F_heuristica();

    virtual int operator()(const Celda&, const Celda&) = 0;
};

//-----------------------DISTANCIA EUCLIDEA-------------------------

class D_euclidea : public F_heuristica {
public:
    D_euclidea();
    int operator()(const Celda&, const Celda&);
};

//-----------------------DISTANCIA RECTILINEA-----------------------

class D_manhattan : public F_heuristica {
public:
    D_manhattan();
    int operator()(const Celda&, const Celda&);
};

