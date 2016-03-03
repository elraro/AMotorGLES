/*
 * planoZ.h
 *
 *  Created on: Nov 7, 2015
 *      Author: francisco
 */

#ifndef PLANOZ_H_
#define PLANOZ_H_

#include "plano.h"

class PlanoZ : public Plano {
public:
    float p;
    float s;
public:

    PlanoZ(float p = 0, float s = 100) : Plano(Vector3D(0, 0, 1), Vector3D(0, 0, -p)), p(p), s(s) {
        this->setColor(Vector3D(0, 1, 0));
    }

    virtual ~PlanoZ();

    void render();

    void resuelveColision(Solido *s) {
        Vector3D &v = s->getV();
        float vz = v.getZ();
        vz *= -1;
        v.setZ(vz);
    }
};

#endif /* PLANOZ_H_ */
