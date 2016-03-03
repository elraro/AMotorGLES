/*
 * contorno.h
 *
 *  Created on: Nov 7, 2015
 *      Author: francisco
 */

#ifndef CONTORNO_H_
#define CONTORNO_H_

#include <cmath>
#include "plano.h"
#include "disparo.h"
#include "nave.h"

class Contorno {
    Vector3D p;
    float r;
public:
    Contorno(Vector3D p, float r) : p(p), r(r) { }

    virtual ~Contorno();

    bool colision(Plano *p);

    bool colision(Disparo *e);

    bool colision(Nave *c);

    const Vector3D &getP() const { return p; }

    void setP(const Vector3D &p) { this->p = p; }

    float getR() const { return r; }

    void setR(float r) { this->r = r; }
};

#endif /* CONTORNO_H_ */
