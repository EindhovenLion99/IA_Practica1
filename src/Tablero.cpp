#include "../include/Tablero.h"

int Tablero::contador = 0;

void Tablero::addObstaculos(bool mod) {

    if (mod) {                                                            //Modo guiado
        int x, y;
        ifstream InputFile;
        InputFile.open ("coordenadas.txt", ios::in);

        while (!InputFile.eof()) {
            InputFile >> x >> y;
            if(x < 0 || y < 0 || x >= rejilla_.size() || y >= rejilla_[0].size()){
                //Out of borders control
            } else {
              rejilla_[x][y].setValor(1);
            }
        }
        InputFile.close();
    }
    else {       //Asignación automática
        for (unsigned int i = 0; i < rejilla_.size(); i++) {
            for (unsigned int j = 0; j < rejilla_[i].size(); j++) {
                if(rand()%100 < porcentajeObstaculos_)  
                    rejilla_[i][j].setValor(1);
            }
        }
    }
}

void Tablero::resetCamino() {
    for (unsigned int i = 0; i < rejilla_.size(); i++)
        for (unsigned int j = 0; j < rejilla_[i].size(); j++)
            if (rejilla_[i][j].getValor() == 3)
                rejilla_[i][j].setValor(0);
}

void Tablero::setVecinosAt(int i, int j) {
    rejilla_[i][j].resetVecinos();
    if (rejilla_[i][j].getValor() != 1) {
        if (i-1 >= 0) {
            if (rejilla_[i-1][j].getValor() != 1) {
                rejilla_[i][j].addVecino(rejilla_[i-1][j]);
            }
        }
        if (i+1 < rejilla_.size()) {
            if (rejilla_[i+1][j].getValor() != 1) {
                rejilla_[i][j].addVecino(rejilla_[i+1][j]);
            }
        }
        if (j-1 >= 0) {
            if (rejilla_[i][j-1].getValor() != 1) {
                rejilla_[i][j].addVecino(rejilla_[i][j-1]);
            }
        }
        if (j+1 < rejilla_[i].size()) {
            if (rejilla_[i][j+1].getValor() != 1) {
                rejilla_[i][j].addVecino(rejilla_[i][j+1]);
            }
        }
    }
}

void Tablero::setVecinos() {
    for (unsigned int i = 0; i < rejilla_.size(); i++) {
        for (unsigned int j = 0; j < rejilla_[i].size(); j++) {
            setVecinosAt(i, j);
        }
    }
}

Tablero::Tablero(int x, int y, bool h, int xc, int yc, int pObst):x_(x), y_(y) {

    if (pObst < 0) porcentajeObstaculos_ = CONST_P_OBSTACULOS;
    else porcentajeObstaculos_ = pObst;

    if (h) heuristica_ = new D_manhattan();
    else heuristica_ = new D_euclidea();

    for (int i = 0; i < x_; i++) {
      vector<Celda> vectorY;
      for (int j = 0; j < y_; j++) {
        Celda aux(i, j);
        vectorY.push_back(aux);
      }
      rejilla_.push_back(vectorY);
    }
    addObstaculos(false);
    rejilla_[xc][yc].setValor(2);
    setVecinos();
}

Tablero::~Tablero() {
    delete heuristica_;
}

void Tablero::visualizar() {
  for(unsigned int i = 0; i < rejilla_.size(); i++){
      cout << "|";
      for (unsigned int j = 0; j < rejilla_[i].size(); j++){
          rejilla_[i][j].visualizar();
      }
      cout << "|" << endl;
  }
}

bool Tablero::is_in_set(const Celda& c, const std::vector<Celda>& s) {
    for(unsigned int i = 0; i < s.size(); i++)
        if(s[i].getX() == c.getX() && s[i].getY() == c.getY())
            return true;

    return false;
}

void Tablero::reconstruir_camino(vector<Celda> &v, Celda actual, Celda I){
    Celda a = actual;
    v.push_back(a);
    while(a.getX() != I.getX() || a.getY() != I.getY()){           //Mientras no llegue a la celda inicial
        a = rejilla_[static_cast<unsigned int>(a.getPadre().first)][static_cast<unsigned int>(a.getPadre().second)];
        v.push_back(a);
    }
}

