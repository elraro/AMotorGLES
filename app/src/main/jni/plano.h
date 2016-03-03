/*
 * Plano.h
 *
 *  Created on: Oct 5, 2015
 *      Author: francisco
 */

#ifndef PLANO_H_
#define PLANO_H_

#include "solido.h"

class Plano : public Solido {
    float a, b, c, d;
public:
    Plano();

    //vn must be normalized
    Plano(Vector3D vn, Vector3D p) : a(vn.getX()), b(vn.getY()), c(vn.getZ()), d(vn * p) { }

    virtual ~Plano();

    inline float getA() const { return a; }

    inline void setA(float a) { this->a = a; }

    inline float getB() const { return b; }

    inline void setB(float b) { this->b = b; }

    inline float getC() const { return c; }

    inline void setC(float c) { this->c = c; }

    inline float getD() const { return d; }

    inline void setD(float d) { this->d = d; }

    bool colision(Solido *s);

    Vector3D getNormal() {
        Vector3D v(a, b, c);
        //v.normalize();
        return v;
    }
};

#endif /* PLANO_H_ */
