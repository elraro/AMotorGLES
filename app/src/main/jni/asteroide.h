/*
 * Asteroide.h
 *
 *  Created on: Nov 12, 2015
 *      Author: francisco
 */

#ifndef ASTEROIDE_H_
#define ASTEROIDE_H_

#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "vector3d.h"
#include "contorno.h"
#include "triangulo.h"
#include <GLES/gl.h>

class Asteroide : public Solido {
    vector<Vector3D *> vertices;
    vector<Triangulo *> triangulos;
    float maxX, maxY, maxZ;
    float minX, minY, minZ;
public:
    Asteroide(const Asteroide &m);

    Asteroide(bool grande);

    virtual ~Asteroide();

    Triangulo *centrar(Triangulo *t);

    inline float getAncho() { return maxX - minX; }

    inline float getAlto() { return maxY - minY; }

    inline float getProfundo() { return maxZ - minZ; }

    inline void addTriangulo(Triangulo *t) {
        triangulos.push_back(t);
    }

    inline void setColor(Vector3D c) {
        for (Triangulo *t:triangulos) {
            t->setColor(c);
        }
    }

    inline void render() {
        Vector3D p = this->getP();
        glPushMatrix();
        glTranslatef(p.getX(), p.getY(), p.getZ());
        for (Triangulo *t:triangulos) {
            t->render();
        }

        glPopMatrix();
    }

    void cargar(string nombreFichero);

    Vector3D *parseVector3D(string &linea);

    Triangulo *parseTriangulo(string &linea);

    void calculaExtremos(Vector3D *v);

    inline Contorno *getContorno();

    bool getGrande() { return this->grande; }

private:
    bool grande = false;
};

#endif /* ASTEROIDE_H_ */
