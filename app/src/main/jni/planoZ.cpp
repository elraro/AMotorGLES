/*
 * planoZ.cpp
 *
 *  Created on: Nov 7, 2015
 *      Author: francisco
 */

#include <GLES/gl.h>
#include "planoZ.h"

PlanoZ::~PlanoZ() {
    // TODO Auto-generated destructor stub
}

void PlanoZ::render() {

    Vector3D c = this->getColor();

    GLfloat plane[] = {
            -s, -s, p,
            s, -s, p,
            s, s, p,
            -s, s, p
    };

    glColor4f(c.getX(), c.getY(), c.getZ(), 1.0f);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, plane);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);

}
