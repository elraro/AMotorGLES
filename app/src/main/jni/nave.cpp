#include "nave.h"
#include "contorno.h"
#include "escena.h"

Nave::Nave() {
    // TODO Auto-generated constructor stub
}

Nave::~Nave() {
    // TODO Auto-generated destructor stub
}

void Nave::render() {
    if (this->invulnerable > 0) {
        this->invulnerable--;
    }
    Vector3D p = this->getP();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(p.getX(), p.getY(), -p.getZ()); //Desplazamos nave
    glRotatef(angulo, 0, 0, 1); // Rotamos
    glTranslatef(-p.getX(), -p.getY(), p.getZ()); // Volvemos a desplazar nave a su origen

    GLfloat nave[] = {
            p.getX() + 6.0f, p.getY() + 0.0f, p.getZ(),
            p.getX() + -4.0f, p.getY() + 4.0f, p.getZ(),
            p.getX() + 0.0f, p.getY() + 0.0f, p.getZ(),
            p.getX() + -4.0f, p.getY() + -4.0f, p.getZ()
    };

    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, nave);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);

    glPopMatrix();

}

inline Contorno *Nave::getContorno() {
    return new Contorno(this->getP(), r);
}

inline bool Nave::colision(Solido *s) {
    Contorno *c = s->getContorno();
    return c->colision(this);
}

void Nave::updatePosition(bool leftPressed, bool rightPressed, bool upPressed) {

    if (leftPressed) {
        this->giroIzquierda();
    }
    if (rightPressed) {
        this->giroDerecha();
    }
    if (upPressed) {
        this->propulsion();
    }

}

void Nave::giroIzquierda() {
    this->angulo += 2;
}

void Nave::giroDerecha() {
    this->angulo -= 2;
}

void Nave::propulsion() {
    Vector3D a = Vector3D(cos(angulo * M_PI / 180) * 0.5, sin(angulo * M_PI / 180) * 0.5, 0);
    Vector3D v = this->calcularV(a);
    if (v.length() < 150) {
        this->setV(v);
    }
}

bool Nave::getVulnerability() {
    return invulnerable > 0;
}
