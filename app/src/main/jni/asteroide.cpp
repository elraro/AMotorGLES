/*
 * Asteroide.h
 */

#include "asteroide.h"

Asteroide::Asteroide(bool grande) {
    if (grande) {
        this->grande = true;
        this->setM(1);
        cargar("asteroideGrande.obj");
    } else {
        this->grande = false;
        this->setM(1);
        cargar("asteroide.obj");
    }
}

Asteroide::Asteroide(const Asteroide &m) {
    for (Triangulo *t:m.triangulos) {
        this->triangulos.push_back(new Triangulo(*t));
    }
    this->minX = m.minX;
    this->maxX = m.maxX;
    this->minY = m.minY;
    this->maxY = m.maxY;
    this->minZ = m.minZ;
    this->maxZ = m.maxZ;
}

Asteroide::~Asteroide() {
    // TODO Auto-generated destructor stub
}

Triangulo *Asteroide::centrar(Triangulo *t) {
    Vector3D centro(minX + getAncho() / 2.0, minY + getAlto() / 2.0, minZ + getProfundo() / 2);
    Vector3D p0 = t->getP0();
    Vector3D p1 = t->getP1();
    Vector3D p2 = t->getP2();
    return (new Triangulo(p0 - centro, p1 - centro, p2 - centro));
}

Vector3D *Asteroide::parseVector3D(string &linea) {
    float x, y, z;
    istringstream ss(linea);
    ss >> x;
    ss >> y;
    ss >> z;
    return new Vector3D(x, y, z);
}

Triangulo *Asteroide::parseTriangulo(string &linea) {
    istringstream ss(linea);
    int iv0, iv1, iv2;
    ss >> iv0;
    ss >> iv1;
    ss >> iv2;
    iv0--;
    iv1--;
    iv2--;
    Vector3D p0 = *vertices[iv0];
    Vector3D p1 = *vertices[iv1];
    Vector3D p2 = *vertices[iv2];
    Triangulo *t = new Triangulo(p0, p1, p2);
    return t;
}

void Asteroide::calculaExtremos(Vector3D *v) {
    float x = v->getX();
    float y = v->getY();
    float z = v->getZ();
    maxX = fmax(maxX, x);
    maxY = fmax(maxY, y);
    maxZ = fmax(maxZ, z);
    minX = fmin(minX, x);
    minY = fmin(minY, y);
    minZ = fmin(minZ, z);

}

void Asteroide::cargar(string nombreFichero) {
    maxX = maxY = maxZ = -1e40;
    minX = minY = minZ = 1e40;
    string linea;
    string path = "/sdcard/asteroids/model/" + nombreFichero;
    ifstream ficheroAsteroideObj(path.c_str());
    if (ficheroAsteroideObj.is_open()) {
        while (!ficheroAsteroideObj.eof()) {
            getline(ficheroAsteroideObj, linea);
            if (linea.c_str()[0] == 'v') {
                linea[0] = ' ';
                Vector3D *v = parseVector3D(linea);
                calculaExtremos(v);
                vertices.push_back(v);
            }
            Vector3D centro(minX + getAncho() / 2.0, minY + getAlto() / 2.0,
                            minZ + getProfundo() / 2);
            if (linea.c_str()[0] == 'f') {
                linea[0] = ' ';
                Triangulo *t = parseTriangulo(linea);
                triangulos.push_back(t);
                //triangulos.push_back(centrar(t));
                //delete t;
            }
        }
    }
}

inline Contorno *Asteroide::getContorno() {
    return new Contorno(getP(), getAlto() / 2.0);
}
