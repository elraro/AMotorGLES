/*
 * Escena.h
 *
 *  Created on: Oct 5, 2015
 *      Author: francisco
 */

#ifndef ESCENA_H_
#define ESCENA_H_

#include <vector>
#include <algorithm>
#include "solido.h"
#include "asteroide.h"
#include "planoZ.h"
#include "planoY.h"
#include "planoX.h"
#include "disparo.h"
#include "nave.h"
#include <cmath>
#include <android/log.h>

#define  LOG_TAG3    "escenajni"
#define  LOGE3(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG3,__VA_ARGS__)

class Escena : public Solido {
    vector<Solido *> solidos;

    vector<Solido *> moviles; //se mueven por la pantalla
    vector<Solido *> limites; //limites del mapa

    vector<Solido *> asteroides; // lista de asteroides
    vector<Solido *> disparos; // lista de disparos

    Nave *nave;
private:
    int lives = 3;
    int level = 1;
    bool death = false;
    int score = 0;

    void removeAsteroid(Solido *s) {
        bool grande = false;
        Asteroide *asteroide;
        asteroide = (Asteroide *) s;
        Vector3D p = s->getP();
        Vector3D v = s->getV();

        // Saber si es grande el asteroide
        if (asteroide->getGrande()) {
            grande = true;
        }

        // Borramos al asteroide
        asteroides.erase(remove(asteroides.begin(), asteroides.end(), s), asteroides.end());
        moviles.erase(remove(moviles.begin(), moviles.end(), s), moviles.end());
        solidos.erase(remove(solidos.begin(), solidos.end(), s), solidos.end());
        s->~Solido(); // Llamamos al destructor

        // Si era grande el asteroide, creamos 3 pequeños
        if (grande) {

            // Vamos a añadir 3 asteroides pequeños
            // el angulo es atan2(x, z)*180/pi
            float angulo = atan2(v.getX(), v.getY()) * 180.0f / M_PI;

            Vector3D ac1 = Vector3D(cos(angulo) * 50 * level, sin(angulo) * 50 * level, 0);
            Vector3D ac2 = Vector3D(cos(angulo + 30) * 50 * level, sin(angulo + 30) * 50 * level,
                                    0);
            Vector3D ac3 = Vector3D(cos(angulo - 30) * 50 * level, sin(angulo - 30) * 50 * level,
                                    0);

            Asteroide *a1 = new Asteroide(false);
            a1->setColor(Vector3D(0.3, 0.3, 0.3));
            a1->setP(p);
            a1->setV(v);
            a1->aplicaFuerza(ac1);
            this->addAsteroid(a1);

            Asteroide *a2 = new Asteroide(false);
            a2->setColor(Vector3D(0.3, 0.3, 0.3));
            a2->setP(p);
            a2->setV(v);
            a2->aplicaFuerza(ac2);
            this->addAsteroid(a2);

            Asteroide *a3 = new Asteroide(false);
            a3->setColor(Vector3D(0.3, 0.3, 0.3));
            a3->setP(p);
            a3->setV(v);
            a3->aplicaFuerza(ac3);
            this->addAsteroid(a3);
        }
    }

    // Borrar el disparo
    void removeBullet(Solido *s) {
        moviles.erase(remove(moviles.begin(), moviles.end(), s), moviles.end());
        solidos.erase(remove(solidos.begin(), solidos.end(), s), solidos.end());
        disparos.erase(remove(disparos.begin(), disparos.end(), s), disparos.end());

        s->~Solido();
    }

    // Borrar la nave
    void removeShip(Solido *s) {
        moviles.erase(remove(moviles.begin(), moviles.end(), s), moviles.end());
        solidos.erase(remove(solidos.begin(), solidos.end(), s), solidos.end());
        s->~Solido();
    }

    // Avanzamos al siguiente nivel
    void nextLevel() {
        this->level++;
        generarAsteroides();
    }

    // Generamos asteroides dependiendo del nivel
    void generarAsteroides() {
        for (int i = 1; i <= level; i++) {
            while (true) {
                Asteroide *m = new Asteroide(true);
                int randX = rand() % 180 + (-90);
                int randY = rand() % 80 + (-40);
                m->setColor(Vector3D(0.3, 0.3, 0.3));
                m->setP(Vector3D(randX, randY, 0));
                m->setV(Vector3D(randX * 0.1 * level, randY * 0.1 * level, 0));

                // Si no colisiona lo añado
                // Una posible mejora es detectar también una distancia
                Solido * n;
                n = nave;
                if (!n->colision(m)) {
                    this->addAsteroid(m);
                    break;
                }

            }
        }
    }

    void addAsteroid(Solido *s) {
        solidos.push_back(s);
        moviles.push_back(s);
        asteroides.push_back(s);
    }

