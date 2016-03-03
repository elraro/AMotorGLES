/*
 * Disparo.h
 */

#ifndef DISPARO_H_
#define DISPARO_H_

#include "solido.h"
#include <vector>

class Disparo : public Solido {
    float r;
public:
    Disparo();

    Disparo(Vector3D p, float r = 0.5) : Solido(p), r(r) { }

    virtual ~Disparo();

    void render();

    inline float getR() const { return r; }

    inline void setR(float r) { this->r = r; }

    inline Contorno *getContorno();

    inline bool colision(Solido *s);

    bool checkTiempo() {
        if (tiempo != 0) {
            tiempo--;
            return false;
        }
        return true;
    }

private:
    int tiempo = 500;
};

#endif /* ESFERA_H_ */
