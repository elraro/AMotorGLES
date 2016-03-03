/*
 * contorno.cpp
 *
 *  Created on: Nov 7, 2015
 *      Author: francisco
 */

#include "contorno.h"

Contorno::~Contorno() {
    // TODO Auto-generated destructor stub
}

bool Contorno::colision(Plano *pl) {
    Vector3D vn(pl->getA(), pl->getB(), pl->getC());
    return fabs(vn * p - pl->getD()) < r;
}

bool Contorno::colision(Disparo *e) {
    Vector3D pe = e->getP();
    float re = e->getR();
    Vector3D vd = pe - p;
    float l = vd.length();
    return l < r + re;
}

bool Contorno::colision(Nave *s) {
    Vector3D pe = s->getP();
    float re = s->getR();
    Vector3D vd = pe - p;
    float l = vd.length();
    return l < r + re;
}
