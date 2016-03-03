/*
 * planoX.cpp
 *
 *  Created on: Nov 7, 2015
 *      Author: francisco
 */

#include "planoX.h"
#include "escena.h"

PlanoX::~PlanoX() {
    // TODO Auto-generated destructor stub
}

void PlanoX::render() {
    Vector3D c = this->getColor();

    GLfloat plane[] = {
            p, -s, -s,
            p, s, -s,
            p, s, s,
            p, -s, s,
    };

    glColor4f(c.getX(), c.getY(), c.getZ(), 1.0f);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, plane);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);

}

