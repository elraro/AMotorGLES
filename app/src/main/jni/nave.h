/*
 * Nave.h
 *
 *  Created on: 21 de dic. de 2015
 *      Author: alberto
 */

#ifndef NAVE_H_
#define NAVE_H_

#include "vector3d.h"
#include "solido.h"

class Nave : public Solido {
    float r;
    float angulo = 0;
public:
    Nave();

    Nave(Vector3D p, float r = 3) : Solido(p), r(r) { }

    virtual ~Nave();

    void render();

    inline float getR() const { return r; }

    inline void setR(float r) { this->r = r; }

    inline Contorno *getContorno();

    inline bool colision(Solido *s);

    //Custom
    void updatePosition(bool leftPressed, bool rightPressed, bool upPressed);

    float getAngulo() { return ((angulo * 3.14) / 180); }

    bool getVulnerability();

private:
    void giroIzquierda();

    void giroDerecha();

    void propulsion();

    int invulnerable = 100;
};

#endif /* NAVE_H_ */