vector<Celda> Tablero::Astar(unsigned int x_coche, unsigned int y_coche, unsigned int x_final, unsigned int y_final){

    vector<Celda> result;                                               // Almacena el camino optimo
    vector<Celda> setAbierto;
    vector<Celda> setCerrado;

    Celda& Inicial = rejilla_[x_coche][y_coche];
    Celda& Final = rejilla_[x_final][y_final];

    Inicial.setg_(0);                                                   //Cambiamos valores heuristicos de la primera Celda
    Inicial.setf_((*heuristica_)(Inicial, Final));

    setAbierto.push_back(Inicial);                                      //Setup completada
    contador++;

    while (!setAbierto.empty()) {
        unsigned int winner = 0;
        for (unsigned int i = 0; i < setAbierto.size(); i++) {            //Se busca la Celda con menor f_valor
            if (setAbierto[i].getf_() < setAbierto[winner].getf_())
                winner = i;
        }

        //Celda copia a la que tenemos en la rejilla y en el set.
        Celda actual = rejilla_[setAbierto[winner].getX()][setAbierto[winner].getY()];

        if ((actual.getX() == x_final) && (y_final == actual.getY())) {     //Es la misma celda -> Hemos llegado al final con camino óptimo
            reconstruir_camino(result, actual, Inicial);
            return result;
        }

        setAbierto.erase(setAbierto.begin() + winner);                  //Cambiamos actual de set
        setCerrado.push_back(actual);

        for (int i = 0; i < actual.sizeVecinos(); i++) {                  //Miramos los vecinos de la Celda actual
            int x = actual.getVecino(i).first;
            int y = actual.getVecino(i).second;
            Celda vecino = rejilla_[x][y];                              //Valor copia de la Celda vecina

            if (is_in_set(vecino, setCerrado))
                continue;

            int tent_g = actual.getg_() + 1;

            if (!is_in_set(vecino, setAbierto)) {
                setAbierto.push_back(vecino);
                contador++;
            }
            else if (tent_g >= vecino.getg_())
                continue;

            //Este camino es el mejor! Guárdalo
            rejilla_[vecino.getX()][vecino.getY()].setPadre(actual);
            rejilla_[vecino.getX()][vecino.getY()].setg_(tent_g);
            rejilla_[vecino.getX()][vecino.getY()].setf_(tent_g + (*heuristica_)(vecino, Final));
        }
    }

    return result;
}

void Tablero::caminoMinimo(unsigned int x_coche, unsigned int y_coche, unsigned int x_final, unsigned int y_final) {

    long t0,t1;
    resetCamino();

    if (rejilla_[x_coche][y_coche].getValor() == 1) {
        rejilla_[x_coche][y_coche].setValor(2);
        setVecinosAt(x_coche, y_coche);
    }
    if (rejilla_[x_final][y_final].getValor() == 1) {
       rejilla_[x_final][y_final].setValor(0);
       if (x_final - 1 >= 0) {
           setVecinosAt(x_final - 1, y_final);
       }
       if (x_final + 1 < rejilla_.size()) {
           setVecinosAt(x_final + 1, y_final);
       }
       if (y_final - 1 >= 0) {
           setVecinosAt(x_final, y_final - 1);
       }
       if (y_final + 1 < rejilla_[0].size()) {
           setVecinosAt(x_final, y_final + 1);
       }
    }


    t0 = clock();
    vector<Celda> result = Astar(x_coche, y_coche, x_final, y_final);
    t1 = clock();

    double time = (double(t1-t0)/CLOCKS_PER_SEC);

    cout << "Tamaño resultado: " << result.size() << endl
         << "Tiempo de ejecucion: " << time;

    
    for (unsigned int i = 0; i < result.size(); i++) {
        rejilla_[result[i].getX()][result[i].getY()].setValor(3);
    }

    cout << "\n\n" << endl;

    visualizar();
}

void Tablero::cambiarHeuristica(bool opt) { 
    delete heuristica_;
    if (opt) {
        //Manhattan
        heuristica_ = new D_manhattan();
    }
    else {
        //Euclidea
        heuristica_ = new D_euclidea();
    }
}
