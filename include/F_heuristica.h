#pragma once

#include <iostream>
#include <math.h>
#include "Celda.h"

using namespace std;

class F_heuristica {
    private:

    public:
        F_heuristica();
        virtual ~F_heuristica();

    virtual int operator()(const Celda&, const Celda&) = 0;
};

//-----------------------DISTANCIA EUCLIDEA-------------------------

class D_euclidea : public F_heuristica
{
public:
    D_euclidea();
    int operator()(Celda&, Celda&);
};

//-----------------------DISTANCIA RECTILINEA-----------------------

class D_manhattan : public F_heuristica
{
public:
    D_manhattan();
    int operator()(Celda&, Celda&);
};
