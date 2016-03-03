/*
 * planoX.h
 *
 *  Created on: Nov 7, 2015
 *      Author: francisco
 */

#ifndef PLANOX_H_
#define PLANOX_H_

#include "plano.h"

class PlanoX : public Plano {
public:
    float p;
    float s;
public:
    PlanoX(float p = 0, float s = 100) : Plano(Vector3D(1, 0, 0), Vector3D(-p, 0, 0)), p(p),
                                         s(s) { this->setColor(Vector3D(0, 1, 0)); }

    virtual ~PlanoX();

    void render();

    void resuelveColision(Solido *s) {
        Vector3D &v = s->getV();
        float vx = v.getX();
        vx *= -1;
        v.setX(vx);
    }
};

#endif /* PLANOX_H_ */
