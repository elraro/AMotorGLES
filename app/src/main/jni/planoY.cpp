/*
 * planoY.cpp
 *
 *  Created on: Nov 6, 2015
 *      Author: francisco
 */

#include <GLES/gl.h>
#include "planoY.h"

PlanoY::~PlanoY() {
    // TODO Auto-generated destructor stub
}

void PlanoY::render() {
    Vector3D c = this->getColor();

    GLfloat plane[] = {
            -s, p, -s,
            s, p, -s,
            s, p, s,
            -s, p, s
    };

    glColor4f(c.getX(), c.getY(), c.getZ(), 1.0f);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, plane);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);

}