    void addShip(Nave *s) {
        solidos.push_back(s);
        moviles.push_back(s);
        nave = s;
        death = false;
    }

    void addLimite(Solido *s) {
        solidos.push_back(s);
        limites.push_back(s);
    }

    void addBullet(Solido *s) {
        solidos.push_back(s);
        moviles.push_back(s);
        disparos.push_back(s);
    }

    int getDisparos() {
        return disparos.size();
    }

public:
    Escena();

    virtual ~Escena();

    int getScore() {
        return score;
    }

    Nave *getShip() {
        return this->nave;
    }

    bool isDead() {
        return death;
    }

    int getLives() {
        return lives;
    }

    // Inicializamos la escena
    void start(int dificultad) {
        Solido *c;

        if (dificultad == 0) { //facil
            level = 1;
            lives = 5;
        } else if (dificultad == 1) { //medio
            level = 1;
            lives = 3;
        } else if (dificultad == 2) { //dificil
            level = 2;
            lives = 1;
        }

        // Vamos a crear los límites del videojuego
        c = new PlanoY(-100, 1000);
        this->addLimite(c);
        c = new PlanoY(100, 1000);
        this->addLimite(c);
        c = new PlanoX(-200, 1000);
        this->addLimite(c);
        c = new PlanoX(200, 1000);
        this->addLimite(c);

        Nave *nave = new Nave(Vector3D(0, 0, -1));
        this->addShip(nave);

        generarAsteroides();
    }

    // Dibujamos
    inline void render() {
        for (Solido *r:solidos) {
            r->render();
        }
    }

    // Actualizamos posiciones
    inline void update(float dt) {
        for (Solido *s:moviles) {
            s->update(dt);
        }
        vector<Solido *> disparosAux;
        for (Solido *s: disparos) {
            // Hago cast
            Disparo* dis;
            dis = static_cast<Disparo*>(s);

            if (dis->checkTiempo()) {
                // Se acabó el tiempo, debo borrar el disparo
                disparosAux.push_back(s);
            }
        }

        for (vector<Solido *>::iterator it = disparosAux.begin(); it != disparosAux.end(); ++it) {
            this->removeBullet(*it);
        }
    }

    // Resolver colisiones
    inline void resuelveColisiones() {
        vector<Solido *> movilesAux;
        vector<Solido *> asteroidesAux;

        // Si algo choca con los límites
        for (Solido *l:limites) {
            for (Solido *s:moviles) {
                if (l->colision(s)) {
                    l->teleportar(s);
                }
            }
        }

        bool checkDead = false;

        for (Solido *m:moviles) {
            for (Solido *a: asteroides) {
                if (a != m) {
                    if (m->colision(a)) {
                        if (m == nave) {
                            // Colision nave con asteroide
                            if (!nave->getVulnerability()) {
                                death = true;
                                checkDead = true;
                            }
                        } else {
                            // Disparo colisiona con asteroide
                            // No podemos borrar mientras recorremos
                            // Se guarda en lista auxiliar y luego se borra
                            movilesAux.push_back(m);
                            asteroidesAux.push_back(a);
                        }
                    }
                }
            }
        }

        // Hemos muerto?
        if (checkDead && death) {
            lives--;
            this->removeShip(nave);
            Nave *nave = new Nave(Vector3D(0, 0, -1));
            this->addShip(nave);
            death = false;
        }

        // Borramos si debemos borrar asteroides o disparos
        for (vector<Solido *>::iterator it = asteroidesAux.begin();
             it != asteroidesAux.end(); ++it) {
            // Hago cast
            Asteroide* a;
            a = static_cast<Asteroide*>(*it);

            if (a->getGrande()) {
                score += 10;
            } else {
                score += 20;
            }

            this->removeAsteroid(*it);
        }
        for (vector<Solido *>::iterator it = movilesAux.begin(); it != movilesAux.end(); ++it) {
            this->removeBullet(*it);
        }

        // Si no hay asteroides, avanzamos de nivel
        if (this->asteroides.size() == 0) {
            this->nextLevel();
        }
    }

    // Método para disparar
    void disparar() {
        if (this->getDisparos() < 3) {
            Solido *c;
            Vector3D p = this->getShip()->getP();
            float disparoX = p.getX() + cos(this->getShip()->getAngulo()) * 7;
            float disparoY = p.getY() + sin(this->getShip()->getAngulo()) * 7;

            c = new Disparo(Vector3D(disparoX, disparoY, 0), 2);
            c->setColor(Vector3D(1, 1, 1));

            float velocidadDisparoX = cos(this->getShip()->getAngulo()) * 150;
            float velocidadDisparoY = sin(this->getShip()->getAngulo()) * 150;
            c->setV(Vector3D(velocidadDisparoX, velocidadDisparoY, 0));
            this->addBullet(c);
        }
    }
};

#endif /* ESCENA_H_ */
