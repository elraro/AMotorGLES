/*
 * Disparo.cpp
 */

#include <GLES/gl.h>
#include "disparo.h"
#include "contorno.h"

Disparo::Disparo() {

}

Disparo::~Disparo() {
    // TODO Auto-generated destructor stub
}

void Disparo::render() {
    Vector3D c = this->getColor();
    Vector3D p = this->getP();

    glColor4f(c.getX(), c.getY(), c.getZ(), 1.0f);
    //glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    int p1 = 120; // vértices de la esfera
    float cx = p.getX();
    float cy = p.getY();
    float cz = p.getZ();

    float theta1 = 0.0, theta2 = 0.0, theta3 = 0.0;
    float ex = 0.0f, ey = 0.0f, ez = 0.0f;
    float px = 0.0f, py = 0.0f, pz = 0.0f;
    GLfloat vertices[p1 * 6 + 6];

    if (r < 0)
        r = -r;

    if (p1 < 0)
        p1 = -p1;

    for (int i = 0; i < p1 / 2; ++i) {
        theta1 = i * (M_PI * 2) / p1 - M_PI_2;
        theta2 = (i + 1) * (M_PI * 2) / p1 - M_PI_2;

        for (int j = 0; j <= p1; ++j) {
            theta3 = j * (M_PI * 2) / p1;

            ex = cosf(theta2) * cosf(theta3);
            ey = sinf(theta2);
            ez = cosf(theta2) * sinf(theta3);
            px = cx + r * ex;
            py = cy + r * ey;
            pz = cz + r * ez;

            vertices[(6 * j) + (0 % 6)] = px;
            vertices[(6 * j) + (1 % 6)] = py;
            vertices[(6 * j) + (2 % 6)] = pz;

            ex = cosf(theta1) * cosf(theta3);
            ey = sinf(theta1);
            ez = cosf(theta1) * sinf(theta3);
            px = cx + r * ex;
            py = cy + r * ey;
            pz = cz + r * ez;

            vertices[(6 * j) + (3 % 6)] = px;
            vertices[(6 * j) + (4 % 6)] = py;
            vertices[(6 * j) + (5 % 6)] = pz;

        }
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, vertices);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, (p1 + 1) * 2);
        glDisableClientState(GL_VERTEX_ARRAY);
    }

}

inline Contorno *Disparo::getContorno() {
    return new Contorno(getP(), getR());
}

inline bool Disparo::colision(Solido *s) {
    Contorno *c = s->getContorno();
    return c->colision(this);
}


