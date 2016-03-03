/*
 * Solido.h
 *
 *  Created on: Oct 5, 2015
 *      Author: francisco
 */

#ifndef SOLIDO_H_
#define SOLIDO_H_

#include "vector3d.h"
#include "renderizable.h"

using namespace std;

class Contorno;

class Solido : public Renderizable {
    Vector3D c;
    Vector3D p;
    Vector3D v;
    float m;
public:
    Solido();

    Solido(Vector3D p) : c(1, 1, 0), p(p), v(0, 0, 0), m(1) { }

    virtual ~Solido();

    inline const float &getM() const { return m; }

    inline void setM(const float &m) { this->m = m; }

    inline const Vector3D &getColor() const { return c; }

    inline void setColor(const Vector3D &c) { this->c = c; }

    inline const Vector3D &getP() const { return p; }

    inline void setP(const Vector3D &p) { this->p = p; }

    inline Vector3D &getV() { return v; }

    inline void setV(const Vector3D &v) { this->v = v; }

    virtual void update(float dt) { p += v * dt; }

    virtual Vector3D calcularV(Vector3D f) {
        Vector3D a = f / m;
        Vector3D aux = Vector3D(v) += a;
        return aux;
    }

    virtual void aplicaFuerza(Vector3D f) {
        Vector3D a = f / m;
        v += a;
    }

    virtual bool colision(Solido *s) { return false; }

    virtual void resuelveColision(Solido *s);

    virtual void teleportar(Solido *s);

    virtual Contorno *getContorno();
};

#endif /* SOLIDO_H_ */
