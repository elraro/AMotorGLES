/*
 * triangulo.cpp
 *
 *  Created on: Nov 12, 2015
 *      Author: francisco
 */

#include <GLES/gl.h>
#include "triangulo.h"

Triangulo::~Triangulo() {
    //TODO
}

Vector3D color; //color
Vector3D vertex0;
Vector3D vertex1;
Vector3D vertex2;

void Triangulo::render() {

    color = this->getColor();
    vertex0 = this->getP0();
    vertex1 = this->getP1();
    vertex2 = this->getP2();


    GLfloat triangle[] = {
            vertex0.getX(), vertex0.getY(), vertex0.getZ(),
            vertex1.getX(), vertex1.getY(), vertex1.getZ(),
            vertex2.getX(), vertex2.getY(), vertex2.getZ()
    };

    glColor4f(color.getX(), color.getY(), color.getZ(), 1.0f);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, triangle);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableClientState(GL_VERTEX_ARRAY);

}
